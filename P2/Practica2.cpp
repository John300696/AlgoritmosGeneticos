#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void ImprimeCromosoma(int Alelo[][7])
{
	for(int i=0;i<10;i++)
	{
		printf("Individuo %d\t",i+1);
		for(int j=0;j<7;j++)
		{
			printf("%d,",Alelo[i][j]);
		}
		printf("\n");
	
	}
	
	printf("\n");
}

void ImprimeCromosomaGray(int Alelo[][7],int AleloFinal[][7],int Decimales[])
{
	for(int i=0;i<10;i++)
	{
		printf("Individuo %d \t(%d)\t",i+1,Decimales[i]);
		for(int j=0;j<7;j++)
		{
			printf("%d",Alelo[i][j]);
		}
		printf("=>");
		for(int j=0;j<7;j++)
		{
			printf("%d",AleloFinal[i][j]);
		}
		printf("\n");
	
	}
	
	printf("\n");
}

void ImprimeCromosoma(float Alelo[][7])
{
	for(int i=0;i<10;i++)
	{
		printf("Individuo %d\t",i+1);
		for(int j=0;j<7;j++)
		{
			printf("%.2lf,",Alelo[i][j]);
		}
		printf("\n");
	
	}
	
	printf("\n");
}


void binaria()
{
	srand(time(NULL));
	
	printf("\nRepresentación binaria\n");
	int Alelo[10][7];
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<7;j++)
		{
			Alelo[i][j]=rand() % 1001;
			if(Alelo[i][j]%2)
			{
				Alelo[i][j] = 1;
			}
			else
			{
				Alelo[i][j] = 0;
			}	
		}
	}
	
	
	ImprimeCromosoma(Alelo);
}

void gray()
{
	printf("\nCódigos de Gray\n");
	
	srand(time(NULL));

	int Alelo[10][7];
	int AleloFinal[10][7];
	int Decimal[10];
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<7;j++)
		{
			Alelo[i][j]=rand() % 1001;
			if(Alelo[i][j]%2)
			{
				Alelo[i][j] = 1;
			}
			else
			{
				Alelo[i][j] = 0;
			}	
		}
	}
	
	//ImprimeCromosoma(Alelo);
	
	int temp = 0;
	int td = 0;
	
	for(int i=0;i<10;i++)
	{
		
		td = 0;
		
		for(int k=0;k<7;k++)
		{
			if(k == 0)
			{
				AleloFinal[i][k] = Alelo[i][k];
			}
			else
			{
				temp = k-1;
				AleloFinal[i][k] = Alelo[i][k]^Alelo[i][temp];
			}
			
			
			
		}
		
		for(int k=0;k<7;k++)
		{
			td += Alelo[i][6-k]*pow(2,k);
			
			
		}
		
		Decimal[i] = td;
		
	}
	
	ImprimeCromosomaGray(Alelo,AleloFinal,Decimal);
	
}

void reales()
{
	printf("\nCodificación en números reales\n");
	
	srand(time(NULL));

	float Alelo[10][7];
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<7;j++)
		{
			Alelo[i][j]=(double)rand()/(RAND_MAX+1)*(99)+1;
				
		}
	}
	
	
	ImprimeCromosoma(Alelo);
	
	
}

void enteros()
{
	srand(time(NULL));
	
	printf("\nCodificación en números enteros\n");
	int Alelo[10][7];
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<7;j++)
		{
			Alelo[i][j]=rand() % 100;
			
		}
	}
	
	
	ImprimeCromosoma(Alelo);
	
	
}

int main()
{
	setlocale(LC_ALL, "");
	printf("ESCUELA SUPERIOR DE CÓMPUTO\n");
	printf("Algoritmos Géneticos\n");
	printf("Práctica 2\n\n");
	
	char continua = 's';
	
	while(continua == 's')
	{
		printf("Seleccione el tipo de representación que desea realizar\n");
		printf("1.- Representación binaria\n");
		printf("2.- Códigos de Gray\n");
		printf("3.- Codificación en números reales\n");
		printf("4.- Codificación en números enteros\n");
		int opc = 0;
		
		
		scanf("%d",&opc);
	
		switch(opc)
		{
			case 1:
				binaria();
			break;	
			case 2:
				gray();
			break;
			case 3:
				reales();
			break;
			case 4:
				enteros();
			break;
			default:
				printf("No es una opción valida\n");
			break;	
		}
	
		printf("Desea continuar? SI (s) , NO (n)\n");
		fflush( stdin );
		scanf("%c",&continua);
	}
	return 0;
}


