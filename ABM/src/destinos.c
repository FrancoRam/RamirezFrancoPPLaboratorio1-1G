/*
 * destinos.c
 *
 *  Created on: 21 oct 2022
 *      Author: Franc
 */

#include <stdio.h>
#include <stdlib.h>
#include "destinos.h"
#include "string.h"

int cargarDescripcionDestino(eDestino destinos[], int tam, int idLocalidad, char descripcion[]){

	int todoOk = 0;

	if(destinos != NULL && tam > 0 && descripcion != NULL){
		for(int i= 0; i < tam; i++){
			if(destinos[i].id == idLocalidad){
				strcpy(descripcion, destinos[i].descripcionDestino);
				break;
			}
		}
		todoOk = 1;
	}



	return todoOk;
}


int mostrarDestinos(eDestino destinos[], int tam, int clear){
	int todoOk= 0;
	if (destinos != NULL && tam > 0 && clear >= 0 && clear <= 1){

		if(clear){

		}
		printf("         *** Lista de destinos ***     \n\n");
		printf("   ID            Descripcion               \n");
		printf("--------------------------------------------\n");
		for(int i= 0; i<tam; i++){
			printf("   %d      %20s\n", destinos[i].id, destinos[i].descripcionDestino);


		}
		printf("\n\n");
		todoOk=1;
	}

	return todoOk;
}

int obtenerDescripcionDestino(int id, char descripcionDestino [], eDestino destinos[], int tamD){
	int todoOk=0;
	 if(descripcionDestino != NULL && tamD > 0){

		 for(int i= 0; i < tamD; i++){

			 if(destinos[i].id == id){
			 strcpy(descripcionDestino, destinos[i].descripcionDestino);
			  todoOk= 1;
				break;
			 }
		 }
	 }
	return todoOk;
}
