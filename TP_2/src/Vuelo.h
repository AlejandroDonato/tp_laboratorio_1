#ifndef VUELO_H_
#define VUELO_H_


#include "EntradaYSalida.h"

#define MAX_CHAR 51
#define FLY_CODE 10
// opcion para mostrar todo en diferentes sircunstancias.
#define ALL 411
//estado de isEmpty:
#define LIBRE 0
#define OCUPADO 1
#define BAJA 2
//estado de los vuelos:
#define ACTIVO 1
#define PENDIENTE 2
#define INACTIVO 3

typedef struct{
	int id;
	char flycode[FLY_CODE];
	int statusFlight;
	int isEmpty;
}eVuelos;

/// @brief harcodea la lista de vuelos
/// @param Vuelo - estructura vuelos
/// @param cantidadVuelos - cantidad de vuelos que posee la estructura
/// @return rotorna 1 si salio bien y -1 para error
int V_harcodearVuelos(eVuelos Vuelo[],int cantidadVuelos);

/// @brief inicializa los vuelos en el estado deceado (isEmpty)
/// @param Vuelo - estructura vuelos
/// @param cantidadVuelos - cantidad de vuelos que posee la estructura
/// @param estado - estado para inicilaizar los vuelos (0 libre/1 ocupado/2 baja)
/// @return rotorna 1 si salio bien y -1 para error
int V_InicializarVuelos(eVuelos Vuelo[],int cantidadVuelos,int estado);

/// @brief muestra la lista de vuelos de un estado determinado
/// @param vuelos - estructura vuelos
/// @param cantidad - cantidad de vuelos que posee la estructura
/// @param estado- estado para mostrar los vuelos (0 libre/1 ocupado/2 baja)
/// @return rotorna la cantidad de vuelos mostrados si salio bien y -1 para error
int V_MostrarVuelos(eVuelos vuelos[],int cantidad, int estado);

/// @brief muestra yb vuelo determinado
/// @param Vuelo - estructura vuelos
/// @param pocicion - pucicion del vuelo que se quiere mostrar
void V_MostrarVuelo(eVuelos Vuelo[],int pocicion);

/// @brief nusca un espacio libre para cargar un vuelo
/// @param vuelos - estructura vuelos
/// @param cantidad - cantidad de vuelos que posee la estructura
/// @return rotorna la pocicion vacia / 0  si no encuentra espacio  -1 y -2 para errores
int V_BuscarEspacioParaVueloNuevo(eVuelos vuelos[],int cantidad);

/// @brief pide los datos y da de alta un vuelo
/// @param vuelos - estructura vuelos
/// @param cantidad - cantidad de vuelos que posee la estructura
/// @return rotorna 1 si salio bien y -1 /-2 /-3 /-4 /-5 para errores
int V_AltaVuelo(eVuelos vuelos[],int cantidad);

/// @brief carga los datos de un vuelo en un espacio determinado
/// @param list - estructura vuelos
/// @param len - pocicion en la que se desea cargar los datos del vuelo
/// @param id - id del vuelo a cargar
/// @param flycode - codigo de vuelo a cargar
/// @param estadoVuelo - estado del vuelo a cargar (1 activo/2 pendiente/3 inactivo)
/// @return rotorna 1 si salio bien y -1 para error
int V_addVuelo(eVuelos list[], int len, int id, char flycode[],int estadoVuelo);

/// @brief muestra la lista y pide seleccionar un id para modificar un vuelo
/// @param Vuelos - estructura vuelos en dererminada pocicion
/// @param cantidad - cantidad de vuelos que posee la estructura
/// @return rotorna 1 si salio bien y -1/-2 para errores
int V_modificarVuelo(eVuelos Vuelos[], int cantidad);

/// @brief busca la pocicion de un vuelo mediante su id
/// @param list - estructura vuelos
/// @param len - cantidad de vuelos que posee la estructura
/// @param id - id del vuelo a buscar pocicion
/// @return rotorna el id si salio bien y -1 para error
int V_findVueloById(eVuelos list[], int len,int id);

/// @brief cuenta la cantidad de vuelos en un determinado estado
/// @param vuelos - estructura vuelos
/// @param cantidad - cantidad de vuelos que posee la estructura
/// @param estado - estado para mostrar los vuelos (0 libre/1 ocupado/2 baja/411 todos)
/// @return rotorna la cantidad de contada si salio bien y -1 para error
int V_contarVuelos(eVuelos vuelos[],int cantidad, int estado);

/// @brief busca el id mayor de un determinado estado de vuelos
/// @param Vuelos - estructura vuelos
/// @param cantidad - cantidad de vuelos que posee la estructura
/// @param estado - estado para buscar id de los vuelos mayores (0 libre/1 ocupado/2 baja/411 todos)
/// @return rotorna eñ id mayor si salio bien y -1 para errores
int V_BuscarIdMayor(eVuelos Vuelos[],int cantidad, int estado);

/// @brief muestra la lista de vuelos y pide seleccionar un id
/// @param vuelos - estructura vuelos
/// @param cantidad - cantidad de vuelos que posee la estructura
/// @param idVuelo - puntero donde devuelve el id seleccionado
/// @return rotorna 1 si salio bien y -1 para errores
int V_getIdVueloFromList(eVuelos vuelos[],int cantidad,int *idVuelo);


#endif /* VUELO_H_ */
