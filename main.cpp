#include <cstdlib>   
#include "funk.cpp" 

int main() {
    system("chcp 65001 >> null");

    wczytajNazwyFunkcji("nazwyFunkcji.txt");
    graniceZPliku("granice.txt");

    char wybranaFunkcja;

    while (sprawdzWybor(wybranaFunkcja)) {
        double dolnaGranica, gornaGranica;
        int wyborGranic = wyborWprowadzeniaGranic();
       
        ustalGraniceCalkowania(wyborGranic, wybranaFunkcja, dolnaGranica, gornaGranica);

        obliczIZaprezentujWynik(wybranaFunkcja, dolnaGranica, gornaGranica);
    }

    return 0;
}
