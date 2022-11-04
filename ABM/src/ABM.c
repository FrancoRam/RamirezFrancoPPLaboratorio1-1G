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
#include "biblioteca.h"
#include "carrera.h"

#include "aerolineas.h"
#include "Avion.h"
#include "destinos.h"
#include "tipos.h"


#define TAM 10
#define TAM_C 5
#define TAM_A 5
#define TAM_T 4
#define TAM_D 25


#define ASC 0
#define DESC 1

#define ID 1
#define NOMBRE 2
#define SEXO 3
#define EDAD 4
#define ALTURA 5

//int obtenerDescripcionAerolineas(int id, char descripcion [], eAerolinea aerolineas[], int tam);



int main(void) {
	setbuf(stdout, NULL);
	char seguir = 's';
	int nextId = 3000;
	int nextIdA = 1000;
	int nextIdT = 5000;
	int nextIdD = 20000;

//	int campo = 1;
//int criterio = 0;




	eTipo tipos[TAM_T] = {
			{5000, "Jet"},
			{5001, "Helice"},
			{5002, "Planeador"},
			{5003, "Carga"}
	};

	eAerolinea aerolineas[TAM_A] = {
			{1000, "Lan"},
			{1001, "Iberia"},
			{1002, "Norwegian"},
			{1003, "American"},
			{1004, "Austral"}
	};

	eDestino destinos[TAM_D] = {
				{20000, "Calafate",22250},
				{20001, "Miami", 103000},
				{20002, "Milan",84400 },
				{20003, "Amsterdam", 95600}
		};


	eAvion listaAvion[TAM];


	if (!inicializarAviones(listaAvion, TAM)) {
		printf("Problema al inicializar!\n");
	}
	hardcodearAviones(&nextId, listaAvion, TAM , 5);


	do {
		switch (menu()) {

		case 1:
			if (!altaAvion(listaAvion, TAM, &nextId, aerolineas, TAM_A, tipos, TAM_T)) {
				printf("No se pudo realizar el alta\n");
			}
			else
			{
				printf("Alta exitosa\n 	");
			}
			break;
		case 2:
			if (!bajaAvion(listaAvion, TAM, aerolineas, TAM_A)) {
				printf("No se pudo realizar la baja\n");
			} else {

				printf("Baja exitosa\n 	");
			}

			break;
		case 3:
			//mostrarAviones(listaAvion, TAM, aerolineas, TAM_A, tipos, tipos, TAM_T);
			modificarAvion(listaAvion, TAM , aerolineas, TAM_A, tipos,TAM_T);
			break;
		case 4:
			//ordenarAviones(listaAvion, TAM, &criterio, &campo);
			break;
		case 5:
			mostrarAviones(listaAvion, TAM, aerolineas, TAM_A, tipos, TAM_T);
			break;
		case 6:

			break;
		case 7:
			limpiarPantalla();
			break;
		case 8:
			//mostrarMujeres(listaAvion, TAM, carreras, TAM_C);
			break;
		case 10:
			printf("Ha seleccionado salir\n");

			confirmarSalida(&seguir);
			printf("Ha salido de la aplicacion con exito!\n");
			break;
		default:
			printf("Opcion invalida!\n");
		}
		system("pause");

	} while (seguir == 's');

	return 0;
}




int obtenerDescripcionAerolineas(int id, char descripcion [], eAerolinea aerolineas[], int tam){
	int todoOk=0;
	 if(descripcion != NULL && tam > 0){

		 for(int i= 0; i < tam; i++){

			 if(aerolineas[i].id == id){
			 strcpy(descripcion, aerolineas[i].descripcionAerolinea);
			  todoOk= 1;
				break;
			 }

		 }



	 }


	return todoOk;
}




















