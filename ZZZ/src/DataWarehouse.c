/*
 * DataWarehouse.c
 *
 *  Created on: 13 oct 2022
 *      Author: Franco Ramirez
 */

#include "DataWarehouse.h"
#include <string.h>

char nombres[10][20] = {
	"Juan",
	"Pedro",
	"Sofia",
	"Miguel",
	"Valen",
	"Camila",
	"Agustin",
	"Andrea",
	"Luis",
	"Diego"

};


int idCarreras [10] = {

	500,501,502,503,504,502,504,502,501,500
};

char descCarreras [10][20] = {
	"Ingenieria", "Abogacia","Medicina", "Traductorado", "Profesorado", "Economia", "Psicologia", "Historia","Sociologia", "Programacion"


};
char sexos[10] ={'m', 'm','f','m','f','f','m','f','m','m'};

int edades [10] = {20,30,32,54,33,50,60,26,53,67};

float alturas[10] = {1.65,1.70,1.81,1.65,1.80,1.92,1.73,1.66,1.84,1.91};

char conferederaciones[6][25] = {
	"CONMEBOL", "UEFA","AFC", "CAF", "CONCACAF","OFC"


};


char regiones[6][25] = {
	"SUDAMERICA", "EUROPA", "ASIA", "AFRICA", "NORTE Y CENTRO AMERICA", "OCEANIA"

};
int hardcodearPersonas(ePersona lista[], int tam, int cant, int* pId){
	int contador = -1;
	if ( lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL){
		contador = 0;
		for(int i = 0; i < cant; i++){
			lista[i].id = *pId;
			(*pId)++;
			strcpy(lista[i].nombre, nombres[i]);
			lista[i].sexo = sexos[i];
			lista[i].edad = edades[i];
			lista[i].altura = alturas[i];
			lista[i].idCarrera = idCarreras[i];
			lista[i].isEmpty = 0;
			lista[i].idCarrera = idCarreras[i];
			contador++;

		}
	}

	return contador;
}
