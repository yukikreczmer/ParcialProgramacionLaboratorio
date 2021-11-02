#include "input.h"
#include "Localidad.h"
#include <string.h>
#include <stdio.h>

int eLocalidad_initIsEmpty(eLocalidad listaLocalidades[], int tamLocalidades)
{
	int i;
	int retorno=-1;
	if(tamLocalidades>0 || listaLocalidades!=NULL)
	{
		for(i=0;i<tamLocalidades;i++)
		{
			listaLocalidades[i].isEmpty=1;
		}

		retorno=0;
	}
	return retorno;
}
int eLocalidad_GenerarIdAuto(eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno=-1;
	int i;
	if(listaLocalidades!=NULL&&tamLocalidades>0)
	{
		for(i=0;i<tamLocalidades;i++)
		{
			listaLocalidades[i].IDLocalidad=i+1;
		}
		retorno=0;
	}
	return retorno;
}

//busca localidad ingresada entre la lista de localidades, devuelve -1 si hay error en las listas, 0 si no hay error pero no encontro la localidad
//o el Id de la localidad si la encontró
//De descripcion a ID
int eLocalidad_BuscarLocalidad(char localidadABuscar[], eLocalidad listaLocalidades[],int tamLocalidades)
{
	int retorno=-1;
	int i;
	if(listaLocalidades!=NULL&&tamLocalidades>0)
	{
		retorno=0;
		for(i=0;i<tamLocalidades;i++)
		{
			if(strcmp(listaLocalidades[i].descripcion, localidadABuscar)==0)
			{
				retorno=listaLocalidades[i].IDLocalidad;
			}
		}
	}

	return retorno;
}
//Se le pasa un ID por parametro, lo busca y devuelve la posicion del array donde esta
//devuelve -1 si hay error en lista/tamaño, -2 si no encontró el ID o la posicion en el array donde se encontro al ID
//De ID a Posicion
int eLocalidad_findPositionById(eLocalidad listaLocalidades[], int tamLocalidades,int IDaBuscar)
{
	int retorno=-1;
	int i;
	if(listaLocalidades!=NULL && tamLocalidades>0)
	{
		retorno=-2;
		for(i=0;i<tamLocalidades;i++)
		{
			if(listaLocalidades[i].IDLocalidad == IDaBuscar)
			{
				retorno=i;
			}
		}
	}
	return retorno;
}

//agrega la localidad en el espacio libre de listaLocalidades
//retorna -1 por error en lista o tamaño. 0 si no hay espacio libre. ID de localidad si agrego la localidad a la lista
int eLocalidad_AltaLocalidad(eLocalidad listalocalidades[],int tamLocalidades,char localidadAAgregar[])
{
	int retorno=-1;
	int i;
	if(listalocalidades!=NULL && tamLocalidades>0)
	{
		retorno=0;
		for(i=0;i<tamLocalidades;i++)
		{
			if(listalocalidades[i].isEmpty==1)
			{
				strcpy(listalocalidades[i].descripcion, localidadAAgregar);
				retorno=listalocalidades[i].IDLocalidad;
				listalocalidades[i].isEmpty=0;
				break;
			}
		}
	}

	return retorno;
}




