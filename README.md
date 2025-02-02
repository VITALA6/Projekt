# Metoda trapezów w C++. 
Projekt i implementacja programu obliczającego całkę złożoną metodą trapezów. 

# Tematy dokumentacji
* [Sformułowanie zadania](#sformułowanie-zadania)
* [Opis problemu](#opis-problemu)
* [Schematy blokowe]
* [Instrukcja programu]

    
## Sformułowanie zadania
Celem programu jest obliczenie wartości całki oznaczonej wybranej funkcji za pomocą metody trapezów. Użytkownik może wybrać jedną z dostępnych funkcji matematycznych oraz sposób wprowadzenia granic całkowania – ręcznie lub z pliku. Wynik obliczeń może być wyświetlony na ekranie, zapisany do pliku lub obie opcje mogą zostać wykonane jednocześnie.

## Opis problemu
Metoda trapezów to numeryczna metoda obliczania całek oznaczonych. Całka oznaczona funkcji f(x) w przedziale [a, b] jest aproksymowana sumą pól trapezów, na które dzielimy ten przedział.

Wzór na metodę trapezów:

![]([https://cdn.discordapp.com/attachments/603599707796668426/1335681625161339010/image.png?ex=67a10df3&is=679fbc73&hm=cc6c9d9a05f81db8355febc5f5111474e8361e53166c952e745184f16a591a4d&](https://cdn.discordapp.com/attachments/603599707796668426/1335690531988176936/image.png?ex=67a1163e&is=679fc4be&hm=dc275f4c7de3d47f58eaf4d63321e0f870210b547eb79f70c596146c10dea1aa&))

gdzie:
* ![](https://cdn.discordapp.com/attachments/603599707796668426/1335682397043167292/image.png?ex=67a10eab&is=679fbd2b&hm=7664bf4e09d60a91ab63016c7985a4127d5dd804a55b235f6214e57724ebcf1f&)
-długość podprzedziału.

- n – liczba podziałów,
- xi=a+i⋅h – punkty podziału przedziału.

### Przykład rozwiązania
Obliczmy przybliżoną wartość całki oznaczonej dla funkcji:

![](https://cdn.discordapp.com/attachments/603599707796668426/1335687623724892200/image.png?ex=67a11389&is=679fc209&hm=0d4290804b4631500e243f75b0379cf1ba77c82bcb8931ece2e2a0a673a9effa&)

w przedziale [0,3] za pomocą metody trapezów dla n=4 (podział na 4 przedziały).

Krok 1: Obliczenie długości podziału
![](https://cdn.discordapp.com/attachments/603599707796668426/1335688016630513664/image.png?ex=67a113e7&is=679fc267&hm=6e53a0dca7bb6d5be2b7b8d8ebbce84e58dd78cc1abad5a9fe91c71cbfec2c89&)

Krok 2: Wyznaczenie wartości funkcji w punktach podziału

Punkty podziału:
![](https://cdn.discordapp.com/attachments/603599707796668426/1335688293366501566/image.png?ex=67a11429&is=679fc2a9&hm=a5e1876537bc829621ea79f366610339301b0b707f189bd279116a4e8404d7d8&)
