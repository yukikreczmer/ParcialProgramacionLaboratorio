/*
 * Cliente.c
 */
#include <stdio.h>
#include "Cliente.h"
#include "input.h"
#include "Localidad.h"

int eCliente_initIsEmpty(eCliente listaClientes[], int tam)
{
	int i;
	int retorno=-1;
	if(tam>0 || listaClientes!=NULL)
	{
		for(i=0;i<tam;i++)
		{
			listaClientes[i].isEmpty=1;
		}

		retorno=0;
	}
	return retorno;
}
int eCliente_BuscarIdLibre(eCliente listaClientes[], int tam)
{
	int retorno=-1;
	int i;
	if(listaClientes!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaClientes[i].isEmpty==1)
			{
				retorno=listaClientes[i].ID;
				break;
			}
		}
	}
	return retorno;
}
int eCliente_GenerarIdAuto(eCliente list[], int len)
{
	int retorno=-1;
	int i;
	if(list!=NULL&&len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].ID=i+1;
		}
		retorno=0;
	}
	return retorno;
}
void ValidarRetorno(int retorno, char ErrorMensaje[])
{
	if(retorno==-1)
	{
		printf("%s",ErrorMensaje);
	}
}
int eCliente_HayEnAlta(eCliente list[], int len)//Retorna -1 si no hay hay clientes dados de alta o 1 si hay
{
	int retorno=-1;
	int i;
	if(list!=NULL&&len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==0)
			{
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}
void eCliente_ImprimirCliente(eCliente cliente, eLocalidad listaLocalidades[], int tamLocalidades)
{
	int i;
	for(i=0;i<tamLocalidades;i++)
	{
		if(cliente.ID==listaLocalidades[i].IdCliente)
		{
			printf("%03d      %-15s %-15s %-20s %-20s\n", cliente.ID, cliente.nombreEmpresa, cliente.cuit, listaLocalidades[i].Localidad, cliente.direccion);
		}
	}
}
int eCliente_ImprimirClientes(eCliente listaClientes[], int tamCliente, eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno=-1;
	int i;
	if(listaClientes!=NULL && tamCliente>0)
	{
		printf("ID:      Empresa:        CUIT:           Localidad:           Direccion:\n\n");
		for(i=0;i<tamCliente;i++)
		{
			if(listaClientes[i].isEmpty==0)
			{
				eCliente_ImprimirCliente(listaClientes[i], listaLocalidades, tamLocalidades);
			}
		}
		retorno=1;
	}
	return retorno;
}


int eCliente_AltaCliente(eCliente listaClientes[], int tamCliente, eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno=-1;
	int i;
	int indexLocalidad;

	if(listaClientes!=NULL && tamCliente>0)
	{
		for(i=0;i<tamCliente;i++)
		{
			if(listaClientes[i].isEmpty==1)
			{
				PedirString("Ingrese Nombre de la empresa: ", listaClientes[i].nombreEmpresa);
				PedirString("\nIngrese su CUIT: ", listaClientes[i].cuit);
				indexLocalidad=eLocalidad_BuscarIdLibre(listaLocalidades, tamLocalidades);
				if(indexLocalidad!=-1)
				{
					listaLocalidades[indexLocalidad].IdCliente=listaClientes[i].ID;
					listaLocalidades[indexLocalidad].isEmpty=0;
					PedirStringPrimeraMayusc("\nIngrese su localidad: ", listaLocalidades[indexLocalidad].Localidad);
				}
				PedirString("\nIngrese la direccion: ", listaClientes[i].direccion);
				listaClientes[i].isEmpty=0;
				printf("\nSe dio de alta a un cliente. Su numero ID es: %03d\n\n", listaClientes[i].ID);
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}
int eCliente_ModificarCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno=-1;
	int retornoOrdenarPorID;
	int retornoPrint;
	int IdToModificar;
	int retornoFindEmployee;
	int opcionAModificar;
	int contadorIntentos=0;
	int i;

	if(listaClientes!=NULL && tamClientes>0)
	{
		do
		{
			if(contadorIntentos>0)
			{
				printf("Error no se encontro al cliente. \n");
			}
			retornoOrdenarPorID=eCliente_OrdenarPorID(listaClientes, tamClientes);
			ValidarRetorno(retornoOrdenarPorID, "Error en la lista de clientes.\n");
			retornoPrint=eCliente_ImprimirClientes(listaClientes, tamClientes, listaLocalidades, tamLocalidades);
			ValidarRetorno(retornoPrint, "Error en la lista de clientes.\n");
			IdToModificar=PedirOpcionValidandoCaracteres("Ingrese el ID del cliente a modificar", 1, tamClientes, "Error. ");
			retornoFindEmployee=eCliente_findPositionById(listaClientes, tamClientes, IdToModificar);

			contadorIntentos++;
		}while(retornoFindEmployee==-1|| listaClientes[retornoFindEmployee].isEmpty==1);
		printf(	"1. Direccion\n"
				"2. Localidad\n");

		opcionAModificar=PedirOpcionValidandoCaracteres("Ingrese opcion a modificar: ", 1, 2, "Error. ");
		switch(opcionAModificar)
		{
			case 1:
				PedirString("Ingrese la direccion: ", listaClientes[retornoFindEmployee].direccion);
				break;
			case 2:
				for(i=0;i<tamLocalidades;i++)
				{
					if(IdToModificar==listaLocalidades[i].IdCliente)
					{
						PedirStringPrimeraMayusc("Ingrese la localidad: ", listaLocalidades[i].Localidad);
					}
				}
				break;
				retornoPrint=eCliente_ImprimirClientes(listaClientes, tamClientes, listaLocalidades, tamLocalidades);
				ValidarRetorno(retornoPrint, "Error en la lista de clientes.\n");
		}
		retorno=0;

	}
	return retorno;
}

int eCliente_BajaCliente(eCliente list[],int len, eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno=-1;
	int retornoPrint;
	int retornoOrdenar;
	int idToBaja;
	int retornoRemove;
	int retornoFind;
	int contadorIntentos=0;
	int i;

	if(list!=NULL && len>0)
	{
		do
		{
			if(contadorIntentos>0)
			{
				printf("Error no se encontro al cliente.\n");
			}
		retornoOrdenar=eCliente_OrdenarPorID(list, len);
		ValidarRetorno(retornoOrdenar, "Error en la lista de clientes.\n");
		retornoPrint=eCliente_ImprimirClientes(list, len, listaLocalidades, tamLocalidades);
		ValidarRetorno(retornoPrint, "Error.\n");
		idToBaja=PedirEnteroPositivoValidandoCaracteres("Ingrese el ID del cliente a dar de baja: \n", "Error. ");
		retornoFind=eCliente_findPositionById(list, len, idToBaja);
		contadorIntentos++;
		}while(retornoFind==-1|| list[retornoFind].isEmpty==1);
		printf("¿Desea eliminar al cliente %s?\n",list[retornoFind].nombreEmpresa);
		printf("1. Confirmar\n"
				"2. Cancelar\n");
		retornoRemove=PedirOpcionValidandoCaracteres("", 1, 2, "Escriba 1 para confirmar o 2 para cancelar\n");
		if(retornoRemove==1)
		{
			list[retornoFind].isEmpty=1;
			for(i=0;i<tamLocalidades;i++)
			{
				if(idToBaja==listaLocalidades[i].IdCliente)
				{
					listaLocalidades[i].isEmpty=1;
				}
			}
		}

		retorno=0;
	}
	return retorno;
}

int eCliente_findPositionById(eCliente listaClientes[], int tamClientes,int ID)
{
	int retorno=-1;
	int i;
	if(listaClientes!=NULL && tamClientes>0)
	{
		for(i=0;i<tamClientes;i++)
		{
			if(listaClientes[i].ID == ID)
			{
				retorno=i;
			}
		}
	}
	return retorno;
}

int eCliente_OrdenarPorID(eCliente list[], int len)
{
	int retorno=-1;
	int i;
	int j;
	eCliente aux;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(list[i].ID>list[j].ID)
				{
					aux=list[i];
					list[i]=list[j];
					list[j]=aux;
				}
			}
		}

		retorno=0;
	}
	return retorno;

}

