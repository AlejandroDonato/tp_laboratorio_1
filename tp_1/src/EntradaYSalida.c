#include "EntradaYSalida.h"

int getInt(char mensaje[],int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado){
	int rtn = -1;
	int auxiliarInt;
	int auxiliarReintentos;
	int retornoScanf;
	auxiliarReintentos = reintentos;

	if(mensaje!= NULL && minimo<maximo && mensajeError != NULL && pNumeroIngresado != NULL && auxiliarReintentos > 0){
		printf("%s",mensaje);
		fflush(stdin);
		retornoScanf = scanf("%d", &auxiliarInt);
		do{
			if(retornoScanf !=1 || auxiliarInt > maximo || auxiliarInt < minimo){
				printf("\n%s, te quedan %d reinentos\n %s\n", mensajeError, auxiliarReintentos, mensaje);
				fflush(stdin);
				retornoScanf = scanf("%d", &auxiliarInt);
				auxiliarReintentos--;
			}
			else{
				rtn =1;
				auxiliarReintentos =0;
				*pNumeroIngresado = auxiliarInt;
			}
			if(!(retornoScanf !=1 || auxiliarInt > maximo || auxiliarInt < minimo)){
				rtn =1;
				auxiliarReintentos =0;
				*pNumeroIngresado = auxiliarInt;
			}
		}while(auxiliarReintentos >0);
	}
	return rtn;
}

int getFloat(char mensaje[],int reintentos, float minimo, float maximo, char mensajeError[], float *pNumeroIngresado){
	int rtn = -1;
	float auxiliarFloat;
	int auxiliarReintentos;
	int retornoScanf;
	auxiliarReintentos = reintentos;


	if(mensaje!= NULL && minimo<maximo && mensajeError != NULL && pNumeroIngresado != NULL && auxiliarReintentos > 0){
	printf("%s",mensaje);
	fflush(stdin);
	retornoScanf = scanf("%f", &auxiliarFloat);
		do{
			if(retornoScanf !=1 || auxiliarFloat > maximo || auxiliarFloat < minimo){
				printf("\n%s, te quedan %d reinentos\n %s\n", mensajeError, auxiliarReintentos, mensaje);
				fflush(stdin);
				retornoScanf = scanf("%f", &auxiliarFloat);
				auxiliarReintentos--;
			}
			else{
				rtn =1;
				auxiliarReintentos =0;
				*pNumeroIngresado = auxiliarFloat;
			}
			if(!(retornoScanf !=1 || auxiliarFloat > maximo || auxiliarFloat < minimo)){
				rtn =1;
				auxiliarReintentos =0;
				*pNumeroIngresado = auxiliarFloat;
			}

		}while(auxiliarReintentos >0);
	}
	return rtn;
}

void MostrarResultados(float valor1,float valor2,float valor3,float valor4,float valor5){

	printf("\n\t Precio Aerolineas: $ %.2f",valor1);
	printf("\n\t a) Precio con tarjeta de débito: $ %.2f",valor2);
	printf("\n\t b) Precio con tarjeta de crédito: $ %.2f",valor3);
	printf("\n\t c) Precio pagando con bitcoin : %f BTC",valor4);
	printf("\n\t d) Precio unitario: %.2f $/km \n",valor5);

}
