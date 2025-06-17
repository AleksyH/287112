/**
 * @file ruletkaokno.cpp
 * @brief Implementacja klasy ruletkaokno.
 */

#include "ruletkaokno.h"
#include "ui_ruletkaokno.h"
#include "mainwindow.h"
#include "portfel.h"
#include <QMessageBox>
#include <QDoubleValidator>
#include <QTimer>

/**
 * @brief Konstruktor okna gry w Ruletkę.
 *
 * Inicjalizuje interfejs użytkownika, tworzy obiekty logiki i statystyk
 * oraz łączy niezbędne sygnały ze slotami.
 */
ruletkaokno::ruletkaokno(QWidget *parent, Portfel *portfel, MainWindow *main)
    : QDialog(parent),
    ui(new Ui::ruletkaokno),
    portfel(portfel),
    mainWindow(main),
    ruletka(new Ruletka(portfel, this)),
    statystyki(new StatystykiRuletki()),
    aktualnaStawka(0.0),
    typZakladu(""),
    obstawionyNumer(-1),
    zakladPostawiony(false)
{

    ui->setupUi(this);


    QPixmap obrazek(":/images/ruletka_projekt.png");
    if(!obrazek.isNull()) {
        ui->labelObrazekRuletki->setPixmap(obrazek.scaled(ui->labelObrazekRuletki->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    ui->labelObrazekRuletki->setAlignment(Qt::AlignCenter);
    setWindowTitle(ruletka->getNazwaGry());
    aktual_walidator();
    ui->stawka->setPlaceholderText("Wpisz stawkę");
    ui->stankonta->setReadOnly(true);
    ui->stankonta->setText(QString::number(this->portfel->pobierzSaldo(), 'f', 2) + " $");


    connect(this->portfel, &Portfel::saldoZmienione, this, [this](double saldo){
        ui->stankonta->setText(QString::number(saldo, 'f', 2) + " $");

    });

    connect(ruletka, &Ruletka::rundaZakonczona, this, &ruletkaokno::obsluzKoniecRundy);

    connect(ui->back, &QPushButton::clicked, this, [this]() {
        if(this->mainWindow) this->mainWindow->show();
        this->close();
    });

    wyswietlStatusZakladu("Wybierz zakład i stawkę.");
}

/**
 * @brief Destruktor.
 */
ruletkaokno::~ruletkaokno()
{
    delete statystyki;
    delete ui;
}

/**
 * @brief Slot obsługujący sygnał `rundaZakonczona` z logiki gry.
 *
 * Odbiera wynik rundy, aktualizuje statystyki, modyfikuje stan portfela
 * i wyświetla użytkownikowi komunikat o wyniku.
 * @param gra Referencja do obiektu gry z wynikiem ostatniej rundy.
 * @param komunikat Podstawowy komunikat o wylosowanym numerze.
 */
void ruletkaokno::obsluzKoniecRundy(const Ruletka& gra, const QString& komunikat)
{
    statystyki->zaktualizujPoZakreceniu(gra);

    double wygrana = gra.m_ostatniaWygrana;
    double stawka = gra.m_ostatniaStawka;
    QString finalnyKomunikat = komunikat;

    if (wygrana > 0) {
        portfel->dodajPieniadze(wygrana);
        double zysk = wygrana - stawka;
        finalnyKomunikat += QString(". Wygrałeś %1 $ (zysk: %2 $).").arg(wygrana, 0, 'f', 2).arg(zysk, 0, 'f', 2);
        QMessageBox::information(this, "Wygrana!", finalnyKomunikat);
    } else {
        finalnyKomunikat += ". Niestety, tym razem przegrana.";
        QMessageBox::information(this, "Przegrana", finalnyKomunikat);
    }

    zakladPostawiony = false;
    wyswietlStatusZakladu("Postaw kolejny zakład.");
}

/**
 * @brief Slot obsługujący kliknięcie przycisku "Zakręć".
 *
 * Sprawdza, czy postawiono zakład, a następnie uruchamia logikę gry
 * za pomocą timera, aby uniknąć problemów z podwójnym kliknięciem.
 */
void ruletkaokno::on_spinButton_clicked()
{
    if (!zakladPostawiony) {
        QMessageBox::information(this, "Brak zakładu", "Proszę najpierw wybrać rodzaj zakładu i stawkę.");
        return;
    }

    QTimer::singleShot(0, this, [=]() {
        if (portfel->odejmijPieniadze(aktualnaStawka)) {
            int wylosowanyNumer = ruletka->zakrec();
            ruletka->sprawdzWygrana(wylosowanyNumer, typZakladu, obstawionyNumer, aktualnaStawka);
        } else {
            QMessageBox::critical(this, "Błąd portfela", "Nie udało się pobrać stawki z portfela. Spróbuj ponownie.");
            zakladPostawiony = false;
            wyswietlStatusZakladu("Błąd portfela. Wybierz zakład ponownie.");
        }

    });
    aktual_walidator();
}

/**
 * @brief Wyświetla aktualny status zakładu w etykiecie na ekranie.
 * @param wiadomosc Opcjonalna wiadomość do wyświetlenia.
 */
void ruletkaokno::wyswietlStatusZakladu(const QString& wiadomosc)
{
    if (wiadomosc.isEmpty()) {
        if (zakladPostawiony) {
            QString komunikat = QString("Twój zakład: %1$ na %2").arg(aktualnaStawka, 0, 'f', 2).arg(typZakladu);
            if (typZakladu.startsWith("Numer ") && obstawionyNumer != -1) {
                komunikat += QString(" (%1)").arg(obstawionyNumer);
            }
            ui->statusZakladuLabel->setText(komunikat);
        } else {
            ui->statusZakladuLabel->setText("Wybierz zakład i stawkę.");
        }
    } else {
        ui->statusZakladuLabel->setText(wiadomosc);
    }
}

/**
 * @brief Przygotowuje zakład po kliknięciu na przycisk.
 * Waliduje stawkę i zapisuje informacje o zakładzie.
 * @param typ Opisowy typ zakładu (np. "Czerwone", "Numer 5").
 * @param numer Numer, na który postawiono (opcjonalny).
 */
void ruletkaokno::przygotujZaklad(const QString& typ, int numer)
{
    QString stawkaText = ui->stawka->text().replace(",", ".");
    if (stawkaText.isEmpty()) {
        QMessageBox::warning(this, "Brak stawki", "Proszę wpisać kwotę stawki.");
        ui->stawka->setFocus();
        return;
    }

    bool ok;
    double stawka = stawkaText.toDouble(&ok);

    if (!ok || stawka <= 0) {
        QMessageBox::warning(this, "Nieprawidłowa stawka", "Proszę wpisać poprawną, dodatnią kwotę stawki.");
        ui->stawka->setFocus();
        ui->stawka->selectAll();
        return;
    }

    if (stawka > portfel->pobierzSaldo()) {
        QMessageBox::warning(this, "Niewystarczające środki", QString("Nie masz wystarczająco środków (%1 $), aby postawić %2 $.")
        .arg(portfel->pobierzSaldo(), 0, 'f', 2)
        .arg(stawka, 0, 'f', 2));
        return;
    }

    aktualnaStawka = stawka;
    typZakladu = typ;
    obstawionyNumer = numer;
    zakladPostawiony = true;
    wyswietlStatusZakladu();
}

/**
 * @brief Slot dla przycisku "ALL IN".
 * Ustawia kwotę stawki na całe dostępne saldo.
 */
void ruletkaokno::on_All_In_clicked()
{
    double saldoPortfela = portfel->pobierzSaldo();
    if (saldoPortfela == 0) {
        QMessageBox::information(this, "Brak środków", "Nie masz środków na grę.");
        return;
    }
    ui->stawka->setText(QString::number(saldoPortfela, 'f', 2));
    wyswietlStatusZakladu(QString("Stawka 'All In' (%1 $) ustawiona.").arg(saldoPortfela, 0, 'f', 2));
}

/**
 * @brief Slot dla przycisku "RESET".
 * Resetuje saldo portfela i stan gry w UI.
 */
void ruletkaokno::on_reset_clicked()
{
    portfel->resetuj();
    ruletka->resetujGre();
    zakladPostawiony = false;
    aktualnaStawka = 0.0;
    typZakladu = "";
    obstawionyNumer = -1;
    ui->stawka->clear();
    wyswietlStatusZakladu("Wybierz zakład i stawkę.");
    aktual_walidator();
}
void ruletkaokno::aktual_walidator(){
    double min = 0.01;
    double max = portfel->pobierzSaldo();
    if (max < min) max = min;
    auto validator = new QDoubleValidator(min, max, 2, ui->stawka);
    validator->setNotation(QDoubleValidator::StandardNotation);
    ui->stawka->setValidator(validator);
}

void ruletkaokno::on_zero_clicked() { przygotujZaklad("Zero",0); }
void ruletkaokno::on_jeden_clicked() { przygotujZaklad("Numer 1", 1); }
void ruletkaokno::on_dwa_clicked() { przygotujZaklad("Numer 2", 2); }
void ruletkaokno::on_trzy_clicked() { przygotujZaklad("Numer 3", 3); }
void ruletkaokno::on_cztery_clicked() { przygotujZaklad("Numer 4", 4); }
void ruletkaokno::on_piec_clicked() { przygotujZaklad("Numer 5", 5); }
void ruletkaokno::on_szesc_clicked() { przygotujZaklad("Numer 6", 6); }
void ruletkaokno::on_siedem_clicked() { przygotujZaklad("Numer 7", 7); }
void ruletkaokno::on_osiem_clicked() { przygotujZaklad("Numer 8", 8); }
void ruletkaokno::on_dziewiec_clicked() { przygotujZaklad("Numer 9", 9); }
void ruletkaokno::on_dziesiec_clicked() { przygotujZaklad("Numer 10", 10); }
void ruletkaokno::on_jedena_clicked() { przygotujZaklad("Numer 11", 11); }
void ruletkaokno::on_dwana_clicked() { przygotujZaklad("Numer 12", 12); }
void ruletkaokno::on_trzyna_clicked() { przygotujZaklad("Numer 13", 13); }
void ruletkaokno::on_czterna_clicked() { przygotujZaklad("Numer 14", 14); }
void ruletkaokno::on_pietna_clicked() { przygotujZaklad("Numer 15", 15); }
void ruletkaokno::on_szesna_clicked() { przygotujZaklad("Numer 16", 16); }
void ruletkaokno::on_siedemna_clicked() { przygotujZaklad("Numer 17", 17); }
void ruletkaokno::on_osiemna_clicked() { przygotujZaklad("Numer 18", 18); }
void ruletkaokno::on_dziewietna_clicked() { przygotujZaklad("Numer 19", 19); }
void ruletkaokno::on_dwadziescia_clicked() { przygotujZaklad("Numer 20", 20); }
void ruletkaokno::on_dwajeden_clicked() { przygotujZaklad("Numer 21", 21); }
void ruletkaokno::on_dwadwa_clicked() { przygotujZaklad("Numer 22", 22); }
void ruletkaokno::on_dwatrzy_clicked() { przygotujZaklad("Numer 23", 23); }
void ruletkaokno::on_dwacztery_clicked() { przygotujZaklad("Numer 24", 24); }
void ruletkaokno::on_dwapiec_clicked() { przygotujZaklad("Numer 25", 25); }
void ruletkaokno::on_dwaszesc_clicked() { przygotujZaklad("Numer 26", 26); }
void ruletkaokno::on_dwasiedem_clicked() { przygotujZaklad("Numer 27", 27); }
void ruletkaokno::on_dwaosiem_clicked() { przygotujZaklad("Numer 28", 28); }
void ruletkaokno::on_dwadziewiec_clicked() { przygotujZaklad("Numer 29", 29); }
void ruletkaokno::on_trzydziesci_clicked() { przygotujZaklad("Numer 30", 30); }
void ruletkaokno::on_trzyjeden_clicked() { przygotujZaklad("Numer 31", 31); }
void ruletkaokno::on_trzydwa_clicked() { przygotujZaklad("Numer 32", 32); }
void ruletkaokno::on_trzytrzy_clicked() { przygotujZaklad("Numer 33", 33); }
void ruletkaokno::on_trzycztery_clicked() { przygotujZaklad("Numer 34", 34); }
void ruletkaokno::on_trzypiec_clicked() { przygotujZaklad("Numer 35", 35); }
void ruletkaokno::on_trzyszesc_clicked() { przygotujZaklad("Numer 36", 36); }
void ruletkaokno::on_red_clicked() { przygotujZaklad("Czerwone"); }
void ruletkaokno::on_black_clicked() { przygotujZaklad("Czarne"); }
void ruletkaokno::on_even_clicked() { przygotujZaklad("Parzyste"); }
void ruletkaokno::on_odd_clicked() { przygotujZaklad("Nieparzyste"); }
