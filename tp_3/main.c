#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

#define ACENDENTE 1
#define DECENDENTE 0

int main(void){
	setbuf(stdout,NULL);
	LinkedList* listaVuelos = ll_newLinkedList();
	controller_loadFlightFromText("data.csv",listaVuelos);
	int option = 0;
	int optionCarga =0;
    int flagCarga = 0;
    int flagGuardar = 1;
    int salir = 0;
    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	puts(	"++-^-++-^-^-^-++-^-^-^-++-^----^-++-^-^-^-++-^-^-^-++-^-++\n"
				"||<o>||>-<o>-<||>-<o>-<||  MENU  ||>-<o>-<||>-<o>-<||<o>||\n"
				"++---++-------++-------++--------++-------++-------++---++\n"
				"||                                                      ||\n"
    			"||  ( 1). Cargar pasajeros desde archivo data.csv       ||\n"
    			"||  ( 2). Cargar pasajeros desde archivo data.bin       ||\n"
    			"||  ( 3). Alta de pasajero                              ||\n"
    			"||  ( 4). Modificar datos de pasajero                   ||\n"
    			"||  ( 5). Baja de pasajero                              ||\n"
    			"||  ( 6). Listar pasajeros                              ||\n"
    			"||  ( 7). Ordenar pasajeros                             ||\n"
    			"||  ( 8). Guardar pasajeros en archivo data.csv         ||\n"
    			"||  ( 9). Guardar pasajeros en archivo data.bin         ||\n"
    			"||  (10). Salir                                         ||\n"
    			"||                                                      ||\n"
    			"++------------------------------------------------------++\n");
    		if(getIntInRange("Ingrese una opcion:",3,1,10,"Opcion invalida",&option) !=1){
    			controller_MensajeError("Error!, agotado numero de reintentos");
    			option =10;
    		}
        switch(option)
        {
            case 1://Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)
            	if(flagCarga == 0){
            		controller_MensajeCabecera("CARGAR DATOS DE PASAJEROS DEL ARCHIVO DATA.CSV");
            		if(getIntInRange("Ingrese una opcion:\n\t 1). cargar DATA.CVS original.\n\t 2). cargar DATA.CVS generado.",3,1,2,"Opcion invalida",&optionCarga) ==1){
            		switch(optionCarga){
            			case 1:
            				if(controller_loadFromText("data.csv",listaPasajeros,listaVuelos)==1){
            					controller_MensajeExitoso("Datos de pasajeros cargados con exito ");
            					flagCarga = 1;
            				}
            				else{controller_MensajeError("Error, no se pudieron cargar los datos");
            				}
            				break;
            			case 2:
            				if(controller_loadFromText("NewData.csv",listaPasajeros,listaVuelos)==1){
            					controller_MensajeExitoso("Datos de pasajeros cargados con exito ");
            					flagCarga = 1;
            				}
            				else{controller_MensajeError("Error, no se pudieron cargar los datos");
            				}
            				break;
            			}
            		}
            		else{controller_MensajeError("Error!, agotado numero de reintentos");
            		}
            	}
            	else{controller_MensajeError("Error!, Imposible cargar 2 veces");
            	}
            	break;
            case 2://Cargar los datos de los pasajeros desde el archivo data.bin (modo binario)
            	if(flagCarga == 0){
            		controller_MensajeCabecera("CARGAR DATOS DE PASAJEROS DEL ARCHIVO DATA.BIN");
            		if(controller_loadFromBinary("NewData.bin",listaPasajeros)==1){
            			controller_MensajeExitoso("Datos de pasajeros cargados con exito ");
            			flagCarga = 1;
            		}
            		else{controller_MensajeError("Error, no se pudieron cargar los datos");
            		}
            	}
            	else{controller_MensajeError("Error!, Imposible cargar 2 veces");}
            	break;
            case 3://Alta de pasajero
            	controller_MensajeCabecera("ALTA DE PASAJERO");
            	if(controller_addPassenger(listaPasajeros,listaVuelos)==1){
            		controller_MensajeExitoso("Alta exitosa");
            		flagGuardar = 0;
            	}
            	else{controller_MensajeError("Error, No se pudo dar de alta ");}
            	break;
            case 4://Modificar datos de pasajero
            	if(controller_countPassengers(listaPasajeros)>0){
            		controller_MensajeCabecera("MODIFICAR PASAJEROS ");
            		if(controller_editPassenger(listaPasajeros,listaVuelos)==1){
            			controller_MensajeExitoso("Modificación exitosa");
            			flagGuardar = 0;
            		}
            		else{controller_MensajeError("Error!, No se pudo modificar");
            		}
            	}
            	else{controller_MensajeError("Error, No existen pasajeros cargados");
            	}
            	break;
            case 5://Baja de pasajero
            	if(controller_countPassengers(listaPasajeros)>0){
            		controller_MensajeCabecera("BAJA DE PASAJEROS ");
            		if(controller_removePassenger(listaPasajeros,listaVuelos)==1){
            			controller_MensajeExitoso("Baja exitosa");
            			flagGuardar = 0;
            		}
            		else{controller_MensajeError("Error!, No se pudo dar de baja");
            		}
            	}
            	else{controller_MensajeError("Error, No existen pasajeros cargados");
            	}
            	break;
            case 6://Listar pasajeros
            	if(controller_countPassengers(listaPasajeros)>0){
            		controller_MensajeCabecera("LISTA DE PASAJEROS");
            		controller_ListPassenger(listaPasajeros,listaVuelos);
            	}
            	else{controller_MensajeError("Error, No existen pasajeros cargados");
            	}
            	break;
            case 7://Ordenar pasajeros
            	if(controller_countPassengers(listaPasajeros)>0){
            		controller_MensajeCabecera("ORDENAR PASAJEROS ");
            		if(controller_sortPassenger(listaPasajeros,ACENDENTE)==1){
            			controller_ListPassenger(listaPasajeros,listaVuelos);
            		}
            		else{controller_MensajeError("Error, No se pudo ordenar ");
            		}
            	}
            	else{controller_MensajeError("Error, No existen pasajeros cargados");
            	}
            	break;
            case 8://Guardar los datos de los pasajeros en el archivo data.csv (modo texto)
            	if(controller_countPassengers(listaPasajeros)>0){
            		controller_MensajeCabecera("GUARDAR DATOS DE PASAJEROS EN ARCHIVO DATA.CSV");
            		if(controller_saveAsText("NewData.csv",listaPasajeros,listaVuelos)==1){
            			controller_MensajeExitoso("Datos guardados con exito ");
            			flagGuardar=1;
            		}
            		else{controller_MensajeError("Error, No se pudo guardar ");
            		}
            	}
            	else{controller_MensajeError("Error, No existen pasajeros cargados");
            	}
            	break;
            case 9://Guardar los datos de los pasajeros en el archivo data.bin (modo binario)
            	if(controller_countPassengers(listaPasajeros)>0){
            		controller_MensajeCabecera("GUARDAR DATOS DE PASAJEROS EN ARCHIVO DATA.BIN");
            		if(controller_saveAsBinary("NewData.bin",listaPasajeros)==1){
            			controller_MensajeExitoso("Datos guardados con exito ");
            			flagGuardar=1;
            		}
            		else{controller_MensajeError("Error, No se pudo guardar ");
            		}
            	}
            	else{controller_MensajeError("Error, No existen pasajeros cargados");
            	}
            	break;
            case 10://salir si se guardo o no se modifico nada
            	if(flagGuardar==1){
            		salir = 1;
            	}
            	else{controller_MensajeError("Error, guardar cambios antes de salir ");
            	}
            	break;
        }
    }while(salir != 1);
    controller_MensajeCabecera("FIN DEL PROGRAMA");
    return 0;
}

