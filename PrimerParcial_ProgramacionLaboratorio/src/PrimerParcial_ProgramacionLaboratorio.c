/*
 ============================================================================

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "nexo.h"
#define tamClientes 100
#define tamPedidos 1000
#define tamLocalidades 100


int main(void) {
	setbuf(stdout,NULL);
	int opcion;

	eCliente listaClientes[tamClientes];
	ePedido listaPedidos[tamPedidos];
	eLocalidad listaLocalidades[tamLocalidades];

	int retornoInit;
	int retornoGral;
	float ppPromedioPorCliente;

	//	INICIALIZO ARRAYS. ISEMPTY=1; (listaClientes, listaPedidos, listaLocalidades)
	retornoInit=eCliente_initIsEmpty(listaClientes, tamClientes);
	ValidarRetorno(retornoInit, "Error en la lista de clientes.\n");
	retornoInit=ePedido_initIsEmpty(listaPedidos, tamPedidos);
	ValidarRetorno(retornoInit, "Error en la lista de pedidos.\n");
	retornoInit=eLocalidad_initIsEmpty(listaLocalidades, tamLocalidades);
	ValidarRetorno(retornoInit, "Error en la lista de localidades\n");

	//	GENERO ID AUTOMATICAMENTE PARA LOS ARRAYS (listaClientes, listaPedidos, listaLocalidades)
	retornoInit=eCliente_GenerarIdAuto(listaClientes, tamClientes);
	ValidarRetorno(retornoInit,"Error en la lista de clientes.\n");
	retornoInit=ePedido_GenerarIdAuto(listaPedidos, tamPedidos);
	ValidarRetorno(retornoInit,"Error en la lista de pedidos.\n");
	retornoInit=eLocalidad_GenerarIdAuto(listaLocalidades, tamLocalidades);
	ValidarRetorno(retornoInit, "Error en la lista de localidades\n");

	//	INICIALIZO CONTADORES DE PEDIDOS PENDIENTES Y COMPLETADOS PARA CADA CLIENTE
	retornoInit=eCliente_IniciarCantidadPedidos(listaClientes, tamClientes);
	ValidarRetorno(retornoInit, "Error en la lista de clientes\n");



	do
	{
		printf("1. Alta de cliente\n"
				"2. Modificar datos de cliente\n"
				"3. Baja de cliente\n"
				"4. Crear pedido de recoleccion\n"
				"5. Procesar residuos\n"
				"6. Imprimr clientes\n"
				"7. Imprimir pedidos pendientes\n"
				"8. Imprimir pedidos procesados\n"
				"9. Pedidos pendientes por localidad\n"
				"10. Promedio de kilos de polipropileno reciclado por clientes\n"
				"11. Imprimir cliente con mas pedidos pendientes\n"
				"12. Imprimir cliente con mas pedidos completados\n"
				"0. SALIR\n");



		opcion=PedirOpcionValidandoCaracteres("Ingrese una opcion: ", 0, 12, "Error. ");
		switch(opcion)
		{
		case 1:
			retornoGral=eCliente_OrdenarPorID(listaClientes, tamClientes);
			ValidarRetorno(retornoGral, "Error en la lista de Clientes.\n");
			retornoGral=eCliente_AltaCliente(listaClientes, tamClientes, listaLocalidades, tamLocalidades);
			ValidarRetorno(retornoGral, "No hay espacio libre para añadir un nuevo cliente.\n");
			break;
		case 2:
			retornoGral=eCliente_HayEnAlta(listaClientes, tamClientes);
			if(retornoGral==0)
				{
					printf("Primero debe realizar la carga de al menos 1 cliente.\n");
				}
			else
			{
				retornoGral=eCliente_ModificarCliente(listaClientes, tamClientes, listaLocalidades, tamLocalidades);
				ValidarRetorno(retornoGral, "Error en la lista de clientes.\n");
			}
			break;
		case 3:
			if(eCliente_HayEnAlta(listaClientes, tamClientes)==0)
				{
					printf("Primero debe realizar la carga de al menos 1 cliente.\n");
				}
			else
			{
				retornoGral=eCliente_BajaCliente(listaClientes, tamClientes, listaLocalidades, tamLocalidades);
				ValidarRetorno(retornoGral, "Error en la lista de clientes.\n");
			}
			break;
		case 4:
			if(eCliente_HayEnAlta(listaClientes, tamClientes)==0)
				{
					printf("Primero debe realizar la carga de al menos 1 cliente.\n");
				}
			else
			{
				retornoGral=ePedido_AltaPedido(listaPedidos, tamPedidos, listaClientes, tamClientes, listaLocalidades, tamLocalidades);
				ValidarRetorno(retornoGral, "Error en las listas.\n");
			}
			break;
		case 5:
			if(ePedido_HayPendientes(listaPedidos, tamPedidos)==-1)
			{
				printf("No hay pedidos pendientes a procesar.\n");
			}
			else
			{
				retornoGral=ePedido_ProcesarPedidoPendiente(listaPedidos, tamPedidos, listaClientes, tamClientes);
				ValidarRetorno(retornoGral, "Error.\n");
			}

			break;
		case 6:
			if(eCliente_HayEnAlta(listaClientes, tamClientes)==0)
			{
				printf("No hay clientes dados de alta.\n");
			}
			else
			{
				retornoGral=ImprimirClientesConPendientes(listaClientes, tamClientes, listaPedidos, tamPedidos, listaLocalidades, tamLocalidades);
			}
			break;
		case 7:
			retornoGral=ePedido_HayPendientes(listaPedidos, tamPedidos);
			if(retornoGral==-1)
			{
				printf("No hay pedidos pendientes.\n");
			}
			else
			{
				printf("Estado:        CUIT cliente:         Direccion de cliente:       Kilos totales a recolectar:\n\n");
				retornoGral=ImprimirPedidosPendientes(listaPedidos, tamPedidos, listaClientes, tamClientes);
				ValidarRetorno(retornoGral, "Error en las listas\n");
			}
			break;
		case 8:
			retornoGral=ePedido_HayProcesados(listaPedidos, tamPedidos);
			if(retornoGral==-1)
			{
				printf("No hay pedidos procesados.\n");
			}
			else
			{
				retornoGral=ImprimirClientesConProcesados(listaClientes, tamClientes, listaPedidos, tamPedidos);
				ValidarRetorno(retornoGral, "Error en las listas.\n");
			}
			break;
		case 9:
			retornoGral=ePedido_HayPendientes(listaPedidos, tamPedidos);
				if(retornoGral==-1)
				{
					printf("No hay pedidos pendientes.\n");
				}
				else
				{
					retornoGral=PendientesPorLocalidad(listaClientes, tamClientes, listaPedidos, tamPedidos, listaLocalidades, tamLocalidades);
				}
			break;
		case 10:
				if(eCliente_HayEnAlta(listaClientes, tamClientes)==-1)
					{
						printf("No hay clientes dados de alta.\n");
					}
				else
					{
						ppPromedioPorCliente=PromedioPPPorCliente(listaClientes, tamClientes, listaPedidos, tamPedidos);
						if(ppPromedioPorCliente==-1)
						{
							printf("Error en las listas.\n");
						}
						else
						{
							printf("El promedio de Polipropileno por cliente es de %.2f\n",ppPromedioPorCliente);
						}

					}

			break;
		case 11:
			retornoGral=ePedido_HayPendientes(listaPedidos, tamPedidos);
				if(retornoGral==-1)
				{
					printf("No hay pedidos pendientes.\n");
				}
				else
				{
					retornoGral=ImprimirMasPendientesCliente(listaClientes, tamClientes, listaLocalidades, tamLocalidades);
					ValidarRetorno(retornoGral, "Error en las listas de clientes/localidades\n");
				}

			break;
		case 12:
			retornoGral=ePedido_HayProcesados(listaPedidos, tamPedidos);
				if(retornoGral==-1)
				{
					printf("No hay pedidos procesados.\n");
				}
				else
				{
					retornoGral=ImprimirMasCompletadosCliente(listaClientes, tamClientes, listaLocalidades, tamLocalidades);
					ValidarRetorno(retornoGral, "Error en las listas de clientes/localidades\n");
				}
		}



	}while(opcion!=0);

	return EXIT_SUCCESS;
}

