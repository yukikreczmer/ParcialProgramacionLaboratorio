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

void eCliente_MostrarClienteDeAlta(eCliente cliente);
int ImprimirPedidosPendientes(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes);
void ImprimirClienteConPendientes(eCliente cliente, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidad);
int ImprimirClientesConPendientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidad);
void ImprimirClienteConProcesados(eCliente cliente, ePedido listaPedidos[], int tamPedidos);
int ImprimirClientesConProcesados(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos);
int PendientesPorLocalidad(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidad);
float PromedioPPPorCliente(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);



#endif /* NEXO_H_ */
