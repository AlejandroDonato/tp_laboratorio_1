/*
 * EntradaYSalida.h
 *
 *  Created on: 13 abr 2022
 *      Author: kyubi
 */

#ifndef ENTRADAYSALIDA_H_
#define ENTRADAYSALIDA_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/// @brief Pide un numero entero al usuario dentro de un rango y verifica que sea correcto, con x reintentos
/// @param mensaje - mensaje para el usuario solicitandole el numero
/// @param reintentos - cantidad de reintentos
/// @param minimo - valor minimo del rango
/// @param maximo - valor maximo del rango
/// @param mensajeError - mensaje de error
/// @param pNumeroIngresado - retorno por puntero del numero ingresado
/// @return - retorna -1 para error y 1 si fue correcto
int getInt(char mensaje[],int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado);

/// @brief Pide un numero flotante al usuario dentro de un rango y verifica que sea correcto, con x reintentos
/// @param mensaje - mensaje para el usuario solicitandole el numero
/// @param reintentos - cantidad de reintentos
/// @param minimo - valor minimo del rango
/// @param maximo - valor maximo del rango
/// @param mensajeError - mensaje de error
/// @param pNumeroIngresado
/// @return - retorna -1 para error y 1 si fue correcto
int getFloat(char mensaje[],int reintentos, float minimo, float maximo, char mensajeError[], float *pNumeroIngresado);

/// @brief muestra los resultado especificos para este tp (?)
/// @param valor1 - valor que corresponde al Precio Aerolíneas
/// @param valor2 - valor que corresponde al Precio con tarjeta de débito
/// @param valor3 - valor que corresponde al Precio con tarjeta de crédito
/// @param valor4 - valor que corresponde al Precio pagando con bitcoin
/// @param valor5 - valor que corresponde al Precio unitario por kilometro - $/km
void MostrarResultados(float valor1,float valor2,float valor3,float valor4,float valor5);



#endif /* ENTRADAYSALIDA_H_ */
