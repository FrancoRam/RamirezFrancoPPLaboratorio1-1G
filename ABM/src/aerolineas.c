/*
 * aerolineas.c
 *
 *  Created on: 21 oct 2022
 *      Author: Franc
 */

#include <stdio.h>
#include <stdlib.h>
#include "aerolineas.h"
#include <string.h>

int cargarDescripcionAerolinea(eAerolinea aerolineas[], int tam, int idLocalidad, char descripcion[]){

	int todoOk = 0;

	if(aerolineas != NULL && tam > 0 && descripcion != NULL){
		for(int i= 0; i < tam; i++){
			if(aerolineas[i].id == idLocalidad){
				strcpy(descripcion, aerolineas[i].descripcionAerolinea);
				break;
			}


		}
		todoOk = 1;
	}



	return todoOk;
}


int mostrarAerolineas(eAerolinea aerolineas[], int tam, int clear)
{
	int todoOk= 0;
	if (aerolineas != NULL && tam > 0 && clear >= 0 && clear <= 1){

		if(clear){

		}
		printf("         *** Lista de aerolineas ***     \n\n");
		printf("   ID            Descripcion               \n");
		printf("--------------------------------------------\n");
		for(int i= 0; i<tam; i++){
			printf("   %d      %20s\n", aerolineas[i].id, aerolineas[i].descripcionAerolinea);


		}
		printf("\n\n");
		todoOk=1;
	}


	return todoOk;
}
