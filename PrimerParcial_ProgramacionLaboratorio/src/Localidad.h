/*
 * Localidad.h
 *
 *  Created on: 19 oct. 2021
 *      Author: YUKI III THE GREAT
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

typedef struct
{
	int IdCliente;
	int IdLocalidad;
	char Localidad[60];
	int cantidadPendientes;
	int isEmpty;

}eLocalidad;

int eLocalidad_GenerarIdAuto(eLocalidad list[], int len);
int eLocalidad_initIsEmpty(eLocalidad listaLocalidades[], int tam);

#endif /* LOCALIDAD_H_ */
