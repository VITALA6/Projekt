#include <iostream>  // Biblioteka do obsługi strumieni wejścia/wyjścia (np. cin, cout)
#include <cmath>     // Biblioteka do funkcji matematycznych (np. pow, exp, cos, sin)
#include <fstream>   // Biblioteka do obsługi plików (np. ifstream, ofstream)
#include <cctype>    // Biblioteka do funkcji operujących na znakach (np. tolower)

// Funkcja do wyboru funkcji
char wybierzFunkcje();

// Funkcja do sprawdzania poprawności wyboru funkcji
int sprawdzWybor(char& funkcja);

// Funkcja do wczytywania nazw funkcji z pliku
void wczytajNazwyFunkcji(const std::string& plikZNazwamiFunkcji);

// Funkcja do sprawdzania czy dolna granica nie jest większa od górnej
int sprawdzCzyAnieWiekszeOdB(double a, double b);

// Funkcja do wprowadzania granic ręcznie
void graniceRecznie(double& dolnaGranica, double& gornaGranica);

// Funkcja do wczytywania granic z pliku
void graniceZPliku(const std::string& plikZGranicami);

// Funkcja do ustalania granic całkowania
void ustalGraniceCalkowania(int wyborGranic, char wybranaFunkcja, double& dolnaGranica, double& gornaGranica);

// Funkcja do wyboru sposobu wprowadzenia granic
int wyborWprowadzeniaGranic();

// Funkcja do wyświetlania menu wyboru granic
void wyswietlMenuGranic();

// Funkcja do wyświetlania menu wyników
void wyswietlMenuWynikow();

// Funkcja do wyboru sposobu wyświetlenia wyników
int wyborWyswietleniaWyniku();

// Funkcja do wprowadzania liczby podziałów
int podajLiczbePodzialow();

// Funkcja do obliczania wartości funkcji
double obliczWartoscFunkcji(double x, char wybranaFunkcja);

// Funkcja do obliczania całki metodą trapezów
double obliczCalkeMetodaTrapezow(double dolnaGranica, double gornaGranica, int liczbaPodzialow, char wybranaFunkcja);

// Funkcja do wyświetlania wyniku
void zapiszWynikWpliku(char wybranaFunkcja, int liczbaPodzialow, double wynik);

// Funkcja do obliczania i prezentacji wyniku
void obliczIZaprezentujWynik(char wybranaFunkcja, double dolnaGranica, double gornaGranica);

// Struktura do przechowywania granic całkowania
struct Granice {
    double dolnaGranica;
    double gornaGranica;
};

// Globalne tablice do przechowywania granic i nazw funkcji
Granice graniceFunkcji[7];
std::string nazwyFunkcji[7];

// Funkcja do wyboru funkcji
char wybierzFunkcje() {
    char wybranaFunkcja = ' ';
    std::cout << "\n=======================================================\n";
    std::cout << "| Wybierz funkcję do obliczenia metodą trapezów:      |\n";
    std::cout << "=======================================================\n";
    std::cout << "| a. f(x) = 2,                     [a, b] = [-1, 1]   |\n";
    std::cout << "| b. f(x) = x² + 2x + 1,           [a, b] = [0, 3]    |\n";
    std::cout << "| c. f(x) = x³,                    [a, b] = [0, 2]    |\n";
    std::cout << "| d. f(x) = 4e^x,                  [a, b] = [0, ln(2)]|\n";
    std::cout << "| e. f(x) = cos(x),                [a, b] = [0, π/2]  |\n";
    std::cout << "| f. f(x) = cos(x) + sin(x),       [a, b] = [0, π]    |\n";
    std::cout << "| g. f(x) = x * sin(x),            [a, b] = [0, π]    |\n";
    std::cout << "| x. Zakończ program.                                 |\n";
    std::cout << "=======================================================\n";
    
    std::cout << " Twój wybór: ";
    std::cin >> wybranaFunkcja;
    return tolower(wybranaFunkcja);
}

// Funkcja do sprawdzania poprawności wyboru funkcji
int sprawdzWybor(char& funkcja) {
    funkcja = wybierzFunkcje();
    if ((funkcja >= 'a' && funkcja <= 'g')) {
        return 1; // Poprawny wybór funkcji
    } else if (funkcja == 'x') {
        std::cout << " Program zakończony.\n"; 
        return 120; // Użytkownik wybrał zakończenie programu
    } else {
        std::cout << "\n Nieprawidłowy wybór. Spróbuj ponownie.\n";
        return sprawdzWybor(funkcja); // Rekurencyjnie proś o ponowny wybór
    }
}

// Funkcja do wczytywania nazw funkcji z pliku
void wczytajNazwyFunkcji(const std::string& plikZNazwamiFunkcji) {
    std::ifstream plik(plikZNazwamiFunkcji);

    std::string nazwa;
    for (int i = 0; i < 7; ++i) {
        std::getline(plik, nazwa);
        nazwyFunkcji[i] = nazwa;
    }
    plik.close();
}

// Funkcja do sprawdzania czy dolna granica nie jest większa od górnej
int sprawdzCzyAnieWiekszeOdB(double a, double b) {
    if (a > b) {
        std::cout << " Dolna granica nie może być większa od górnej. Spróbuj ponownie.\n";
        return 1;
    }
    return 0;
}

// Funkcja do wprowadzania granic ręcznie
void graniceRecznie(double& dolnaGranica, double& gornaGranica) {
        std::cout << " Podaj dolną granicę (a): ";
        std::cin >> dolnaGranica;
        std::cout << " Podaj górną granicę (b): ";
        std::cin >> gornaGranica;
        if(sprawdzCzyAnieWiekszeOdB(dolnaGranica, gornaGranica)) {
            graniceRecznie(dolnaGranica, gornaGranica);
        }
}

// Funkcja do wczytywania granic z pliku
void graniceZPliku(const std::string& plikZGranicami) {
    std::ifstream plik(plikZGranicami);

    char funkcja;
    double dolna, gorna;
    int index = 0;
    while (plik >> funkcja >> dolna >> gorna) {
        graniceFunkcji[index++] = {dolna, gorna};
    }
    plik.close();
}

// Funkcja do ustalania granic całkowania
void ustalGraniceCalkowania(int wyborGranic, char wybranaFunkcja, double& dolnaGranica, double& gornaGranica) {
    int index = wybranaFunkcja - 'a';
    
    if (wyborGranic == 1) {
        dolnaGranica = graniceFunkcji[index].dolnaGranica;
        gornaGranica = graniceFunkcji[index].gornaGranica;

        if (sprawdzCzyAnieWiekszeOdB(dolnaGranica, gornaGranica)) {
            std::cout << " W pliku dla funkcji (" << nazwyFunkcji[index] << ") podano nieprawidłowe granice. Wprowadź granice ręcznie.\n";
            graniceRecznie(dolnaGranica, gornaGranica);
        }

        if (dolnaGranica == 0 && gornaGranica == 0) {
            std::cout << " Nie wczytano granic dla funkcji " << wybranaFunkcja << " z pliku. Wprowadź granice ręcznie.\n";
            graniceRecznie(dolnaGranica, gornaGranica);
        }
        
    } else if (wyborGranic == 2) {
        graniceRecznie(dolnaGranica, gornaGranica);
    }
}


// Funkcja do wyboru sposobu wprowadzenia granic
// Shemat blokowy
int wyborWprowadzeniaGranic() {
    int wyborGranic = 0;     
    do {    
        wyswietlMenuGranic();
        std::cout << " Twój wybór: ";
        std::cin >> wyborGranic;
        if (wyborGranic != 1 && wyborGranic != 2) {
            std::cout << " Nieprawidłowy wybór. Spróbuj ponownie.\n";
        }
    } while (wyborGranic != 1 && wyborGranic != 2);
    return wyborGranic;
}

// Funkcja do wyświetlania menu wyboru granic
void wyswietlMenuGranic() {
    std::cout << "=======================================================\n";
    std::cout << "| Wybierz sposób wprowadzenia granic całkowania:      |\n";
    std::cout << "=======================================================\n";
    std::cout << "| 1. Wczytaj granice z pliku                          |\n";
    std::cout << "| 2. Wprowadź granice ręcznie                         |\n";
    std::cout << "=======================================================\n";
}

// Funkcja do wyboru sposobu wyświetlenia wyników
int wyborWyswietleniaWyniku() {
    int wybor;
    do {
        wyswietlMenuWynikow();
        std::cout << " Twój wybór: ";
        std::cin >> wybor;
        if (wybor < 1 || wybor > 3) {
            std::cout << " Nieprawidłowy wybór. Spróbuj ponownie.\n";
        }
    } while (wybor < 1 || wybor > 3);
    return wybor;
}

// Funkcja do wyświetlania menu wyników
void wyswietlMenuWynikow() {
    std::cout << "=======================================================\n";
    std::cout << "| Wybierz sposób wyświetlenia wyniku:                 |\n";
    std::cout << "=======================================================\n";
    std::cout << "| 1. Zapisz wynik do pliku                            |\n";
    std::cout << "| 2. Wyświetl wynik na ekranie                        |\n";
    std::cout << "| 3. Zapisz do pliku i wyświetl na ekranie            |\n";
    std::cout << "=======================================================\n";
}

// Funkcja do wprowadzania liczby podziałów
int podajLiczbePodzialow() {
    int liczbaPodzialow;
    do {
        std::cout << " Podaj liczbę podziałów (n): ";
        std::cin >> liczbaPodzialow;
        if (liczbaPodzialow <= 0) {
            std::cout << " Liczba podziałów musi być dodatnia. Spróbuj ponownie.\n";
        }
    } while (liczbaPodzialow <= 0);
    return liczbaPodzialow;
}

// Funkcja do obliczania wartości funkcji
double obliczWartoscFunkcji(double x, char wybranaFunkcja) {
    switch (wybranaFunkcja) {
        case 'a': return 2;
        case 'b': return pow(x, 2.0) + 2 * x + 1;
        case 'c': return pow(x, 3.0);
        case 'd': return 4 * exp(x);    
        case 'e': return cos(x);
        case 'f': return cos(x) + sin(x);
        case 'g': return x * sin(x);
        default: return 0;
    }
}

// Funkcja do obliczania całki metodą trapezów
double obliczCalkeMetodaTrapezow(double dolnaGranica, double gornaGranica, int liczbaPodzialow, char wybranaFunkcja) {
    double krok = (gornaGranica - dolnaGranica) / liczbaPodzialow;
    double suma = obliczWartoscFunkcji(dolnaGranica, wybranaFunkcja) + obliczWartoscFunkcji(gornaGranica, wybranaFunkcja);
    for (int i = 1; i < liczbaPodzialow; ++i) {
        suma += 2 * obliczWartoscFunkcji(dolnaGranica + i * krok, wybranaFunkcja);
    }
    return suma * (krok / 2.0);
}

// Funkcja do wyświetlania wyniku
void zapiszWynikWpliku(char wybranaFunkcja, int liczbaPodzialow, double wynik) {
    std::ofstream plik("wyniki.txt", std::ios::app);
    if (plik) {
        plik << "=======================================================\n";
        plik << "Funkcja: " << nazwyFunkcji[wybranaFunkcja - 'a'] << '\n';
        plik << "Liczba podziałów: " << liczbaPodzialow << '\n';
        plik << "Wynik: " << wynik << '\n';
        plik.close();
        std::cout << " Wynik zapisano w pliku 'wyniki.txt'\n";
    } else {
        std::cout << " Nie udało się zapisać wyniku do pliku!\n";
    }
}

// Funkcja do obliczania i prezentacji wyniku
void obliczIZaprezentujWynik(char wybranaFunkcja, double dolnaGranica, double gornaGranica) {
    int liczbaPodzialow = podajLiczbePodzialow();
    double wynik = obliczCalkeMetodaTrapezow(dolnaGranica, gornaGranica, liczbaPodzialow, wybranaFunkcja);
    int wyborWyswietlenia = wyborWyswietleniaWyniku();
    switch (wyborWyswietlenia) {
        case 1:
            zapiszWynikWpliku(wybranaFunkcja, liczbaPodzialow, wynik);
            break;
        case 2:
            std::cout << " Wynik: " << wynik << '\n';
            break;
        case 3:
            zapiszWynikWpliku(wybranaFunkcja, liczbaPodzialow, wynik);
            std::cout << " Wynik: " << wynik << '\n';
            break;
        default:
            std::cout << " Nieprawidłowy wybór. Spróbuj ponownie.\n";
            break;
    }
}