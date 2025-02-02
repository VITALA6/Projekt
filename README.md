# Metoda trapezów w C++. 
Projekt i implementacja programu obliczającego całkę złożoną metodą trapezów. 

# Treść dokumentacji
* [Tematy dokumentacji](#tematy-dokumentacji)
* [Sformułowanie zadania](#sformułowanie-zadania)
* [Opis problemu](#opis-problemu)
* [Porównanie wyników](#porównanie-wyników)
* [Schematy blokowe](#schematy-blokowe)
* [Instrukcja programu](#instrukcja-programu)
* [Przykłady działania](#przykłady-działania)
* [Żródła](#źródła)
    
## Sformułowanie zadania
Celem programu jest obliczenie wartości całki oznaczonej wybranej funkcji za pomocą metody trapezów. Użytkownik może wybrać jedną z dostępnych funkcji matematycznych oraz sposób wprowadzenia granic całkowania – ręcznie lub z pliku. Wynik obliczeń może być wyświetlony na ekranie, zapisany do pliku lub obie opcje mogą zostać wykonane jednocześnie.

## Opis problemu
Metoda trapezów to numeryczna metoda obliczania całek oznaczonych. Całka oznaczona funkcji f(x) w przedziale [a, b] jest aproksymowana sumą pól trapezów, na które dzielimy ten przedział.

Wzór na metodę trapezów:

![](https://cdn.discordapp.com/attachments/603599707796668426/1335692856383242372/image.png?ex=67a11868&is=679fc6e8&hm=337425d56f6c576b2bf1f0264015cc8676063b60272f8f99e8c09c03e7f2eb87&)

gdzie:
* ![](https://cdn.discordapp.com/attachments/603599707796668426/1335693240367579197/image.png?ex=67a118c4&is=679fc744&hm=60d5c21d9934995b4197cff2d8b9ae1bf4ee5105b4b72d6b4105506f96b2899a&)
-długość podprzedziału.

- n – liczba podziałów,
- xi=a+i⋅h – punkty podziału przedziału.

### Przykład rozwiązania
Obliczmy przybliżoną wartość całki oznaczonej dla funkcji:

![](https://cdn.discordapp.com/attachments/603599707796668426/1335693284978200576/image.png?ex=67a118cf&is=679fc74f&hm=06c8ee38e67d6f6642967ee153b0b346efb689fda55ddb23e7b0e5fd69247bf8&)

w przedziale [0,3] za pomocą metody trapezów dla n=4 (podział na 4 przedziały).

Krok 1: Obliczenie długości podziału
![](https://cdn.discordapp.com/attachments/603599707796668426/1335693325159628832/image.png?ex=67a118d8&is=679fc758&hm=ebb5a6346f6b844c67c12cb0b1d011624486cbbed7e9a803946bda4147cdc3ee&)

Krok 2: Wyznaczenie wartości funkcji w punktach podziału

Punkty podziału:

![](https://cdn.discordapp.com/attachments/603599707796668426/1335693409620328491/image.png?ex=67a118ec&is=679fc76c&hm=c066deb6140205195a3ce0f013433ec024a8bbcee654fc5a7bdf04feaf5241e3&)

Krok 3: Podstawienie do wzoru

![](https://cdn.discordapp.com/attachments/603599707796668426/1335693440729612410/image.png?ex=67a118f4&is=679fc774&hm=cc66156c299719fe9782b7b8eb7eb5de665b93d9da1db33e53165cbe3fc16f83&)

Wynik: I~19.78

Czyli wartość całki oznaczonej
![](https://cdn.discordapp.com/attachments/603599707796668426/1335694488559026266/image.png?ex=67a119ee&is=679fc86e&hm=d0714e61f9382fbe6228cd21cdc3b5574cfe91d6ad7990f0baf65f0dabc338a1&)
oszacowana metodą trapezów dla n=4 wynosi 19.78.

## Porównanie wyników

![](https://cdn.discordapp.com/attachments/603599707796668426/1335708258169786388/image.png?ex=67a126c1&is=679fd541&hm=ddcf0e8c9cfa5b330a0ebca4c4a01f2d6a6ef2ea54c4617cf822e8bd8bb030a8&)


## Schematy blokowe
- Main
```mermaid
graph TB
Start([Start]) --> Init["Ustaw kodowanie (chcp 65001)"]
Init --> Load["Wczytaj nazwy funkcji z pliku"]
Load --> Loop{Sprawdź poprawność wyboru}
Loop -->|Tak| WyborGranic["Wybierz sposób wprowadzenia granic"]
WyborGranic --> Wprowadz["Wprowadź granice całkowania"]
Wprowadz --> Oblicz["Oblicz i zaprezentuj wynik"]
Oblicz --> Loop
Loop -->|Nie| Koniec([Koniec programu])
```


- Funk
```mermaid
graph TB
Start([Start]) --> Menu["Wyświetl menu funkcji"]
Menu --> Wybor{"Wybór funkcji"}
Wybor -->|a-g| Granice{"Sposób wprowadzenia granic"}
Wybor -->|x| Koniec([Koniec])
Granice -->|Z pliku| Plik{Sprawdź plik}
Granice -->|Ręcznie| Reczywnie["Podaj a i b"]
Plik -->|Istnieje| Wczytaj["Załaduj granice"]
Plik -->|Nie istnieje| Blad["Błąd: Brak pliku"]
Reczywnie --> Warunek{"a < b?"}
Warunek -->|Nie| Reczywnie
Warunek -->|Tak| Podzialy["Podaj liczbę podziałów n"]
Wczytaj --> Podzialy
Podzialy --> Walidacja{"n > 0?"}
Walidacja -->|Nie| BladN["Błąd: Niepoprawne n"]
Walidacja -->|Tak| Obliczenia["Oblicz metodą trapezów"]
Obliczenia --> Prezentacja{"Sposób prezentacji"}
Prezentacja -->|Plik| Zapis["Zapisz do pliku"]
Prezentacja -->|Ekran| Wyswietl["Wyświetl wynik"]
Prezentacja -->|Oba| Oba["Zapisz i wyświetl"]
Zapis --> Koniec
Wyswietl --> Koniec
Oba --> Koniec
```

## Instrukcja programu
1. Uruchomienie programu
Program należy skompilować i uruchomić w konsoli.

2. Wybór funkcji
Po uruchomieniu programu użytkownik wybiera funkcję spośród podanych w menu (a-g).

3. Określenie granic całkowania
Użytkownik może:
- Wczytać granice z pliku
- Wprowadzić granice ręcznie

4. Podanie liczby podziałów
Użytkownik podaje liczbę przedziałów (musi być dodatnia).

5. Obliczenie całki metodą trapezów
Program oblicza wartość całki dla wybranej funkcji i zadanych parametrów.

6. Prezentacja wyników
Użytkownik wybiera sposób prezentacji wyniku:
- Zapis do pliku
- Wyświetlenie na ekranie
- Obie opcje

7. Powtórzenie procesu lub zakończenie programu
Użytkownik może powtórzyć proces lub zakończyć program

## Przykłady działania
### Wybranie funkcji
Przed:

![](https://cdn.discordapp.com/attachments/603599707796668426/1335710388179832867/image.png?ex=67a128bc&is=679fd73c&hm=844ffe0f5d5d4e9417be7d1b34155e31e54515923b76f44e347ca4db782ab7d0&)

Po:

![](https://cdn.discordapp.com/attachments/603599707796668426/1335710582120120401/image.png?ex=67a128eb&is=679fd76b&hm=c7de47cdf687ffc681737f71a936aa6a4d22cd6b04a231f1138b1d1e12f513eb&)

### Wybór wprowadzenia granic całkowania
Przed:

![](https://cdn.discordapp.com/attachments/603599707796668426/1335711682869071992/image.png?ex=67a129f1&is=679fd871&hm=776e95eb7f2fbc51cfa6dc8d41572efd92af6fcd9c9962bc9c54f9f12da8e223&)

Po:

![](https://cdn.discordapp.com/attachments/603599707796668426/1335711718373851267/image.png?ex=67a129f9&is=679fd879&hm=ac12f2e698a56f0eda21aeae41a4327f2fa59fac4ef8872f51f06a7b6372a27e&)

### Wprowadzenie podziałów(n)
Przed:

![](https://cdn.discordapp.com/attachments/603599707796668426/1335711718373851267/image.png?ex=67a129f9&is=679fd879&hm=ac12f2e698a56f0eda21aeae41a4327f2fa59fac4ef8872f51f06a7b6372a27e&)

Po:

![](https://cdn.discordapp.com/attachments/603599707796668426/1335711774359421079/image.png?ex=67a12a07&is=679fd887&hm=e996de99649d6ea8181bdccb6cd23bdbeeff3ebe8fa0f753eefabf36fd46b638&)

### Wybór sposobu wyświetlania wyników
Przez:

![](https://cdn.discordapp.com/attachments/603599707796668426/1335711774359421079/image.png?ex=67a12a07&is=679fd887&hm=e996de99649d6ea8181bdccb6cd23bdbeeff3ebe8fa0f753eefabf36fd46b638&)

Po:

![](https://cdn.discordapp.com/attachments/603599707796668426/1335711941384998944/image.png?ex=67a12a2f&is=679fd8af&hm=a8e4f8811bed9a5268b8d4a0573602c667bf2d1d9d125ecec267c9b29a4da8fa&)

## Źródła
- Visual Studio Code version: 1.96.4
https://code.visualstudio.com/

- gcc (Rev3, Built by MSYS2 project) 13.2.0
https://code.visualstudio.com/docs/cpp/config-mingw

-   https://www.learncpp.com/
-	https://cplusplus.com/doc/tutorial/
-   https://www.mathros.net.ua/
-	https://www.wolframalpha.com/
-   https://books.goalkicker.com/CPlusPlusBook/
-   https://chatgpt.com/
