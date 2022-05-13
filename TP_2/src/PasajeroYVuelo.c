#include "PasajeroYVuelo.h"

static int P_GenerarId(void);
static int P_GenerarId(void){
	static int contadorP = 1000;
	return contadorP++;
}

int PV_AltaPasajero(ePassengers passengers[],int cantidadPasajeros,eVuelos vuelos[], int cantidadVuelos){
	int rtn;
	int clienteLibre;
	int auxId;
	char auxName[MAX_CHAR];
	char auxLastName[MAX_CHAR];
	float auxPrice;
	int auxtypePassenger;
	int auxIdVuelo;

	if(passengers != NULL && cantidadPasajeros > 0 && vuelos != NULL && cantidadVuelos > 0){
		clienteLibre = P_BuscarEspacioParaPasajeroNuevo(passengers,cantidadPasajeros);
		if(clienteLibre != -1){
			if(GetArrayCharsWithRetrys("Ingrese Nombre:",3,"Nombre invalido,",auxName,MAX_CHAR) == 1){
				if(GetArrayCharsWithRetrys("Ingrese Apellido:",3,"Apellido invalido,",auxLastName,MAX_CHAR) == 1){
					if(getFloatInRange("Ingrese Precio:",3,0,10000000, "Valor invalido,",&auxPrice) == 1){
						if(getIntInRange("Ingrese Tipo:\n\t 1- Primera clase \n\t 2- Ejecutiva \n\t 3- Turista",3,1,3,"Opcion invalida,",&auxtypePassenger) == 1){
							if(V_getIdVueloFromList(vuelos,cantidadVuelos,&auxIdVuelo) == 1 ){
								auxId = P_GenerarId();
								if(P_addPassenger(passengers,clienteLibre,auxId, auxName,auxLastName,auxPrice,auxtypePassenger,auxIdVuelo)==1){
									passengers[clienteLibre].isEmpty = OCUPADO;
									rtn =1;
								}
								else{rtn =-8;//error en la funcion addPassenger
								}
							}
							else{rtn =-7;//error al cargar id del vuelo
							}
						}
						else{rtn =-6;//error al cargar tipo de pasajero
						}
					}
					else{rtn =-5;//error al cargar precio
					}
				}
				else{rtn =-4;//error al cargar apellido
				}
			}
			else{rtn =-3;//error al cargar nombre
			}
		}
		else{rtn =-2;//error al buscar espacio libre
		}
	}
	else{rtn =-1;//error estructura o cantidad nula
	}
return rtn;
}

int PV_modificarPasajero(ePassengers pasajeros[], int cantidadPasajeros, eVuelos vuelos[], int cantidadVuelos){
	int rtn;

	if(pasajeros != NULL && cantidadPasajeros > 0 && vuelos != NULL && cantidadVuelos > 0){
		int auxId;
		char auxName[MAX_CHAR];
		char auxLastName[MAX_CHAR];
		float auxPrice;
		int auxtypePassenger;
		int auxIdVuelo;

		int finalizar;
		int opcion;
		int maxId;
		int pocicion;

		maxId = P_BuscarIdMayor(pasajeros,cantidadPasajeros,OCUPADO);
		PV_MostrarPasajeros(pasajeros,cantidadPasajeros,OCUPADO,vuelos,cantidadVuelos);

		if(getIntInRange("Ingrese una id:",3,0,maxId,"Id invalida,",&auxId)==1){
			pocicion = P_findPassengerById(pasajeros,cantidadPasajeros,auxId);
			puts("Pasajero a Modificar:");
			PV_MostrarPasajero(pasajeros,pocicion,vuelos,cantidadVuelos);
			puts(" ");

			strcpy(auxName,pasajeros[pocicion].name);
			strcpy(auxLastName,pasajeros[pocicion].lastName);
			auxPrice = pasajeros[pocicion].price;
			auxtypePassenger = pasajeros[pocicion].typePassenger;
			auxIdVuelo = pasajeros[pocicion].idVuelo;

			do{
				puts("------Menu de Opciones------");
				printf("\t 1) Modificar nombre \n"
						"\t 2) Modificar apellido \n"
						"\t 3) Modificar precio \n"
						"\t 4) Modificar tipo de pasajero \n"
						"\t 5) Modificar codigo id del vuelo \n"
						"\t 6) Guardar / Salir\n");

				if(getIntInRange("ingrese una opcion:",3,1,6,"Opcion invalida",&opcion) !=1){
					puts("/////Error/////");
					finalizar =1;
				}

				switch(opcion){
				case 1://Modificar Nombre
					puts("/////Modificar Nombre/////");
					if(GetArrayCharsWithRetrys("Ingrese Nombre:",3,"Nombre invalido,",auxName,MAX_CHAR) != 1){
						puts("Error al Modificar Nombre");
					}
					break;
				case 2://Modificar Apellido
					puts("/////Modificar Apellido/////");
					if(GetArrayCharsWithRetrys("Ingrese Apellido:",3,"Apellido invalido,",auxLastName,MAX_CHAR) != 1){
						puts("Error al Modificar Apellido");
					}
					break;
				case 3://Modificar Precio
					puts("/////Modificar Precio/////");
					if(getFloatInRange("Ingrese Precio:",3,0,100000000, "Valor invalido,",&auxPrice) != 1){
						puts("Error al Modificar Precio");
					}
					break;
				case 4://Modificar Tipo de pasajero
					puts("/////Modificar Tipo de pasajero/////");
					if(getIntInRange("Ingrese Tipo:\n\t 1- Primera clase \n\t 2- Ejecutiva \n\t 3- Turista",3,1,3,"Opcion invalida,",&auxtypePassenger) != 1){
						puts("Error al Modificar Tipo de pasajero");
					}
					break;
				case 5://Modificar Codigo de vuelo
					puts("/////Modificar Codigo de vuelo/////");
					if(V_getIdVueloFromList(vuelos,cantidadVuelos,&auxIdVuelo) != 1){
						puts("Error al Modificar id de vuelo");
					}
					break;
				case 6://salir
					if(PedirVerificacion("Desea guardar los cambios?","Opcion invalida")==1){
					P_addPassenger(pasajeros,pocicion, auxId, auxName,auxLastName,auxPrice,auxtypePassenger,auxIdVuelo);
					puts("/////Guardardado exitoso/////");
					}
					finalizar =1;
					rtn = 1;
					puts("/////Saliendo de modificar/////");
					break;
				}

			}while(finalizar!=1);
		}
		else{rtn=-2;//id ingresado incorrecto
		}
	}
	else{rtn=-1;//datos nulos o cantidad 0
	}
	return rtn;
}

int PV_MostrarPasajeros(ePassengers passengers[],int cantidadPasajeros, int estado,eVuelos vuelos[], int cantidadVuelos){
	int contador = -1;
	int flagContador =-1;
	if(passengers != NULL && cantidadPasajeros > 0 && vuelos != NULL && cantidadVuelos > 0){
		contador = 0;
		printf( "|Id   |Apellido            |nombre              |Precio          |Clase          |Codigo de Vuelo|Estado         |\n"
				"|     |                    |                    |                |               |               |               |\n");
		for(int i = 0;i<cantidadPasajeros;i++){
			if(estado == 411 && passengers[i].isEmpty >0){
				PV_MostrarPasajero(passengers,i,vuelos,cantidadVuelos);
				contador++;
				flagContador =1;
			}
			if( passengers[i].isEmpty == estado){
				PV_MostrarPasajero(passengers,i,vuelos,cantidadVuelos);
				contador++;
				flagContador =1;
			}
		}
		if(flagContador == -1){
			printf("No hay pasajeros para mostrar\n");
		}
	}
	return contador;
}

void PV_MostrarPasajero(ePassengers passenger[],int pocicionPasajero,eVuelos vuelos[], int cantidadVuelos){
	char auxTypePassenger[MAX_CHAR];
	char auxFlycode[FLY_CODE];
	char auxEstadoVuelo[MAX_CHAR];
	int i;
	switch (passenger[pocicionPasajero].typePassenger){
	case 1:
		strcpy(auxTypePassenger,"Primera");
		break;
	case 2:
		strcpy(auxTypePassenger,"Ejecutiva");
		break;
	case 3:
		strcpy(auxTypePassenger,"Turista");
		break;
	}
	for (i= 0; i < cantidadVuelos; i++) {
		if(passenger[pocicionPasajero].idVuelo == vuelos[i].id){
			strcpy(auxFlycode,vuelos[i].flycode);
			switch(vuelos[i].statusFlight){
				case 1:
					strcpy(auxEstadoVuelo,"Activo");
					break;
				case 2:
					strcpy(auxEstadoVuelo,"Pendiente");
					break;
				case 3:
					strcpy(auxEstadoVuelo,"inactivo");
					break;
				}
			break;
		}
	}


	printf( "|%-5d|%-20s|%-20s|$%-15.2f|%-15s|%-15s|%-15s|\n",
			passenger[pocicionPasajero].id,
			passenger[pocicionPasajero].lastName,
			passenger[pocicionPasajero].name,
			passenger[pocicionPasajero].price,
			auxTypePassenger,
			auxFlycode,
			auxEstadoVuelo);

}


int PV_BajaDeUnPasajero(ePassengers pasajeros[], int cantidadPasajeros,eVuelos vuelos[], int cantidadVuelos){
	int rtn =-1;
	if(pasajeros != NULL && cantidadPasajeros > 0 && vuelos != NULL && cantidadVuelos > 0){
		int auxId;
		int maxId;
		int pocicion;

		maxId = P_BuscarIdMayor(pasajeros,cantidadPasajeros,OCUPADO);
		PV_MostrarPasajeros(pasajeros,cantidadPasajeros,OCUPADO,vuelos,cantidadVuelos);

		if(getIntInRange("Ingrese una id:",3,0,maxId,"Id invalida,",&auxId)==1){

			pocicion = P_findPassengerById(pasajeros,cantidadPasajeros,auxId);
			puts("Pasagero seleccionado para eliminar:");
			PV_MostrarPasajero(pasajeros,pocicion,vuelos,cantidadVuelos);
			puts(" ");
			if(PedirVerificacion("Desea dar de baja este pasajero?","Opcion invalida")==1){
				pasajeros[pocicion].isEmpty=BAJA;
				puts("/////Baja exitosa exitoso/////");
				rtn =1;
			}
			else{
				puts("/////Baja cancelada/////");
				rtn =0;
			}
		}
	}
	return rtn;
}

int PV_harcodearPasajeros(ePassengers passenger[],int cantidadPasajeros,eVuelos vuelos[], int cantidadVuelos){
	int rtn =-1;
	float precio;
	char nombres[10][MAX_CHAR]={"Jane","Inori","Diane","Lara","Hikaru","Kaouru","Musoki","heckate","Ilyasvel","Tsubaki"};
	char Apellido[10][MAX_CHAR]={"Dark","Kitsune","Tark","Rasputin","Tosaka","Doe","Yusuriha","Wolf","White","Shadow"};

	if(passenger != NULL && cantidadPasajeros > 0){
	for (int i = 0; i < cantidadPasajeros; i++){
		precio=1000 + rand()%10*100;
		passenger[i].isEmpty = 1;
		passenger[i].price=precio;
		passenger[i].typePassenger=rand()%3+1;
		strcpy(passenger[i].name,nombres[rand()%10]);
		strcpy(passenger[i].lastName,Apellido[rand()%10]);
		passenger[i].idVuelo= vuelos[rand()%FLY_CODE].id ;
		passenger[i].id = P_GenerarId();
	}
	rtn = 1;
	}
	return rtn;
}

int PV_sortPassengersByCode(ePassengers passenger[],int cantidadPasajeros,eVuelos vuelos[],int cantidadVuelos, int orden){
	int rtn = -1;
	ePassengers auxPasajero;
	int flagSwap;
	int limite;
	int i;
	V_MostrarVuelos(vuelos,cantidadVuelos,ALL);
	if(passenger != NULL && cantidadPasajeros >= 0 && vuelos != NULL && cantidadVuelos >= 0 && orden > 0){
		limite=cantidadPasajeros-1;
		do{
			flagSwap=0;
			for (i = 0; i < limite; i++){
				if(orden == 1){
					if(passenger[i].idVuelo > passenger[i+1].idVuelo){
						flagSwap=1;
						auxPasajero = passenger[i];
						passenger[i] =	passenger[i+1];
						passenger[i+1] = auxPasajero;
					}
					if(passenger[i].idVuelo == passenger[i+1].idVuelo){
						flagSwap=1;
						if(vuelos[V_findVueloById(vuelos,cantidadVuelos,passenger[i].idVuelo)].statusFlight >
						   vuelos[V_findVueloById(vuelos,cantidadVuelos,passenger[i+1].idVuelo)].statusFlight){
							auxPasajero = passenger[i];
							passenger[i] =	passenger[i+1];
							passenger[i+1] = auxPasajero;
						}
					}
				}
				if(orden == 2){
					if(passenger[i].idVuelo < passenger[i+1].idVuelo){
						flagSwap=1;
						auxPasajero = passenger[i];
						passenger[i] =	passenger[i+1];
						passenger[i+1] = auxPasajero;
					}
					if(passenger[i].idVuelo == passenger[i+1].idVuelo){
						flagSwap=1;
						if(vuelos[V_findVueloById(vuelos,cantidadVuelos,passenger[i].idVuelo)].statusFlight >
						   vuelos[V_findVueloById(vuelos,cantidadVuelos,passenger[i+1].idVuelo)].statusFlight){
							auxPasajero = passenger[i];
							passenger[i] =	passenger[i+1];
							passenger[i+1] = auxPasajero;
						}
					}
				}
			}
			limite--;
		}while(flagSwap);
		rtn = 1;
	}
return rtn;
}

