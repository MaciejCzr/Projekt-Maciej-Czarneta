#include "matrix.h"

int zgodne_do_sumy(int wA, int kA, int wB, int kB) {
    return (wA == wB && kA == kB);
}

int zgodne_do_mnozenia(int wA, int kA, int wB, int kB) {
    (void)wA;
    (void)kB;
    return (kA == wB);
}

void dodaj(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k) {
    int i, j;
    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void odejmij(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k) {
    int i, j;
    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void pomnoz(double A[][MAX], double B[][MAX], double C[][MAX], int wA, int kA, int kB) {
    int i, j, k;
    for (i = 0; i < wA; i++) {
        for (j = 0; j < kB; j++) {
            C[i][j] = 0.0;
            for (k = 0; k < kA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
