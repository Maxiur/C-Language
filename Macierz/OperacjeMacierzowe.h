#ifndef OPERACJE_MACIERZOWE
#define OPERACJE_MACIERZOWE

#include <stdio.h>
#include <assert.h>

int czytajMacierz(FILE *wejscie, char *nazwa, int n, double M[n][n]);

int wypiszMacierz(FILE *wyjscie, char *nazwa, int n, double M[n][n]);

int czytajWektor(FILE *wejscie, char *nazwa, int n, double V[n]);

int wypiszWektor(FILE *wyjscie, char *nazwa, int n, double V[n]);

int czytajLiczbe(FILE *wejscie, char *nazwa, double *restrict c);

int wypiszLiczbe(FILE *wyjscie, char *nazwa, double c);

void transponujMacierz(int n, double M[n][n], double MT[n][n]);

void dodajMacierze(int n, double A[n][n], double B[n][n], double C[n][n]);

void odejmijMacierze(int n, double A[n][n], double B[n][n], double C[n][n]);

void mnozLiczbaMacierz(int n, double c, double A[n][n], double B[n][n]);

void mnozMacierzWektor(int n, double A[n][n], double V[n], double W[n]);

void mnozMacierze(int n, double A[n][n], double B[n][n], double C[n][n]);

#endif // OPERACJE_MACIERZOWE

