/*
 * Localidad.c
 *
 *  Created on: 19 oct. 2021
 *      Author: YUKI III THE GREAT
 */

#include "Localidad.h"
#include <stdio.h>

int eLocalidad_GenerarIdAuto(eLocalidad list[], int len)
{
	int retorno=-1;
	int i;
	if(list!=NULL&&len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].IdLocalidad=i+1;
		}
		retorno=0;
	}
	return retorno;
}
int eLocalidad_initIsEmpty(eLocalidad listaLocalidades[], int tam)
{
	int i;
	int retorno=-1;
	if(tam>0 || listaLocalidades!=NULL)
	{
		for(i=0;i<tam;i++)
		{
			listaLocalidades[i].isEmpty=1;
		}

		retorno=0;
	}
	return retorno;
}
int eLocalidad_BuscarIdLibre(eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno=-1;
	int i;
	if(listaLocalidades!=NULL && tamLocalidades>0)
	{
		for(i=0;i<tamLocalidades;i++)
		{
			if(listaLocalidades[i].isEmpty==1)
			{
				retorno=listaLocalidades[i].IdLocalidad;
				break;
			}
		}
	}
	return retorno;
}
