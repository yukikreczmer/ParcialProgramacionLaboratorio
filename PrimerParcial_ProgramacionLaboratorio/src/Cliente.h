/*
 * Cliente.h
 *
 *  Created on: 14 oct. 2021
 *      Author: YUKI III THE GREAT
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "Localidad.h"

typedef struct
{
	char nombreEmpresa[20];
	char cuit[15];
	char direccion[51];
	int ID;
	int isEmpty;
}eCliente;

int eCliente_initIsEmpty(eCliente listaClientes[], int tam);
int eCliente_BuscarIdLibre(eCliente listaClientes[], int tam);
int eCliente_GenerarIdAuto(eCliente list[], int len);
void ValidarRetorno(int retorno, char ErrorMensaje[]);
int eCliente_HayEnAlta(eCliente list[], int len);//Retorna -1 si no hay hay empleados dados de alta o 1 si hay
void eCliente_ImprimirCliente(eCliente cliente, eLocalidad listaLocalidades[], int tamLocalidades);
int eCliente_ImprimirClientes(eCliente listaClientes[], int tamCliente, eLocalidad listaLocalidades[], int tamLocalidades);
int eCliente_OrdenarPorID(eCliente list[], int len);
int eCliente_AltaCliente(eCliente listaClientes[], int tamCliente, eLocalidad listaLocalidades[], int tamLocalidades);
int eCliente_findPositionById(eCliente listaClientes[], int tamClientes,int ID);
int eCliente_ModificarCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades);
int eCliente_BajaCliente(eCliente list[],int len, eLocalidad listaLocalidades[], int tamLocalidades);
















#endif /* CLIENTE_H_ */
