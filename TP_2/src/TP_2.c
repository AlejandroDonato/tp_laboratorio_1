/*
 ============================================================================
 Name        : TP_2.c
 Author      : Donato Alejandro
 Description :
 ============================================================================
 */

#include "PasajeroYVuelo.h"

#define MAX_PASSENGERS 2000
#define MAX_VUELOS 10

#define LIBRE 0
#define OCUPADO 1

#define HARCODE_PASSENGERS 100

int main(void) {
	setbuf(stdout,NULL);

int salir;
int opcion;
int subOpcion;
int flagAlta=0;

ePassengers pasajeros[MAX_PASSENGERS];
eVuelos vuelos[MAX_VUELOS];

P_InicializarPasajeros(pasajeros,MAX_PASSENGERS,LIBRE);
V_InicializarVuelos(vuelos,MAX_VUELOS,LIBRE);
V_harcodearVuelos(vuelos,MAX_VUELOS);

do{

	puts("\n----Menu de Opciones----");

	printf("1) Altas \n"
		   "2) Modificar \n"
		   "3) Baja \n"
		   "4) Informar \n"
		   "5) Harcodeo de datos \n"
		   "6) Salir \n");

if(getIntInRange("Ingrese una opcion:",3,1,6,"Opcion invalida",&opcion) !=1){
	puts("/////Error/////");
	salir =1;
}

	switch(opcion){
	case 1://altas
		puts("/////Opcion 1 Altas/////");
		if(PV_AltaPasajero(pasajeros,MAX_PASSENGERS,vuelos,MAX_VUELOS) == 1){
			flagAlta =1;
			puts("/////correcto/////");
		}
		else{printf("/////error en la alta de un pasagero /////\n");
		}

		break;
	case 2://modificar
		if(flagAlta == 1){
			puts("/////Opcion 2 Modificar/////");
			if(PV_modificarPasajero(pasajeros,MAX_PASSENGERS,vuelos,MAX_VUELOS)==1){
				puts("Modificacion exitosa");
			}
			else{puts("No se pudo Modificar");
			}
		}
		else{puts("-No hay pasajeros cargados para modificar-");
		}
		break;
	case 3://baja
		if(flagAlta == 1){
			puts("/////Opcion 3 Baja/////");
			if(PV_BajaDeUnPasajero(pasajeros,MAX_PASSENGERS,vuelos,MAX_VUELOS)==-1){
				puts("/////Error al dar de baja/////");
			}
			else{
				if(P_contarPasajeros(pasajeros,MAX_PASSENGERS,OCUPADO)==0){
					flagAlta=0;
				}
			}
		}
		else{puts("-No hay pasajeros cargados para dar de baja-");
		}
		break;
	case 4://informar
		if(flagAlta == 1){
			puts("/////Opcion 4 Informar/////");
			if(getIntInRange("\nIngrese una opcion:\n"
							 "\t1)mostrar lista de pasajeros\n"
							 "\t2)Ordenar por nombre ascendente\n"
							 "\t3)Ordenar por nombre descendiente\n"
							 "\t4)Total y promedio de los precios de los pasajes\n"
							 "\t5)Listado de los pasajeros por Código de vuelo y estado\n"
							 "\t6) Menu principal\n"
							 ,3,1,6,"Opcion invalida",&subOpcion) !=1){
			puts("/////Error/////");
			}
			switch(subOpcion){
				case 1:
					if(P_sortPassengersById(pasajeros,MAX_PASSENGERS)!=-1){
						puts("/////lista de pasajeros://///");
						PV_MostrarPasajeros(pasajeros,MAX_PASSENGERS,OCUPADO,vuelos,MAX_VUELOS);
					}
					else{
						puts("/////ERROR, no se pudo mostrar/////");
					}
					break;
				case 2:
					if(P_sortPassengers(pasajeros,MAX_PASSENGERS,1)!=-1){
					puts("/////lista reordenada ascendente://///");
					PV_MostrarPasajeros(pasajeros,MAX_PASSENGERS,OCUPADO,vuelos,MAX_VUELOS);
					}
					else{
						puts("/////ERROR, no se pudo reordenar/////");
					}
					break;
				case 3:
					if(P_sortPassengers(pasajeros,MAX_PASSENGERS,2)!=-1){
					puts("/////lista reordenada descendiente://///");
					PV_MostrarPasajeros(pasajeros,MAX_PASSENGERS,OCUPADO,vuelos,MAX_VUELOS);
					}
					else{
						puts("/////ERROR, no se pudo reordenar/////");
					}
					break;
				case 4:
					P_MostrarPromedioYPreciosDePasajes(pasajeros,MAX_PASSENGERS,OCUPADO);
					break;
				case 5:
					if(PV_sortPassengersByCode(pasajeros,MAX_PASSENGERS,vuelos,MAX_VUELOS,1)!=-1){
					puts("/////lista por codigo de vuelo://///");
					PV_MostrarPasajeros(pasajeros,MAX_PASSENGERS,OCUPADO,vuelos,MAX_VUELOS);
					}
					else{
						puts("/////ERROR, no se pudo reordenar/////");
					}
					break;
				case 6:
					break;
			}

		}
		else{puts("No hay pasajeros cargados para mostrar");
		}
		break;
	case 5://harcodeo
		puts("/////Opcion 5 harcodeo/////");
		flagAlta = PV_harcodearPasajeros(pasajeros,HARCODE_PASSENGERS,vuelos,MAX_VUELOS);
		break;
	case 6://salir
		puts("/////Opcion 6 Salir/////\n\n-----FIN DEL PROGRAMA-----");
		salir =1;
		break;
	}

}while(salir!=1);

return EXIT_SUCCESS;
}
