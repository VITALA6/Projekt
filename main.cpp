#include "funkcje.cpp" // Dołączenie pliku z funkcjami

int main() {
    system("chcp 65001 >> null"); // Obsługa polskich znaków
    wczytajNazwyFunkcji("nazwyFunkcji.txt"); // Wczytanie nazw funkcji z pliku

    char wybranaFunkcja;
    while (SprawdzPoprawnoscWyboru(wybranaFunkcja)) { // Główna pętla programu
        int wyborGranic = WyborWprowadzeniaGranic(); // Wybór sposobu wprowadzenia granic
        double dolnaGranica, gornaGranica;
        WprowadzGranice(dolnaGranica, gornaGranica, wyborGranic); // Wprowadzenie granic
        ObliczIZaprezentujWynik(wybranaFunkcja, dolnaGranica, gornaGranica); // Obliczenie i prezentacja wyniku
    }
    return 0;
}
