#include "Passenger.h"

static int IsValidNombre(char* posibleNombre);
static int IsValidApellido(char* posibleApellido);
static int IsValidId(char* arrayPosiblesNumeros);
static int IsValidPrice(char arrayPosiblesNumeros[]);


Passenger* Passenger_new(){
	return (Passenger*)malloc(sizeof(Passenger));
}

Passenger* Passenger_newParametrosTxt(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,int idVuelo){
	Passenger* auxPassengerP = NULL;
	auxPassengerP = Passenger_new();
	if(auxPassengerP != NULL && idStr != NULL && apellidoStr != NULL && nombreStr != NULL &&
	   precioStr != NULL && tipoPasajeroStr != NULL && idVuelo >= 0){
		if( Passenger_setIdTxt(auxPassengerP,idStr) ==1 &&
			Passenger_setNombre(auxPassengerP,nombreStr) ==1 &&
			Passenger_setApellido(auxPassengerP,apellidoStr) ==1 &&
			Passenger_setPrecioTxt(auxPassengerP,precioStr) ==1 &&
			Passenger_setTipoPasajeroTxt(auxPassengerP,tipoPasajeroStr) ==1 &&
			Passenger_setIdVuelo(auxPassengerP,idVuelo) ==1){
		}
		else{
			free(auxPassengerP);
			auxPassengerP = NULL;
		}
	}
	else{
		free(auxPassengerP);
		auxPassengerP = NULL;
	}
	return auxPassengerP;
}

Passenger* Passenger_newParametros(int id,char* nombreStr,char* apellidoStr,float precio,int tipoPasajero,int idVuelo){
	Passenger* auxPassengerP = NULL;
	auxPassengerP = Passenger_new();
	if(auxPassengerP != NULL && id >= 0 && apellidoStr != NULL && nombreStr != NULL &&
	   precio > 0 && (tipoPasajero >= 1 && tipoPasajero <= 3) && idVuelo >= 0){
		if( Passenger_setId(auxPassengerP,id) ==1 &&
			Passenger_setNombre(auxPassengerP,nombreStr) ==1 &&
			Passenger_setApellido(auxPassengerP,apellidoStr) ==1 &&
			Passenger_setPrecio(auxPassengerP,precio) ==1 &&
			Passenger_setTipoPasajero(auxPassengerP,tipoPasajero) ==1 &&
			Passenger_setIdVuelo(auxPassengerP,idVuelo) == 1){
		}
		else{
			free(auxPassengerP);
			auxPassengerP = NULL;
		}
	}
	else{
		free(auxPassengerP);
		auxPassengerP = NULL;
	}
	return auxPassengerP;
}

int Passenger_setIdTxt(Passenger* this,char* id){
	int rtn=-1;
	if(this != NULL && id != NULL){
		if(IsValidId(id)==1){
			rtn =1;
			this->id = atoi(id);
		}
	}
	return rtn;
}
int Passenger_getIdTxt(Passenger* this,char* id){
	int rtn=-1;
	if(this != NULL && id != NULL){
		rtn =1;
		sprintf(id,"%d",this->id);
	}
	return rtn;
}
int Passenger_setId(Passenger* this,int id){
	int rtn=-1;
	if(this != NULL && id >= 0){
		rtn =1;
		this->id = id;
	}
	return rtn;
}
int Passenger_getId(Passenger* this,int* id){
	int rtn=-1;
	if(this != NULL && id >= 0){
		rtn =1;
		*id = this->id;
	}
	return rtn;
}

int Passenger_setNombre(Passenger* this,char* nombre){
	int rtn=-1;
	if(this != NULL && nombre != NULL){
		if(IsValidNombre(nombre)==1){
			rtn =1;
			strncpy(this->nombre,nombre,NOMBRE_LEN);
		}
	}
	return rtn;
}
int Passenger_getNombre(Passenger* this,char* nombre){
	int rtn=-1;
	if(this != NULL && nombre != NULL){
		rtn =1;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return rtn;
}

int Passenger_setApellido(Passenger* this,char* apellido){
	int rtn=-1;
	if(this != NULL && apellido != NULL){
		if(IsValidApellido(apellido)==1){
			rtn =1;
			strncpy(this->apellido,apellido,APELLIDO_LEN);
		}
	}
	return rtn;
}
int Passenger_getApellido(Passenger* this,char* apellido){
	int rtn=-1;
	if(this != NULL && apellido != NULL){
		rtn =1;
		strncpy(apellido,this->apellido,APELLIDO_LEN);
	}
	return rtn;
}

int Passenger_setTipoPasajeroTxt(Passenger* this,char* tipoPasajero){
	int rtn=-1;
	if(this != NULL && tipoPasajero != NULL){
		rtn =0;
		if(strcmp(tipoPasajero,"FirstClass")==0){
			this->tipoPasajero = 1;
			rtn =1;
		}
		if(strcmp(tipoPasajero,"ExecutiveClass")==0){
			this->tipoPasajero = 2;
			rtn =1;
		}
		if(strcmp(tipoPasajero,"EconomyClass")==0){
			this->tipoPasajero = 3;
			rtn =1;
		}
	}
	return rtn;
}
int Passenger_getTipoPasajeroTxt(Passenger* this,char* tipoPasajero){
	int rtn=-1;
	if(this != NULL && tipoPasajero != NULL){
		rtn =1;
		sprintf(tipoPasajero,"%d",this->tipoPasajero);
	}
	return rtn;
}
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
	int rtn=-1;
	if(this != NULL && tipoPasajero >= 0){
		rtn =1;
		this->tipoPasajero = tipoPasajero;
	}
	return rtn;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){
	int rtn=-1;
	if(this != NULL && tipoPasajero >= 0){
		rtn =1;
		*tipoPasajero = this->tipoPasajero;
	}
	return rtn;
}

int Passenger_setPrecioTxt(Passenger* this,char* precio){
	int rtn=-1;
	if(this != NULL && precio != NULL){
		if(IsValidPrice(precio)==1){
			rtn =1;
			this->precio = atof(precio);
		}
	}
	return rtn;
}
int Passenger_getPrecioTxt(Passenger* this,char* precio){
	int rtn=-1;
	if(this != NULL && precio != NULL){
		rtn =1;
		sprintf(precio,"%f",this->precio);
	}
	return rtn;
}
int Passenger_setPrecio(Passenger* this,float precio){
	int rtn=-1;
	if(this != NULL && precio >= 0){
		rtn =1;
		this->precio = precio;
	}
	return rtn;
}
int Passenger_getPrecio(Passenger* this,float* precio){
	int rtn=-1;
	if(this != NULL && precio >= 0){
		rtn =1;
		*precio = this->precio;
	}
	return rtn;
}

int Passenger_setIdVuelo(Passenger* this,int id){
	int rtn=-1;
	if(this != NULL && id >= 0){
		rtn =1;
		this->idVuelo = id;
	}
	return rtn;
}
int Passenger_getIdVuelo(Passenger* this,int* id){
	int rtn=-1;
	if(this != NULL && id >= 0){
		rtn =1;
		*id = this->idVuelo;
	}
	return rtn;
}


static int IsValidNombre(char* posibleNombre){
	int retorno = 1;
	int i = 0;

	if(posibleNombre != NULL){
		while(posibleNombre[i] != '\0'){
			if(!((posibleNombre[i]>=65 && posibleNombre[i]<=90)||(posibleNombre[i]>=97 && posibleNombre[i]<=122)||posibleNombre[i]==' ')){
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
static int IsValidApellido(char* posibleApellido){
	int retorno = 1;
	int i = 0;

	if(posibleApellido != NULL){
		while(posibleApellido[i] != '\0'){
			if(!((posibleApellido[i]>=65 && posibleApellido[i]<=90)||(posibleApellido[i]>=97 && posibleApellido[i]<=122)||posibleApellido[i]==' ')){
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
static int IsValidPrice(char arrayPosiblesNumeros[]){
	int retorno = 1;
	int i = 0;
	int flagDecimal = 0;

	if(arrayPosiblesNumeros != NULL){
		if(arrayPosiblesNumeros[i] == '.' || arrayPosiblesNumeros[i] == ','){
			retorno = -1;
		}
		while(!(arrayPosiblesNumeros[i] == '\0' || retorno == -1)){
			if((arrayPosiblesNumeros[i] == '.' || arrayPosiblesNumeros[i] == ',') && flagDecimal == 0){
				arrayPosiblesNumeros[i] = '.';//para que siempre sea un punto aunque ingresen una coma
				flagDecimal = 1; // solo se permite que tenga una coma/punto en un numero decimal
			}
			else if(arrayPosiblesNumeros[i] < '0' || arrayPosiblesNumeros[i] > '9'){
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


void Passenger_showPassenger(Passenger* passenger,char flightCode[], char flightStatus[]){
	char auxTypePassenger[MAX_CHARS];
	switch (passenger->tipoPasajero){
	case 1:
		strcpy(auxTypePassenger,"FirstClass");
		break;
	case 2:
		strcpy(auxTypePassenger,"ExecutiveClass");
		break;
	case 3:
		strcpy(auxTypePassenger,"EconomyClass");
		break;
	}

	printf( "| %-5d| %-20s| %-20s| $%-19.2f| %-20s| %-20s| %-20s|\n",
			passenger->id,
			passenger->nombre,
			passenger->apellido,
			passenger->precio,
			auxTypePassenger,
			flightCode,
			flightStatus);

}

Passenger* Passenger_findPassengerById(LinkedList* this,int id){
	Passenger* rtn = NULL;
	int i;
	Passenger* auxPassenger;
	if(this != NULL && id >= 0){
		for(i = 0;i < ll_len(this); i++){
			auxPassenger = ll_get(this, i);
			if(auxPassenger != NULL && auxPassenger->id == id){
				rtn = auxPassenger;
				break;
			}
		}
	}
	return rtn;
}

int Passenger_lastId(char* path){
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
			pFileID = fopen("lastID","w");
			fprintf(pFileID, "%d\n",maxId);
			fclose(pFileID);
			rtn = 1;
		}
	}
	else{
		pFileID = fopen("lastID","w");
		maxId = 0;
		fprintf(pFileID, "%d\n",maxId);
		fclose(pFileID);
		rtn = 1;
	}
	return rtn;
}

int Passenger_GenerarId(void){
	FILE* pFileID;
	char maxId[MAX_CHARS];
	int newId;
	pFileID = fopen("lastID","r");
	fscanf(pFileID,"%[^,]\n",maxId);
	fclose(pFileID);
	newId = atoi(maxId);
	newId++;
	pFileID = fopen("lastID","w");
	fprintf(pFileID, "%d\n",newId);
	fclose(pFileID);
	return newId;
}

int Passenger_GetLastId(void){
	FILE* pFileID;
	char maxId[MAX_CHARS];
	pFileID = fopen("lastID","r");
	fscanf(pFileID,"%[^,]\n",maxId);
	fclose(pFileID);
	return atoi(maxId);
}

int Passenger_isValid(Passenger* this){
    int rtn = -1;
    int id;
    char nombre[MAX_CHARS];
    char apellido[MAX_CHARS];
    float precio;
    int tipoPasajero;
    int idVuelo;

    if(this != NULL){
        Passenger_getId(this,&id);
        Passenger_getNombre(this,nombre);
        Passenger_getApellido(this,apellido);
        Passenger_getPrecio(this,&precio);
        Passenger_getTipoPasajero(this,&tipoPasajero);
        Passenger_getIdVuelo(this,&idVuelo);

        if(id > 0 && nombre != NULL && apellido != NULL && precio > 0 && tipoPasajero > 0 && idVuelo > 0){
            rtn=1;
        }
    }
    return rtn;
}

int Passenger_remplazar(Passenger* this, Passenger* this2){
	int rtn = -1;
	if(this != NULL && this2 != NULL){
		this->id = this2->id;
		strncpy(this->nombre,this2->nombre,MAX_CHARS);
		strncpy(this->apellido,this2->apellido,MAX_CHARS);
		this->precio = this2->precio;
		this->tipoPasajero = this2->tipoPasajero;
		this->idVuelo = this2->idVuelo;
		rtn =1;
	}
	return rtn;
}

int Passenger_sortById( void* this1, void* this2){
    int rtn = 0;
    Passenger* auxP1;
    Passenger* auxP2;
    if( this1 != NULL && this2 != NULL){
    	auxP1 = (Passenger*) this1;
    	auxP2 = (Passenger*) this2;
        if(auxP1->id > auxP2->id){
        	rtn = 1;
        } else if(auxP1->id < auxP2->id){
        	rtn = -1;
        } else{
        	rtn = 0;
        }
    }
    return rtn;
}

int Passenger_sortByName( void* this1, void* this2){
    int rtn = 0;
    Passenger* auxP1;
    Passenger* auxP2;
    if( this1 != NULL && this2 != NULL){
    	auxP1 = (Passenger*) this1;
    	auxP2 = (Passenger*) this2;
        if( strcmp(auxP1->nombre, auxP2->nombre) > 0){
        	rtn = 1;
        } else if( strcmp(auxP1->nombre, auxP2->nombre) < 0){
        	rtn = -1;
        } else{
        	rtn = 0;
        }
    }
    return rtn;
}

int Passenger_sortByApellido( void* this1, void* this2){
    int rtn = 0;
    Passenger* auxP1;
    Passenger* auxP2;
    if( this1 != NULL && this2 != NULL){
    	auxP1 = (Passenger*) this1;
    	auxP2 = (Passenger*) this2;
        if( strcmp(auxP1->apellido, auxP2->apellido) > 0){
        	rtn = 1;
        } else if( strcmp(auxP1->apellido, auxP2->apellido) < 0){
        	rtn = -1;
        } else{
        	rtn = 0;
        }
    }
    return rtn;
}

int Passenger_sortByPrice( void* this1, void* this2){
    int rtn = 0;
    Passenger* auxP1;
    Passenger* auxP2;
    if( this1 != NULL && this2 != NULL){
    	auxP1 = (Passenger*) this1;
    	auxP2 = (Passenger*) this2;
        if(auxP1->precio > auxP2->precio){
        	rtn = 1;
        } else if(auxP1->precio < auxP2->precio){
        	rtn = -1;
        } else{
        	rtn = 0;
        }
    }
    return rtn;
}

int Passenger_sortByType( void* this1, void* this2){
    int rtn = 0;
    Passenger* auxP1;
    Passenger* auxP2;
    if( this1 != NULL && this2 != NULL){
    	auxP1 = (Passenger*) this1;
    	auxP2 = (Passenger*) this2;
        if(auxP1->tipoPasajero > auxP2->tipoPasajero){
        	rtn = 1;
        } else if(auxP1->tipoPasajero < auxP2->tipoPasajero){
        	rtn = -1;
        } else{
        	rtn = 0;
        }
    }
    return rtn;
}

int Passenger_sortByFlight( void* this1, void* this2){
    int rtn = 0;
    Passenger* auxP1;
    Passenger* auxP2;
    if( this1 != NULL && this2 != NULL){
    	auxP1 = (Passenger*) this1;
    	auxP2 = (Passenger*) this2;
        if(auxP1->idVuelo > auxP2->idVuelo){
        	rtn = 1;
        } else if(auxP1->idVuelo < auxP2->idVuelo){
        	rtn = -1;
        } else{
        	rtn = 0;
        }
    }
    return rtn;
}
