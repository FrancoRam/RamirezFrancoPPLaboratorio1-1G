/*
 * tipos.c
 *
 *  Created on: 21 oct 2022
 *      Author: Franc
 */
#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include <string.h>

int cargarDescripcionTipo(eTipo tipos[], int tam, int idLocalidad, char descripcion[]){

	int todoOk = 0;

	if(tipos != NULL && tam > 0 && descripcion != NULL){
		for(int i= 0; i < tam; i++){
			if(tipos[i].id == idLocalidad){
				strcpy(descripcion, tipos[i].descripcionTipo);
				break;
			}
		}
		todoOk = 1;
	}



	return todoOk;
}


int mostrarTipos(eTipo tipos[], int tam, int clear){
	int todoOk= 0;
	if (tipos != NULL && tam > 0 && clear >= 0 && clear <= 1){

		if(clear){

		}
		printf("         *** Lista de tipos ***     \n\n");
		printf("   ID            Descripcion               \n");
		printf("--------------------------------------------\n");
		for(int i= 0; i<tam; i++){
			printf("   %d      %20s\n", tipos[i].id, tipos[i].descripcionTipo);


		}
		printf("\n\n");
		todoOk=1;
	}


	return todoOk;
}

int obtenerDescripcionTipo(int id, char descripcionTipo [], eTipo tipos[], int tamT){
	int todoOk=0;
	 if(descripcionTipo != NULL && tamT > 0){

		 for(int i= 0; i < tamT; i++){

			 if(tipos[i].id == id){
			 strcpy(descripcionTipo, tipos[i].descripcionTipo);
			  todoOk= 1;
				break;
			 }
		 }
	 }
	return todoOk;
}
