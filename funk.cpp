#include <iostream>
#include <cmath>
#include <fstream>

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
int SprawdzPoprawnoscWyboru(char& wybranaFunkcja) {
    wybranaFunkcja = WybierzFunkcje();
    if ((wybranaFunkcja >= 'a' && wybranaFunkcja <= 'g') || wybranaFunkcja == 'x') {
        if (wybranaFunkcja == 'x') {
            std::cout << "\nProgram zakończony.\n";
            return 0;
        }
        return 1;
    }
    std::cout << "\nNieprawidłowy wybór. Spróbuj ponownie.\n";
    return SprawdzPoprawnoscWyboru(wybranaFunkcja);
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

// Funkcja do wyboru sposobu wprowadzenia granic
int WyborWprowadzeniaGranic() {
    int wybor;
    WyswietlMenuGranic();
    std::cout << " Twój wybór: ";
    std::cin >> wybor;
    while (wybor != 1 && wybor != 2) {
        std::cout << " Nieprawidłowy wybór. Spróbuj ponownie.\n";
        std::cout << " Twój wybór: ";
        std::cin >> wybor;
    }
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

// Funkcja do wyboru sposobu wyświetlenia wyników
int WyborWyswietleniaWyniku() {
    int wybor;
    WyswietlMenuWynikow();
    std::cout << " Twój wybór: ";
    std::cin >> wybor;
    while (wybor < 1 || wybor > 3) {
        std::cout << " Nieprawidłowy wybór. Spróbuj ponownie.\n";
        std::cout << " Twój wybór: ";
        std::cin >> wybor;
    }
    return wybor;
}

// Funkcja do ręcznego wprowadzania granic
void graniceRecznie(double& dolnaGranica, double& gornaGranica) {
    std::cout << " Podaj dolną granicę (a): ";
    std::cin >> dolnaGranica;
    std::cout << " Podaj górną granicę (b): ";
    std::cin >> gornaGranica;
}

// Funkcja do wczytywania granic z pliku
void graniceZPliku(const std::string& plikZGranicami) {
    std::ifstream plik(plikZGranicami);
    if (!plik) {
        std::cout << " Nie udało się otworzyć pliku " << plikZGranicami << "!\n";
        exit(1);
    }
    char funkcja;
    double dolna, gorna;
    int index = 0;
    while (plik >> funkcja >> dolna >> gorna) {
        graniceFunkcji[index++] = {dolna, gorna};
    }
    plik.close();
}

// Funkcja do wczytywania nazw funkcji z pliku
void wczytajNazwyFunkcji(const std::string& plikZNazwamiFunkcji) {
    std::ifstream plik(plikZNazwamiFunkcji);
    if (!plik) {
        std::cout << " Nie udało się otworzyć pliku " << plikZNazwamiFunkcji << "!\n";
        exit(1);
    }
    std::string nazwa;
    for (int i = 0; i < 7; ++i) {
        std::getline(plik, nazwa);
        nazwyFunkcji[i] = nazwa;
    }
    plik.close();
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

// Funkcja do ustalania granic całkowania
void UstalGraniceCalkowania(char wybranaFunkcja, double& dolnaGranica, double& gornaGranica) {
    int index = wybranaFunkcja - 'a';
    if (index >= 0 && index < 7) {
        dolnaGranica = graniceFunkcji[index].dolnaGranica;
        gornaGranica = graniceFunkcji[index].gornaGranica;
    } else {
        std::cout << " Nie znaleziono granic dla wybranej funkcji!\n";
        exit(1);
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
void WyswietlWynik(char wybranaFunkcja, int liczbaPodzialow, double wynik) {
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

// Funkcja do wprowadzania granic
void WprowadzGranice(double& dolnaGranica, double& gornaGranica, int wyborGranic) {
    if (wyborGranic == 1) {
        graniceZPliku("granice.txt");
    } else if (wyborGranic == 2) {
        graniceRecznie(dolnaGranica, gornaGranica);
    }
}

// Funkcja do obliczania i prezentacji wyniku
void ObliczIZaprezentujWynik(char wybranaFunkcja, double dolnaGranica, double gornaGranica) {
    UstalGraniceCalkowania(wybranaFunkcja, dolnaGranica, gornaGranica);
    int liczbaPodzialow = PodajLiczbePodzialow();
    double wynik = ObliczCalkeMetodaTrapezow(dolnaGranica, gornaGranica, liczbaPodzialow, wybranaFunkcja);

    int wyborWyniku = WyborWyswietleniaWyniku();
    if (wyborWyniku == 1) {
        WyswietlWynik(wybranaFunkcja, liczbaPodzialow, wynik);
    } else if (wyborWyniku == 2) {
        std::cout << " Wynik: " << wynik << "\n";
    } else if (wyborWyniku == 3) {
        std::cout << " Wynik: " << wynik << "\n";
        WyswietlWynik(wybranaFunkcja, liczbaPodzialow, wynik);
    }
}
