/*
 * biblioteca.c
 *
 *  Created on: 13 oct 2022
 *      Author: Franco Ramirez
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include <ctype.h>
int confirmarSalida(char *pControl) {

	int todoOk = 0;
	char confirma;
	if (pControl != NULL) {
		printf(
				"Desea confirmar la salida? ('s' para confirmar la salida o 'n' para cancelarla)");
		fflush(stdin);
		scanf("%c", &confirma);
		while (confirma != 's' && confirma != 'n') {
			printf(
					"Caracter invalido.Desea confirmar la salida? ('s' para confirmar la salida o 'n' para cancelarla) ");
			fflush(stdin);
			scanf("%c", &confirma);
		}
		if (confirma == 'n') {
			*pControl = 's';
		}else {
			*pControl = 'n';
		}

		todoOk = 1; //Informa que salio bien
	}
	return todoOk;
}


void limpiarPantalla() {
	for (int i = 0; i < 40; i++) {
		printf("\n");
	}
}

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo) {
	int todoOk = 0;
	int num;
	printf(mensaje);
	getInt(&num);

	if (num <= maximo && num >= minimo){

		*pResultado = num;

		todoOk = 1;

	}

	while (num > maximo || num < minimo) {


		printf(mensajeError);
		printf(mensaje);
		getInt(&num);
		todoOk = 1;
	}
	*pResultado = num;


	return todoOk;
}

//static
int getInt(int *pResultado) {
	char buffer[64];
	scanf("%s", buffer);
	*pResultado = atoi(buffer);
	return 1;
}

int getAnyFloat(float *pResultado){
	char buffer[64];
	scanf("%s", buffer);
	*pResultado = atof(buffer);
	return 1;


}
int validarCaracter(char caracterIngresado,char opcionA, char opcionB){ //Retorna 1 si es valido, 0 si no es valido
	int esValido=0;
	if(caracterIngresado == opcionA || caracterIngresado  == opcionB){
		esValido=1;
	}
	return esValido;
}


int getFloat(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo) {
	int todoOk = 0;
	float num;
	printf(mensaje);
	getAnyFloat(&num);

	if (num <= maximo && num >= minimo){

		*pResultado = num;

		todoOk = 1;

	}

	while (num > maximo || num < minimo) {


		printf(mensajeError);
		printf(mensaje);
		getAnyFloat(&num);
		todoOk = 1;
	}
	*pResultado = num;


	return todoOk;
}
