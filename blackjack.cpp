/**
 * @file blackjack.cpp
 * @brief Implementacja klasy BlackJack.
 */

#include "blackjack.h"
#include <QDebug>
#include <algorithm>

QDebug operator<<(QDebug debug, const Card& card)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << card.toString();
    return debug;
}

QString Card::toString() const {
    QString r, s;
    switch (rank) {
    case ACE: r = "A"; break; case KING: r = "K"; break;
    case QUEEN: r = "Q"; break; case JACK: r = "J"; break;
    default: r = QString::number(static_cast<int>(rank)); break;
    }
    switch (suit) {
    case HEARTS: s = QChar(0x2665); break; case DIAMONDS: s = QChar(0x2666); break;
    case CLUBS: s = QChar(0x2663); break; case SPADES: s = QChar(0x2660); break;
    }
    return r + s;
}

QString Card::valueString() const {
    if (rank >= JACK && rank <= KING) return (rank == JACK ? "J" : (rank == QUEEN ? "Q" : "K"));
    if (rank == ACE) return "A";
    return QString::number(static_cast<int>(rank));
}

int Card::value(bool aceAsEleven) const {
    if (rank >= JACK && rank <= KING) return 10;
    if (rank == ACE) return aceAsEleven ? 11 : 1;
    return static_cast<int>(rank);
}

BlackJack::BlackJack(Portfel *portfel, QObject *parent)
    : Gra(portfel, parent), m_currentBet(0.0), m_currentState(GameState::Betting) {
    qDebug() << "Konstruktor BlackJack: tworzenie obiektu gry.";
    createDeck();
    shuffleDeck();
}

BlackJack::~BlackJack() {
    qDebug() << "Destruktor BlackJack: niszczenie obiektu gry.";
}

QString BlackJack::getNazwaGry() const
{
    return "Black Jack";
}

void BlackJack::createDeck() {
    deck.clear();
    for (int s = Card::HEARTS; s <= Card::SPADES; ++s)
        for (int r = Card::TWO; r <= Card::ACE; ++r)
            deck.append({static_cast<Card::Suit>(s), static_cast<Card::Rank>(r)});
}

void BlackJack::shuffleDeck() {
    std::shuffle(deck.begin(), deck.end(), *QRandomGenerator::global());
}

Card BlackJack::dealCard() {
    if (deck.size() < 15) {
        createDeck();
        shuffleDeck();
    }
    if (deck.isEmpty()) {
        qCritical() << "Talia jest pusta!";
        return {Card::SPADES, Card::TWO};
    }
    return deck.takeLast();
}

int BlackJack::calculateHandValue(const QVector<Card>& hand) const {
    int value = 0;
    int aces = 0;
    for (const Card& card : hand) {
        value += card.value(true);
        if (card.rank == Card::ACE) aces++;
    }
    while (value > 21 && aces > 0) {
        value -= 10;
        aces--;
    }
    return value;
}

void BlackJack::startGame(double betAmount) {
    if (m_currentState != GameState::Betting) {
        qWarning() << "Gra już się toczy lub nie jest w stanie do rozpoczęcia.";
        return;
    }
    if (!m_portfel || !m_portfel->odejmijPieniadze(betAmount)) {
        emit gameStateChanged(m_currentState, "Niewystarczające środki lub błąd portfela!");
        return;
    }

    m_currentBet = betAmount;
    playerHand.clear();
    dealerHand.clear();

    playerHand.append(dealCard()); emit playerCardDealt(playerHand.last());
    dealerHand.append(dealCard()); emit dealerCardDealt(dealerHand.last(), true);
    playerHand.append(dealCard()); emit playerCardDealt(playerHand.last());
    dealerHand.append(dealCard()); emit dealerCardDealt(dealerHand.last(), false);

    m_currentState = GameState::PlayerTurn;
    emit scoresUpdated(getPlayerScore(), getDealerScore());

    if (getPlayerScore() == 21) {
        emit dealerRevealedCard(dealerHand.first());
        emit scoresUpdated(getPlayerScore(), getDealerScore(true));
        if (getDealerScore(true) == 21) {
            zakonczRozdanie(GameState::Push, "Push! Obaj Blackjack! Zwracam zakład.");
            m_portfel->dodajPieniadze(m_currentBet);
        } else {
            zakonczRozdanie(GameState::Blackjack, QString("Blackjack! Wygrywasz %1!").arg(m_currentBet * 1.5));
            m_portfel->dodajPieniadze(m_currentBet * 2.5);
        }
    } else {
        emit gameStateChanged(m_currentState, "Twoja tura. Hit or Stand?");
    }
}

void BlackJack::playerHit() {
    if (m_currentState != GameState::PlayerTurn) return;

    playerHand.append(dealCard());
    emit playerCardDealt(playerHand.last());
    emit scoresUpdated(getPlayerScore(), getDealerScore());

    if (getPlayerScore() > 21) {
        emit dealerRevealedCard(dealerHand.first());
        emit scoresUpdated(getPlayerScore(), getDealerScore(true));
        zakonczRozdanie(GameState::PlayerBust, QString("Przekroczyłeś 21! Przegrywasz %1.").arg(m_currentBet));
    } else if (getPlayerScore() == 21) {
        playerStand();
    }
}

void BlackJack::playerStand() {
    if (m_currentState != GameState::PlayerTurn) return;

    m_currentState = GameState::DealerTurn;
    emit dealerRevealedCard(dealerHand.first());
    emit scoresUpdated(getPlayerScore(), getDealerScore(true));
    emit gameStateChanged(m_currentState, "Tura krupiera.");
    dealerPlay();
}

void BlackJack::dealerPlay() {
    while (getDealerScore(true) < 17) {
        dealerHand.append(dealCard());
        emit dealerCardDealt(dealerHand.last(), false);
        emit scoresUpdated(getPlayerScore(), getDealerScore(true));
    }
    determineWinner();
}

void BlackJack::determineWinner() {
    int pScore = getPlayerScore();
    int dScore = getDealerScore(true);

    if (dScore > 21) {
        zakonczRozdanie(GameState::DealerBust, QString("Krupier przekroczył 21! Wygrywasz %1.").arg(m_currentBet));
        m_portfel->dodajPieniadze(m_currentBet * 2.0);
    } else if (pScore > dScore) {
        zakonczRozdanie(GameState::PlayerWins, QString("Wygrałeś! Zdobywasz %1.").arg(m_currentBet));
        m_portfel->dodajPieniadze(m_currentBet * 2.0);
    } else if (dScore > pScore) {
        zakonczRozdanie(GameState::DealerWins, QString("Krupier wygrał! Tracisz %1.").arg(m_currentBet));
    } else {
        zakonczRozdanie(GameState::Push, "Push! Remis, zwracam zakład.");
        m_portfel->dodajPieniadze(m_currentBet);
    }
}

void BlackJack::zakonczRozdanie(GameState finalState, const QString& message) {
    m_currentState = finalState;
    emit gameStateChanged(m_currentState, message);
    emit graZakonczona(*this);
}

void BlackJack::resetujGre() {
    playerHand.clear();
    dealerHand.clear();
    m_currentBet = 0.0;
    m_currentState = GameState::Betting;
    emit gameStateChanged(m_currentState, "Postaw zakład, aby rozpocząć nową grę.");
    emit scoresUpdated(0, 0);
}

const QVector<Card>& BlackJack::getPlayerHand() const { return playerHand; }
const QVector<Card>& BlackJack::getDealerHand() const { return dealerHand; }
int BlackJack::getPlayerScore() const { return calculateHandValue(playerHand); }
int BlackJack::getDealerScore(bool revealAll) const {
    if (dealerHand.isEmpty()) return 0;
    if (!revealAll && dealerHand.size() >= 2) {
        return dealerHand[1].value(dealerHand[1].rank == Card::ACE);
    }
    return calculateHandValue(dealerHand);
}
BlackJack::GameState BlackJack::getCurrentState() const { return m_currentState; }
double BlackJack::getCurrentBet() const { return m_currentBet; }
