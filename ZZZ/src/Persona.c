/*
 * Persona.c
 *
 *  Created on: 13 oct 2022
 *      Author: Agustín
 */

#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"
#include "carrera.h"

int menu() {
	int opcion;
	limpiarPantalla();
	printf("     *** ABM PERSONAS  ***\n\n");
	printf("1- Alta persona\n");
	printf("2- Baja persona\n");
	printf("3- Modificar persona\n");
	printf("4- Ordenar personas\n");
	printf("5- Listar personas\n");
	printf("6- Salir\n");
	printf("7- Listar Carreras\n");
	printf("8- Mostrar Mujeres\n");
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	return opcion;

}

int inicializarPersonas(ePersona lista[], int tam) {

	int todoOk = 0;
	if (lista != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {

			lista[i].isEmpty = 1;
		}

		todoOk = 1;
	}
	return todoOk;
}

int buscarLibre(ePersona lista[], int tam) {

	int indiceEstructuraVacia = -1;
	for (int i = 0; i < tam; i++) {

		if (lista[i].isEmpty) {
			indiceEstructuraVacia = i;
			break;
		}

	}

	return indiceEstructuraVacia;
}

int altaPersona(ePersona lista[], int tam, int *pId,eCarrera carreras[], int tamC) {
	int indice;
	ePersona auxPersona;
	int todoOk = 0;
	if (lista != NULL && tam > 0) {
		limpiarPantalla();
		printf(" ***   Alta Persona   *** \n");
		indice = buscarLibre(lista, tam);
		if (indice == -1) {
			printf("No hay lugar\n");
		} else {

			auxPersona.id = *pId;
			(*pId)++;

			printf("Ingrese nombre: \n");
			fflush(stdin);
			gets(auxPersona.nombre);
			strlwr(auxPersona.nombre);
			auxPersona.nombre[0] = toupper(auxPersona.nombre[0]);

			printf("Ingrese sexo: \n");
			fflush(stdin);
			//scanf("%c", &auxPersona.sexo);
			auxPersona.sexo= tolower(getchar());
			while(!validarCaracter(auxPersona.sexo, 'f', 'm')){
							printf("Sexo Invalido. Reingrese sexo: \n");
							fflush(stdin);
							auxPersona.sexo= tolower(getchar());

						}

			if(utn_getNumero(&auxPersona.edad, "Ingrese la edad: \n",
						"Su numero no pudo ser validado\n Ingrese nuevamente una edad valida (1-120)\n", 1, 120) == 1){
					printf("Su numero fue valido correctamente!\n");
				}
			/*printf("Ingrese edad: \n");
			scanf("%d", &auxPersona.edad);*/

			/*printf("Ingrese altura: \n");
			scanf("%f", &auxPersona.altura);*/
			if(getFloat(&auxPersona.altura, "Ingrese la altura: \n",
									"Su numero no pudo ser validado\n Ingrese nuevamente una altura valida (1.30-2.20)\n", 1.30, 2.20) == 1){
								printf("Su numero fue valido correctamente!\n");
							}

			mostrarCarreras(carreras, tamC, 1);
			if(utn_getNumero(&auxPersona.idCarrera, "Ingrese el id de la carrera: \n",
									"Su numero no pudo ser validado\n Ingrese nuevamente una edad valida (500-504)\n", 500, 504) == 1){
								printf("Su numero fue valido correctamente!\n");
							}
			auxPersona.isEmpty = 0;
			lista[indice] = auxPersona;
			todoOk = 1;
		}

	}
	return todoOk;
}

void mostrarPersona(ePersona p, eCarrera carreras[], int tam) {
	char descCarrera[20];

	cargarDescripcionCarrera(carreras, tam, p.idCarrera, descCarrera);
	printf(" %d       %-8s      %c             %2d             %.2f       %-12s \n", p.id,
			p.nombre, p.sexo, p.edad, p.altura, descCarrera);

}
int mostrarPersonas(ePersona lista[], int tam, eCarrera carreras[], int tamC) {

	int flag = 1;
	int todoOk = 0;
//	char descripcion [20];
	if (lista != NULL && tam > 0) {
		limpiarPantalla();
		printf("                  *** Lista de Personas ***        \n");
		printf(
				"---------------------------------------------------------------------------\n");
		printf(
				" ID        Nombre        Sexo          Edad           Altura       Carrera\n");
		printf(
				"---------------------------------------------------------------------------\n");

		for (int i = 0; i < tam; i++) {
			if (!(lista[i].isEmpty)) {
				//obtenerDescripcionCarrera(lista[i].id, descripcion, carreras, 10);
				mostrarPersona(lista[i], carreras, tamC);
				flag = 0;
			}

		}
		if (flag) {
			printf("No hay personas para mostrar\n");
		}

		todoOk = 1;
	}

	return todoOk;

}

int bajaPersona(ePersona lista[], int tam, eCarrera carreras[], int tamC) {
	int todoOk = 0;
	int indice;
	int id;
	char confirma;
	if (lista != NULL && tam > 0) {
		limpiarPantalla();
		printf("      *** Baja Persona ***     \n \n");
		printf("Ingrese ID: ");
		scanf("%d", &id);
		indice = buscarPersonaId(lista, tam, id);
		if (indice == -1) {
			printf("El ID: %d no esta registrado en el sistema\n", id);
		} else {
			mostrarPersona(lista[indice], carreras, tamC);
			printf("Confirma baja?:\n");
			fflush(stdin);
			scanf("%c", &confirma);
			if (confirma == 's') {
				lista[indice].isEmpty = 1;
				todoOk = 1;
			} else {
				printf("Baja cancelada por el usuario \n");
			}

		}
	}

	return todoOk;
}

int buscarPersonaId(ePersona lista[], int tam, int id) {
	int indice = -1;
	for (int i = 0; i < tam; i++) {

		if (lista[i].id == id && !lista[i].isEmpty) {
			indice = i;
			break;
		}

	}

	return indice;
}

int modificarPersona(ePersona lista[], int tam, eCarrera carreras[], int tamC) {

	int todoOk = 0;
	int indice;
	int id;
	char confirma;
	char seguir = 's';
	if (lista != NULL && tam > 0) {
		limpiarPantalla();

		printf("      *** Modificar Persona ***     \n \n");
		if(utn_getNumero(&id, "Ingrese el ID: \n",
								"Su numero no pudo ser validado\n Ingrese nuevamente un ID valido\n", 20000, 20010) == 1){
							printf("Su numero fue valido correctamente!\n");
						}
		indice = buscarPersonaId(lista, tam, id);

		if (indice == -1) {
			printf("El ID: %d no esta registrado en el sistema\n", id);
		} else {
			mostrarPersona(lista[indice], carreras, tamC);
			printf("Confirma que quiere modificar esta persona?");
			fflush(stdin);
			//scanf("%c", &confirma);
			confirma= tolower(getchar());
			while(!validarCaracter(confirma, 's', 'n')){
										printf("Caracter Invalido. Reingrese caracter valido para confirmar (s para confirmar - n para no confirmar): \n");
										fflush(stdin);
										confirma= tolower(getchar());

									}
			printf("\n\n");
			if(confirma == 's'){
				do {
								switch (submenuModificar()) {
								case 1:
									printf("Ha ingresado para modificar el nombre\n");
									printf("Cual es el nuevo nombre que desea ingresar?: \n");
									fflush(stdin);
									gets(lista[indice].nombre);
									strlwr(lista[indice].nombre);
									lista[indice].nombre[0] = toupper(lista[indice].nombre[0]);
									break;
								case 2:
									printf("Ha ingresado para modificar el sexo\n");
									printf("Cual es el nuevo sexo que desea ingresar?: \n");
									fflush(stdin);
									scanf("%c", &lista[indice].sexo);
									while(!validarCaracter(lista[indice].sexo, 'f', 'm')){
																printf("Sexo Invalido. Reingrese sexo: \n");
																fflush(stdin);
																lista[indice].sexo= tolower(getchar());

															}

									break;
								case 3:
									/*printf("Ha ingresado para modificar la edad\n");

									printf("Cual es la nueva edad que desea ingresar?: \n");
									scanf("%d", &lista[indice].edad);*/
									if(utn_getNumero(&lista[indice].edad, "Ingrese la nueva edad: \n",
															"Su numero no pudo ser validado\n Ingrese nuevamente una edad valida (1-120)\n", 1, 120) == 1){
														printf("Su numero fue valido correctamente!\n");
													}
									break;
								case 4:
									printf("Ha ingresado para modificar la altura\n");
									/*printf("Cual es la nueva altura que desea ingresar? \n");
									scanf("%f", &lista[indice].altura);*/
									if(getFloat(&lista[indice].altura, "Ingrese la altura: \n",
															"Su numero no pudo ser validado\n Ingrese nuevamente una altura valida (1.30-2.20)\n", 1.30, 2.20) == 1){
														printf("Su numero fue valido correctamente!\n");
													}

									break;
								case 5:
									printf("Ha salido de la modificacion de los datos\n");
									seguir = 'n';
									break;
								default:
									printf("La opcion ingresada no es valida\n");

								}
								system("pause");
							} while (seguir == 's');
			}else{
				printf("Se ha cancelado la modificacion de los datos de la persona\n");
			}


		}
	}

	return todoOk;
}

int submenuModificar() {
	int opcion;


	printf("     *** Que datos desea modificar?  ***\n\n");
	printf("1- Nombre\n");
	printf("2- Sexo\n");
	printf("3- Edad\n");
	printf("4- Altura\n");
	printf("5- Salir\n");
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	return opcion;

}

int ordenarPersonas(ePersona lista[], int tam, int* pCriterio, int* pCampo){
	int todoOk = 0;
	char seguirCriterio = 's';
	char seguirCampo = 's';
	ePersona auxPersona;
	do{
		switch(submenuCriterioOrdenamiento()){
		case 1: *pCriterio= 0;
		seguirCriterio = 'n';
			break;
		case 2: *pCriterio= 1;
		seguirCriterio = 'n';
			break;
		case 3: printf("Ha seleccionado salir\n");

		confirmarSalida(&seguirCriterio);
		printf("Ha salido del submenu con exito!\n");
		break;
	default:
		printf("Opcion invalida!\n");

		}system("pause");


	}
	while(seguirCriterio == 's');


	do{
			switch(submenuCampoOrdenamiento()){
			case 1: *pCampo= 1;
			seguirCampo = 'n';
				break;
			case 2: *pCampo= 2;
			seguirCampo = 'n';
				break;
			case 3: *pCampo= 3;
			seguirCampo = 'n';
				break;
			case 4: *pCampo= 4;
			seguirCampo = 'n';
				break;
			case 5: *pCampo= 5;
			seguirCampo = 'n';
				break;

			case 6: printf("Ha seleccionado salir\n");

			confirmarSalida(&seguirCampo);
			printf("Ha salido de la aplicacion con exito!\n");
			break;
		default:
			printf("Opcion invalida!\n");

			}system("pause");


		}
		while(seguirCampo == 's');


	if(lista != NULL && tam > 0 &&  *pCriterio >= 0 &&  *pCriterio <=1 && *pCampo >= 1 && *pCampo <= 5){
		for(int i= 0; i < tam - 1; i++){
			for(int j = i + 1; j < tam; j++){
				if(( *pCriterio && *pCampo == 1 && lista[i].id < lista[j].id )
				   ||(! *pCriterio && *pCampo == 1 && lista[i].id > lista[j].id )
				   ||( *pCriterio && *pCampo == 2 && strcmp(lista[i].nombre, lista[j].nombre) < 0)
				   ||(! *pCriterio && *pCampo == 2 && strcmp(lista[i].nombre, lista[j].nombre) > 0 )
				   ||( *pCriterio && *pCampo == 3 && lista[i].sexo < lista[j].sexo )
				   ||(! *pCriterio && *pCampo == 3 && lista[i].sexo > lista[j].sexo )
				   ||( *pCriterio && *pCampo == 4 && lista[i].edad < lista[j].edad )
				   ||(! *pCriterio && *pCampo == 4 && lista[i].edad > lista[j].edad )
				   ||( *pCriterio && *pCampo == 5 && lista[i].altura < lista[j].altura )
				   ||(! *pCriterio && *pCampo == 5 && lista[i].altura > lista[j].altura )
				){
					auxPersona = lista[i];
					lista[i] = lista[j];
					lista[j] = auxPersona;

				}

			}


		}



		todoOk = 1;
	}

	return todoOk;
}
int submenuCriterioOrdenamiento(){
	int opcion;
	printf(" Que criterio desea aplicar al ordenamiento?\n\n");
	printf("1- Ascendente\n");
	printf("2- Descendente\n");
	printf("3- Salir del ordenamiento\n");
	if(utn_getNumero(&opcion, "Ingrese el criterio que desea aplicar: \n",
							"Su numero no pudo ser validado\n Ingrese nuevamente un numero de criterio valido (1-3)\n", 1, 3) == 1){
						printf("Su numero fue valido correctamente!\n");
					}
	return opcion;
}



int submenuCampoOrdenamiento(){
	int opcion;
	printf(" Que campo desea aplicar al ordenamiento?\n\n");
	printf("1- ID\n");
	printf("2- Nombre\n");
	printf("3- Sexo\n");
	printf("4- Edad\n");
	printf("5- Altura\n");
	printf("6- Salir del ordenamiento\n");
	if(utn_getNumero(&opcion, "Ingrese el campo que desea aplicar: \n",
							"Su numero no pudo ser validado\n Ingrese nuevamente un numero de campo valido (1-6)\n", 1, 36) == 1){
						printf("Su numero fue valido correctamente!\n");
					}
	return opcion;
}


int mostrarMujeres(ePersona lista[], int tam, eCarrera carreras[], int tamC){

	int flag = 1;
		int todoOk = 0;
	//	char descripcion [20];
		if (lista != NULL && tam > 0) {
			limpiarPantalla();
			printf("                  *** Lista de Mujeres ***        \n");
			printf(
					"---------------------------------------------------------------------------\n");
			printf(
					" ID        Nombre        Sexo          Edad           Altura       Carrera\n");
			printf(
					"---------------------------------------------------------------------------\n");

			for (int i = 0; i < tam; i++) {
				if (!(lista[i].isEmpty) && lista[i].sexo == 'f') {
					//obtenerDescripcionCarrera(lista[i].id, descripcion, carreras, 10);
					mostrarPersona(lista[i], carreras, tamC);
					flag = 0;
				}

			}
			if (flag) {
				printf("No hay personas para mostrar\n");
			}

			todoOk = 1;
		}

		return todoOk;




}
