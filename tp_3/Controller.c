#include "Controller.h"

int controller_loadFlightFromText(char* path , LinkedList* pArrayListFlight){
	int rtn = -1;
	FILE* pFile;
	if(pArrayListFlight != NULL && path != NULL){
		pFile = fopen(path,"r");
		if(pFile != NULL && parser_FlightFromText(pFile ,pArrayListFlight) == 1){
			rtn = 1;
		}
	}
	return rtn;
}

int controller_ListFlight(LinkedList* pArrayListFlight){
	int contador = -1;
	int flagContador =-1;
	int i;
	Flight* auxFlight;
	if(pArrayListFlight != NULL){
		contador = 0;
		printf( "+--------+-----------------------+-----------------------+\n"
				"| Id     | Codigo de Vuelo       | Estado de Vuelo       |\n"
				"+--------+-----------------------+-----------------------+\n");
		for(i = 0;i<ll_len(pArrayListFlight);i++){
			auxFlight = ll_get(pArrayListFlight,i);
			if(auxFlight != NULL){
				Flight_showFlight(auxFlight);
				contador++;
				flagContador =1;
			}
		}
		if(flagContador == -1){
			controller_MensajeError("No hay vuelos para mostrar");
		}
	}
	return contador;
}

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, LinkedList* pArrayListflight){
	int rtn = -1;
	FILE* pFile;
	if(pArrayListPassenger != NULL && path != NULL){
		pFile = fopen(path,"r");
		if(pFile != NULL){
			parser_PassengerFromText(pFile ,pArrayListPassenger,pArrayListflight);
			fclose(pFile);
			rtn = 1;
		}
	}
	return rtn;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger){
	int rtn = -1;
	FILE* pFile;
	if(pArrayListPassenger != NULL && path != NULL){
		pFile = fopen(path,"rb");
		if(pFile != NULL){
			parser_PassengerFromBinary(pFile ,pArrayListPassenger);
			fclose(pFile);
			rtn = 1;
		}
	}
	return rtn;
}

int controller_addPassenger(LinkedList* pArrayListPassenger,LinkedList* pArrayListFlight){
	int rtn;
		int auxId;
		char auxName[MAX_CHARS];
		char auxLastName[MAX_CHARS];
		float auxPrice;
		int auxtypePassenger;
		int auxIdVuelo;
		Passenger* auxPassenger;
		int maxIdVuelo;
		int minIdVuelo;

		if(pArrayListPassenger != NULL && pArrayListFlight != NULL){

			if(GetArrayCharsWithRetrys("Ingrese Nombre:",3,"Nombre invalido,",auxName,MAX_CHARS) == 1 &&
				GetArrayCharsWithRetrys("Ingrese Apellido:",3,"Apellido invalido,",auxLastName,MAX_CHARS) == 1 &&
				getFloatInRange("Ingrese Precio:",3,0,10000000, "Valor invalido,",&auxPrice) == 1 &&
				getIntInRange("Ingrese Tipo:\n\t 1- First Class \n\t 2- Executive Class \n\t 3- Economy Class",3,1,3,"Opcion invalida,",&auxtypePassenger) == 1){
				controller_ListFlight(pArrayListFlight);
				maxIdVuelo = Flight_findMaxId(pArrayListFlight);
				minIdVuelo = Flight_findMinId(pArrayListFlight);
				if(getIntInRange("Ingrese el Id del vuelo que desea",3,minIdVuelo,maxIdVuelo,"Opcion invalida,",&auxIdVuelo) == 1){
					auxId = Passenger_GenerarId();//
					auxPassenger = Passenger_newParametros(auxId,auxName,auxLastName,auxPrice,auxtypePassenger,auxIdVuelo);
					ll_add(pArrayListPassenger,auxPassenger);
					rtn =1;
				}
			}
			else{rtn =-2;//error al cargar de datos pedidos
			}
		}
		else{rtn =-1;//error NULL
		}
	return rtn;
}

int controller_editPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlight){
	int rtn = -1;
	int auxId;
	int maxIdP;
	int opcion;
	int finalizar;
	char auxNombre[MAX_CHARS];
	char auxApellido[MAX_CHARS];
	float auxPrecio;
	int auxTipo;
	int minIdVuelo;
	int maxIdVuelo;
	int auxIdVuelo;
	Passenger* auxPassenger;
	Passenger* buferPassenger;
	if(pArrayListPassenger != NULL && pArrayListFlight != NULL){
		controller_ListPassenger(pArrayListPassenger,pArrayListFlight);
		maxIdP = Passenger_GetLastId();
		if(getIntInRange("Ingrese el Id del pasajero que desea modificar",3,1,maxIdP,"Opcion invalida,",&auxId) == 1){
			auxPassenger = Passenger_findPassengerById(pArrayListPassenger,auxId);
			if(auxPassenger != NULL){
				buferPassenger = Passenger_newParametros(auxPassenger->id,auxPassenger->nombre,auxPassenger->apellido,auxPassenger->precio,auxPassenger->tipoPasajero,auxPassenger->idVuelo);
				do{
					puts(	"++------------------------------------------------------++\n"
							"||                         MENU                         ||\n"
							"++------------------------------------------------------++\n"
							"||                                                      ||\n"
			    			"||  ( 1). Modificar nombre                              ||\n"
			    			"||  ( 2). Modificar apellido                            ||\n"
			    			"||  ( 3). Modificar precio                              ||\n"
			    			"||  ( 4). Modificar tipo de pasajero                    ||\n"
			    			"||  ( 5). Modificar vuelo                               ||\n"
			    			"||  ( 6). Guardar / Salir                               ||\n"
							"||                                                      ||\n"
			    			"++------------------------------------------------------++\n");
					if(getIntInRange("ingrese una opcion:",3,1,6,"Opcion invalida",&opcion) !=1){
						controller_MensajeError("Error, agotado el numero de reintentos");
						finalizar =1;
					}
					switch(opcion){
					case 1://Modificar Nombre
						controller_MensajeExitoso("MODIFICAR NOMBRE");
						if(GetArrayCharsWithRetrys("Ingrese Nombre:",3,"Nombre invalido,",auxNombre,MAX_CHARS) == 1){
							Passenger_setNombre(buferPassenger,auxNombre);
						}
						else{controller_MensajeError("Error al Modificar Nombre");
						}
						break;
					case 2://Modificar Apellido
						controller_MensajeExitoso("MODIFICAR APELLIDO");
						if(GetArrayCharsWithRetrys("Ingrese Apellido:",3,"Apellido invalido,",auxApellido,MAX_CHARS) == 1){
							Passenger_setApellido(buferPassenger,auxApellido);
						}
						else{controller_MensajeError("Error al Modificar Apellido");
						}
						break;
					case 3://Modificar Precio
						controller_MensajeExitoso("MODIFICAR PRECIO");
						if(getFloatInRange("Ingrese Precio:",3,0,100000000, "Valor invalido,",&auxPrecio) == 1){
							Passenger_setPrecio(buferPassenger,auxPrecio);
						}
						else{controller_MensajeError("Error al Modificar Precio");
						}
						break;
					case 4://Modificar Tipo de pasajero
						controller_MensajeExitoso("MODIFICAR TIPO DE PASAJERO");
						if(getIntInRange("Ingrese Tipo:\n\t 1- Primera clase \n\t 2- Ejecutiva \n\t 3- Turista",3,1,3,"Opcion invalida,",&auxTipo) == 1){
							Passenger_setTipoPasajero(buferPassenger,auxTipo);
						}
						else{controller_MensajeError("Error al Modificar Tipo de Pasajero");
						}
						break;
					case 5://Modificar vuelo
						controller_MensajeExitoso("MODIFICAR VUELO ");
						controller_ListFlight(pArrayListFlight);
						maxIdVuelo = Flight_findMaxId(pArrayListFlight);
						minIdVuelo = Flight_findMinId(pArrayListFlight);
						if(getIntInRange("Ingrese el Id del vuelo que desea",3,minIdVuelo,maxIdVuelo,"Opcion invalida,",&auxIdVuelo) == 1){
										Passenger_setIdVuelo(buferPassenger,auxIdVuelo);
						}
						else{controller_MensajeError("Error al Modificar Vuelo");
						}
						break;
					case 6://salir
						if(PedirVerificacion("Desea guardar los cambios?","Opcion invalida")==1){
							if(Passenger_remplazar(auxPassenger,buferPassenger)==1){
								finalizar =1;
								rtn = 1;
							}
						}
						break;
					}
				}while(finalizar!=1);
			}
			else{controller_MensajeError("El ID seleccionado no valido");
			}
		}
	}
	return rtn;
}

int controller_removePassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlight){
	int rtn = -1;
	int auxId;
	int maxIdP;
	Passenger* auxPassenger;
	if(pArrayListPassenger != NULL && pArrayListFlight != NULL){
		controller_ListPassenger(pArrayListPassenger,pArrayListFlight);
		maxIdP = Passenger_GetLastId();
		if(getIntInRange("Ingrese el Id del pasajero que desea eliminar",3,1,maxIdP,"Opcion invalida,",&auxId) == 1){
			auxPassenger = Passenger_findPassengerById(pArrayListPassenger,auxId);
			if(auxPassenger != NULL && PedirVerificacion("Desea guardar los cambios?","Opcion invalida")==1){
				if(ll_remove(pArrayListPassenger,ll_indexOf(pArrayListPassenger,auxPassenger))==0){
					free(auxPassenger);
					auxPassenger = NULL;
					rtn = 1;
				}
			}
		}
	}
    return rtn;
}

int controller_ListPassenger(LinkedList* pArrayListPassenger,LinkedList* pArrayListFlight){
	int contador = -1;
	int flagContador =-1;
	Passenger* auxPassenger;
	Flight* auxFlight;
	if(pArrayListPassenger != NULL && pArrayListFlight != NULL){
		contador = 0;
		printf( "+------+---------------------+---------------------+---------------------+---------------------+---------------------+---------------------+\n"
				"| Id   | nombre              | Apellido            | Precio              | Clase               | Codigo de Vuelo     | estado de Vuelo     |\n"
				"+------+---------------------+---------------------+---------------------+---------------------+---------------------+---------------------+\n");
		for(int i = 0;i<ll_len(pArrayListPassenger);i++){
			auxPassenger = ll_get(pArrayListPassenger,i);
			if(auxPassenger != NULL){
				auxFlight = Flight_findFlightbyId(pArrayListFlight, auxPassenger->idVuelo);
				Passenger_showPassenger(auxPassenger,auxFlight->flightCode,auxFlight->statusFlight);
				contador++;
				flagContador =1;
			}
		}
		if(flagContador == -1){
			printf("| No hay pasajeros para mostrar                                                                                                            |\n");
		}
		printf(    "+------+---------------------+---------------------+---------------------+---------------------+---------------------+---------------------+\n");
	}
	return contador;
}

int controller_countPassengers(LinkedList* pArrayListPassenger){
	int contador = -1;
	Passenger* auxPassenger;
	if(pArrayListPassenger != NULL){
		contador = 0;
		for(int i = 0;i<ll_len(pArrayListPassenger);i++){
			auxPassenger = ll_get(pArrayListPassenger,i);
			if(auxPassenger != NULL){
				contador++;
			}
		}
	}
	return contador;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger, int order){
	int sortOption = 0;
	int rtn = -1;
	if(pArrayListPassenger != NULL){
		if(ll_len(pArrayListPassenger) > 0){
			puts(	"++------------------------------------------------------++\n"
					"||                         MENU                         ||\n"
					"++------------------------------------------------------++\n"
					"||                                                      ||\n"
	    			"||  ( 1). Ordenar pasajeros por ID                      ||\n"
	    			"||  ( 2). Ordenar pasajeros por nombre                  ||\n"
	    			"||  ( 3). Ordenar pasajeros por apellido                ||\n"
	    			"||  ( 4). Ordenar pasajeros por precio                  ||\n"
	    			"||  ( 5). Ordenar pasajeros por tipo de pasajero        ||\n"
	    			"||  ( 6). Ordenar pasajeros por vuelo                   ||\n"
					"||                                                      ||\n"
	    			"++------------------------------------------------------++\n");
			if(getIntInRange("Ingrese una opcion:",3,1,6,"Opcion invalida",&sortOption) !=1){
				controller_MensajeError("Error, agotado el numero de reintentos");
				sortOption =10;
			}
			switch(sortOption){
			case 1:
				ll_sort(pArrayListPassenger,Passenger_sortById, order);
				break;
			case 2:
				ll_sort(pArrayListPassenger,Passenger_sortByName, order);
				break;
			case 3:
				ll_sort(pArrayListPassenger,Passenger_sortByApellido, order);
				break;
			case 4:
				ll_sort(pArrayListPassenger,Passenger_sortByPrice, order);
				break;
			case 5:
				ll_sort(pArrayListPassenger,Passenger_sortByType, order);
				break;
			case 6:
				ll_sort(pArrayListPassenger,Passenger_sortByFlight, order);
				break;
			}
			rtn = 1;
		}
	}
	return rtn;
}

int controller_saveAsText(char* path,LinkedList* pArrayListPassenger,LinkedList* pArrayListFlight){
	int rtn = -1;
	FILE* pfile;
	Passenger* auxPassenger;
	Flight* auxFlight;
	int len = -1;
	int i;
	int id;
	char nombre[MAX_CHARS];
	char apellido[MAX_CHARS];
	float precio;
	int tipoPasajero;
	int idVuelo;
	char tipoPasajeroStr[MAX_CHARS];
	if(path != NULL && pArrayListPassenger != NULL){
		len = ll_len(pArrayListPassenger);
		if(len > 0){
			pfile = fopen(path,"w");
			if(pfile!=NULL){
				for(i=0;i<len;i++){
					auxPassenger=(Passenger*)ll_get(pArrayListPassenger,i);
					auxFlight = Flight_findFlightbyId(pArrayListFlight, auxPassenger->idVuelo);
					Passenger_getId(auxPassenger,&id);
					Passenger_getNombre(auxPassenger,nombre);
					Passenger_getApellido(auxPassenger,apellido);
					Passenger_getPrecio(auxPassenger,&precio);
					Passenger_getTipoPasajero(auxPassenger,&tipoPasajero);
					Passenger_getIdVuelo(auxPassenger,&idVuelo);
					switch (auxPassenger->tipoPasajero){
						case 1:
							strcpy(tipoPasajeroStr,"FirstClass");
							break;
						case 2:
							strcpy(tipoPasajeroStr,"ExecutiveClass");
							break;
						case 3:
							strcpy(tipoPasajeroStr,"EconomyClass");
							break;
					}
					fprintf(pfile,"%d,%s,%s,%.0f,%s,%s,%s\n",id,nombre,apellido,precio,auxFlight->flightCode,tipoPasajeroStr,auxFlight->statusFlight);
				}
				fclose(pfile);
				if(i == len){
					rtn = 1;
				}
			}
		}
		else{
			rtn = 0;
		}
	}
	return rtn;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger){
	int rtn = -1;
	FILE* file;
	Passenger* auxPassenger;
	int len;
	int i;
	if(path != NULL && pArrayListPassenger != NULL){
		len = ll_len(pArrayListPassenger);
		if(len > 0){
			file = fopen(path,"wb");
			if(file!=NULL){
				for(i=0;i<len;i++){
					auxPassenger = ll_get(pArrayListPassenger,i);
					if(auxPassenger != NULL){
						fwrite(auxPassenger,sizeof(Passenger),1,file);
					}
				}
				fclose(file);
				if(i == len){
					rtn = 1;
				}
			}
		}
		else{
			rtn = 0;
		}
	}
	return rtn;
}

void controller_MensajeCabecera(char mensaje[]){
	int espace = (48 - strlen(mensaje))/2;
	int i;
	printf(	"+-^-+-^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^-+-^-+\n"
			"|<o>|");
	for (i = 0; i < espace; ++i) {
		printf(" ");
	}
	printf("%s",mensaje);
	for (i = 0; i < espace; ++i) {
		printf(" ");
	}
	printf(														 "|<o>|\n"
			"+---+------------------------------------------------+---+\n");
}

void controller_MensajeExitoso(char mensaje[]){
	int espace = (48 - strlen(mensaje))/2;
	int i;
	printf(	"+---+------------------------------------------------+---+\n"
			"|<o>|");
	for	(i = 0; i < espace; ++i) {
		printf(" ");
	}
	printf("%s",mensaje);
	for (i = 0; i < espace; ++i) {
		printf(" ");
	}
	printf(														 "|<o>|\n"
			"+---+------------------------------------------------+---+\n");
}

void controller_MensajeError(char mensaje[]){
	int espace = (48 - strlen(mensaje))/2;
	int i;
	printf(	"+---+------------------------------------------------+---+\n"
			"|<x>|");
	for	(i = 0; i < espace; ++i) {
		printf(" ");
	}
	printf("%s",mensaje);
	for (i = 0; i < espace; ++i) {
		printf(" ");
	}
	printf(														 "|<x>|\n"
			"+---+------------------------------------------------+---+\n");
}


