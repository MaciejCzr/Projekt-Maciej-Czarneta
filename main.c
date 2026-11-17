#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "matrix_io.h"

int main() {
    double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int wA, kA, wB, kB;
    int wC = 0, kC = 0;

    if (!wczytaj_macierz("macierz1.txt", A, &wA, &kA)) {
        printf("Blad: Nie udalo sie otworzyc lub odczytac pliku macierz1.txt!\n");
        return 1;
    }

    if (!wczytaj_macierz("macierz2.txt", B, &wB, &kB)) {
        printf("Blad: Nie udalo sie otworzyc lub odczytac pliku macierz2.txt!\n");
        return 1;
    }

    printf("Wybierz operacje:\n1 - Dodawanie\n2 - Odejmowanie\n3 - Mnozenie\nWybor: ");
    int wybor;
    if (scanf("%d", &wybor) != 1) {
        printf("Nieprawidlowy wybor!\n");
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

    // Zapis do pliku wynikowego
    zapisz_macierz("wynik.txt", C, wC, kC);
    printf("\nWynik zapisano do pliku wynik.txt\n");

    return 0;
}
