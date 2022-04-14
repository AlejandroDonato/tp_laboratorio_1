/*
 ============================================================================
 Name        		: TP_1.c
 Author      		: Donato Alejandro
 vercion OnlineGDB	: https://onlinegdb.com/A3sD9yNTX
 ============================================================================
 */


#include "Operaciones.h"
#define DESCUENTODEVITO 0.9 // baja 10%
#define INTERESCREDITO 1.25 // incrementa un 25%
#define BTC 4606954.55		// valor del bitcoin

int main(void) {
	setbuf(stdout,NULL);
	//datos de menus:
	int opcion;
	int subOpcion;
	int salir=0;
	//datos a pedidos:
	float kilometros;
	float precioAerolineas;
	float precioLatam;
	//datos a calcular:
	float aerolineasDevito;
	float latamDevito;
	float aerolineasCredito;
	float latamCredito;
	float aerolineasBtc;
	float latamBtc;
	float aerolineasPrecioXKm;
	float latamPrecioXKm;
	float diferenciaDePrecios;
	//Banderas:
	int flagKm = 0;
	int flagPrecioAerolineas = 0;
	int flagPrecioLatam = 0;
	int flagCalculos = 0;
	//Carga Forzada:
	float kilometrosF;
	float precioAerolineasF;
	float precioLatamF;
	//resultados de carga forzada:
	float aerolineasDevitoF;
	float latamDevitoF;
	float aerolineasCreditoF;
	float latamCreditoF;
	float aerolineasBtcF;
	float latamBtcF;
	float aerolineasPrecioXKmF;
	float latamPrecioXKmF;
	float diferenciaDePreciosF;

	do{
		if(flagKm == 1){
			printf("\n1- Ingresar Kilómetros: %.2f Km\n",kilometros);
		}
		else{
			printf("\n1- Ingresar Kilómetros:\n");
		}
		if(flagPrecioAerolineas == 1 && flagPrecioLatam == 1){
			printf("2- Ingresar Precio de Vuelos: (Aerolineas: $ %.2f -- Latam: $ %.2f)\n",precioAerolineas,precioLatam);
		}
		else if(flagPrecioAerolineas == 1){
			printf("2- Ingresar Precio de Vuelos: (Aerolineas: $ %.2f)\n",precioAerolineas);
		}
		else if(flagPrecioLatam == 1){
			printf("2- Ingresar Precio de Vuelos: (Latam: $ %.2f)\n",precioLatam);
		}
		else{
			printf("2- Ingresar Precio de Vuelos:\n");
		}
		printf("3- Calcular todos los costos:\n"
				"4. Informar Resultados\n"
				"5. Carga forzada de datos\n"
				"6. Salir\n");

		if(getInt("ingrese una opción:",3,1,6,"opción invalida", &opcion)!=1){
			printf("\nError\n");
			opcion=0;
			salir=1;
		}

		switch(opcion){

		//1- Ingresar Kilómetros:
		case 1:
			if(getFloat("Ingrese la distancia en kilometros:",3,1,100000,"Distancia invalida",&kilometros)!=1){
				printf("\nNo se ingresaron los kilometros correctamente\n");
			}
			else{
				flagKm = 1;
				printf("\nkilometros ingresados: %.0f Km\n", kilometros);
			}
		break;

		//2- Ingresar Precio de Vuelos:
		case 2:
			printf("\n---Ingresar Precio de Vuelos:---\n"
					"   1- Precio vuelo Aerolíneas:\n"
					"   2- Precio vuelo Latam:\n");

			if(getInt("ingrese una opción:",3,1,2,"opción invalida", &subOpcion)!=1){
						printf("\nError, ");
						subOpcion=0;
						salir=1;
						break;
			}
			switch(subOpcion){
			//2.1- Precio vuelo Aerolíneas:
			case 1:
				if(getFloat("Ingrese el precio del vuelo de Aerolineas:",3,1,1000000,"valor invalido",&precioAerolineas)!=1){
					printf("\nNo se ingreso el valor correctamente\n");
				}
				else{
					printf("\nValor del vuelo de Aerolineas: $ %.2f\n", precioAerolineas);
					flagPrecioAerolineas = 1;
				}
			break;
			//2.2- Precio vuelo Latam:
			case 2:
				if(getFloat("Ingrese el precio del vuelo de Latam:",3,1,1000000,"valor invalido",&precioLatam)!=1){
					printf("\nNo se ingreso el valor correctamente\n");
				}
				else{
					printf("\nValor del vuelo de Latam: $ %.2f\n", precioLatam);
					flagPrecioLatam = 1;
				}
			break;
			}

		break;

		//3- Calcular todos los costos:
		case 3:

			if(flagKm == 1 && flagPrecioAerolineas == 1 && precioAerolineas != 0){
				flagCalculos = TodosLosCalculos(precioAerolineas,DESCUENTODEVITO,INTERESCREDITO,BTC,kilometros,
						 	 	 	 	 	 	&aerolineasDevito,&aerolineasCredito,&aerolineasBtc,&aerolineasPrecioXKm);
			}
			if(flagKm == 1 && flagPrecioLatam == 1 && precioLatam != 0){
				flagCalculos = TodosLosCalculos(precioLatam,DESCUENTODEVITO,INTERESCREDITO,BTC,kilometros,
												&latamDevito,&latamCredito,&latamBtc,&latamPrecioXKm);
			}
			if(flagPrecioLatam == 1 && precioLatam != 0 && flagPrecioAerolineas == 1){
				resta(precioLatam, precioAerolineas, &diferenciaDePrecios);
			}
			if(flagCalculos == 1){
				printf("\n--Calculo de datos exitoso--\n");
			}

			break;
		//4- Informar Resultados:
		case 4:
			if(flagKm == 1 && flagPrecioAerolineas == 1 && flagCalculos == 1){
				MostrarResultados(precioAerolineas,aerolineasDevito,aerolineasCredito,aerolineasBtc,aerolineasPrecioXKm);
			}
			if(flagKm == 1 && flagPrecioLatam == 1 && flagCalculos == 1){
				MostrarResultados(precioLatam,latamDevito,latamCredito,latamBtc,latamPrecioXKm);
			}
			if(flagPrecioLatam == 1 && flagPrecioAerolineas == 1 && flagCalculos == 1){
				printf("\n	La diferencia de precio es : $ %.2f \n",diferenciaDePrecios);
			}
			if(flagCalculos != 1){
				printf("\n--No se realizaron calculos para mostrar--\n");
			}
			break;
		//5. Carga forzada de datos:
		case 5:
			kilometrosF =7090;
			precioAerolineasF =162965;
			precioLatamF =159339;

			printf("\n--Carga de datos Forzados exitosa--\n");

			printf("\n1- Ingresar Kilómetros: %.2f Km"
					"\n2- Ingresar Precio de Vuelos: (Aerolineas: $ %.2f -- Latam: $ %.2f)"
					"\n3- Calcular todos los costos"
					"\n4. Informar Resultados"
					"\n5. Carga forzada de datos"
					"\n6. Salir\n",kilometrosF,precioAerolineasF,precioLatamF);

			//calcular carga forzada
			TodosLosCalculos(precioAerolineasF,DESCUENTODEVITO,INTERESCREDITO,BTC,kilometrosF,
			 	 	 	 	&aerolineasDevitoF,&aerolineasCreditoF,&aerolineasBtcF,&aerolineasPrecioXKmF);

			TodosLosCalculos(precioLatamF,DESCUENTODEVITO,INTERESCREDITO,BTC,kilometrosF,
							&latamDevitoF,&latamCreditoF,&latamBtcF,&latamPrecioXKmF);

			resta(precioLatamF, precioAerolineasF, &diferenciaDePreciosF);

			printf("\n--Calculo de datos exitoso--\n");

			//mostrar resultados carga forzada
			MostrarResultados(precioAerolineasF,aerolineasDevitoF,aerolineasCreditoF,aerolineasBtcF,aerolineasPrecioXKmF);
			MostrarResultados(precioLatamF,latamDevitoF,latamCreditoF,latamBtcF,latamPrecioXKmF);

			salir=1;
			break;
		case 6:
			printf("\n Chau, Chau, vuelva pronto!\n");
			salir=1;
			break;
		default :
			printf("opción incorrecta\n");
			fflush(stdin);
			break;
		}


	}while(salir != 1);

	return EXIT_SUCCESS;
}

