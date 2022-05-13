#include "Vuelo.h"

static int V_GenerarId(void);
static int V_GenerarId(void){
	static int contadorV = 100;
	return contadorV++;
}
int V_harcodearVuelos(eVuelos Vuelo[],int cantidadVuelos){
	int rtn =-1;
	char flycode[10][MAX_CHAR]={"EU3971534","US4859514","SA7531568","AR7596248","RU1534862","KO2486245","FR1679432","EU2689543","US5139275","RU6839264"};

	if(Vuelo != NULL && cantidadVuelos > 0){
	for (int i = 0; i < cantidadVuelos; i++){

		Vuelo[i].isEmpty = 1;
		strcpy(Vuelo[i].flycode,flycode[i]);
		Vuelo[i].statusFlight=rand()%3+1;
		Vuelo[i].id = V_GenerarId();

	}
	rtn = 1;
	}
	return rtn;
}

int V_InicializarVuelos(eVuelos Vuelo[],int cantidadVuelos,int estado){
	int rtn =-1;
	if(Vuelo != NULL && cantidadVuelos > 0){
	for (int i = 0; i < cantidadVuelos; i++){
		Vuelo[i].isEmpty = estado;
	}
	rtn = 1;
	}
	return rtn;
}

int V_MostrarVuelos(eVuelos vuelos[],int cantidad, int estado){
	int contador = -1;
	int flagContador =-1;
	if(vuelos != NULL && cantidad>0){
		contador = 0;
		printf( "|  Id  |   Codigo de Vuelo   |   Estado del Vuelo   |\n"
				"|      |                     |                      |\n");
		for(int i = 0;i<cantidad;i++){
			if(estado == 411 && vuelos[i].isEmpty> 0){
				V_MostrarVuelo(vuelos,i);
				contador++;
				flagContador =1;
			}
			if( vuelos[i].isEmpty == estado){
				V_MostrarVuelo(vuelos,i);
				contador++;
				flagContador =1;
			}
		}
		if(flagContador == -1){
			printf("No hay Vuelos para mostrar\n");
		}
	}
	return contador;
}

void V_MostrarVuelo(eVuelos Vuelo[],int pocicion){

	char auxStatusFlight[MAX_CHAR];

	switch (Vuelo[pocicion].statusFlight){
	case ACTIVO:
		strcpy(auxStatusFlight,"Activo");
		break;
	case PENDIENTE:
		strcpy(auxStatusFlight,"Pendiente");
		break;
	case INACTIVO:
		strcpy(auxStatusFlight,"Inactivo");
		break;
	}
	printf( "|%-6d|%-21s|%-22s|\n",Vuelo[pocicion].id,Vuelo[pocicion].flycode,auxStatusFlight);
}

int V_BuscarEspacioParaVueloNuevo(eVuelos vuelos[],int cantidad){
	int rtn;
	int flag = 0;
	if(vuelos != NULL && cantidad>0){
		if(cantidad > 0){
			for(int i = 0;i<cantidad;i++){
				if( vuelos[i].isEmpty == LIBRE){
					rtn = i;
					flag = 1;
					break;
				}
			}
			if(flag == 0){rtn = 0;//sin espacio en la lista
			}
		}
		else{rtn =-2;//cantidad != de 0
		}
	}
	else{rtn=-1;//array nulo
	}
return rtn;
}

int V_AltaVuelo(eVuelos vuelos[],int cantidad){
	int rtn;
	int vueloLibre;
	int auxId;
	char auxFlycode[FLY_CODE];
	int auxEstadoVuelo;

	if(vuelos != NULL && cantidad > 0){
		vueloLibre = V_BuscarEspacioParaVueloNuevo(vuelos,cantidad);
		if(vueloLibre != -1){
			if(GetArrayCharsAndIntWithRetrys("Ingrese codigo de vuelo:",3,"Codigo invalido,",auxFlycode,FLY_CODE) == 1){
				if(getIntInRange("Ingrese Estado de vuelo:\n\t 1- Activo\n\t 2- Pendiente\n\t 3- Inactivo",3,1,3,"Opcion invalida,",&auxEstadoVuelo) == 1){
					auxId = V_GenerarId();
						if(V_addVuelo(vuelos,vueloLibre,auxId,auxFlycode,auxEstadoVuelo)==1){
							vuelos[vueloLibre].isEmpty = OCUPADO;
								rtn =1;
						}
						else{rtn =-5;//error en la funcion addVuelo
						}
				}
				else{rtn =-4;//error en la carga de estado de Vuelo
				}
			}
			else{rtn =-3;//error al cargar codigo del vuelo
			}
		}
		else{rtn =-2;//error al buscar espacio libre
		}
	}
	else{rtn =-1;//error estructura o cantidad nula
	}
return rtn;
}

int V_addVuelo(eVuelos list[], int len, int id, char flycode[],int estadoVuelo){
	int rtn;
	if(list != NULL && len > -1){
		list[len].id = id;
		list[len].statusFlight = estadoVuelo;
		strcpy(list[len].flycode,flycode);
		rtn = 1;
	}
	else{rtn = -1;
	}
return rtn;
}

int V_modificarVuelo(eVuelos Vuelos[], int cantidad){
	int rtn;

	if(Vuelos != NULL && cantidad > 0){
		int auxId;
		char auxFlycode[FLY_CODE];
		int auxEstadoVuelo;

		int finalizar;
		int opcion;
		int maxId;
		int pocicion;

		maxId = V_BuscarIdMayor(Vuelos,cantidad,OCUPADO);
		V_MostrarVuelos(Vuelos,cantidad,OCUPADO);


		if(getIntInRange("Ingrese una id:",3,0,maxId,"Id invalida,",&auxId)==1){
			pocicion = V_findVueloById(Vuelos,cantidad,auxId);
			puts("Vuelo a Modificar:");
			V_MostrarVuelo(Vuelos,pocicion);
			puts(" ");

			auxEstadoVuelo = Vuelos[pocicion].statusFlight;
			strcpy(auxFlycode,Vuelos[pocicion].flycode);

			do{
				puts("------Menu de Opciones------");
				printf(	"\t 1) Modificar codigo del vuelo \n"
						"\t 2) Modificar estado del Vuelo \n"
						"\t 3) Salir\n");

				if(getIntInRange("ingrese una opcion:",3,1,3,"Opcion invalida",&opcion) !=1){
					puts("/////Error/////");
					finalizar =1;
				}

				switch(opcion){
				case 1://Modificar Nombre
					puts("/////Modificar Codigo de vuelo/////");
					if(GetArrayCharsAndIntWithRetrys("Ingrese codigo de vuelo:",3,"Codigo invalido,",auxFlycode,FLY_CODE) != 1){
						puts("Error al Modificar Codigo de vuelo");
					}
					break;
				case 2://Modificar Apellido
					puts("/////Modificar Tipo de Vuelo/////");
					if(getIntInRange("Ingrese Tipo:\n\t 1- Primera clase \n\t 2- Ejecutiva \n\t 3- Turista",3,1,3,"Opcion invalida,",&auxEstadoVuelo) != 1){
						puts("Error al Modificar Tipo de Vuelo");
					}
					break;
				case 3://Modificar Precio
					if(PedirVerificacion("Desea guardar los cambios?","Opcion invalida")==1){
						V_addVuelo(Vuelos,pocicion, auxId,auxFlycode,auxEstadoVuelo);
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

int V_findVueloById(eVuelos list[], int len,int id){
int rtn = -1;
for(int i = 0;i < len; i++){
	if(list[i].id == id){
		rtn = i;
		break;
	}
}
return rtn;
}

int V_BajaDeUnVuelo(eVuelos Vuelos[], int cantidad){
	int rtn =-1;
	if(Vuelos != NULL && cantidad > 0){
		int auxId;
		int maxId;
		int pocicion;

		maxId = V_BuscarIdMayor(Vuelos,cantidad,OCUPADO);
		V_MostrarVuelos(Vuelos,cantidad,OCUPADO);

		if(getIntInRange("Ingrese una id:",3,0,maxId,"Id invalida,",&auxId)==1){

			pocicion = V_findVueloById(Vuelos,cantidad,auxId);
			puts("Vuelo seleccionado para eliminar:");
			V_MostrarVuelo(Vuelos,pocicion);
			puts(" ");
			if(PedirVerificacion("Desea dar de baja este Vuelo?","Opcion invalida")==1){
				Vuelos[pocicion].isEmpty=BAJA;
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


int V_contarVuelos(eVuelos vuelos[],int cantidad, int estado){
	int contador = -1;

	if(vuelos != NULL && cantidad >0){
		contador = 0;
		for(int i = 0;i<cantidad;i++){
			if(estado == 411 && vuelos[i].isEmpty> 0){
				contador++;
			}
			if( vuelos[i].isEmpty == estado){
				contador++;
			}
		}
	}
	return contador;
}


int V_BuscarIdMayor(eVuelos vuelos[],int cantidad, int estado){
	int auxMaxId =-1;
	if(vuelos != NULL && cantidad >0){
		auxMaxId =0;
		for(int i = 0;i<cantidad;i++){
			if(estado == 411 && vuelos[i].id>auxMaxId){
				auxMaxId = vuelos[i].id;
			}
			if( vuelos[i].isEmpty == estado && vuelos[i].id>auxMaxId ){
				auxMaxId = vuelos[i].id;
			}
		}
	}
	return auxMaxId;
}

int V_getIdVueloFromList(eVuelos vuelos[],int cantidad,int *idVuelo){
	int rtn=-1;
	int auxIdVueloMayor;
	int auxIdVuelo;
	int flagId = -1;
	int contador =0;
	int i;

	if(vuelos != NULL && cantidad >0){
		V_MostrarVuelos(vuelos,cantidad,ALL);
		auxIdVueloMayor = V_BuscarIdMayor(vuelos,cantidad,ALL);
		do{
			if(getIntInRange("Ingrese Id del vuelo:",3,0,auxIdVueloMayor,"Opcion invalida,",&auxIdVuelo) == 1 ){
				for (i = 0; i < cantidad; ++i) {
					if(vuelos[i].id == auxIdVuelo){
						*idVuelo = auxIdVuelo;
						flagId =1;
						rtn = 1;
						break;
					}
				}
				if(flagId !=1){
					puts("////ERROR////");
					contador++;
				}
				if(contador == 3){
					flagId =1;
				}
			}
		}while(flagId !=1);
	}
	return rtn;
}
