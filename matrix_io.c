#include <stdio.h>
#include "matrix_io.h"

int wczytaj_macierz(const char *nazwa_pliku, double M[][MAX], int *wiersze, int *kolumny) {
    FILE *plik = fopen(nazwa_pliku, "r");
    if (plik == NULL) {
        return 1; // Brak pliku
    }

    if (fscanf(plik, "%d %d", wiersze, kolumny) != 2) {
        fclose(plik);
        return 2; // Nie-liczba lub pusty plik przy wymiarach
    }

    if (*wiersze <= 0 || *wiersze > MAX || *kolumny <= 0 || *kolumny > MAX) {
        fclose(plik);
        return 3; // Zly zakres wymiarow (musi byc od 1 do MAX)
    }

    int i, j;
    for (i = 0; i < *wiersze; i++) {
        for (j = 0; j < *kolumny; j++) {
            if (fscanf(plik, "%lf", &M[i][j]) != 1) {
                fclose(plik);
                return 4; // Nie-liczba w macierzy lub za malo danych
            }
        }
    }

    fclose(plik);
    return 0; // Wszystko OK
}

void zapisz_macierz(const char *nazwa_pliku, double M[][MAX], int wiersze, int kolumny) {
    FILE *plik = fopen(nazwa_pliku, "w");
    if (plik == NULL) return;

    fprintf(plik, "%d %d\n", wiersze, kolumny);
    int i, j;
    for (i = 0; i < wiersze; i++) {
        for (j = 0; j < kolumny; j++) {
            fprintf(plik, "%.2lf ", M[i][j]);
        }
        fprintf(plik, "\n");
    }
    fclose(plik);
}

void wypisz_macierz(double M[][MAX], int wiersze, int kolumny) {
    int i, j;
    for (i = 0; i < wiersze; i++) {
        for (j = 0; j < kolumny; j++) {
            printf("%.2lf ", M[i][j]);
        }
        printf("\n");
    }
}
