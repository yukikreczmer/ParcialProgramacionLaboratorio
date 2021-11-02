/*
 * Pedido.c
 *
 *  Created on: 15 oct. 2021
 *      Author: YUKI III THE GREAT
 */
#include "Pedido.h"
#include <stdio.h>
#include <string.h>
#include"input.h"

int ePedido_initIsEmpty(ePedido lista[], int tam)
{
	int i;
	int retorno=-1;
	if(tam>0 || lista!=NULL)
	{
		for(i=0;i<tam;i++)
		{
			lista[i].isEmpty=1;
		}

		retorno=0;
	}
	return retorno;
}
int ePedido_BuscarIdLibre(ePedido listaPedidos[], int tam)
{
	int retorno=-1;
	int i;
	if(listaPedidos!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaPedidos[i].isEmpty==1)
			{
				retorno=listaPedidos[i].IDPedido;
				break;
			}
		}
	}
	return retorno;
}

int ePedido_GenerarIdAuto(ePedido list[], int len)
{
	int retorno=-1;
	int i;
	if(list!=NULL&&len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].IDPedido=i+1;
		}
		retorno=0;
	}
	return retorno;
}

int ePedido_HayPendientes(ePedido list[], int len)//Retorna -1 si no hay pedidos pendientes o 1 si hay
{
	int retorno=-1;
	int i;
	if(list!=NULL&&len>0)
	{
		for(i=0;i<len;i++)
		{
			if(strcmp(list[i].estado,PENDIENTE)==0)
			{
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}
int ePedido_HayProcesados(ePedido list[], int len)//Retorna -1 si no hay pedidos procesados/completados o 1 si hay
{
	int retorno=-1;
	int i;
	if(list!=NULL&&len>0)
	{
		for(i=0;i<len;i++)
		{
			if(strcmp(list[i].estado,COMPLETADO)==0)
			{
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}
//ID Cliente:	ID Pedido:		Kilos Totales:		Estado de pedido:	Cantidad de Polietileno de alta:	Cantidad de polietileno de baja:	Cantidad de Polipropileno:
void ePedido_MostrarPedidoEntero(ePedido pedido)
{
	printf("%03d      %04d     %.2f      %s      %15.2f     %8.2f    %8.2f\n",pedido.IDCliente, pedido.IDPedido, pedido.kilosTotales, pedido.estado, pedido.cantidadPolietilenoAlta, pedido.cantidadPolietilenoBaja, pedido.cantidadPolipropileno);
}
void ePedido_MostrarPedidoCompletado(ePedido pedido)
{
	printf("%03d 10%04d %.2f %s\n",pedido.IDCliente, pedido.IDPedido, pedido.kilosTotales, pedido.estado);
}
int ePedido_OrdenarPorID(ePedido listaPedidos[], int tamPedidos)
{
	int retorno=-1;
	int i;
	int j;
	ePedido aux;
	if(listaPedidos!=NULL && tamPedidos>0)
	{
		for(i=0;i<tamPedidos;i++)
		{
			for(j=i+1;j<tamPedidos;j++)
			{
				if(listaPedidos[i].IDPedido>listaPedidos[j].IDPedido)
				{
					aux=listaPedidos[i];
					listaPedidos[i]=listaPedidos[j];
					listaPedidos[j]=aux;
				}
			}
		}

		retorno=0;
	}

	return retorno;
}

int ePedido_AltaPedido(ePedido listaPedidos[],int tamPedidos, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno=-1;
	int i;
	int retornoGral;
	int IDCliente;
	int IDPedido=-1;
	int retornoFind;
	int contadorIntentos=0;

	if((listaPedidos!=NULL &&tamPedidos>0) && (listaClientes!=NULL&&tamClientes>0) && (listaLocalidades!=NULL&&tamLocalidades>0))
	{
		retornoGral=ePedido_OrdenarPorID(listaPedidos, tamPedidos);
		ValidarRetorno(retornoGral, "Error en la lista de pedidos.\n");
		for(i=0;i<tamPedidos;i++)
		{
			if(listaPedidos[i].isEmpty==1)
			{
				IDPedido=listaPedidos[i].IDPedido;
				break;
			}
		}
		if(IDPedido!=-1)
		{
			do
				{
					if(contadorIntentos>0)
					{
						printf("Error no se encontro al cliente. \n");
					}
					retornoGral=eCliente_OrdenarPorID(listaClientes, tamClientes);
					ValidarRetorno(retornoGral, "Error en la lista de clientes.\n");

					retornoGral=eCliente_ImprimirClientes(listaClientes, tamClientes, listaLocalidades, tamLocalidades);
					ValidarRetorno(retornoGral, "Error en la lista de clientes.\n");

					IDCliente=PedirOpcionValidandoCaracteres("Ingrese el ID del cliente a realizar el pedido: ", 1, tamClientes, "Error. ");
					retornoFind=eCliente_findPositionById(listaClientes, tamClientes, IDCliente);

					contadorIntentos++;
				}while(retornoFind==-1||listaClientes[retornoFind].isEmpty==1);

			listaPedidos[i].kilosTotales=PedirFlotantePositivoValidandoCaracteres("Ingrese la cantidad de kilos totales a recolectar: \n");
			listaPedidos[i].IDCliente=IDCliente;
			strcpy(listaPedidos[i].estado, PENDIENTE);
			listaPedidos[i].isEmpty=0;
			listaClientes[retornoFind].cantidadPendientes ++;
		}
		else
		{
			printf("No hay lugar libre para realizar un Pedido.\n");
		}


		retorno=0;

	}
	return retorno;
}
int ePedido_findPositionById(ePedido listaPedidos[], int tamPedidos,int ID)
{
	int retorno=-1;
	int i;
	if(listaPedidos!=NULL && tamPedidos>0)
	{
		for(i=0;i<tamPedidos;i++)
		{
			if(listaPedidos[i].IDPedido == ID)
			{
				retorno=i;
			}
		}
	}
	return retorno;
}
int ePedido_ProcesarPedidoPendiente(ePedido listaPedidos[],int tamPedidos, eCliente listaClientes[], int tamClientes)
{
	int retorno=-1;
	int retornoOrdenar;
	int i;
	int j;
	int IDPedidoToProcesar;
	int contadorIntentos=0;
	int indexPedidoToProcesar;
	int indexClienteToProcesar;


	if((listaPedidos!=NULL &&tamPedidos>0)&& (listaClientes!=NULL && tamClientes>0))
	{
		do
		{
			if(contadorIntentos>0)
			{
				printf("Error no se encontro al cliente. \n");
			}
			retornoOrdenar=ePedido_OrdenarPorID(listaPedidos, tamPedidos);
			ValidarRetorno(retornoOrdenar, "Error en la lista de pedidos.\n");
			for(i=0;i<tamPedidos;i++)
			{
				if(strcmp(listaPedidos[i].estado,PENDIENTE)==0)
				{
					for(j=0;j<tamClientes;j++)
					{
						if(listaPedidos[i].IDCliente==listaClientes[j].ID)
						{
							printf("%04d    %-14s  %20s %10.2f\n",listaPedidos[i].IDPedido, listaPedidos[i].estado, listaClientes[j].nombreEmpresa,listaPedidos[i].kilosTotales);
						}
					}
				}
			}
		IDPedidoToProcesar=PedirOpcionValidandoCaracteres("\nIngrese el numero ID del pedido a procesar: ", 1, 1000, "Error. ");
		indexPedidoToProcesar=ePedido_findPositionById(listaPedidos, tamPedidos, IDPedidoToProcesar);

		contadorIntentos++;
		}while(indexPedidoToProcesar==-1|| listaPedidos[indexPedidoToProcesar].isEmpty==1);

		listaPedidos[indexPedidoToProcesar].cantidadPolietilenoAlta=PedirFlotantePositivoValidandoCaracteres("Ingrese la cantidad de kilos de Polietileno de Alta Densidad: \n");
		listaPedidos[indexPedidoToProcesar].cantidadPolietilenoBaja=PedirFlotantePositivoValidandoCaracteres("Ingrese la cantidad de kilos de Polietileno de Baja Densidad: \n");
		listaPedidos[indexPedidoToProcesar].cantidadPolipropileno=PedirFlotantePositivoValidandoCaracteres("Ingrese la cantidad de kilos de Polipropileno: \n");

		strcpy(listaPedidos[indexPedidoToProcesar].estado,COMPLETADO);
		indexClienteToProcesar=eCliente_findPositionById(listaClientes, tamClientes, listaPedidos[indexPedidoToProcesar].IDCliente);
		listaClientes[indexClienteToProcesar].cantidadPendientes--;
		listaClientes[indexClienteToProcesar].cantidadCompletados++;

		retorno=0;
	}
	return retorno;
}
