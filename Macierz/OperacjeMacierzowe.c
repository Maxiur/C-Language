#include "OperacjeMacierzowe.h"

int czytajMacierz(FILE *wejscie, char *nazwa, int n, double M[n][n])
{
	fscanf(wejscie, "%s", nazwa);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fscanf(wejscie, "%lf", &M[i][j]);
	return 1;
}

int wypiszMacierz(FILE *wyjscie, char *nazwa, int n, double M[n][n])
{
	fprintf(wyjscie, "\n%s", nazwa);
	for(int i=0;i<n;i++)
	{	
		fprintf(wyjscie,"\n");
		for(int j=0;j<n;j++)
			fprintf(wyjscie, "%10.2lf ", M[i][j]);
	}
	fprintf(wyjscie,"\n");
	return 1;
}
int czytajWektor(FILE *wejscie, char *nazwa, int n, double V[n])
{
	fscanf(wejscie, "%s", nazwa);
	for(int i=0;i<n;i++)
		fscanf(wejscie, "%lf", &V[i]);
	return 1;
}

int wypiszWektor(FILE *wyjscie, char *nazwa, int n, double V[n])
{
	fprintf(wyjscie, "\n%s\n", nazwa);
	for(int i=0;i<n;i++)
	{
		fprintf(wyjscie, "%10.2lf\n", V[i]);
	}
	return 1;
}

int czytajLiczbe(FILE *wejscie, char *nazwa, double *restrict c)
{
	fscanf(wejscie, "%s", nazwa);
	fscanf(wejscie, "%lf", c);
	return 1;
}

int wypiszLiczbe(FILE *wyjscie, char *nazwa, double c)
{
	fprintf(wyjscie, "\n%s\n", nazwa);
	fprintf(wyjscie, "%10.2lf\n", c);
	return 1;
}

void transponujMacierz(int n, double M[n][n], double MT[n][n])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			MT[j][i]=M[i][j];
}

void dodajMacierze(int n, double A[n][n], double B[n][n], double C[n][n])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			C[i][j]=A[i][j]+B[i][j];
}

void odejmijMacierze(int n, double A[n][n], double B[n][n], double C[n][n])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			C[i][j]=A[i][j]-B[i][j];
}

void mnozLiczbaMacierz(int n, double c, double A[n][n], double B[n][n])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			B[i][j]=c*A[i][j];
}

void mnozMacierzWektor(int n, double A[n][n], double V[n], double W[n])
{
	for(int i=0;i<n;i++)
		{
		W[i]=0;
		for(int j=0;j<n;j++)
			W[i]+=A[i][j]*V[j];
		}

}

void mnozMacierze(int n, double A[n][n], double B[n][n], double C[n][n])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			{
			C[i][j]=0;
			for(int k=0;k<n;k++)
				C[i][j]+=A[i][k]*B[k][j];
			}
}
