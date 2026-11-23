#ifndef MATRIX_H
#define MATRIX_H

#define MAX 20

int zgodne_do_sumy(int wA, int kA, int wB, int kB);
int zgodne_do_mnozenia(int wA, int kA, int wB, int kB);

void dodaj(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k);
void odejmij(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k);
void pomnoz(double A[][MAX], double B[][MAX], double C[][MAX], int wA, int kA, int kB);

#endif
