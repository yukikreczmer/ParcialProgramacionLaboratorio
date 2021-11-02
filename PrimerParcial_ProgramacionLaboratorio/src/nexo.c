/*
 * nexo.c
 */
#include "nexo.h"

int ImprimirPedidosPendientes(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes)
{
	int retorno=-1;
	int i;
	int j;

	if((listaPedidos!=NULL &&tamPedidos>0) && (listaClientes!=NULL&&tamClientes>0))
	{
		retorno=0;
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
void ImprimirClienteConPendientes(eCliente cliente, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades)
{
	int i;
	int contadorPendientes=0;
	int posicionLocalidad;
	for(i=0;i<tamPedidos;i++)
	{
		if((listaPedidos[i].IDCliente==cliente.ID)&&(strcmp(listaPedidos[i].estado,PENDIENTE)==0))
		{
			contadorPendientes++;
		}
	}
	posicionLocalidad=eLocalidad_findPositionById(listaLocalidades, tamLocalidades, cliente.IDlocalidad);
	printf("%03d      %-15s %-15s %-20s %-20s %10d \n", cliente.ID, cliente.nombreEmpresa, cliente.cuit, listaLocalidades[posicionLocalidad].descripcion, cliente.direccion, contadorPendientes);
}
int ImprimirClientesConPendientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades)
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
				ImprimirClienteConPendientes(listaClientes[i], listaPedidos, tamPedidos, listaLocalidades, tamLocalidades);
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


int PendientesPorLocalidad(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno=-1;
	int i;
	int j;
	char localidadABuscar [60];
	int IDLocalidadABuscar;
	int contadorPendientesPorLocalidad=0;

	PedirStringPrimeraMayusc("Ingrese la localidad a buscar pedidos pendientes: \n", localidadABuscar);
	if((listaClientes!=NULL && tamCliente>0)&&(listaPedidos!=NULL && tamPedidos>0)&&(listaLocalidades!=NULL && tamLocalidades>0))
	{
		//busca localidad ingresada entre la lista de localidades, devuelve -1 si hay error en las listas, 0 si no hay error pero no encontro la localidad
		//o el Id de la localidad si la encontró
		//De descripcion a ID
		//eLocalidad_BuscarLocalidad
		IDLocalidadABuscar=eLocalidad_BuscarLocalidad(localidadABuscar, listaLocalidades, tamLocalidades);
		if(IDLocalidadABuscar==-1)
		{
			printf("Hubo un error en las listas de localidades\n");
		}
		else if(IDLocalidadABuscar==0)
		{
			printf("No hay clientes registrados de esa localidad\n");
		}
		else //Si el retorno de eLocalidad_BuscarLocalidad no es -1 ni 0, es el ID de la localidad en la listaLocalidades
		{
			for(i=0;i<tamCliente;i++)
			{
				if(listaClientes[i].IDlocalidad==IDLocalidadABuscar)
				{
					for(j=0;j<tamPedidos;j++)
					{
						if((listaPedidos[j].IDCliente==listaClientes[i].ID) && (strcmp(listaPedidos[j].estado,PENDIENTE)==0))
						{
							contadorPendientesPorLocalidad++;
						}
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
int ImprimirMasPendientesCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno=-1;
	int i;
	int banderaPrimero=1;
	int cantidadMasPendientes;

	if((listaClientes!=NULL && tamClientes>0) && (listaLocalidades!=NULL && tamLocalidades>0))
	{
		retorno=0;
		for(i=0;i<tamClientes;i++)
		{
			if(banderaPrimero==1||listaClientes[i].cantidadPendientes>cantidadMasPendientes)
			{
				cantidadMasPendientes=listaClientes[i].cantidadPendientes;
				banderaPrimero=0;
			}
		}
		printf("El/Los cliente/s con mas pedidos pendientes es/son: \n\n"
				"ID:      Empresa:        CUIT:           Localidad:           Direccion:\n\n");
		for(i=0;i<tamClientes;i++)
		{
			if(listaClientes[i].cantidadPendientes==cantidadMasPendientes)
			{
				eCliente_ImprimirCliente(listaClientes[i], listaLocalidades, tamLocalidades);
			}
		}
		printf("Cantidad de pedidos pendientes: %d\n\n",cantidadMasPendientes);
	}

	return retorno;
}
int ImprimirMasCompletadosCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno=-1;
	int i;
	int banderaPrimero=1;
	int cantidadMasCompletados;

	if((listaClientes!=NULL && tamClientes>0) && (listaLocalidades!=NULL && tamLocalidades>0))
	{
		retorno=0;
		for(i=0;i<tamClientes;i++)
		{
			if(banderaPrimero==1||listaClientes[i].cantidadCompletados>cantidadMasCompletados)
			{
				cantidadMasCompletados=listaClientes[i].cantidadCompletados;
				banderaPrimero=0;
			}
		}
		printf("El/Los cliente/s con mas pedidos Completados es/son: \n\n"
				"ID:      Empresa:        CUIT:           Localidad:           Direccion:\n\n");
		for(i=0;i<tamClientes;i++)
		{
			if(listaClientes[i].cantidadCompletados==cantidadMasCompletados)
			{
				eCliente_ImprimirCliente(listaClientes[i], listaLocalidades, tamLocalidades);
			}
		}
		printf("Cantidad de pedidos completados: %d\n\n",cantidadMasCompletados);
	}

	return retorno;
}
