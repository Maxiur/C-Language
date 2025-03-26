#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ILOSC_PAR 50

int main()
{
	srand(time(NULL));
	FILE *plik=fopen("dane.txt","w");
	
	for(int i=0;i<ILOSC_PAR;i++)
		fprintf(plik, "(%.2lf,%.2lf)\n",((rand()%20001)-10000)/100.0,((rand()%20001)-10000)/100.0); // Zakres [-100, 100]
	return 0;
}
