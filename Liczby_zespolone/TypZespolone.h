#ifndef TYPZESPOLONE_H
#define TYPZESPOLONE_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

// Definicja struktury liczby zespolonej
typedef struct
{
	double re; // Czesc rzeczywista
	double im; // Czesc urojona
} TypZespolone;

// Deklaracja funkcji

// Funkcja wczytujaca
TypZespolone czytajZ(FILE *plik);

// Funkcja zapisujaca
int piszZ(FILE *plik, TypZespolone z);

// Obliczanie sprzezenia
TypZespolone sprzezenie(TypZespolone z);

// Obliczanie modulu
double modul(TypZespolone z);

// Obliczanie fazy
double faza(TypZespolone z);

// Obliczanie sumy
TypZespolone suma(TypZespolone z1, TypZespolone z2);

// Obliczanie roznicy
TypZespolone roznica(TypZespolone z1, TypZespolone z2);

// Obliczanie iloczynu
TypZespolone iloczyn(TypZespolone z1, TypZespolone z2);

// Obliczanie ilorazu
TypZespolone iloraz(TypZespolone z1, TypZespolone z2);

#endif // TYPZESPOLONE_H
