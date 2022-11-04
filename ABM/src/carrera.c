/*
 * carrera.c
 *
 *  Created on: 17 oct 2022
 *      Author: Franco Ramirez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carrera.h"
#include "biblioteca.h"

int cargarDescripcionCarrera(eCarrera carreras[], int tam, int idLocalidad, char descripcion[]){

	int todoOk = 0;

	if(carreras != NULL && tam > 0 && descripcion != NULL){
		for(int i= 0; i < tam; i++){
			if(carreras[i].id == idLocalidad){
				strcpy(descripcion, carreras[i].descripcion);
				break;
			}


		}



		todoOk = 1;
	}



	return todoOk;
}


int mostrarCarreras(eCarrera carreras[], int tam, int clear){
	int todoOk= 0;
	if (carreras != NULL && tam > 0 && clear >= 0 && clear <= 1){

		if(clear){

		}
		printf("         *** Lista de Carreras ***     \n\n");
		printf("   ID            Descripcion               \n");
		printf("--------------------------------------------\n");
		for(int i= 0; i<tam; i++){
			printf("   %d      %20s\n", carreras[i].id, carreras[i].descripcion);


		}
		printf("\n\n");
		todoOk=1;
	}


	return todoOk;
}
