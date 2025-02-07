#include <cstdlib>   // Biblioteka do funkcji systemowych (np. system)
#include "funk.cpp" // Dołączenie pliku z funkcjami

int main() {
    system("chcp 65001 >> null"); // Ustawienie kodowania na UTF-8 dla obsługi polskich znaków

    // Wczytanie nazw funkcji i granic całkowania z pliku
    wczytajNazwyFunkcji("nazwyFunkcji.txt");
    graniceZPliku("granice.txt");

    char wybranaFunkcja; // Zmienna przechowująca wybraną funkcję

    // Główna pętla programu
    while (sprawdzWybor(wybranaFunkcja)) { // Sprawdzenie poprawności wyboru funkcji
        double dolnaGranica, gornaGranica; // Zmienne przechowujące granice całkowania
        int wyborGranic = wyborWprowadzeniaGranic(); // Wybór sposobu wprowadzenia granic całkowania
       
        // Ustalenie granic całkowania na podstawie wyboru użytkownika
        ustalGraniceCalkowania(wyborGranic, wybranaFunkcja, dolnaGranica, gornaGranica);

        // Obliczenie i prezentacja wyniku całkowania
        obliczIZaprezentujWynik(wybranaFunkcja, dolnaGranica, gornaGranica);
    }

    return 0;
}