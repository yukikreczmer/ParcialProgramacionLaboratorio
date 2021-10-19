/*
 * nexo.c
 */
#include "nexo.h"
/*int ImprimirClientesAProcesar(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos)
{
	int retorno=-1;
	int i;
	if(listaClientes!=NULL && tamCliente>0 && listaPedidos!=NULL && tamPedidos>0)
	{
		for(i=0;i<)
	}
	return retorno;
}
*/
int ImprimirPedidosPendientes(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes)
{
	int retorno=-1;
	int i;
	int j;

	if((listaPedidos!=NULL &&tamPedidos>0) && (listaClientes!=NULL&&tamClientes>0))
	{
		for(i=0;i<tamPedidos;i++)
		{
			if(strcmp(listaPedidos[i].estado,PENDIENTE)==0)
			{
				for(j=0;j<tamClientes;j++)
				{
					if(listaPedidos[i].IDCliente==listaClientes[j].ID)
					{
						printf("%-14s %-21s %-23s %15.2f\n",listaPedidos[i].estado, listaClientes[j].cuit, listaClientes[j].direccion, listaPedidos[i].kilosTotales);
					}
				}
			}
		}
	}
	printf("\n");

	return retorno;
}
void ImprimirClienteConPendientes(eCliente cliente, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidad)
{
	int i;
	int contadorPendientes=0;
	for(i=0;i<tamPedidos;i++)
	{
		if((listaPedidos[i].IDCliente==cliente.ID)&&(strcmp(listaPedidos[i].estado,PENDIENTE)==0))
		{
			contadorPendientes++;
		}
	}
	for(i=0;i<tamLocalidad;i++)
	{
		if(cliente.ID==listaLocalidades[i].IdCliente)
		{
			printf("%03d      %-15s %-15s %-20s %-20s %10d \n", cliente.ID, cliente.nombreEmpresa, cliente.cuit, listaLocalidades[i].Localidad, cliente.direccion, contadorPendientes);
		}
	}
}
int ImprimirClientesConPendientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidad)
{
	int retorno=-1;
	int i;
	if(listaClientes!=NULL && tamCliente>0)
	{
		printf("ID:      Empresa:        CUIT:           Localidad:           Direccion:           Cantidad de pedidos pendientes:\n\n");
		for(i=0;i<tamCliente;i++)
		{
			if(listaClientes[i].isEmpty==0)
			{
				ImprimirClienteConPendientes(listaClientes[i], listaPedidos, tamPedidos, listaLocalidades,  tamLocalidad);
			}
		}
		retorno=1;
	}
	return retorno;
}
void ImprimirClienteConProcesados(eCliente cliente, ePedido listaPedidos[], int tamPedidos)
{
	int i;
	for(i=0;i<tamPedidos;i++)
	{
		if((listaPedidos[i].IDCliente==cliente.ID)&&(strcmp(listaPedidos[i].estado,COMPLETADO)==0))
		{
			printf("%03d      %-15s %-20s %-25.2f %-25.2f %-25.2f \n", cliente.ID, cliente.cuit, cliente.direccion, listaPedidos[i].cantidadPolietilenoAlta, listaPedidos[i].cantidadPolietilenoBaja, listaPedidos[i].cantidadPolipropileno);
		}
	}
}
int ImprimirClientesConProcesados(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos)
{
	int retorno=-1;
	int i;
	if(listaClientes!=NULL && tamCliente>0)
	{
		printf("ID:      CUIT:           Direccion:           Cantidad de kilos HDPE:   Cantidad de kilos LDPE:   Cantidad de kilos PP:\n\n");
		for(i=0;i<tamCliente;i++)
		{
			if(listaClientes[i].isEmpty==0)
			{
				ImprimirClienteConProcesados(listaClientes[i], listaPedidos, tamPedidos);
			}
		}
		retorno=1;
	}
	return retorno;
}

int PendientesPorLocalidad(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidad)
{
	int retorno=-1;
	int i;
	int j;
	char localidadABuscar [60];
	int contadorPendientesPorLocalidad=0;

	PedirStringPrimeraMayusc("Ingrese la localidad a buscar pedidos pendientes: \n", localidadABuscar);
	if((listaLocalidades!=NULL && tamLocalidad>0)&&(listaPedidos!=NULL && tamPedidos>0))
	{
		for(i=0;i<tamLocalidad;i++)
		{
			if(strcmp(listaLocalidades[i].Localidad,localidadABuscar)==0)
			{
				for(j=0;j<tamPedidos;j++)
				{
					if((listaLocalidades[i].IdCliente==listaPedidos[j].IDCliente) && (strcmp(listaPedidos[j].estado,PENDIENTE)==0))
					{
						contadorPendientesPorLocalidad++;
					}
				}
			}
		}
		if(contadorPendientesPorLocalidad==0)
		{
			printf("No hay pedidos pendientes para %s\n",localidadABuscar);
		}
		else
		{
			printf("La cantidad de pedidos pendientes para '%s' es de: %d\n",localidadABuscar,contadorPendientesPorLocalidad);
		}
		retorno=0;
	}

	return retorno;
}

float PromedioPPPorCliente(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos)
{
	float retorno=-1;
	int i;
	int contadorClientes=0;
	float acumuladorPP=0;
	float promedioPP;

	if((listaClientes!=NULL && tamClientes>0)&&(listaPedidos!=NULL && tamPedidos>0))
	{
		for(i=0;i<tamClientes;i++)
		{
			if(listaClientes[i].isEmpty==0)
			{
				contadorClientes++;
			}
		}
		for(i=0;i<tamPedidos;i++)
		{
			if(strcmp(listaPedidos[i].estado,COMPLETADO)==0)
			{
				acumuladorPP+=listaPedidos[i].cantidadPolipropileno;
			}
		}
		promedioPP=acumuladorPP/contadorClientes;
		retorno=promedioPP;
	}

	return retorno;
}
