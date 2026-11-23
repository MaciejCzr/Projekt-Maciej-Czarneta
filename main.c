#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "matrix_io.h"

void wypisz_blad_pliku(int kod, const char *nazwa) {
    if (kod == 1) {
        printf("Blad: Brak pliku %s!\n", nazwa);
    } else if (kod == 2) {
        printf("Blad: Nie-liczba lub brak wymiarow w pliku %s!\n", nazwa);
    } else if (kod == 3) {
        printf("Blad: Zly zakres wymiarow w pliku %s (dozwolone 1..%d)!\n", nazwa, MAX);
    } else if (kod == 4) {
        printf("Blad: Nie-liczba lub za malo danych w pliku %s!\n", nazwa);
    }
}

int main(void) {
    double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int wA, kA, wB, kB;
    int wC = 0, kC = 0;
    int blad1, blad2, wybor;
    char plik1[256], plik2[256], plik_wynik[256];

    printf("Podaj nazwe pliku pierwszej macierzy (np. macierz1.txt): ");
    if (scanf("%255s", plik1) != 1) {
        printf("Blad: Nie udalo sie wczytac nazwy pliku!\n");
        return 1;
    }


    
    printf("Podaj nazwe pliku drugiej macierzy (np. macierz2.txt): ");
    if (scanf("%255s", plik2) != 1) {
        printf("Blad: Nie udalo sie wczytac nazwy pliku!\n");
        return 1;
    }

    printf("Podaj nazwe pliku wynikowego (np. wynik.txt): ");
    if (scanf("%255s", plik_wynik) != 1) { 
        printf("Blad: Nie udalo sie wczytac nazwy pliku!\n");
        return 1;
    }

    blad1 = wczytaj_macierz(plik1, A, &wA, &kA);
    if (blad1 != 0) {
        wypisz_blad_pliku(blad1, plik1);
        return 1;
    }




    

    blad2 = wczytaj_macierz(plik2, B, &wB, &kB);
    if (blad2 != 0) {
        wypisz_blad_pliku(blad2, plik2);
        return 1;
    }

    printf("Wybierz operacje:\n1 - Dodawanie\n2 - Odejmowanie\n3 - Mnozenie\nWybor: ");
    if (scanf("%d", &wybor) != 1) {
        printf("Blad: Wybor musi byc liczba!\n");
        return 1;
    }

    if (wybor == 1) {
        if (!zgodne_do_sumy(wA, kA, wB, kB)) {
            printf("Blad: Macierze musza miec identyczne wymiary do dodawania!\n");
            return 1;
        }
        dodaj(A, B, C, wA, kA);
        wC = wA;
        kC = kA;
    } else if (wybor == 2) {
        if (!zgodne_do_sumy(wA, kA, wB, kB)) {
            printf("Blad: Macierze musza miec identyczne wymiary do odejmowania!\n");
            return 1;
        }




        
        odejmij(A, B, C, wA, kA);
        wC = wA;
        kC = kA;
    } else if (wybor == 3) {
        if (!zgodne_do_mnozenia(wA, kA, wB, kB)) {
            printf("Blad: Liczba kolumn pierwszej macierzy musi rownac sie liczbie wierszy drugiej!\n");
            return 1;
        }
        pomnoz(A, B, C, wA, kA, kB);
        wC = wA;
        kC = kB;
    } else {
        printf("Blad: Nieznana operacja!\n");
        return 1;
    }
    printf("\nWynik:\n");
    wypisz_macierz(C, wC, kC);

    if (zapisz_macierz(plik_wynik, C, wC, kC) != 0) {
        printf("Blad: Nie udalo sie zapisac wyniku do pliku %s!\n", plik_wynik);
        return 1;
    }
    printf("\nWynik zapisano do pliku %s\n", plik_wynik);
    return 0;
}
