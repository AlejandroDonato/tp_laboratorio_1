#include "parser.h"

//CONTROLER VUELO
/// @brief abre el archivo .csv y se lo pasa al parcer para que lo lea y se cargue en la linkedlist
/// @param path nombre o direccion del archivo a leer
/// @param pArrayListFlight linkedlist de vuelos
/// @return retorna 1 si salio bien y -1 para error
int controller_loadFlightFromText(char* path , LinkedList* pArrayListFlight);

/// @brief lista los buelos de la linkedlist
/// @param pArrayListFlight linkedlist de vuelos
/// @return retorna -1 para error o la cantidad de vuelos que se imprimieron
int controller_ListFlight(LinkedList* pArrayListFlight);

//CONTROLLER PASAJERO
/// @brief abre el archivo .csv y se lo pasa al parcer para que lo lea y se cargue en la linkedlist
/// @param path nombre o direccion del archivo a leer
/// @param pArrayListPassenger linkedlist de pasajeros
/// @param pArrayListFlight linkedlist de vuelos
/// @return retorna 1 si salio bien y -1 para error
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger,LinkedList* pArrayListFlight);

/// @brief abre el archivo .bin y se lo pasa al parcer para que lo lea y se cargue en la linkedlist
/// @param path nombre o direccion del archivo a leer en binario
/// @param pArrayListPassenger linkedlist de pasajeros
/// @return retorna 1 si salio bien y -1 para error
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/// @brief íde los datos al usuario para un pasajero nuevo
/// @param pArrayListPassenger linkedlist de pasajeros
/// @param pArrayListFlight linkedlist de vuelos
/// @return retorna 1 si salio bien y -1 o -2 para errores
int controller_addPassenger(LinkedList* pArrayListPassenger,LinkedList* pArrayListFlight);

/// @brief muestra la lista de pasajeros y pide el id de uno para modificar su informacion
/// @param pArrayListPassenger linkedlist de pasajeros
/// @param pArrayListFlight linkedlist de vuelos
/// @return retorna 1 si salio bien y -1 para error
int controller_editPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlight);

/// @brief muestra la lista y pide un id para elminar
/// @param pArrayListPassenger linkedlist de pasajeros
/// @param pArrayListFlight linkedlist de vuelos
/// @return retorna 1 si salio bien y -1 para error
int controller_removePassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlight);

/// @brief muestra la lista de pasajeros
/// @param pArrayListPassenger linkedlist de pasajeros
/// @param pArrayListFlight linkedlist de vuelos
/// @return retorna -1 para error o la cantidad de pasajeros que se imprimieron
int controller_ListPassenger(LinkedList* pArrayListPassenger,LinkedList* pArrayListFlight);

/// @brief cuenta la cantidad de pasajeros en la linkedlist
/// @param pArrayListPassenger linkedlist de pasajeros
/// @return retorna -1 para error o la cantidad de pasajeros que se contaron
int controller_countPassengers(LinkedList* pArrayListPassenger);

/// @brief muestra las opcions para ordenar la lista
/// @param pArrayListPassenger linkedlist de pasajeros
/// @param order 1 pasa ascendente y 0 para descendente
/// @return retorna 1 si salio bien y -1 para error
int controller_sortPassenger(LinkedList* pArrayListPassenger, int order);

/// @brief lee la linkedlis y guarda cada pasajero como texto en un NewData.csv
/// @param path nombre o direccion del archivo a escribir
/// @param pArrayListPassenger linkedlist de pasajeros
/// @param pArrayListFlight linkedlist de vuelos
/// @return retorna 1 si salio bien y -1 para error y 0 si la linked list esta vacia
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger,LinkedList* pArrayListFlight);

/// @brief lee la linkedlis y guarda cada pasajero como texto en un NewData.bin
/// @param path nombre o direccion del archivo a escribir
/// @param pArrayListPassenger linkedlist de pasajeros
/// @return retorna 1 si salio bien y -1 para error y 0 si la linked list esta vacia
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

// MARCOS PARA LOS MENSAJES
/// @brief pone un mensaje centrado dentro de un marco cabecera
/// @param mensaje dentro del marco
void controller_MensajeCabecera(char mensaje[]);

/// @brief pone un mensaje centrado dentro de un marco de operacion exitosa
/// @param mensaje dentro del marco
void controller_MensajeExitoso(char mensaje[]);

/// @brief pone un mensaje centrado dentro de un marco de error
/// @param mensaje dentro del marco
void controller_MensajeError(char mensaje[]);
