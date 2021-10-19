/*
 * input.c
 *
 *  Created on: 7 sep. 2021
 *      Author: YUKI
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

int PedirEntero(char mensaje[])
{
	int numeroIngresado;
	printf("%s", mensaje);
	scanf("%d",&numeroIngresado);

	return numeroIngresado;
}

int ValidarEntero(int numeroIngresado, int minimo , int maximo, char mensaje[])
{
	while (numeroIngresado<minimo || numeroIngresado>maximo)
		{
			printf("%s", mensaje);
			scanf("%d",&numeroIngresado);
		}
	return numeroIngresado;
}
void PedirString (char mensaje[], char stringIngresado[])
{
    printf("%s \n", mensaje);
    fflush(stdin);
    scanf("%[^\n]", stringIngresado);
}
void PedirStringPrimeraMayusc (char mensaje[], char stringIngresado[])
{
	char aux[100];
    printf("%s \n", mensaje);
    fflush(stdin);
    scanf("%[^\n]", aux);
    strlwr(aux);
    aux[0]=toupper(aux[0]);
    strcpy(stringIngresado,aux);
}

void PedirStringSinDigitos (char mensaje[], char stringIngresado[])
{
	int retornoDigit;
	int contadorIntentos=0;
	int i;
	char aux[100];
	strcpy(aux,stringIngresado);
	do
	{
		if(contadorIntentos>0)
		{
			printf("Error, no se admiten numeros. ");
		}
		printf("%s \n", mensaje);
		fflush(stdin);
		scanf("%[^\n]", aux);

		for(i=0;i<strlen(aux);i++)
		{
			retornoDigit=isdigit(aux[i]);
			if(retornoDigit==1)
			{
				break;
			}
		}
		contadorIntentos++;
	}while(retornoDigit==1);
	strcpy(stringIngresado,aux);
}

float PedirFlotanteValidandoCaracteres(char mensaje[])
	{

	char numeroIngresado[100];
	int retornoExtension;
	int i;
	int retornoValidacionNumero;
	float numeroIngresadoValidado;
	int contadorIntentos;
	contadorIntentos=0;

	do{
		if(contadorIntentos>0)
		{
			printf("Error. ");
		}
		PedirString(mensaje,numeroIngresado);

		retornoExtension=strlen(numeroIngresado);


		for(i=0;i<retornoExtension;i++)	//recorro el array de caracteres para ver si todos los caracteres son números
		{
			retornoValidacionNumero=isdigit(numeroIngresado[i]);
			if(i==0 && numeroIngresado[i]=='-')	//Si el primer caracter es un - tambien lo tomo como válido
			{
				retornoValidacionNumero=1;
			}
			if(numeroIngresado[i]== '.')	//Si hay un . para indicar la parte flotante tambien lo tomo como válido (incluyendo al inicio: .5 seria 0.5 ;y tambien al final: 5. seria 5.0)
			{
				retornoValidacionNumero=1;
			}
			if(retornoValidacionNumero==0)	//Si encuentra un caso no válido romper el for
			{
				break;
			}
		}
		contadorIntentos++;
		}while(retornoValidacionNumero==0);		//Mientras Un caracter no sea válido pido de nuevo el número

		numeroIngresadoValidado=atof(numeroIngresado);
		return numeroIngresadoValidado;
	}
float PedirFlotantePositivoValidandoCaracteres(char mensaje[])
	{

	char numeroIngresado[100];
	int retornoExtension;
	int i;
	int retornoValidacionNumero;
	float numeroIngresadoValidado;
	int contadorIntentos;
	contadorIntentos=0;

	do{
		if(contadorIntentos>0)
		{
			printf("Error. ");
		}
		PedirString(mensaje,numeroIngresado);

		retornoExtension=strlen(numeroIngresado);


		for(i=0;i<retornoExtension;i++)	//recorro el array de caracteres para ver si todos los caracteres son números
		{
			retornoValidacionNumero=isdigit(numeroIngresado[i]);
			if(numeroIngresado[i]== '.')	//Si hay un . para indicar la parte flotante tambien lo tomo como válido (incluyendo al inicio: .5 seria 0.5 ;y tambien al final: 5. seria 5.0)
			{
				retornoValidacionNumero=1;
			}
			if(retornoValidacionNumero==0)	//Si encuentra un caso no válido romper el for
			{
				break;
			}
		}
		contadorIntentos++;
		}while(retornoValidacionNumero==0);		//Mientras Un caracter no sea válido pido de nuevo el número

		numeroIngresadoValidado=atof(numeroIngresado);
		return numeroIngresadoValidado;
	}

int PedirOpcionValidandoCaracteres (char mensaje[], int min, int max, char mensajeError[])
{
	int opcionValidada;
	char opcionIngresada[100];
	int retornoExtension;
	int i;
	int retornoValidacionNumero; // 1 para válido 0 para no válido
	int contadorIntentos;
	contadorIntentos=0;

	do{
		if(contadorIntentos>0)
		{
			printf("%s", mensajeError);
		}
		PedirString(mensaje,opcionIngresada);

		retornoExtension=strlen(opcionIngresada);

		for(i=0;i<retornoExtension;i++)	//recorro el array de caracteres para ver si todos los caracteres son números
		{
			retornoValidacionNumero=isdigit(opcionIngresada[i]);
			if(opcionIngresada[i]=='-')
			{
				retornoValidacionNumero=1;
			}
			if (retornoValidacionNumero==0)
			{
				break;
			}
		}
		if(retornoValidacionNumero)	//si todos los caracteres son digitos los convierto a entero y valido con max y minimo
		{
			opcionValidada=atoi(opcionIngresada);
			if(opcionValidada<min || opcionValidada>max)
			{
				retornoValidacionNumero=0;
			}
		}

		contadorIntentos++;

		}while(retornoValidacionNumero==0);		//Mientras Un caracter no sea válido pido de nuevo el número

		return opcionValidada;
}

int PedirEnteroPositivoValidandoCaracteres (char mensaje[], char mensajeError[])
{
	int opcionValidada;
	char opcionIngresada[100];
	int retornoExtension;
	int i;
	int retornoValidacionNumero; // 1 para válido 0 para no válido
	int contadorIntentos;
	contadorIntentos=0;

	do{
		if(contadorIntentos>0)
		{
			printf("%s", mensajeError);
		}
		PedirString(mensaje,opcionIngresada);

		retornoExtension=strlen(opcionIngresada);

		for(i=0;i<retornoExtension;i++)	//recorro el array de caracteres para ver si todos los caracteres son números
		{
			retornoValidacionNumero=isdigit(opcionIngresada[i]);
			if (retornoValidacionNumero==0)
			{
				break;
			}
		}
		if(retornoValidacionNumero)	//si todos los caracteres son digitos los convierto a entero
		{
			opcionValidada=atoi(opcionIngresada);
		}

		contadorIntentos++;

		}while(retornoValidacionNumero==0);		//Mientras Un caracter no sea válido pido de nuevo el número

		return opcionValidada;
}
int PedirEnteroValidandoCaracteres (char mensaje[], char mensajeError[])
{
	int opcionValidada;
	char opcionIngresada[100];
	int retornoExtension;
	int i;
	int retornoValidacionNumero; // 1 para válido 0 para no válido
	int contadorIntentos;
	contadorIntentos=0;

	do{
		if(contadorIntentos>0)
		{
			printf("%s", mensajeError);
		}
		PedirString(mensaje,opcionIngresada);

		retornoExtension=strlen(opcionIngresada);

		for(i=0;i<retornoExtension;i++)	//recorro el array de caracteres para ver si todos los caracteres son números
		{
			retornoValidacionNumero=isdigit(opcionIngresada[i]);
			if(opcionIngresada[i]=='-')
			{
				retornoValidacionNumero=1;
			}
			if (retornoValidacionNumero==0)
			{
				break;
			}
		}
		if(retornoValidacionNumero)	//si todos los caracteres son digitos los convierto a entero
		{
			opcionValidada=atoi(opcionIngresada);
		}

		contadorIntentos++;

		}while(retornoValidacionNumero==0);		//Mientras Un caracter no sea válido pido de nuevo el número

		return opcionValidada;
}

//---------FUNCIONES DE CALCULADORA---------
float SumarDosNumeros(float primerNumero, float segundoNumero)
{
	float resultado;
	resultado=primerNumero+segundoNumero;
	return resultado;
}

float RestarDosNumeros(float primeroNumero, float segundoNumero)
{
	float resultado;
	resultado=primeroNumero-segundoNumero;
	return resultado;
}
int DividirDosNumeros(float primerOperando, float segundoOperando, float* refResultado)
{
	int hayCero;
	hayCero=1;// 1 = verdadero = el segundo operando es 0
	if(segundoOperando!=0)
	{
		*refResultado=primerOperando/segundoOperando;
		hayCero=0;
	}

	return hayCero;
}
float MultiplicarDosNumeros(float primerOperando, float segundoOperando)
{
	float resultado;
	resultado=primerOperando*segundoOperando;
	return resultado;
}
int FactorearNumero(float numeroIngresado,int* refResultado)
{
	int retornoValidacionNegativoOFlotante=1; //verdadero, solo lo cambio si compruebo que el numero ingresado es positivo y entero, preguntando una vez
	int auxiliarFactoreo;
	int numeroFactorial=1;
	int i;

	auxiliarFactoreo=numeroIngresado;
	if(numeroIngresado>0 && numeroIngresado-auxiliarFactoreo==0)
	{
		retornoValidacionNegativoOFlotante=0;
		for(i=auxiliarFactoreo;i>0;i--)
			{
				numeroFactorial=numeroFactorial*i;
			}
		*refResultado=numeroFactorial;
	}
	return retornoValidacionNegativoOFlotante;
}


