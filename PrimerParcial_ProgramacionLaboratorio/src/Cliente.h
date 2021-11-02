/*
 * Cliente.h
 *
 *  Created on: 14 oct. 2021
 *      Author: YUKI III THE GREAT
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <stdio.h>
#include "input.h"
#include "Localidad.h"
#include <string.h>

typedef struct
{
	char nombreEmpresa[20];
	char cuit[15];
	char direccion[51];
	int IDlocalidad;
	int ID;
	int isEmpty;
	int cantidadPendientes;
	int cantidadCompletados;
}eCliente;

/// @brief inicializa el campo isEmpty del array de la estructura en 1.
///
/// @param listaClientes
/// @param tamanio listaClientes
/// @return -1 si hay error en la lista o el tamaño no es mayor a 0. retorna 0 si esta todo ok.
int eCliente_initIsEmpty(eCliente listaClientes[], int tam);

/// @brief si el retorno (pasado como parametro) es -1 imprime el mensaje pasado como parametro
///
/// @param retorno a validar
/// @param ErrorMensaje
void ValidarRetorno(int retorno, char ErrorMensaje[]);

/// @brief Asigna en el campo ID de las estructuras de la lista un valor unico comenzando en 1, incrementando en 1 al siguiente.
///
/// @param lista clientes
/// @param len tamanio lista clientes
/// @return -1 si hay error en la lista o el tamaño no es mayor a 0. retorna 0 si esta todo ok.
int eCliente_GenerarIdAuto(eCliente list[], int len);

/// @brief Busca una posicion de la lista de clientes libre (isEmpty=1) y devuelve el ID
///
/// @param listaClientes
/// @param tamanio listaClientes
/// @return -1 si hay error en la lista o el tamaño no es mayor a 0. Retorna el ID de la posicion libre si esta todo ok.
int eCliente_BuscarIdLibre(eCliente listaClientes[], int tam);

/// @brief Ordena la lista de clientes por su ID de manera ascendente (menor a mayor)
///
/// @param list
/// @param len
/// @return -1 si hay error en la lista o tamaño, 0 si esta todo ok.
int eCliente_OrdenarPorID(eCliente list[], int len);

/// @brief ¿hay clientes dados de alta?
///
/// @param list lista clientes
/// @param len tamaño lista clientes
/// @return Retorna -1 por error en lista o tamanio. 0 si no hay clientes dados de alta. 1 si hay clientes dados de alta
int eCliente_HayEnAlta(eCliente list[], int len);//Retorna -1 si no hay hay empleados dados de alta o 1 si hay

/// @brief imprime el cliente pasado como parametro con los datos ID, nombre de empresa, cuit del cliente, localidad y direccion
///
/// @param cliente
/// @param listaLocalidades
/// @param tamLocalidades
void eCliente_ImprimirCliente(eCliente cliente, eLocalidad listaLocalidades[], int tamLocalidades);

/// @brief imprime clientes de la lista de clientes dados de alta con los datos ID, nombre de empresa, cuit del cliente, localidad y direccion
///
/// @param listaClientes
/// @param tamCliente
/// @param listaLocalidades
/// @param tamLocalidades
/// @return -1 por error en listas o 1 si esta ok
int eCliente_ImprimirClientes(eCliente listaClientes[], int tamCliente,  eLocalidad listaLocalidades[], int tamLocalidades);

/// @brief Busca posicion en el array listaClientes donde este el ID pasado por parametro
///
/// @param listaClientes
/// @param tamClientes
/// @param ID
/// @return -1 por error en listas o la posicion del array donde se encuentra el ID
int eCliente_findPositionById(eCliente listaClientes[], int tamClientes,int ID);

/// @brief Se da de alta a un nuevo cliente en la lista de clientes con cada uno de sus datos (Nombre de empresa, CUIT, direccion, localidad)
///
/// @param listaClientes
/// @param tamCliente
/// @param listaLocalidades
/// @param tamLocalidades
/// @return -1 por error en listas o 0 si esta ok
int eCliente_AltaCliente(eCliente listaClientes[], int tamCliente, eLocalidad listaLocalidades[], int tamLocalidades);

/// @brief Se da de baja a un cliente de la lista de clientes
///
/// @param list
/// @param len
/// @param listaLocalidades
/// @param tamLocalidades
/// @return -1 por error en listas o 0 si esta ok
int eCliente_BajaCliente(eCliente list[],int len, eLocalidad listaLocalidades[], int tamLocalidades);

/// @brief Se modifica direccion o localidad de un cliente dado de alta
///
/// @param listaClientes
/// @param tamClientes
/// @param listaLocalidades
/// @param tamLocalidades
/// @return -1 por error en listas o 0 si esta ok
int eCliente_ModificarCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades);

/// @brief Inicia los campos cantidadPendientes y cantidadCompletados de la estructura eCliente, en toda la lista de clientes, en 0
///
/// @param listaClientes
/// @param tamClientes
/// @return -1 por error en listas o 1 si esta ok
int eCliente_IniciarCantidadPedidos(eCliente listaClientes[], int tamClientes);


















#endif /* CLIENTE_H_ */
