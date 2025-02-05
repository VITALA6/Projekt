#include <cstdlib>   // Biblioteka do funkcji systemowych (np. system)
#include "funk.cpp" // Dołączenie pliku z funkcjami

int main() {
    system("chcp 65001 >> null"); // Ustawienie kodowania na UTF-8 dla obsługi polskich znaków
    char wybranaFunkcja; // Zmienna przechowująca wybraną funkcję

    // Wczytanie nazw funkcji i granic całkowania z pliku
    wczytajNazwyFunkcji("nazwyFunkcji.txt");
    graniceZPliku("granice.txt");

    // Główna pętla programu
    while (SprawdzWybor(wybranaFunkcja)) { // Sprawdzenie poprawności wyboru funkcji
        int wyborGranic = WyborWprowadzeniaGranic(); // Wybór sposobu wprowadzenia granic całkowania
        double dolnaGranica, gornaGranica; // Zmienne przechowujące granice całkowania

        // Ustalenie granic całkowania na podstawie wyboru użytkownika
        UstalGraniceCalkowania(wyborGranic, wybranaFunkcja, dolnaGranica, gornaGranica);

        // Obliczenie i prezentacja wyniku całkowania
        ObliczIZaprezentujWynik(wybranaFunkcja, dolnaGranica, gornaGranica);
    }

    return 0;
}