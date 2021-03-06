/*
 * input.h
 *
 *  Created on: 7 sep. 2021
 *      Author: YUKI
 */

#ifndef INPUT_H_
#define INPUT_H_
/// @brief pide un entero al usuario y lo retorna
///
/// @param mensaje para pedir el entero
/// @return entero
int PedirEntero(char[]);

/// @brief valida entero entre m?nimo y m?ximo
///
/// @param numeroIngresado
/// @param minimo
/// @param maximo
/// @param mensaje
/// @return numero v?lido
int ValidarEntero(int numeroIngresado, int minimo , int maximo, char mensaje[]);

/// @brief Pide un string y lo almacena en un char[] pasado como par?metro
///
/// @param Mensaje a mostrar para pedir el string
/// @param Direcci?n de memoria del char[] donde se guardar? el string
void PedirString (char mensaje[], char stringIngresado []);

void PedirStringPrimeraMayusc (char mensaje[], char stringIngresado[]);


/// @brief Pide un string hasta que no se ingresen numeros
///
/// @param mensaje
/// @param stringIngresado
void PedirStringSinDigitos (char mensaje[], char stringIngresado[]);

/// @brief Pide un string numerico hasta que solo se ingresen numeros y lo devuelve por referencia
///
/// @param mensaje
/// @param numeroIngresado
void PedirStringNumerico(char mensaje[], char numeroIngresado[]);


/// @brief Pide un flotante y valida si hay algun caracter ingresado o un - (signo negativo) luego de la primer posici?n. Sino muestra error y vuelve a pedirlo
///
/// @param Mensaje a mostrar para pedir el n?mero
/// @return N?mero flotante validado
float PedirFlotanteValidandoCaracteres(char mensaje[]);

/// @brief Pide un flotante y valida si hay algun caracter ingresado. Sino muestra error y vuelve a pedirlo
///
/// @param Mensaje a mostrar para pedir el n?mero
/// @return N?mero flotante validado
float PedirFlotantePositivoValidandoCaracteres(char mensaje[]);

/// @brief Pide un entero, valida si hay caracteres ingresados, si esta en el rango de m?nimo y m?ximo y lo retorna. Si no cumple muestra mensaje de error
///
/// @param mensaje para que ingrese opci?n
/// @param min
/// @param max
/// @param mensajeError
/// @return numero entero validado
int PedirOpcionValidandoCaracteres (char mensaje[], int min, int max, char mensajeError[]);

/// @brief Pide un entero, valida si hay caracteres ingresados. Incluye n?meros negativos. Sino muestra el mensaje de error. (Sin rango min y max)
///
/// @param mensaje	para que ingrese el numero
/// @param mensajeError
/// @return	numero entero validado
int PedirEnteroValidandoCaracteres (char mensaje[], char mensajeError[]);

/// @brief  Pide hasta que ingrese un entero positivo. Sino muestra mensaje de error.
///
/// @param mensaje para que ingrese el numero
/// @param mensajeError
/// @return entero positivo validado
int PedirEnteroPositivoValidandoCaracteres (char mensaje[], char mensajeError[]);



#endif /* INPUT_H_ */
