#include "TypZespolone.h"

// Funkcja wczytujaca
TypZespolone czytajZ(FILE *plik)
{
	TypZespolone z = {0.0, 0.0};
	assert(plik!=NULL); // Czy plik jest otwarty
	fscanf(plik, " (%lf,%lf) ", &z.re, &z.im); // Wczytanie czesci rzeczywistej i urojonej
	return z;
}

// Funkcja zapisujaca
int piszZ(FILE *plik, TypZespolone z)
{
	assert(plik!=NULL);
	if(fprintf(plik,"(%.2lf,%.2lf)", z.re, z.im) > 0) // Sprawdzenie czy zapis sie udal
		return 1;
	else
		return 0;
}

// Obliczanie sprzezenia
TypZespolone sprzezenie(TypZespolone z)
{
	z.im=-z.im; // Zamiana znaku czesci urojonej
	return z;
}

// Obliczanie modulu
double modul(TypZespolone z)
{
	return sqrt(pow(z.re, 2)+pow(z.im, 2)); // Pierwiastek(Re^2 + Im^2)
}

// Obliczanie fazy
double faza(TypZespolone z)
{
	return atan2(z.im, z.re); // Obliczanie arctan(y/x) gdzie y=Im, x=Re
}

// Obliczanie sumy
TypZespolone suma(TypZespolone z1, TypZespolone z2)
{
	TypZespolone wynik={z1.re + z2.re, z1.im + z2.im};
	return wynik;
}

// Obliczanie roznicy
TypZespolone roznica(TypZespolone z1, TypZespolone z2)
{
	TypZespolone wynik={z1.re - z2.re, z1.im - z2.im};
	return wynik;
}

// Obliczanie iloczynu
TypZespolone iloczyn(TypZespolone z1, TypZespolone z2)
{
	TypZespolone wynik={(z1.re * z2.re) - (z1.im * z2.im), (z1.re * z2.im) + (z2.re * z1.im)};
	return wynik;
}

// Obliczanie ilorazu
TypZespolone iloraz(TypZespolone z1, TypZespolone z2)
{
	assert(z2.im !=0 || z2.re !=0); // Czy nie dzielimy przez 0
	TypZespolone sprzZ2 = sprzezenie(z2); // Obliczanie sprzezenia z2
	double modulZ2 = modul(z2) * modul(z2); // Obliczanie mianownika
	TypZespolone licznik = iloczyn(z1, sprzZ2); // Obliczanie licznika
	
	TypZespolone wynik={licznik.re / modulZ2 , licznik.im / modulZ2}; // Obliczanie wyniku, gdzie z1/z2= [z1*sprzezenie(z2)]/modul(z2)^2
	return wynik;
}
