#include "EntradaYSalida.h"
#include "LinkedList.h"

#ifndef PASSENGER_H_
#define PASSENGER_H_
#define NOMBRE_LEN 50
#define MAX_CHARS 50
#define APELLIDO_LEN 50
#define ID_LEN 10
#define FLIGHT_CODE 50

typedef struct{
	int id;
	char nombre[NOMBRE_LEN];
	char apellido[APELLIDO_LEN];
	float precio;
	int tipoPasajero;
	int idVuelo;
}Passenger;

/// @brief genera un espacio en memoria para un pasajero
/// @return devuelve el puntero a ese espacio
Passenger* Passenger_new();

/// @brief genera un espacio en memoria para un pasajero y le carga los datos
/// @param id del pasajero
/// @param nombreStr del pasajero
/// @param apellidoStr del pasajero
/// @param precio del pasajero
/// @param tipoPasajero del pasajero
/// @param idVuelo del pasajero
/// @return retorna el pasajero cargado
Passenger* Passenger_newParametros(int id,char* nombreStr,char* apellidoStr,float precio,int tipoPasajero,int idVuelo);

/// @brief genera un espacio en memoria para un pasajero y le carga los datos recividos en chars en el formato que corresponda
/// @param idStr del pasajero
/// @param nombreStr del pasajero
/// @param apellidoStr del pasajero
/// @param precioStr del pasajero
/// @param tipoPasajeroStr del pasajero
/// @param idVuelo del pasajero
/// @return retorna el pasajero cargado
Passenger* Passenger_newParametrosTxt(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,int idVuelo);

/// @brief carga el id de un pasajero pasado como texto a int
/// @param this pasajero al cual cargar el dato
/// @param id pasado como texto
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_setIdTxt(Passenger* this,char* id);

/// @brief carga el id de un pasajero desde un char*
/// @param this pasajero del cual sacar lo pedido
/// @param id pasado como texto
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_getIdTxt(Passenger* this,char* id);

/// @brief carga el id en un pasajero
/// @param this pasajero al cual cargar el dato
/// @param id
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_setId(Passenger* this,int id);

/// @brief obtiene el id de un pasjaero
/// @param this pasajero del cual sacar lo pedido
/// @param id
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_getId(Passenger* this,int* id);

/// @brief carga el nombre en un pasajero
/// @param this pasajero al cual cargar el dato
/// @param nombre
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_setNombre(Passenger* this,char* nombre);

/// @brief obtiene el nombre de un pasajero
/// @param this pasajero del cual sacar lo pedido
/// @param nombre
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_getNombre(Passenger* this,char* nombre);

/// @brief carga el apellido en un pasjero
/// @param this pasajero al cual cargar el dato
/// @param apellido
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_setApellido(Passenger* this,char* apellido);

/// @brief obtiene el apellido de un pasajero
/// @param this pasajero del cual sacar lo pedido
/// @param apellido
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_getApellido(Passenger* this,char* apellido);

/// @brief carga el tipo de pasajero en un pasajero desde un char*
/// @param this pasajero al cual cargar el dato
/// @param tipoPasajero
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_setTipoPasajeroTxt(Passenger* this,char* tipoPasajero);

/// @brief obtiene el tipo de pasajero y lo pasa a char
/// @param this pasajero del cual sacar lo pedido
/// @param tipoPasajero
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_getTipoPasajeroTxt(Passenger* this,char* tipoPasajero);

/// @brief carga el tipo de pasajero a un pasajero
/// @param this pasajero al cual cargar el dato
/// @param tipoPasajero
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);

/// @brief obtiene el tipo de pasjaero
/// @param this pasajero del cual sacar lo pedido
/// @param tipoPasajero
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

/// @brief carga el precio en un pasajero desde un char*
/// @param this pasajero al cual cargar el dato
/// @param precio
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_setPrecioTxt(Passenger* this,char* precio);

/// @brief obtiene el precio en texto de un pasajero
/// @param this pasajero del cual sacar lo pedido
/// @param precio
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_getPrecioTxt(Passenger* this,char* precio);

/// @brief carga el precio en un pasajero
/// @param this pasajero al cual cargar el dato
/// @param precio
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_setPrecio(Passenger* this,float precio);

/// @brief obtiene el precio de un pasajero
/// @param this pasajero del cual sacar lo pedido
/// @param precio
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_getPrecio(Passenger* this,float* precio);

/// @brief carga un id vuelo en un pasajero
/// @param this pasajero al cual cargar el dato
/// @param id del vuelo del pasajero
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_setIdVuelo(Passenger* this,int id);

/// @brief devuelve el id del vuelo del pasajero dado
/// @param this pasajero del cual sacar lo pedido
/// @param id del vuelo del pasajero
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_getIdVuelo(Passenger* this,int* id);

/// @brief muestra el pasajero pasado con su codigo de vuelo y estado de vuelo pasados por parametro
/// @param passenger pasajero a mostras
/// @param flightCode codigo de vuelo
/// @param flightStatus estado de vuelo
void Passenger_showPassenger(Passenger* passenger,char flightCode[], char flightStatus[]);

/// @brief busca un pasajero en la linkedlist por su id
/// @param this linkedlist
/// @param id del pasajero a buscar
/// @return el puntero al pasajero buscado
Passenger* Passenger_findPassengerById(LinkedList* this,int id);

/// @brief busca en el archivo .cvs el id mayor guardado
/// @param path archivo .cvs
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_lastId(char* path);

/// @brief genera un id nuevo a apartir del ultimo registrado
/// @return retorna un id nuevo
int Passenger_GenerarId(void);

/// @brief busca el ultimo id
/// @return retorna el valor del ultimo id
int Passenger_GetLastId(void);

/// @brief verifica que el pasajero tenga todos los campos correctos
/// @param this pasajero a analizar
/// @return rertorna 1 si es un pásajero valido y -1 para error
int Passenger_isValid(Passenger* this);

/// @brief remplaza un pasajero con otro
/// @param this pasajero 1 a rempalazar
/// @param this2 pasajero 2 remplazante
/// @return rertorna 1 si salio bien y -1 para error
int Passenger_remplazar(Passenger* this, Passenger* this2);

/// @brief criterio de ordenamiento por id
/// @param this1 pasajero 1 a comparar
/// @param this2 pasajero 2 a comparar
/// @return retorna 1 si es mayo o -1 si es menor y 0 si son iguales
int Passenger_sortById( void* this1, void* this2);

/// @brief criterio de ordenamiento por nombre
/// @param this1 pasajero 1 a comparar
/// @param this2 pasajero 2 a comparar
/// @return retorna 1 si es mayo o -1 si es menor y 0 si son iguales
int Passenger_sortByName( void* this1, void* this2);

/// @brief criterio de ordenamiento por apellido
/// @param this1 pasajero 1 a comparar
/// @param this2 pasajero 2 a comparar
/// @return retorna 1 si es mayo o -1 si es menor y 0 si son iguales
int Passenger_sortByApellido( void* this1, void* this2);

/// @brief criterio de ordenamiento por precio
/// @param this1 pasajero 1 a comparar
/// @param this2 pasajero 2 a comparar
/// @return retorna 1 si es mayo o -1 si es menor y 0 si son iguales
int Passenger_sortByPrice( void* this1, void* this2);

/// @brief criterio de ordenamiento por tipo de pasajero
/// @param this1 pasajero 1 a comparar
/// @param this2 pasajero 2 a comparar
/// @return retorna 1 si es mayo o -1 si es menor y 0 si son iguales
int Passenger_sortByType( void* this1, void* this2);

/// @brief criterio de ordenamiento por vuelo
/// @param this1 pasajero 1 a comparar
/// @param this2 pasajero 2 a comparar
/// @return retorna 1 si es mayo o -1 si es menor y 0 si son iguales
int Passenger_sortByFlight( void* this1, void* this2);

#endif /* PASSENGER_H_ */
