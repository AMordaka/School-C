#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


double** zaladowanie(const char* sciezka,int* n);
FILE* otwarcie_pliku(const char* sciezka);
int wielkosc_macierzy(FILE* fp);
double** alokacja_pamieci(int n);
void wczytanie_liczb(FILE *fp, double** tab, int n);
void wydrukowanie_liczb(double** tab, int n);
void zwolnienie_pamieci(double** tab, int n);
double obliczenie_wyznacznika(double **tab,int n);
void dopelnienie(int j1, int n, double** minor, double** tab);



int main(int argc, char* argv[])
{
	
	double** tab=NULL;
	int n;
    double wynik;
	
	tab = zaladowanie(argv[1],&n);
	wydrukowanie_liczb(tab,n);
	
    wynik=obliczenie_wyznacznika(tab,n);
    printf("\n\n%.2f\n\n",wynik);
    
	zwolnienie_pamieci(tab,n);
	
	return 0;
}

double** zaladowanie(const char* sciezka,int* n)
{
	double** tab;
	FILE* fp;

	fp=otwarcie_pliku(sciezka); 
	*(n) = wielkosc_macierzy(fp);
	tab = alokacja_pamieci(*n);
	wczytanie_liczb(fp,tab,*n);
	
	fclose(fp);
	
	
	return tab;
}



FILE* otwarcie_pliku(const char* sciezka)
{
	FILE *fp;
	
	if((fp=fopen(sciezka,"r"))==NULL)	
	{
		printf("Blad otwarcia pliku\n");
		exit(1);
	}
	
	return fp;
}

int wielkosc_macierzy(FILE* fp)
{
	int n;
	fscanf(fp,"%d",&n);
	return n;
}

double** alokacja_pamieci(int n)
{
	int i;
	
	double **tab=NULL;
	tab=(double**)calloc(n,sizeof(double*));
	assert(tab);
	
	for(i=0;i<n;i++) 
	{
		*(tab+i)=(double*)calloc(n,sizeof(double));
		assert(tab+i);
	}
	
	return tab;
}



void wczytanie_liczb(FILE *fp, double** tab, int n)
{
	int i,j;
	double bufor;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%lf",&bufor);
			*(*(tab+i)+j)=bufor;
		}
	
	}
}


void wydrukowanie_liczb(double** tab, int n)
{
	int i,j;
	
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		printf("%.2lf\t",*(*(tab+i)+j));
	}	
}


void zwolnienie_pamieci(double** tab, int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		free(*(tab+i));
	}
	free(tab);	
}






double obliczenie_wyznacznika(double **tab,int n)
{
    int j1 ;                    
    double det = 0.0 ;                   
    double **minor = NULL ;    
    double sign=1.0;


    if (n == 1) 
	 	{                 
        det = tab[0][0] ;
        }

    else if (n == 2)  
		{                        
        det = tab[0][0] * tab[1][1] - tab[1][0] * tab[0][1] ;
        }

    else 
	{    
	                        
        det = 0 ;
        
        for (j1 = 0 ; j1 < n ; j1++) 
		{	
                    
			minor=alokacja_pamieci(n-1);
			dopelnienie(j1,n,minor,tab);
			
			det += sign * tab[0][j1] * obliczenie_wyznacznika(minor,n-1) ;
			sign = - sign;

			zwolnienie_pamieci(minor,n-1);
		}
	}
        
        return(det) ;
}

void dopelnienie(int j1, int n, double** minor, double** tab)
{
    int i,j,j2;
    
    for (i = 1 ; i < n ; i++) 
	{
		j2 = 0 ;    
		
		for (j = 0 ; j < n ; j++) 
		{
			if (j == j1) 
			{
				continue ; 
			}
			
			minor[i-1][j2] = tab[i][j] ;  
			j2++ ;                 
		}
	}

}
