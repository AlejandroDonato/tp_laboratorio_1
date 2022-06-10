#include "Vuelo.h"

static int IsValidId(char* arrayPosiblesNumeros);
static int IsValidFlyCode(char arrayPosiblesLetras[]);
static int IsValidEstadoVuelo(char* posibleEstadoVuelo);
static int V_GenerarId(void);
static int V_GenerarId(void){
	static int contadorV = 100;
	return contadorV++;
}

Flight* Flight_new(){
	return (Flight*)malloc(sizeof(Flight));
}

Flight* Flight_newParametros(char* codigoStr, char* stadoStr){
	Flight* auxFlightP = NULL;
	auxFlightP = Flight_new();
	if(auxFlightP != NULL && codigoStr != NULL){
		if( Flight_setCodigoVuelo(auxFlightP,codigoStr) ==1 &&
			Flight_setEstadoVuelo(auxFlightP,stadoStr) == 1){
			auxFlightP->id = V_GenerarId();
		}
		else{
			free(auxFlightP);
			auxFlightP = NULL;
		}
	}
	else{
		free(auxFlightP);
		auxFlightP = NULL;
	}
	return auxFlightP;
}

int Flight_delete(Flight* flight[],int len, int index){
	int rtn=-1;
	if(flight != NULL && index >= 0 && index <= len && flight[index] != NULL){
		rtn =1;
		free(flight[index]);
		flight[index] = NULL;
	}
	return rtn;
}


int Flight_setIdTxt(Flight* this,char* id){
	int rtn=-1;
	if(this != NULL && id != NULL){
		if(IsValidId(id)==1){
			rtn =1;
			this->id = atoi(id);
		}
	}
	return rtn;
}
int Flight_getIdTxt(Flight* this,char* id){
	int rtn=-1;
	if(this != NULL && id != NULL){
		rtn =1;
		sprintf(id,"%d",this->id);
	}
	return rtn;
}
int Flight_setId(Flight* this,int id){
	int rtn=-1;
	if(this != NULL && id >= 0){
		rtn =1;
		this->id = id;
	}
	return rtn;
}
int Flight_getId(Flight* this,int* id){
	int rtn=-1;
	if(this != NULL && id >= 0){
		rtn =1;
		*id = this->id;
	}
	return rtn;
}

int Flight_setCodigoVuelo(Flight* this,char* codigoVuelo){
	int rtn=-1;
	if(this != NULL && codigoVuelo != NULL){
		if(IsValidFlyCode(codigoVuelo)==1){
			rtn =1;
			strncpy(this->flightCode,codigoVuelo,FLIGHT_CODE);
		}
	}
	return rtn;
}
int Flight_getCodigoVuelo(Flight* this,char* codigoVuelo){
	int rtn=-1;
	if(this != NULL && codigoVuelo != NULL){
		rtn =1;
		strncpy(codigoVuelo,this->flightCode,FLIGHT_CODE);
	}
	return rtn;
}

int Flight_setEstadoVuelo(Flight* this,char* estadoVuelo){
	int rtn=-1;
	if(this != NULL && estadoVuelo != NULL){
		if(IsValidEstadoVuelo(estadoVuelo)==1){
			rtn =1;
			strncpy(this->statusFlight,estadoVuelo,MAX_CHARS);
		}
	}
	return rtn;
}
int Flight_getEstadoVuelo(Flight* this,char* estadoVuelo){
	int rtn=-1;
	if(this != NULL && estadoVuelo != NULL){
		rtn =1;
		strncpy(estadoVuelo,this->statusFlight,MAX_CHARS);
	}
	return rtn;
}


static int IsValidId(char* arrayPosiblesNumeros){
	int retorno = 1;
	int i = 0;
	if(arrayPosiblesNumeros != NULL){
		while(arrayPosiblesNumeros[i] != '\0'){
			if(arrayPosiblesNumeros[i] < '0' || arrayPosiblesNumeros[i] > '9'){
				retorno = -1;
				break;
			}
			i++;
		}
	}
	else{
		retorno = -1;
	}
	return retorno;
}
static int IsValidFlyCode(char arrayPosiblesLetras[]){
	int retorno = 1;
	int i = 0;

	if(arrayPosiblesLetras != NULL){

		while(arrayPosiblesLetras[i] != '\0'){
			if(!((arrayPosiblesLetras[i]>=65 && arrayPosiblesLetras[i]<=90)||
				(arrayPosiblesLetras[i]>=97 && arrayPosiblesLetras[i]<=122)||
				(arrayPosiblesLetras[i] >='0' && arrayPosiblesLetras[i] <='9'))){
				retorno = -1;
				break;
			}
			i++;
		}
	}
	else{
		retorno = -1;
	}
	return retorno;
}
static int IsValidEstadoVuelo(char* posibleEstadoVuelo){
	int retorno = 1;
	int i = 0;

	if(posibleEstadoVuelo != NULL){
		while(posibleEstadoVuelo[i] != '\0'){
			if(!((posibleEstadoVuelo[i]>=65 && posibleEstadoVuelo[i]<=90)||(posibleEstadoVuelo[i]>=97 && posibleEstadoVuelo[i]<=122)||posibleEstadoVuelo[i]==' ')){
				retorno = -1;
				break;
			}
			i++;
		}
	}
	else{
		retorno = -1;
	}
	return retorno;
}


void Flight_showFlight(Flight* this){
	printf( "| %-7d| %-22s| %-22s|\n"
			"+--------+-----------------------+-----------------------+\n",
			this->id,
			this->flightCode,
			this->statusFlight);
}

int Flight_lastId(char* path){
	int rtn = -1;
	int maxId = -1;
	char auxId[MAX_CHARS];
	char auxBasura[MAX_CHARS];
	FILE* pFile;
	FILE* pFileID;
	if(path != NULL){
		pFile = fopen(path,"r");
		do{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxBasura,auxBasura,auxBasura,auxBasura,auxBasura,auxBasura);
			if(atoi(auxId) > maxId){
				maxId = atoi(auxId);
			}
		}while(!feof(pFile));
		fclose(pFile);
		if(maxId >= 0){
			pFileID = fopen("lastIDVuelo","w");
			fprintf(pFileID, "%d\n",maxId);
			fclose(pFileID);
			rtn = 1;
		}

	}
	return rtn;
}

int Flight_GenerarId(void){
	FILE* pFileID;
	char maxId[MAX_CHARS];
	int newId;
	newId = atoi(maxId);
	pFileID = fopen("lastIDVuelo","r");
	fscanf(pFileID,"%[^,]\n",maxId);
	fclose(pFileID);
	newId++;
	pFileID = fopen("lastIDVuelo","w");
	fprintf(pFileID, "%d\n",newId);
	fclose(pFileID);
	return newId;
}

int Flight_findIdByFlightCode(LinkedList* this, char* flightCode){
	int rtn = -1;
	int i;
	Flight* auxFlight;
	if(this != NULL && flightCode != NULL){
		rtn = -2;
		i = 0;
		while(i < ll_len(this)){
			auxFlight = ll_get(this,i);
			if(strcmp(auxFlight->flightCode,flightCode)==0){
				rtn = auxFlight->id;
				break;
			}
			i++;
		}
	}
	return rtn;
}

Flight* Flight_findFlightbyId(LinkedList* this, int id){
	Flight* rtn = NULL;
	int i;
	Flight* auxFlight;
	if(this != NULL && id >0){
		i = 0;
		while(i < ll_len(this)){
			auxFlight = ll_get(this,i);
			if(auxFlight->id == id){
				rtn = auxFlight;
				break;
			}
			i++;
		}
	}
	return rtn;
}

int Flight_findMaxId(LinkedList* this){
	int maxID = -1;
	int i;
	Flight* auxFlight;
	if(this != NULL){
		for(i = 0;i < ll_len(this); i++){
			auxFlight = ll_get(this,i);
			if(auxFlight->id > maxID){
				maxID = auxFlight->id;
			}
		}
	}
	return maxID;
}

int Flight_findMinId(LinkedList* this){
	int maxID = -1;
	int i;
	Flight* auxFlight;
	if(this != NULL){
		for(i = 0;i < ll_len(this); i++){
			auxFlight = ll_get(this,i);
			if(maxID == -1){
				maxID = auxFlight->id;
			}
			else if(auxFlight->id < maxID){
				maxID = auxFlight->id;
			}
		}
	}
	return maxID;
}

int Flight_flightRepetido(Flight *auxVuelos[],char codigoVuelo[]){
	int i;
	int rtn = 1;
	for(i = 0; i < 1000; ++i){
		if(strcmp(auxVuelos[i]->flightCode,codigoVuelo)== 0){
			rtn = -1;
			break;
		}
	}
	return rtn;
}

