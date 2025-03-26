#include "TypZespolone.h"

int main(int argc, char *argv[]) {
	// Sprawdzenie liczby argumentów
	assert(argc == 3 && "Użyj formatu: ./zespolone <plik_dane> <plik_wyniki>");

	// Otwieramy pliki
    	FILE *plikWej = fopen(argv[1], "r");
    	FILE *plikWyj = fopen(argv[2], "w");
    	assert(plikWej != NULL && "Nie udało się otworzyć pliku z danymi wejściowymi.");
    	assert(plikWyj != NULL && "Nie udało się otworzyć pliku z wynikami.");

    	printf("\n-----------------------------------------\n\n");

    	// Wczytywanie i przetwarzanie par liczb zespolonych, dopóki są dostępne w pliku
    	TypZespolone z1, z2;
    	while (1)
	{
        	// Wczytanie dwóch liczb zespolonych
        	z1 = czytajZ(plikWej);
		if(feof(plikWej))
			break;
        	z2 = czytajZ(plikWej);
		if(feof(plikWej))
			exit(1);

	// Zapis wczytanych liczb do pliku wynikowego i wypisanie na ekran
	printf("Liczba zespolona z1: %.2lf%c%.2lfi\n", z1.re, (z1.im < 0) ? '-' : '+', fabs(z1.im));
	printf("Liczba zespolona z2: %.2lf%c%.2lfi\n", z2.re, (z2.im < 0) ? '-' : '+', fabs(z2.im));

        fprintf(plikWyj, "Liczba zespolona z1: %.2lf%c%.2lfi\n", z1.re, (z1.im < 0) ? '-' : '+', fabs(z1.im));
        fprintf(plikWyj, "Liczba zespolona z2: %.2lf%c%.2lfi\n", z2.re, (z2.im < 0) ? '-' : '+', fabs(z2.im));

        // Wykonywanie operacji
        TypZespolone wynik;

        // Obliczanie sumy
        wynik = suma(z1, z2);
        printf("Suma: %.2lf%c%.2lfi\n", wynik.re, (wynik.im < 0) ? '-' : '+', fabs(wynik.im));
        fprintf(plikWyj, "Suma: %.2lf%c%.2lfi\n", wynik.re, (wynik.im < 0) ? '-' : '+', fabs(wynik.im));

        // Obliczanie różnicy
        wynik = roznica(z1, z2);
        printf("Różnica: %.2lf%c%.2lfi\n", wynik.re, (wynik.im < 0) ? '-' : '+', fabs(wynik.im));
        fprintf(plikWyj, "Różnica: %.2lf%c%.2lfi\n", wynik.re, (wynik.im < 0) ? '-' : '+', fabs(wynik.im));

        // Obliczanie iloczynu
        wynik = iloczyn(z1, z2);
        printf("Iloczyn: %.2lf%c%.2lfi\n", wynik.re, (wynik.im < 0) ? '-' : '+', fabs(wynik.im));
        fprintf(plikWyj, "Iloczyn: %.2lf %c %.2lfi\n", wynik.re, (wynik.im < 0) ? '-' : '+', fabs(wynik.im));

        // Obliczanie ilorazu (jeśli z2 != 0)
        if (z2.re != 0 || z2.im != 0) { // Unikamy dzielenia przez zero
            wynik = iloraz(z1, z2);
            printf("Iloraz: %.2lf%c%.2lfi\n", wynik.re, (wynik.im < 0) ? '-' : '+', fabs(wynik.im));
            fprintf(plikWyj, "Iloraz: %.2lf%c%.2lfi\n", wynik.re, (wynik.im < 0) ? '-' : '+', fabs(wynik.im));
        } else {
            printf("Iloraz: dzielenie przez zero jest niedozwolone.\n");
            fprintf(plikWyj, "Iloraz: dzielenie przez zero jest niedozwolone.\n");
        }

        // Obliczanie modułów i faz
        printf("Moduł z1: %.2lf\n", modul(z1));
        printf("Moduł z2: %.2lf\n", modul(z2));
        fprintf(plikWyj, "Moduł z1: %.2lf\n", modul(z1));
        fprintf(plikWyj, "Moduł z2: %.2lf\n", modul(z2));

        printf("Faza z1: %.2lf rad\n", faza(z1));
        printf("Faza z2: %.2lf rad\n", faza(z2));
        fprintf(plikWyj, "Faza z1: %.2lf rad\n", faza(z1));
        fprintf(plikWyj, "Faza z2: %.2lf rad\n", faza(z2));

        printf("\n-----------------------------------------\n\n");
        fprintf(plikWyj, "\n-----------------------------------------\n\n");
    }

    // Zamknięcie plików
    fclose(plikWej);
    fclose(plikWyj);

    return 0;
}

