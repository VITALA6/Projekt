# Metoda trapezów w C++. 
Projekt i implementacja programu obliczającego całkę złożoną metodą trapezów. 

# Tematy dokumentacji
* [Sformułowanie zadania]( #Sformułowaniezadania)
* [Opis problemu]
* [Schematy blokowe]
* [Instrukcja programu]

    
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

## Schematy blokowe

