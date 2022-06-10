#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int parser_PassengerFromText(FILE* pFile ,LinkedList* pArrayListPassenger,LinkedList* pArrayListflight){
	int rtn = -1;
	char auxId[MAX_CHARS];
	char auxNombre[MAX_CHARS];
	char auxApellido[MAX_CHARS];
	char auxPrecio[MAX_CHARS];
	char auxTipoPasajero[MAX_CHARS];
	char auxCodigoVuelo[MAX_CHARS];
	char auxStadoVuelo[MAX_CHARS];
	int cant;
	int auxIdVuelo;
	Passenger* auxPassenger;
	if(pFile != NULL && pArrayListPassenger != NULL && pArrayListflight != NULL){
		while(!feof(pFile)){
			cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajero,auxStadoVuelo);
			auxIdVuelo = Flight_findIdByFlightCode(pArrayListflight,auxCodigoVuelo);
			if(auxIdVuelo >= 0){
				auxPassenger = Passenger_newParametrosTxt(auxId,auxNombre,auxApellido,auxPrecio,auxTipoPasajero,auxIdVuelo);
				ll_add(pArrayListPassenger,auxPassenger);
			}
			if(cant < 7){
				if(feof(pFile)){
					break;
				}
				else{
					rtn = 0;
					break;
				}
			}
		}
		rtn = 1;
	}
    return rtn;
}


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger){
	int rtn = -1;
	int cant;
	Passenger* auxPassenger;
	if(pFile != NULL && pArrayListPassenger != NULL){
		while(!feof(pFile)){
			auxPassenger = Passenger_new();
			cant = fread(auxPassenger,sizeof(Passenger),1,pFile);
			if(auxPassenger != NULL){
				if(Passenger_isValid(auxPassenger)==1){
					ll_add(pArrayListPassenger,auxPassenger);
				}
			}
			if(cant < 1){
				if(feof(pFile)){
					break;
				}
				else{
					rtn = 0;
					break;
				}
			}
		}
		rtn = 1;
	}
	return rtn;
}


int parser_FlightFromText(FILE* pFile, LinkedList* pArrayListFlight){
	int rtn = -1;
	char auxId[MAX_CHARS];
	char auxNombre[MAX_CHARS];
	char auxApellido[MAX_CHARS];
	char auxPrecio[MAX_CHARS];
	char auxTipoPasajero[MAX_CHARS];
	char auxCodigoVuelo[MAX_CHARS];
	char auxStadoVuelo[MAX_CHARS];
	int cant;
	int i;
	int flag = 0;
	Flight* auxFlight;
	Flight* newFlight;
	if(pFile != NULL && pArrayListFlight != NULL){
		while(!feof(pFile)){
			cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajero,auxStadoVuelo);
			i = 0;
			if(flag == 0){
				newFlight = Flight_newParametros(auxCodigoVuelo,auxStadoVuelo);
				ll_add(pArrayListFlight,newFlight);
				flag = 1;
			}
			while(i < ll_len(pArrayListFlight) && flag == 1){
				auxFlight = ll_get(pArrayListFlight,i);
				if(strcmp(auxFlight->flightCode,auxCodigoVuelo)==0){
				flag = 2;
					break;
				}
				i++;
			}
			if(flag == 1){
				newFlight = Flight_newParametros(auxCodigoVuelo,auxStadoVuelo);
				ll_add(pArrayListFlight,newFlight);
			}
			if(flag == 2){
				flag = 1;
			}
			rtn = 1;
			if(cant < 7){
				if(feof(pFile)){
					break;
				}
				else{
					rtn = 0;
					break;
				}
			}
		}
		rtn = 1;
	}
	return rtn;
}
