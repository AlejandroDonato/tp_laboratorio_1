#ifndef PASAJEROYVUELO_H_
#define PASAJEROYVUELO_H_

#include "Vuelo.h"
#include "passenger.h"

#define MAX_CHAR 51
#define FLY_CODE 10
#define ALL 411

#define LIBRE 0
#define OCUPADO 1
#define BAJA 2

#define ACTIVO 1
#define PENDIENTE 2
#define INACTIVO 3

/// @brief busca un espacio y pide los datos para cargar un pasajero nuevo
/// @param passengers - estructura pasajeros
/// @param cantidadPasageros - cantidad de pasajeros que puede contener la estructura
/// @param vuelos - estructura cuelos
/// @param cantidadVuelos - cantidad de vuelos que puede contener la estructura
/// @return retorna 1 si salio bien o -1 a -8 para distintos errores
int PV_AltaPasajero(ePassengers passengers[],int cantidadPasageros,eVuelos vuelos[], int cantidadVuelos);

/// @brief muestra la lista de pasajeros, pide seleccionar id de uno para modificar, pregunra y pide los datos
/// @param pasajeros - estructura pasajeros
/// @param cantidadPasajeros - cantidad de pasajeros que puede contener la estructura
/// @param vuelos - estructura cuelos
/// @param cantidadVuelos - cantidad de vuelos que puede contener la estructura
/// @return retorna 1 si salio bien o -1 / -2 para distintos errores
int PV_modificarPasajero(ePassengers pasajeros[], int cantidadPasajeros, eVuelos vuelos[], int cantidadVuelos);

/// @brief muestra los pasajeros segun un estado determinado
/// @param passengers - estructura pasajeros
/// @param cantidadPasajeros - cantidad de pasajeros que puede contener la estructura
/// @param estado - estado que se desa mostrar los pasajeros (0 libre/1 ocupado/2 baja/411 ocupado y baja)
/// @param vuelos - estructura cuelos
/// @param cantidadVuelos - cantidad de vuelos que puede contener la estructura
/// @return retorna la cantidad de pasajeros mostrado si salio bien o -1 para error
int PV_MostrarPasajeros(ePassengers passengers[],int cantidadPasajeros, int estado,eVuelos vuelos[], int cantidadVuelos);

/// @brief muestra un pasajero determinado segun la pocicion dada
/// @param passenger - estructura pasajeros
/// @param pocicionPasajero - pocicion del pasajeros que se desea mostrar
/// @param vuelos - estructura cuelos
/// @param cantidadVuelos - cantidad de vuelos que puede contener la estructura
void PV_MostrarPasajero(ePassengers passenger[],int pocicionPasajero,eVuelos vuelos[], int cantidadVuelos);

/// @brief harcodea los pasajeros
/// @param passenger - estructura pasajeros
/// @param cantidadPasajeros - cantidad de pasajeros que puede contener la estructura
/// @param vuelos - estructura cuelos
/// @param cantidadVuelos - cantidad de vuelos que puede contener la estructura
/// @return retorna 1 si salio bien o -1 para error
int PV_harcodearPasajeros(ePassengers passenger[],int cantidadPasajeros,eVuelos vuelos[], int cantidadVuelos);

/// @brief muesta los pasajeros y se pide un id para dar de baja uno con confirmacion
/// @param pasajeros - estructura pasajeros
/// @param cantidadPasajeros - cantidad de pasajeros que puede contener la estructura
/// @param vuelos - estructura cuelos
/// @param cantidadVuelos - cantidad de vuelos que puede contener la estructura
/// @return retorna 1 si salio bien, 0 si se cancelo y no se guardo o -1 para error
int PV_BajaDeUnPasajero(ePassengers pasajeros[], int cantidadPasajeros,eVuelos vuelos[], int cantidadVuelos);

/// @brief ordena los pasajeros por codigo de vuelo
/// @param passenger - estructura pasajeros
/// @param cantidadPasajeros - cantidad de pasajeros que puede contener la estructura
/// @param vuelos - estructura cuelos
/// @param cantidadVuelos - cantidad de vuelos que puede contener la estructura
/// @param orden - 1 para ascendente  o 2 para descente
/// @return retorna 1 si salio bien o -1 para error
int PV_sortPassengersByCode(ePassengers passenger[],int cantidadPasajeros,eVuelos vuelos[],int cantidadVuelos, int orden);

#endif /* PASAJEROYVUELO_H_ */
