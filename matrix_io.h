#ifndef MATRIX_IO_H
#define MATRIX_IO_H

#include "matrix.h"

int wczytaj_macierz(const char *nazwa_pliku, double M[][MAX], int *wiersze, int *kolumny);
int zapisz_macierz(const char *nazwa_pliku, double M[][MAX], int wiersze, int kolumny);
void wypisz_macierz(double M[][MAX], int wiersze, int kolumny);

#endif
