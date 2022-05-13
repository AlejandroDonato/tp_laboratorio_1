#include "passenger.h"


int P_InicializarPasajeros(ePassengers passenger[],int cantidad,int estado){
	int rtn =-1;
	if(passenger != NULL && cantidad > 0){
	for (int i = 0; i < cantidad; i++){
		passenger[i].isEmpty = estado;
	}
	rtn = 1;
	}
	return rtn;
}


int P_BuscarEspacioParaPasajeroNuevo(ePassengers passengers[],int cantidad){
	int rtn;
	int flag = 0;
	if(passengers != NULL){
		if(cantidad > 0){
			for(int i = 0;i<cantidad;i++){
				if( passengers[i].isEmpty == LIBRE){
					rtn = i;
					flag = 1;
					break;
				}
			}
			if(flag == 0){rtn = -3;//sin espacio en la lista
			}
		}
		else{rtn =-2;//cantidad != de 0
		}
	}
	else{rtn=-1;//array nulo
	}
return rtn;
}

int P_addPassenger(ePassengers list[], int index, int id, char name[],char lastName[],float price,int typePassenger,int idVuelo){
	int rtn;
	if(list != NULL && index > -1){
		list[index].id = id;
		strcpy(list[index].name,name);
		strcpy(list[index].lastName,lastName);
		list[index].price = price;
		list[index].typePassenger = typePassenger;
		list[index].idVuelo=idVuelo;
		rtn = 1;
	}
	else{rtn = -1;
	}
return rtn;
}

int P_findPassengerById(ePassengers list[], int len,int id){
int rtn = -1;
for(int i = 0;i < len; i++){
	if(list[i].id == id){
		rtn = i;
		break;
	}
}
return rtn;
}


int P_contarPasajeros(ePassengers passengers[],int cantidad, int estado){
	int contador = -1;
	if(passengers != NULL && cantidad >0){
	contador = 0;
	for(int i = 0;i<cantidad;i++){
		if(estado == 411 && passengers[i].isEmpty >0){
			contador++;
		}
		if( passengers[i].isEmpty == estado){
			contador++;
		}
	}
	}
	return contador;
}

int P_PromedioPrecioViajes(ePassengers passengers[],int cantidad, int estado, float *promedio,float *total){
	int rtn =-1;
	int contador;
	float sumador;
	if(passengers!= NULL && cantidad>0 && promedio != NULL && total != NULL){
		contador =0;
		sumador =0;
		for (int i = 0; i < cantidad; ++i) {
			if(estado == 411){
				sumador += passengers[i].price;
				contador++;
			}
			if(passengers[i].isEmpty == estado){
				sumador += passengers[i].price;
				contador++;
			}
		}
		*promedio=sumador/contador;
		*total=sumador;
		rtn = contador;
	}
	return rtn;
}

int P_sortPassengers(ePassengers passengers[],int cantidad, int orden){
	int rtn = -1;
	ePassengers auxPassenger;
	int flagSwap;
	int limite;
	int i;

	if(passengers != NULL && cantidad >= 0 && orden > 0){
		limite = cantidad-1;
		do{
			flagSwap=0;
			for (i = 0; i < limite; i++){
				if(orden == 1){
					if(strcmp(passengers[i].lastName , passengers[i+1].lastName)>0){
						flagSwap=1;
						auxPassenger = passengers[i];
						passengers[i] =	passengers[i+1];
						passengers[i+1] = auxPassenger;
					}
					if(strcmp(passengers[i].lastName , passengers[i+1].lastName) ==0){
						flagSwap=1;
						if(passengers[i].typePassenger > passengers[i+1].typePassenger){
						auxPassenger = passengers[i];
						passengers[i] =	passengers[i+1];
						passengers[i+1] = auxPassenger;
						}
					}
				}
				if(orden == 2){
					if(strcmp(passengers[i].lastName , passengers[i+1].lastName)<0){
						flagSwap=1;
						auxPassenger = passengers[i];
						passengers[i] =	passengers[i+1];
						passengers[i+1] = auxPassenger;
					}
					if(strcmp(passengers[i].lastName , passengers[i+1].lastName) ==0){
						flagSwap=1;
						if(passengers[i].typePassenger < passengers[i+1].typePassenger){
							auxPassenger = passengers[i];
							passengers[i] =	passengers[i+1];
							passengers[i+1] = auxPassenger;
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

int P_sortPassengersById(ePassengers passengers[],int cantidad){
	int rtn = -1;
	ePassengers auxPassenger;
	int flagSwap;
	int limite;
	int i;

	if(passengers != NULL && cantidad >= 0){
		limite = cantidad-1;
		do{
			flagSwap=0;
			for (i = 0; i < limite; i++){
				if(passengers[i].id > passengers[i+1].id){
					flagSwap=1;
					auxPassenger = passengers[i];
					passengers[i] =	passengers[i+1];
					passengers[i+1] = auxPassenger;
				}
			}
			limite--;
		}while(flagSwap);
		rtn = 1;
	}
return rtn;
}

int P_MostrarPromedioYPreciosDePasajes(ePassengers passengers[],int cantidad, int estado){
	int rtn =-1;
	float promedioPrecios;
	float totalPrecios;
	int pasajerosSobrePromedio;
	if(P_PromedioPrecioViajes(passengers,cantidad,estado, &promedioPrecios,&totalPrecios)>0){
		pasajerosSobrePromedio = P_PasajerosSobrePromedio(passengers,cantidad,estado,promedioPrecios);
		puts("/////opcion 3 Datos de precios y promedios/////");
		printf("Total de los precios de los vuelos:$ %.2f\n"
				"Total de los promedios de precios de los vuelos:$ %.2f\n"
				"Pasajeros que superan el precio promedio: %d\n\n"
				,totalPrecios,promedioPrecios,pasajerosSobrePromedio);
		rtn =1;
	}
	return rtn;
}

int P_PasajerosSobrePromedio(ePassengers passengers[],int cantidad, int estado, float promedioPrecios){
	int rtn=-1;
	int contador;
	if(passengers != NULL && cantidad >0 && promedioPrecios >0){
		contador=0;
		for (int i = 0; i < cantidad; ++i) {
			if(passengers[i].price > promedioPrecios){
				contador++;
			}
		}
		rtn=contador;
	}
	return rtn;
}

int P_BuscarIdMayor(ePassengers passengers[],int cantidad, int estado){
	int auxMaxId =-1;
	if(passengers != NULL && cantidad > 0){
		auxMaxId =0;
		for(int i = 0;i<cantidad;i++){
			if(estado == 411 && passengers[i].id>auxMaxId){
				auxMaxId = passengers[i].id;
			}
			if( passengers[i].isEmpty == estado && passengers[i].id>auxMaxId ){
				auxMaxId = passengers[i].id;
			}
		}
	}
	return auxMaxId;
}
