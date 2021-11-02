/*
 * Localidad.h
 *
 *  Created on: 21 oct. 2021
 *      Author: YUKI III THE GREAT
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

typedef struct
{
	int IDLocalidad;
	char descripcion[60];
	int isEmpty;
}eLocalidad;

/// @brief Inicia todas las posiciones del array listaLocalidades en isEmpty=1
///
/// @param listaLocalidades
/// @param tamLocalidades
/// @return -1 si hay error en las listas, 0 si no hay error
int eLocalidad_initIsEmpty(eLocalidad listaLocalidades[], int tamLocalidades);
/// @brief Genera ID Automaticamente comenzando desde el 1 para la posicion 0
///
/// @param listaLocalidades
/// @param tamLocalidades
/// @return
int eLocalidad_GenerarIdAuto(eLocalidad listaLocalidades[], int tamLocalidades);

/// @brief Busca localidad ingresada entre la lista de localidades y retorna su id
///
/// @param localidadABuscar
/// @param listaLocalidades
/// @param tamLocalidades
/// @return -1 si hay error en las listas, 0 si no hay error pero no encontro la localidad, o el Id de la localidad si la encontró(>0)
int eLocalidad_BuscarLocalidad(char localidadABuscar[], eLocalidad listaLocalidades[],int tamLocalidades);

/// @brief Busca la posicion en el array de localidades donde esta el ID
///
/// @param listaLocalidades
/// @param tamLocalidades
/// @param IDaBuscar
/// @return devuelve -1 si hay error en lista/tamaño, -2 si no encontró el ID o la posicion en el array donde se encontro al ID
int eLocalidad_findPositionById(eLocalidad listaLocalidades[], int tamLocalidades,int IDaBuscar);

/// @brief agrega la localidad en el espacio libre de listaLocalidades
///
/// @param listalocalidades
/// @param tamLocalidades
/// @param localidadAAgregar
/// @return -1 por error en lista o tamaño. 0 si no hay espacio libre. ID de localidad si agrego la localidad a la lista
int eLocalidad_AltaLocalidad(eLocalidad listalocalidades[],int tamLocalidades,char localidadAAgregar[]);




#endif /* LOCALIDAD_H_ */
