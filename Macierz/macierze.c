#include "OperacjeMacierzowe.h"

int main(int argc, char *argv[])
{
	assert(argc == 3 && "Uzyj formatu: ./macierze <dane> <wyniki>\n");
	FILE *wejscie = fopen(argv[1], "r");
	if(!wejscie)
	{
		perror("Nie udalo sie otworzyc pliku z danymi!\n");
		return 1;
	}
	FILE *wyjscie = fopen(argv[2], "w");
	if(!wyjscie)
	{
		perror("Nie udalo sie otworzyc pliku z wynikami!\n");
		return 1;
	}
	assert(wejscie != NULL && "Nie udalo sie otworzyc pliku z danymi.\n");
	assert(wyjscie != NULL && "Nie udalo sie otworzyc pliku z wynikami.\n");
	
	// Deklaracja zmiennych

	const int n=4;
	double A[n][n],B[n][n],C[n][n];
	double c;
	double V[n], W[n];
	char nazwa[100];
	
	// Wczytywanie danych

	assert(czytajMacierz(wejscie, nazwa, n, A) && "Blad odczytu macierzy A\n");
	wypiszMacierz(stdout, nazwa, n, A);
	wypiszMacierz(wyjscie, nazwa, n, A);
 
	assert(czytajMacierz(wejscie, nazwa, n, B) && "Blad odczytu macierzy B\n");
	wypiszMacierz(stdout, nazwa, n, B);
	wypiszMacierz(wyjscie, nazwa, n, B);

	assert(czytajLiczbe(wejscie, nazwa, &c) && "Blad odczytu litery c\n");
	wypiszLiczbe(stdout, nazwa, c);
	wypiszLiczbe(wyjscie, nazwa, c);

	assert(czytajWektor(wejscie, nazwa, n, V) && "Blad odczytu wektora V\n");
	wypiszWektor(stdout, nazwa, n, V);
	wypiszWektor(wyjscie, nazwa, n, V);

	// Operacje na macierzach
	
	dodajMacierze(n, A, B, C);
	wypiszMacierz(stdout, "Suma macierzy A i B:", n, C);
	wypiszMacierz(wyjscie, "Suma macierzy A i B:", n, C);
	
	odejmijMacierze(n, A, B, C);
        wypiszMacierz(stdout, "Roznica macierzy A i B:", n, C);
        wypiszMacierz(wyjscie, "Roznica macierzy A i B:", n, C);
	
	mnozLiczbaMacierz(n, c, A, C);
        wypiszMacierz(stdout, "Iloczyn macierzy A i liczby c:", n, C);
        wypiszMacierz(wyjscie, "Iloczyn macierzy A i liczby c:", n, C);

	mnozMacierzWektor(n, A, V, W);
    	wypiszWektor(stdout, "Iloczyn macierzy A i wektora V:", n, W);
    	wypiszWektor(wyjscie, "Iloczyn macierzy A i wektora V:", n, W);

    	mnozMacierze(n, A, B, C);
    	wypiszMacierz(stdout, "Iloczyn macierzy A i B:", n, C);
    	wypiszMacierz(wyjscie, "Iloczyn macierzy A i B:", n, C);

    	transponujMacierz(n, A, C);
    	wypiszMacierz(stdout, "Transpozycja macierzy A:", n, C);
    	wypiszMacierz(wyjscie, "Transpozycja macierzy A:", n, C);
	
	
	fclose(wejscie);
	fclose(wyjscie);

	return 0;
}
