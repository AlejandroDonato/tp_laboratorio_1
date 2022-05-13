#include "EntradaYSalida.h"

int getIntInRange(char mensaje[],int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado){
	int rtn = -1;
	int auxiliarInt;
	int auxiliarReintentos;
	int returnGetInt;
	auxiliarReintentos = reintentos;

	if(mensaje!= NULL && minimo<maximo && mensajeError != NULL && pNumeroIngresado != NULL && auxiliarReintentos > 0){
		printf("%s\n",mensaje);
		returnGetInt = GetInt(&auxiliarInt);

		do{
			if(returnGetInt !=1 || auxiliarInt > maximo || auxiliarInt < minimo){
				printf("\n%s, te quedan %d reinentos\n %s\n", mensajeError, auxiliarReintentos, mensaje);
				returnGetInt = GetInt(&auxiliarInt);
				auxiliarReintentos--;
			}
			else{
				rtn =1;
				auxiliarReintentos =0;
				*pNumeroIngresado = auxiliarInt;
			}
			if(!(returnGetInt !=1 || auxiliarInt > maximo || auxiliarInt < minimo)){
				rtn =1;
				auxiliarReintentos =0;
				*pNumeroIngresado = auxiliarInt;
			}
		}while(auxiliarReintentos >0);
	}
	return rtn;
}

int getFloatInRange(char mensaje[],int reintentos, float minimo, float maximo, char mensajeError[], float *pNumeroIngresado){
	int rtn = -1;
	float auxiliarFloat;
	int auxiliarReintentos;
	int returnGetFloat;
	auxiliarReintentos = reintentos;


	if(mensaje!= NULL && minimo<maximo && mensajeError != NULL && pNumeroIngresado != NULL && auxiliarReintentos > 0){
	printf("%s\n",mensaje);
	returnGetFloat = GetFloat(&auxiliarFloat);
		do{
			if(returnGetFloat !=1 || auxiliarFloat > maximo || auxiliarFloat < minimo){
				printf("\n%s, te quedan %d reinentos\n %s\n", mensajeError, auxiliarReintentos, mensaje);
				returnGetFloat = GetFloat(&auxiliarFloat);
				auxiliarReintentos--;
			}
			else{
				rtn =1;
				auxiliarReintentos =0;
				*pNumeroIngresado = auxiliarFloat;
			}
			if(!(returnGetFloat !=1 || auxiliarFloat > maximo || auxiliarFloat < minimo)){
				rtn =1;
				auxiliarReintentos =0;
				*pNumeroIngresado = auxiliarFloat;
			}

		}while(auxiliarReintentos >0);
	}
	return rtn;
}

int GetInt(int *pNumeroTomado){
	int rtn;
	char numeroAuxiliar[100];
	if(MyGets(numeroAuxiliar,sizeof(numeroAuxiliar))==1 && (EsNumeroEntero(numeroAuxiliar)==1)){
		*pNumeroTomado = atoi(numeroAuxiliar);
		rtn = 1;
	}
	else{
		rtn = -1;
	}
	return rtn;
}

int GetFloat(float *pNumeroTomado){
	int rtn;
	char numeroAuxiliar[100];
	if(MyGets(numeroAuxiliar,sizeof(numeroAuxiliar))==1 && (EsNumeroFlotante(numeroAuxiliar)==1)){
		*pNumeroTomado = atof(numeroAuxiliar);
		rtn = 1;
	}
	else{
		rtn = -1;
	}
	return rtn;
}

int GetArrayChars(char *pLetrasTomadas,int longitud){
	int rtn;
	char textoAuxiliar[1000];
	if(MyGets(textoAuxiliar,sizeof(textoAuxiliar))==1 && (EsChar(textoAuxiliar)==1)){
		strncpy(pLetrasTomadas,textoAuxiliar,longitud);
		rtn = 1;
	}
	else{
		rtn = -1;
	}
	return rtn;
}

int MyGets(char cadena[], int longitud){
	int rtn =-1;
	char textoAuxiliar[1000];
	if(cadena != NULL && longitud > 0){
		fflush(stdin);
		if(fgets(textoAuxiliar,sizeof(textoAuxiliar),stdin) != NULL){
			if(textoAuxiliar[strnlen(textoAuxiliar,sizeof(textoAuxiliar))-1] == '\n'){
				textoAuxiliar[strnlen(textoAuxiliar,sizeof(textoAuxiliar))-1] = '\0';
			}
			if(strnlen(textoAuxiliar,sizeof(textoAuxiliar))<=longitud){
				strncpy(cadena,textoAuxiliar,longitud);
				rtn =1;
			}
		}
	}
	return rtn;
}

int GetArrayCharsWithRetrys(char mensaje[],int reintentos, char mensajeError[],char *pLetrasIngresadas,int longitud){
	int rtn = -1;
	char auxiliarChar[100];
	int auxiliarReintentos;
	int returnGetArrayChars;
	auxiliarReintentos = reintentos+1;
	if(mensaje!= NULL && mensajeError != NULL && pLetrasIngresadas != NULL && auxiliarReintentos > 0){
		printf("%s\n",mensaje);
		do{
			returnGetArrayChars = GetArrayChars(auxiliarChar,sizeof(auxiliarChar));
			if(returnGetArrayChars ==1){
				rtn =1;
				auxiliarReintentos =0;
				strncpy(pLetrasIngresadas,auxiliarChar,longitud);
			}
			else{
				auxiliarReintentos--;
				if(auxiliarReintentos>0){
					printf("\n%s, te quedan %d reinentos\n %s\n", mensajeError, auxiliarReintentos, mensaje);
				}
				else{
					puts("ERROR, Ya no te quedan reinentos");
				}
			}

		}while(auxiliarReintentos >0);
	}
	return rtn;
}


int GetArrayCharsAndIntWithRetrys(char mensaje[],int reintentos, char mensajeError[],char *pLetrasIngresadas,int longitud){
	int rtn = -1;
	char auxiliarCharAndInt[1000];
	int auxiliarReintentos;
	int returnGetArrayCharsAndInt;
	auxiliarReintentos = reintentos+1;

	if(mensaje!= NULL && mensajeError != NULL && pLetrasIngresadas != NULL && auxiliarReintentos > 0){
		printf("%s\n",mensaje);
		do{
			returnGetArrayCharsAndInt = GetArrayCharsAndInt(auxiliarCharAndInt,sizeof(auxiliarCharAndInt));
			if(returnGetArrayCharsAndInt ==1){
				rtn =1;
				auxiliarReintentos =0;
				strncpy(pLetrasIngresadas,auxiliarCharAndInt,longitud);
				printf("se ingreso: %s\n",pLetrasIngresadas);
			}
			else{
				auxiliarReintentos--;
				if(auxiliarReintentos>0){
					printf("\n%s, te quedan %d reinentos\n %s\n", mensajeError, auxiliarReintentos, mensaje);
				}
				else{
					puts("ERROR, Ya no te quedan reinentos");
				}
			}
		}while(auxiliarReintentos >0);
	}
	return rtn;
}

int GetArrayCharsAndInt(char *pLetrasTomadas,int longitud){
	int rtn;
	char textoAuxiliar[1000];
	if(MyGets(textoAuxiliar,sizeof(textoAuxiliar))==1 && ((EsCharAndInt(textoAuxiliar)==1))){
		strncpy(pLetrasTomadas,textoAuxiliar,longitud);
		rtn = 1;
	}
	else{
		rtn = -1;
	}
	return rtn;
}

int getCharInRange(char mensaje[],char mensajeError[],char minimo,char maximo,int reintentos,char *pLetra){
	int rtn=-1;
	char auxChar;
	int auxReintentos;
	auxReintentos = reintentos;
	if(pLetra != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0){
		printf("%s\n",mensaje);
		do{
			fflush(stdin);
			scanf("%c",&auxChar);
			if(auxChar >= minimo && auxChar <=maximo){
				*pLetra = auxChar;
				rtn = 1;
				break;
			}
			printf("%s, %s\n",mensajeError,mensaje);
			auxReintentos--;
		}while(auxReintentos >=0);
	}
	return rtn;
}


int PedirVerificacion(char mensaje[],char mensajeError[]){
	int rtn = -1;
	char c;
	int auxReintentos=3;
	printf("%s S/N\n",mensaje);
	do{
		fflush(stdin);
		scanf("%c",&c);
		c = toupper(c);
		if(c== 'S'){
			rtn = 1;
			break;
		}
		if(c=='N'){
			rtn = 0;
			break;
		}
		printf("%s, %s S/N\n",mensajeError,mensaje);
		auxReintentos--;
	}while(auxReintentos >=0);
	return rtn;
}
