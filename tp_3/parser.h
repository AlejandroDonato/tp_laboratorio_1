#include <stdio.h>
#include <stdlib.h>
#include "Passenger.h"
#include "Vuelo.h"

/// @brief lee el archivo .cvs y carga la linked list
/// @param pFile nombre del archivo .cvs
/// @param pArrayListPassenger linkedlist de pasajeros
/// @param pArrayListFlight linkedlist de vuelos
/// @return rertorna 1 si salio bien y -1 para error
int parser_PassengerFromText(FILE* pFile,LinkedList* pArrayListPassenger,LinkedList* pArrayListflight);

/// @brief lee el archivo .bin y carga la linked list
/// @param pFile nombre del archivo .bin
/// @param pArrayListPassenger linkedlist de pasajeros
/// @return rertorna 1 si salio bien y -1 para error
int parser_PassengerFromBinary(FILE* pFile,LinkedList* pArrayListPassenger);

/// @brief lee el archivo .cvs y carga la linked list
/// @param pFile nombre del archivo .cvs
/// @param pArrayListFlight linkedlist de vuelos
/// @return rertorna 1 si salio bien y -1 para error
int parser_FlightFromText(FILE* pFile,LinkedList* pArrayListFlight);
