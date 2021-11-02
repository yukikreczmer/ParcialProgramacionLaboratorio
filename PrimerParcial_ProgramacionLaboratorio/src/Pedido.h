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

/// @brief Inicia la lista de pedidos en isEmpty=1
///
/// @param listaPedidos
/// @param tamPedidos
/// @return -1 por error en listas o 0 si esta ok
int ePedido_initIsEmpty(ePedido lista[], int tam);

/// @brief Busca una posicion de la lista de pedidos que este libre (isEmpty==1) y devuelve el ID
///
/// @param listaPedidos
/// @param tamPedidos
/// @return -1 por error en listas o el ID de la posicion libre
int ePedido_BuscarIdLibre(ePedido listaPedidos[], int tam);

/// @brief Asigna en el campo ID de las estructuras de la lista un valor unico comenzando en 1, incrementando en 1 al siguiente.
///
/// @param listaPedidos
/// @param lenPedidos
/// @return -1 por error en listas o 0 si esta ok
int ePedido_GenerarIdAuto(ePedido list[], int len);

/// @brief ¿Hay pedidos pendientes?
///
/// @param list
/// @param len
/// @return Retorna -1 si no hay pedidos pendientes o 1 si hay
int ePedido_HayPendientes(ePedido list[], int len);

/// @brief ¿Hay pedidos procesados?
///
/// @param list
/// @param len
/// @return Retorna -1 si no hay pedidos procesados/completados o 1 si hay
int ePedido_HayProcesados(ePedido list[], int len);

/// @brief Muestra un pedido con los datos: ID cliente, ID pedido, Kilos totales, estado de pedido y cantidad de cada tipo de plastico
///
/// @param pedido
void ePedido_MostrarPedidoEntero(ePedido pedido);

/// @brief Se da de alta un pedido. Se elige un ID de cliente existente, la cantidad de kilos totales a recolectar y se le genera un nuevo pedido en estado pendiente
///
/// @param listaPedidos
/// @param tamPedidos
/// @param listaClientes
/// @param tamClientes
/// @param listaLocalidades
/// @param tamLocalidades
/// @return -1 por error en listas o 0 si esta ok
int ePedido_AltaPedido(ePedido listaPedidos[],int tamPedidos, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades);

/// @brief Ordena la lista de pedidos por ID de manera ascendente (menor a mayor)
///
/// @param listaPedidos
/// @param tamPedidos
/// @return -1 por error en listas o 0 si esta ok
int ePedido_OrdenarPorID(ePedido listaPedidos[], int tamPedidos);

/// @brief Imprime la lista de pedidos pendientes, se pide elegir el ID de un pedido y se lo procesa, teniendo que completar cantidad de kilos de cada tipo de plastico
///
/// @param listaPedidos
/// @param tamPedidos
/// @param listaClientes
/// @param tamClientes
/// @return -1 por error en listas o 0 si esta ok
int ePedido_ProcesarPedidoPendiente(ePedido listaPedidos[],int tamPedidos, eCliente listaClientes[], int tamClientes);





#endif /* PEDIDO_H_ */
