#include <stdio.h>
#include "matrix_io.h"

int wczytaj_macierz(const char *nazwa_pliku, double M[][MAX], int *wiersze, int *kolumny) {
    FILE *plik;
    int i, j;

    plik = fopen(nazwa_pliku, "r");
    if (plik == NULL) {
        return 1;
    }






    

    if (fscanf(plik, "%d %d", wiersze, kolumny) != 2) {
        fclose(plik);
        return 2;
    }


    

    if (*wiersze <= 0 || *wiersze > MAX || *kolumny <= 0 || *kolumny > MAX) {
        fclose(plik);
        return 3;
    }

    for (i = 0; i < *wiersze; i++) {
        for (j = 0; j < *kolumny; j++) {
            if (fscanf(plik, "%lf", &M[i][j]) != 1) {
                fclose(plik);
                return 4;
            }
        }
    }



    
    fclose(plik);
    return 0;
}

int zapisz_macierz(const char *nazwa_pliku, double M[][MAX], int wiersze, int kolumny) {
    FILE *plik;
    int i, j;

    plik = fopen(nazwa_pliku, "w");
    if (plik == NULL) {
        return 1;
    }

    if (fprintf(plik, "%d %d\n", wiersze, kolumny) < 0) {
        fclose(plik);
        return 1;
}



    
    for (i = 0; i < wiersze; i++) {
        for (j = 0; j < kolumny; j++) {
            if (j > 0) {
                fprintf(plik, " ");
            }
            if (fprintf(plik, "%.2f", M[i][j]) < 0) {
                fclose(plik);
                return 1;
            }
        }
        fprintf(plik, "\n");
    }

    if (fclose(plik) != 0) {
        return 1;
    }
    return 0;
}




void wypisz_macierz(double M[][MAX], int wiersze, int kolumny) {
    int i, j;
    for (i = 0; i < wiersze; i++) {
        for (j = 0; j < kolumny; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%.2f", M[i][j]);
        }
        printf("\n");
    }
}
