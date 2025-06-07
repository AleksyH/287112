Wymagania systemowe:
System operacyjny: Windows 10/11 (64-bit).
Procesor (CPU): Dowolny nowoczesny procesor dwurdzeniowy (Intel i3, AMD Ryzen 3 lub nowszy).
Pamięć RAM: Minimum 2 GB.
Miejsce na dysku: Około 30 MB wolnego miejsca na dysku twardym.
Biblioteki: Zainstalowane środowisko uruchomieniowe Qt w wersji 6.x. Aplikacja wymaga standardowych bibliotek systemowych.
Karta graficzna: Dowolna karta graficzna obsługująca standard OpenGL 2.1 lub nowszy.

Krótki opis:
Aplikacja "Kasyno" to symulator gier hazardowych, zrealizowany jako program desktopowy z graficznym interfejsem użytkownika (GUI). Projekt został napisany w języku C++ z wykorzystaniem frameworka Qt, co zapewnia jego wieloplatformowość. Użytkownik może zagrać w dwie popularne gry kasynowe: Blackjack oraz Ruletkę.
Aplikacja demonstruje kluczowe założenia programowania obiektowego, takie jak hermetyzacja, dziedziczenie, polimorfizm i przyjaźń. Każda gra posiada własną, odseparowaną logikę oraz dedykowany interfejs, a wspólny system zarządzania finansami gracza (portfel) zapewnia spójność rozgrywki. Aplikacja śledzi również podstawowe statystyki dla każdej z gier, takie jak liczba wygranych, przegranych i całkowity bilans finansowy.

Założenia funkcjonalne i niefunkcjonalne:
Założenia funkcjonalne (Co aplikacja robi?):
Menu Główne: Aplikacja uruchamia się z ekranu głównego, który pozwala na wybór jednej z dostępnych gier.
Wspólny Portfel: System zarządza wirtualnym portfelem gracza. Saldo jest współdzielone między wszystkimi grami i aktualizowane w czasie rzeczywistym.
Gra w Blackjacka:
Użytkownik może postawić zakład przed rozpoczęciem rozdania.
Gracz może dobierać karty ("Hit") lub spasować ("Stand").
Logika gry poprawnie implementuje zasady Blackjacka, w tym liczenie punktów (as jako 1 lub 11), zasady dobierania kart przez krupiera (do 17) oraz specjalne warunki, jak Blackjack i "push" (remis).
Interfejs graficzny dynamicznie pokazuje karty i wyniki gracza oraz krupiera.
Gra w Ruletkę:
Użytkownik może postawić zakład na pojedynczy numer, kolor (czerwony/czarny) lub parzystość (parzyste/nieparzyste).
Dostępna jest opcja "All-In" do postawienia całego dostępnego salda.
Interfejs graficzny pozwala na łatwe wybieranie zakładów i inicjowanie kręcenia kołem.
Statystyki: Dla każdej gry oddzielnie zliczane są i wyświetlane w konsoli podstawowe statystyki: liczba wygranych, przegranych i bilans finansowy.
Resetowanie: Użytkownik ma możliwość zresetowania swojego salda do wartości początkowej w obu grach.
Założenia niefunkcjonalne (Jak aplikacja działa?):
Użyteczność: Interfejs graficzny jest intuicyjny i czytelny. Komunikaty informują użytkownika o wyniku gry, błędach (np. braku środków) i stanie rozgrywki.
Niezawodność: Aplikacja obsługuje podstawowe błędy użytkownika, takie jak wpisanie nieprawidłowej kwoty zakładu czy próba gry bez wystarczających środków.
Wydajność: Aplikacja działa płynnie i responsywnie na systemach spełniających minimalne wymagania. Nie zużywa nadmiernych zasobów systemowych.
Architektura: Kod źródłowy jest zorganizowany zgodnie z zasadami programowania obiektowego. Wykorzystano klasę abstrakcyjną "Gra" jako wspólny interfejs, co ułatwia potencjalną rozbudowę o nowe gry. Logika gry jest oddzielona od interfejsu użytkownika.
Wieloplatformowość: Dzięki użyciu frameworka Qt, aplikacja może być skompilowana i uruchomiona na różnych systemach operacyjnych (Windows, macOS, Linux) bez zmian w kodzie źródłowym.

Krótka instrukcja obsługi:
Uruchomienie aplikacji: Po uruchomieniu pliku wykonywalnego pojawi się okno główne. W lewym górnym rogu widoczne jest Twoje początkowe saldo w portfelu.
Wybór gry: Kliknij na przycisk "Black Jack" lub "Ruletka", aby przejść do okna wybranej gry.

Gra w Blackjacka:
Postaw zakład: Wpisz kwotę w pole tekstowe na środku ekranu i kliknij przycisk "DEAL".
Rozgrywka: Otrzymasz dwie karty. Twoim celem jest uzyskanie sumy punktów bliższej 21 niż krupier, ale nieprzekraczającej tej wartości.
"HIT": Kliknij, aby dobrać kolejną kartę.
"STAND": Kliknij, aby zakończyć swoją turę i oddać ruch krupierowi.
Po zakończeniu rozdania pojawi się komunikat z wynikiem. Aby zagrać ponownie, wpisz stawkę i kliknij "DEAL".

Gra w Ruletkę:
Postaw zakład: Najpierw wpisz kwotę w pole tekstowe na środku ekranu. Następnie kliknij na wybrany numer, kolor ("Red"/"Black") lub parzystość ("even"/"odd"). Twój zakład zostanie potwierdzony komunikatem.
Zakręć kołem: Kliknij przycisk "zakręć", aby rozpocząć losowanie.
Po zatrzymaniu się koła pojawi się komunikat z wynikiem. Możesz od razu postawić kolejny zakład.
Reset salda: W obu grach przycisk "RESET" przywraca stan Twojego portfela do wartości początkowej (10000.0 $).
Powrót do menu: Aby wrócić do menu głównego, kliknij przycisk "Powrót" w prawym dolnym rogu okna gry.
Statystyki: Wyniki i bilans dla każdej gry są na bieżąco wyświetlane w konsoli, z której uruchomiono aplikację.
