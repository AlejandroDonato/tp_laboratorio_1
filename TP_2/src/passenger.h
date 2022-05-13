#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "EntradaYSalida.h"

#define MAX_CHAR 51
#define FLY_CODE 10
#define ALL 411

#define LIBRE 0
#define OCUPADO 1
#define BAJA 2

#define ACTIVO 1
#define PENDIENTE 2
#define INACTIVO 3

typedef struct{
	int id;
	char name[MAX_CHAR];
	char lastName[MAX_CHAR];
	float price;
	int typePassenger;
	int idVuelo;
	int isEmpty;
}ePassengers;

/// @brief inicializa la estructura de ePasajeros
/// @param pasangers - estructura de pasajeros
/// @param cantidad - cantidad de pasajeros maxima
/// @param estado - estado en que se quiere inicializar (0 LIBRE / 1 OCUPADO / 2 BAJA)
/// @return retorna 1 si es correcto o -1 para error
int P_InicializarPasajeros(ePassengers pasangers[],int cantidad, int estado);

/// @brief Busca Espacio Para Pasa jero Nuevo
/// @param passengers - estructura de pasajeros
/// @param cantidad - cantidad de pasajeros maxima
/// @return retorna la ubicacion encontrada libre o -1 para error
int P_BuscarEspacioParaPasajeroNuevo(ePassengers passengers[],int cantidad);

/// @brief Carga un pasajero nuevo en una ubicacion deseada
/// @param list - estructura de pasajeros
/// @param len - pocicion en la estructura donde se desa guardar
/// @param id - el id generado del pasajero a guardar
/// @param name - el nombre del pasajero
/// @param lastName - el apellido del pasajero
/// @param price - el precio del pasaje
/// @param typePassenger - tipo de pasajero (1- Primera clase / 2- Ejecutiva / 3- Turista)
/// @param idVuelo clave foranea para uvicar el vuelo del pasajero dentro de la estructura de vuelo
/// @return retorna 1 si es correcto o -1 para error
int P_addPassenger(ePassengers list[], int index, int id, char name[],char lastName[],float price,int typePassenger,int idVuelo);

/// @brief busca la pocicion de un pasajero mediante su id
/// @param list - estructura de pasajeros
/// @param len - cantidad de pasajeros maxima
/// @param id - id del pasajero que buscamos
/// @return retorna el indice del pasajero buscado o -1 si no encontro nada/error
int P_findPassengerById(ePassengers list[], int len,int id);

/// @brief cuenta la cantidad de pasajeros segun el estado que se desee
/// @param passengers - estructura de pasajeros
/// @param cantidad - cantidad de pasajeros maxima
/// @param estado - estado en que se quiere inicializar (0 LIBRE / 1 OCUPADO / 2 BAJA /411 ocupados y baja)
/// @return retorna la cantidad de pasajeros contados o -1 para error
int P_contarPasajeros(ePassengers passengers[],int cantidad, int estado);

/// @brief calcula y devuelve el precio promedio de todos los pasajes y el precio total
/// @param passengers - estructura de pasajeros
/// @param cantidad - cantidad de pasajeros maxima
/// @param estado - estado en que se quiere calcular (1 OCUPADO / 2 BAJA / 411 ocupado y baja)
/// @param promedio - puntero que devuelve el precio promedio
/// @param total - puntero que devuelve el precio total
/// @return retorna la cantidad de pasajes sumados o -1 para error
int P_PromedioPrecioViajes(ePassengers passengers[],int cantidad, int estado, float *promedio ,float *total);

/// @brief ordena la estructura de pasajeros por apelledio alfaveticamente ascendente o descentende (1/2)
/// @param passengers - estructura de pasajeros
/// @param cantidad - cantidad de pasajeros maxima
/// @param orden - alfaveticamente ascendente o descentende (1/2)
/// @return retorna 1 si es correcto o -1 para error
int P_sortPassengers(ePassengers passengers[],int cantidad, int orden);

/// @brief calcula y muestra el promedio y el precio total de los pasajes y la cantidad de pasajes por ensima del promedio
/// @param passengers - estructura de pasajeros
/// @param cantidad - cantidad de pasajeros maxima
/// @param estado - estado en que se quiere calcular (1 OCUPADO / 2 BAJA / 411 ocupado y baja)
/// @return retorna 1 si es correcto o -1 para error
int P_MostrarPromedioYPreciosDePasajes(ePassengers passengers[],int cantidad, int estado);

/// @brief cuenta cuantos pasajes estan por ensima del promedio
/// @param passengers - estructura de pasajeros
/// @param cantidad - cantidad de pasajeros maxima
/// @param estado - estado en que se quiere calcular (1 OCUPADO / 2 BAJA / 411 ocupado y baja)
/// @param promedioPrecios - precio promedio de los pasajes
/// @return retorna la cantidad de pasajes por ensima del promedio o -1 para erroro
int P_PasajerosSobrePromedio(ePassengers passengers[],int cantidad, int estado, float promedioPrecios);

/// @brief busca el id mayor en la estructura
/// @param passengers - estructura de pasajeros
/// @param cantidad - cantidad de pasajeros maxima
/// @param estado - estado en que se quiere buscar (0 LIBRE / 1 OCUPADO / 2 BAJA / 411 ocupado y baja)
/// @return retorna el id mayor encontrado o -1 para error
int P_BuscarIdMayor(ePassengers passengers[],int cantidad, int estado);

/// @brief prdena la estructura por id
/// @param passengers - estructura de pasajeros
/// @param cantidad - cantidad de pasajeros maxima
/// @return retorna 1 si es correcto o -1 para error
int P_sortPassengersById(ePassengers passengers[],int cantidad);

#endif /* PASSENGER_H_ */
