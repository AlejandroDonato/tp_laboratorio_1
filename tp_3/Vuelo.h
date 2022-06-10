#ifndef VUELO_H_
#define VUELO_H_

#include "EntradaYSalida.h"
#include "LinkedList.h"

#define MAX_CHARS 50
#define ID_LEN 10
#define FLIGHT_CODE 50
// opcion para mostrar todos en diferentes sircunstancias.
#define ALL 411
//estado de los vuelos:
#define ACTIVO 1
#define PENDIENTE 2
#define INACTIVO 3

typedef struct{
	int id;
	char flightCode[FLIGHT_CODE];
	char statusFlight[MAX_CHARS];
}Flight;

/// @brief genera un vielo nuevo sin nada cargado
/// @return retorna el puntero al vuelo
Flight* Flight_new();

/// @brief genera un vuelo nuevo con sus parametros cargados
/// @param codigoStr
/// @param stadoStr
/// @return rtorna el puntero al velo nuevo
Flight* Flight_newParametros(char* codigoStr,char* stadoStr);

/// @brief elimina un vuelo
/// @param vuelo
/// @param len
/// @param index
/// @return retorna el id del vuelo o -1 para error
int Flight_delete(Flight*  vuelo[],int len, int index);

/// @brief carga el id del vuelo desde un char*
/// @param this vuelo
/// @param id
/// @return retorna el id del vuelo o -1 para error
int Flight_setIdTxt(Flight* this,char* id);

/// @brief obtiene el id de vuelo en char*
/// @param this vuelo
/// @param id
/// @return retorna el id del vuelo o -1 para error
int Flight_getIdTxt(Flight* this,char* id);

/// @brief carga el id del vuelo
/// @param this vuelo
/// @param id
/// @return retorna el id del vuelo o -1 para error
int Flight_setId(Flight* this,int id);

/// @brief obtiene el id de vuelo
/// @param this vuelo
/// @param id
/// @return retorna el id del vuelo o -1 para error
int Flight_getId(Flight* this,int* id);

/// @brief carga el codigo del vuelo
/// @param this vuelo
/// @param codigoVuelo
/// @return retorna el id del vuelo o -1 para error
int Flight_setCodigoVuelo(Flight* this,char* codigoVuelo);

/// @brief obtiene el codigo de vuelo
/// @param this vuelo
/// @param codigoVuelo
/// @return retorna el id del vuelo o -1 para error
int Flight_getCodigoVuelo(Flight* this,char* codigoVuelo);

/// @brief carga el estado del vuelo
/// @param this vuelo
/// @param estadoVuelo
/// @return retorna el id del vuelo o -1 para error
int Flight_setEstadoVuelo(Flight* this,char* estadoVuelo);

/// @brief obtiene el estado de vuelo
/// @param this vuelo
/// @param estadoVuelo
/// @return retorna el id del vuelo o -1 para error
int Flight_getEstadoVuelo(Flight* this,char* estadoVuelo);

/// @brief muestra un vuelo
/// @param vuelo
void Flight_showFlight(Flight* this);

/// @brief genera un ide para el vuelo desde un archivo
/// @return retorna el id generado
int Flight_GenerarId(void);

/// @brief busca el id del vuelo por su codigo de vuelo
/// @param this linkedlist
/// @param flightCode
/// @return retorna el id del vuelo o -1 para error
int Flight_findIdByFlightCode(LinkedList* this, char* flightCode);

/// @brief busca un vuelo por su id
/// @param this linkedlist
/// @param id
/// @return retorna el puntero al vuelo o -1 para error
Flight* Flight_findFlightbyId(LinkedList* this, int id);

/// @brief busca el id maximo de los vuelos
/// @param this linkedlist
/// @return retorna el id maximo
int Flight_findMaxId(LinkedList* this);

/// @brief busca el id minimo de los vuelos
/// @param this linkedlist
/// @return retorna el id minimo
int Flight_findMinId(LinkedList* this);

/// @brief comprueva si el vuelo esta cargado en la lista
/// @param auxVuelos
/// @param codigoVuelo
/// @return rertorna 1 si salio bien y -1 para vuelo repetido
int Flight_flightRepetido(Flight *auxVuelos[],char codigoVuelo[]);

#endif /* VUELO_H_ */
