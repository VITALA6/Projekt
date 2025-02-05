#include <iostream>  // Biblioteka do obsługi strumieni wejścia/wyjścia (np. cin, cout)
#include <cmath>     // Biblioteka do funkcji matematycznych (np. pow, exp, cos, sin)
#include <fstream>   // Biblioteka do obsługi plików (np. ifstream, ofstream)
#include <cctype>    // Biblioteka do funkcji operujących na znakach (np. tolower)

// Funkcja do wyboru funkcji
char WybierzFunkcje();

// Funkcja do sprawdzania poprawności wyboru funkcji
int SprawdzWybor(char& funkcja);

// Funkcja do wczytywania nazw funkcji z pliku
void wczytajNazwyFunkcji(const std::string& plikZNazwamiFunkcji);

// Funkcja do wprowadzania granic ręcznie
void graniceRecznie(double& dolnaGranica, double& gornaGranica);

// Funkcja do wczytywania granic z pliku
void graniceZPliku(const std::string& plikZGranicami);

// Funkcja do ustalania granic całkowania
void UstalGraniceCalkowania(int wyborGranic, char wybranaFunkcja, double& dolnaGranica, double& gornaGranica);

// Funkcja do wyboru sposobu wprowadzenia granic
int WyborWprowadzeniaGranic();

// Funkcja do wyświetlania menu wyboru granic
void WyswietlMenuGranic();

// Funkcja do wyświetlania menu wyników
void WyswietlMenuWynikow();

// Funkcja do wyboru sposobu wyświetlenia wyników
int WyborWyswietleniaWyniku();

// Funkcja do wprowadzania liczby podziałów
int PodajLiczbePodzialow();

// Funkcja do obliczania wartości funkcji
double ObliczWartoscFunkcji(double x, char wybranaFunkcja);

// Funkcja do obliczania całki metodą trapezów
double ObliczCalkeMetodaTrapezow(double dolnaGranica, double gornaGranica, int liczbaPodzialow, char wybranaFunkcja);

// Funkcja do wyświetlania wyniku
void ZapiszWynikWpliku(char wybranaFunkcja, int liczbaPodzialow, double wynik);

// Funkcja do obliczania i prezentacji wyniku
void ObliczIZaprezentujWynik(char wybranaFunkcja, double dolnaGranica, double gornaGranica);

// Struktura do przechowywania granic całkowania
struct Granice {
    double dolnaGranica;
    double gornaGranica;
};

// Globalne tablice do przechowywania granic i nazw funkcji
Granice graniceFunkcji[7];
std::string nazwyFunkcji[7];

// Funkcja do wyboru funkcji
char WybierzFunkcje() {
    char wybranaFunkcja = ' ';
    std::cout << "=======================================================\n";
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
int SprawdzWybor(char& funkcja) {
    funkcja = WybierzFunkcje();
    if ((funkcja >= 'a' && funkcja <= 'g')) {
        return 1; // Poprawny wybór funkcji
    } else if (funkcja == 'x') {
        std::cout << "Program zakończony.\n"; 
        return 0; // Użytkownik wybrał zakończenie programu
    } else {
        std::cout << "\nNieprawidłowy wybór. Spróbuj ponownie.\n";
        return SprawdzWybor(funkcja); // Rekurencyjnie proś o ponowny wybór
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

// Funkcja do wprowadzania granic ręcznie
void graniceRecznie(double& dolnaGranica, double& gornaGranica) {
    do {
        std::cout << " Podaj dolną granicę (a): ";
        std::cin >> dolnaGranica;
        std::cout << " Podaj górną granicę (b): ";
        std::cin >> gornaGranica;

        if (dolnaGranica >= gornaGranica) {
            std::cout << " Błąd: Dolna granica musi być mniejsza od górnej granicy. Spróbuj ponownie.\n";
        }
    } while (dolnaGranica >= gornaGranica); 
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
void UstalGraniceCalkowania(int wyborGranic, char wybranaFunkcja, double& dolnaGranica, double& gornaGranica) {
    graniceZPliku("granice.txt");
    int index = wybranaFunkcja - 'a';
    
        if (wyborGranic == 1) {
            dolnaGranica = graniceFunkcji[index].dolnaGranica;
            gornaGranica = graniceFunkcji[index].gornaGranica;

            if (dolnaGranica == 0 && gornaGranica == 0) {
                std::cout << "Nie wczytano granic dla funkcji " << wybranaFunkcja << " z pliku. Wprowadź granice ręcznie.\n";
                graniceRecznie(dolnaGranica, gornaGranica);
            }
            
        } else if (wyborGranic == 2) {
            graniceRecznie(dolnaGranica, gornaGranica);
        }
}


// Funkcja do wyboru sposobu wprowadzenia granic
int WyborWprowadzeniaGranic() {
    int wyborGranic = 0;
    do {
        WyswietlMenuGranic();
        std::cout << " Twój wybór: ";
        std::cin >> wyborGranic;
        if (wyborGranic != 1 && wyborGranic != 2) {
            std::cout << " Nieprawidłowy wybór. Spróbuj ponownie.\n";
        }
    } while (wyborGranic != 1 && wyborGranic != 2);
    return wyborGranic;
}

// Funkcja do wyświetlania menu wyboru granic
void WyswietlMenuGranic() {
    std::cout << "=======================================================\n";
    std::cout << "| Wybierz sposób wprowadzenia granic całkowania:      |\n";
    std::cout << "=======================================================\n";
    std::cout << "| 1. Wczytaj granice z pliku                          |\n";
    std::cout << "| 2. Wprowadź granice ręcznie                         |\n";
    std::cout << "=======================================================\n";
}

// Funkcja do wyboru sposobu wyświetlenia wyników
int WyborWyswietleniaWyniku() {
    int wybor;
    do {
        WyswietlMenuWynikow();
        std::cout << " Twój wybór: ";
        std::cin >> wybor;
        if (wybor < 1 || wybor > 3) {
            std::cout << " Nieprawidłowy wybór. Spróbuj ponownie.\n";
        }
    } while (wybor < 1 || wybor > 3);
    return wybor;
}

// Funkcja do wyświetlania menu wyników
void WyswietlMenuWynikow() {
    std::cout << "=======================================================\n";
    std::cout << "| Wybierz sposób wyświetlenia wyniku:                 |\n";
    std::cout << "=======================================================\n";
    std::cout << "| 1. Zapisz wynik do pliku                            |\n";
    std::cout << "| 2. Wyświetl wynik na ekranie                        |\n";
    std::cout << "| 3. Zapisz do pliku i wyświetl na ekranie            |\n";
    std::cout << "=======================================================\n";
}

// Funkcja do wprowadzania liczby podziałów
int PodajLiczbePodzialow() {
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
double ObliczWartoscFunkcji(double x, char wybranaFunkcja) {
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
double ObliczCalkeMetodaTrapezow(double dolnaGranica, double gornaGranica, int liczbaPodzialow, char wybranaFunkcja) {
    double krok = (gornaGranica - dolnaGranica) / liczbaPodzialow;
    double suma = ObliczWartoscFunkcji(dolnaGranica, wybranaFunkcja) + ObliczWartoscFunkcji(gornaGranica, wybranaFunkcja);
    for (int i = 1; i < liczbaPodzialow; ++i) {
        suma += 2 * ObliczWartoscFunkcji(dolnaGranica + i * krok, wybranaFunkcja);
    }
    return suma * (krok / 2.0);
}

// Funkcja do wyświetlania wyniku
void ZapiszWynikWpliku(char wybranaFunkcja, int liczbaPodzialow, double wynik) {
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
void ObliczIZaprezentujWynik(char wybranaFunkcja, double dolnaGranica, double gornaGranica) {
    int liczbaPodzialow = PodajLiczbePodzialow();
    double wynik = ObliczCalkeMetodaTrapezow(dolnaGranica, gornaGranica, liczbaPodzialow, wybranaFunkcja);
    int wyborWyswietlenia = WyborWyswietleniaWyniku();
    switch (wyborWyswietlenia) {
        case 1:
            ZapiszWynikWpliku(wybranaFunkcja, liczbaPodzialow, wynik);
            break;
        case 2:
            std::cout << " Wynik: " << wynik << '\n';
            break;
        case 3:
            ZapiszWynikWpliku(wybranaFunkcja, liczbaPodzialow, wynik);
            std::cout << " Wynik: " << wynik << '\n';
            break;
        default:
            std::cout << "Nieprawidłowy wybór. Spróbuj ponownie.\n";
            break;
    }
}


