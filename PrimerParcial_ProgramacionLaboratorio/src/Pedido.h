/*
 * Pedido.h
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_
#define PENDIENTE "Pendiente"
#define COMPLETADO "Completado"
#include "Cliente.h"



typedef struct
{
	int IDCliente;
	int IDPedido;
	float kilosTotales;
	char estado[50];
	float cantidadPolietilenoBaja;
	float cantidadPolietilenoAlta;
	float cantidadPolipropileno;
	int isEmpty;
}ePedido;

int ePedido_initIsEmpty(ePedido lista[], int tam);
int ePedido_BuscarIdLibre(ePedido listaPedidos[], int tam);
int ePedido_GenerarIdAuto(ePedido list[], int len);
int ePedido_HayPendientes(ePedido list[], int len);//Retorna -1 si no hay pedidos pendientes o 1 si hay
int ePedido_HayProcesados(ePedido list[], int len);//Retorna -1 si no hay pedidos procesados/completados o 1 si hay
void ePedido_MostrarPedidoEntero(ePedido pedido);
int ePedido_AltaPedido(ePedido listaPedidos[],int tamPedidos, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades);
int ePedido_OrdenarPorID(ePedido listaPedidos[], int tamPedidos);
int ePedido_ProcesarPedidoPendiente(ePedido listaPedidos[],int tamPedidos, eCliente listaClientes[], int tamClientes);





#endif /* PEDIDO_H_ */
