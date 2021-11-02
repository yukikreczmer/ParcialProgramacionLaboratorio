/*
 * nexo.h
 */

#ifndef NEXO_H_
#define NEXO_H_
#include "Cliente.h"
#include "Pedido.h"
#include "input.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/// @brief Imprime los pedidos en estados pendientes con los datos de cuit, direccion del cliente, y cantidad de kilos a procesar
///
/// @param listaPedidos
/// @param tamPedidos
/// @param listaClientes
/// @param tamClientes
/// @return -1 por error en listas o 0 si esta ok
int ImprimirPedidosPendientes(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes);

/// @brief Imprime un cliente que tenga minimo 1 pedido pendiente y lo imprime junto con la cantidad de pedidos en estados pendientes que tiene
///
/// @param cliente
/// @param listaPedidos
/// @param tamPedidos
/// @param listaLocalidades
/// @param tamLocalidades
void ImprimirClienteConPendientes(eCliente cliente, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades);

/// @brief Imprime todos los clientes que tengan minimo 1 pedido pendiente y lo imprime junto con la cantidad de pedidos en estados pendientes que tiene
///
/// @param listaClientes
/// @param tamCliente
/// @param listaPedidos
/// @param tamPedidos
/// @param listaLocalidades
/// @param tamLocalidades
/// @return -1 por error en listas o 1 si esta ok
int ImprimirClientesConPendientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades);

/// @brief Se imprime un cliente que tenga minimo 1 pedido en estado “Completado” con la información:
/// Cuit del cliente, dirección del cliente, cantidad de kilos reciclados de cada tipo de plástico.
///
/// @param cliente
/// @param listaPedidos
/// @param tamPedidos
void ImprimirClienteConProcesados(eCliente cliente, ePedido listaPedidos[], int tamPedidos);

/// @brief Se imprimirá una lista de los pedidos que se encuentren en estado “Completado” con la información:
/// Cuit del cliente, dirección del cliente, cantidad de kilos reciclados de cada tipo de plástico.
///
/// @param listaClientes
/// @param tamCliente
/// @param listaPedidos
/// @param tamPedidos
/// @return -1 por error en listas o 1 si esta ok
int ImprimirClientesConProcesados(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos);

/// @brief Se ingresa una localidad e indica la cantidad de pedidos pendientes para dicha localidad.
///
///
/// @param listaClientes
/// @param tamCliente
/// @param listaPedidos
/// @param tamPedidos
/// @param listaLocalidades
/// @param tamLocalidades
/// @return -1 por error en listas o 0 si esta ok
int PendientesPorLocalidad(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades);

/// @brief Calcula la cantidad de kilos de polipropileno reciclado promedio por cliente y lo retorna
///
/// @param listaClientes
/// @param tamClientes
/// @param listaPedidos
/// @param tamPedidos
/// @return -1 por error en listas o el promedio de polipropileno reciclado por cliente
float PromedioPPPorCliente(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);

/// @brief Imprime al/los cliente/s con mas pedidos en estado pendiente con sus datos de: ID, Empresa, CUIT, Localidad y Direccion
///
/// @param listaClientes
/// @param tamClientes
/// @param listaLocalidades
/// @param tamLocalidades
/// @return -1 por error en listas o 0 si esta ok
int ImprimirMasPendientesCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades);

/// @brief  Imprime al/los cliente/s con mas pedidos en estado procesado con sus datos de: ID, Empresa, CUIT, Localidad y Direccion
///
/// @param listaClientes
/// @param tamClientes
/// @param listaLocalidades
/// @param tamLocalidades
/// @return -1 por error en listas o 0 si esta ok
int ImprimirMasCompletadosCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades);




#endif /* NEXO_H_ */
