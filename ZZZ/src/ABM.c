/*
 ============================================================================
 Name        : ABM.c
 Author      : Ramirez Franco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"
#include "DataWarehouse.h"
#include "biblioteca.h"
#include "carrera.h"

#define TAM 10
#define TAM_C 5

#define ASC 0
#define DESC 1

#define ID 1
#define NOMBRE 2
#define SEXO 3
#define EDAD 4
#define ALTURA 5




int main(void) {
	setbuf(stdout, NULL);
	char seguir = 's';
	int nextId = 20000;
	int campo = 1;
	int criterio = 0;
	ePersona lista[TAM];
	eCarrera carreras[TAM_C] = {
			{500, "Sistemas"},
			{501, "Electronica"},
			{502, "Industrial"},
			{503, "Mecanica"},
			{504, "Quimica"}


	};


	if (!inicializarPersonas(lista, TAM)) {
		printf("Problema al inicializar!\n");
	}

	hardcodearPersonas(lista, TAM, 8, &nextId);


	do {
		switch (menu()) {

		case 1:
			if (!altaPersona(lista, TAM, &nextId, carreras, TAM_C)) {
				printf("No se pudo realizar el alta\n");
			} else {

				printf("Alta exitosa\n 	");
			}
			break;
		case 2:
			if (!bajaPersona(lista, TAM, carreras, TAM_C)) {
				printf("No se pudo realizar la baja\n");
			} else {

				printf("Baja exitosa\n 	");
			}

			break;
		case 3:
			modificarPersona(lista, TAM , carreras, TAM_C);
			break;
		case 4:
			ordenarPersonas(lista, TAM, &criterio, &campo);
			break;
		case 5:
			mostrarPersonas(lista, TAM, carreras, TAM_C);
			break;
		case 6:
			printf("Ha seleccionado salir\n");

			confirmarSalida(&seguir);
			printf("Ha salido de la aplicacion con exito!\n");
			break;
		case 7:
			limpiarPantalla();
			mostrarCarreras(carreras, TAM_C, 1);
			break;
		case 8: mostrarMujeres(lista, TAM, carreras, TAM_C);
			break;
		default:
			printf("Opcion invalida!\n");
		}
		system("pause");

	} while (seguir == 's');

	return 0;
}




int obtenerDescripcionCarrera(int id, char descripcion [], eCarrera carreras[], int tam){
	int todoOk=0;
	 if(descripcion != NULL && tam > 0){

		 for(int i= 0; i < tam; i++){

			 if(carreras[i].id == id){
			 strcpy(descripcion, carreras[i].descripcion);
			  todoOk= 1;
				break;


			 }

		 }



	 }


	return todoOk;
}
