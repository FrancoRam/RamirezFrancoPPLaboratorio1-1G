/*
 * Avion.c
 *
 *  Created on: 13 oct 2022
 *      Author: Franco Ramirez
 */

#include "Avion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"
#include "funcionesBasic1.h"
#include "destinos.h"
#include "tipos.h"
#include "aerolineas.h"

int menu() {
	int opcion;
	limpiarPantalla();
	printf("     *** ABM VUELOS  ***\n\n");
	printf("1- Alta Avion\n");
	printf("2- Modificar persona\n");
	printf("3- Baja Avion\n");
	printf("4- LISTAR AVIONES\n");
	printf("5- LISTAR AEROLINEAS\n");
	printf("6- LISTAR TIPOS\n");
	printf("7- LISTAR DESTINOS\n");
	printf("8- ALTA VUELO\n");
	printf("9- LISTAR DESTINOS\n");
	printf("10- SALIR\n");
	printf(" \t - INGRESE OPCION: ");
	scanf("%d", &opcion);

	return opcion;
}
int hardcodearAviones(int* pLegajo, eAvion vec[], int tam, int cantAviones)
{
	int ret=-1;
	eAvion auxAvion[5]={
		{3000,1000,5000,25, {14,02,1997}, 0},
		{3001,1001,5001,27, {1,02,1987},0},
		{3002,1002,5002,22, {14,02,2000},0},
		{3003,1003,5003,18, {14,02,2001},0},
		{3004,1002,5002,18, {2,01,2002},0}
	};
	if(vec!=NULL && tam>0 && pLegajo != NULL && cantAviones<=tam)
	{
		for(int i=0; i<cantAviones; i++)
		{
			vec[i]=auxAvion[i];
			*pLegajo=*pLegajo+1;
		}
	}
	return ret;
}

//-----------------------------------------
int inicializarAviones(eAvion listaAvion[], int tam) {

	int todoOk = 0;
	if (listaAvion != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {

			listaAvion[i].isEmpty = 1;
		}

		todoOk = 1;
	}
	return todoOk;
}
//-----------------------------------------

int buscarLibre(eAvion listaAvion[], int tam) {

	int indiceEstructuraVacia = -1;
	for (int i = 0; i < tam; i++) {

		if (listaAvion[i].isEmpty) {
			indiceEstructuraVacia = i;
			break;
		}

	}

	return indiceEstructuraVacia;
}
//-----------------------------------------

int altaAvion(eAvion listaAvion[], int tam, int *pId,eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT) {
	int indice;
	eAvion auxAvion;
	eTipo auxTipo;
	int verificacion;
	int todoOk = 0;
	if (listaAvion != NULL && tam > 0 && aerolineas != NULL && tamA > 0 && pId!=NULL) {
		limpiarPantalla();
		printf(" ***   Alta Avion   *** \n");
		indice = buscarLibre(listaAvion, tam);
		if (indice == -1) {
			printf("No hay lugar\n");
		} else {

			auxAvion.id = *pId;
			(*pId)++;
			mostrarAerolineas(aerolineas, tamA, 1);
			if(utn_getNumero(&auxAvion.idAerolinea, "Ingrese el id de la aerolinea: \n",
							"Su numero de ID no pudo ser validado\n Ingrese nuevamente una AEROLINEA valida (1000-1004)\n", 1000, 1004) == 1)
			{
				printf("Su numero fue valido correctamente!\n");
				verificacion=0;
			}
			else
			{
				verificacion=-1;
			}
			mostrarTipos(tipos, tamT, 1);
			if(utn_getNumero(&auxTipo.id, "Ingrese el id del tipo de Avion: \n",
										"Su numero de ID no pudo ser validado\n Ingrese nuevamente un TIPO DE AVION valida (5000-5003)\n", 5000, 5003) == 1)
			{
				printf("Su numero fue valido correctamente!\n");
				verificacion=0;
			}
			else
			{
				verificacion=-1;
			}
			getIntRange_(&auxAvion.capacidad, "Ingrese la capacidad del avión: ","ERROR-Ingrese la capacidad del Avión (10-300):", 10, 300);
			utn_getNumeroReintentos(&auxAvion.fVuelo.dia, "Ingrese el día de vuelo","ERROR-Ingrese el día de vuelo",2);
			utn_getNumeroReintentos(&auxAvion.fVuelo.mes, "Ingrese el mes de vuelo","ERROR-Ingrese el día de vuelo",2);
			utn_getNumeroReintentos(&auxAvion.fVuelo.anio, "Ingrese el anio de vuelo","ERROR-Ingrese el día de vuelo",2);
			if(isValidFecha(auxAvion.fVuelo.dia, auxAvion.fVuelo.mes, auxAvion.fVuelo.anio)==1)
			{
				printf("Su numero fue valido correctamente!\n");
				verificacion=0;
			}
			else
			{
				verificacion=-1;
			}
			if(verificacion!=-1)
			{
				auxAvion.isEmpty = 0;
				listaAvion[indice] = auxAvion;
				tipos[indice] = auxTipo;
				todoOk = 1;
			}
		}
	}
	return todoOk;
}
//-----------------------------------------

void mostrarAvion(eAvion p, eAerolinea aerolineas[], int tam,eTipo tipos[], int tamT) {
	char descAerolinea[20];
	//char descDestino[25];
	char descTipoAvion[20];

	cargarDescripcionAerolinea(aerolineas, tam, p.idAerolinea, descAerolinea);
	cargarDescripcionTipo(tipos, tamT, p.idTipo, descTipoAvion);
	//obtenerDescripcionTipo(t.id, descTipoAvion, tipos, tamT);
	printf(" %d      %-9s         %-9s   	  %d    	       %02d/%02d/%4d  \n",
			p.id, descAerolinea,descTipoAvion,p.capacidad, p.fVuelo.dia,p.fVuelo.mes,p.fVuelo.anio);

}
//-----------------------------------------

int mostrarAviones(eAvion listaAvion[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT) {

	int flag = 1;
	int todoOk = 0;
	if (listaAvion != NULL && tam > 0) {
		limpiarPantalla();
		printf("                  *** Lista de Aviones ***        \n");
		printf(
				"-----------------------------------------------------------------------------------------------------\n");
		printf(
				" ID        Aerolinea         Tipo avion           Capacidad           Fecha vuelo\n");
		printf(
				"-----------------------------------------------------------------------------------------------------\n");

		for (int i = 0; i < tam; i++) {
			if (listaAvion[i].isEmpty==0) {
				mostrarAvion(listaAvion[i], aerolineas, tamA, tipos, tamT);
				flag = 0;
			}

		}
		if (flag) {
			printf("No hay Aviones para mostrar\n");
		}

		todoOk = 1;
	}

	return todoOk;
}
//-----------------------------------------

int bajaAvion(eAvion listaAvion[], int tam, eAerolinea aerolineas[], int tamA) {
	int todoOk = 0;
	int indice;
	int id;
	char confirma;
	if (listaAvion != NULL && tam > 0) {
		limpiarPantalla();
		printf("      *** Baja Avion ***     \n \n");
		printf("Ingrese ID: ");
		scanf("%d", &id);
		indice = buscarAvionId(listaAvion, tam, id);
		if (indice == -1) {
			printf("El ID: %d no esta registrado en el sistema\n", id);
		} else {
			//mostrarAvion(listaAvion[indice], aerolineas, tamA, );
			printf("Confirma baja?:\n");
			fflush(stdin);
			scanf("%c", &confirma);
			if (confirma == 's') {
				listaAvion[indice].isEmpty = 1;
				todoOk = 1;
			} else {
				printf("Baja cancelada por el usuario \n");
			}

		}
	}

	return todoOk;
}
//-----------------------------------------

int buscarAvionId(eAvion listaAvion[], int tam, int id) {
	int indice = -1;
	for (int i = 0; i < tam; i++) {

		if (listaAvion[i].id == id && !listaAvion[i].isEmpty) {
			indice = i;
			break;
		}

	}

	return indice;
}
//-----------------------------------------

int modificarAvion(eAvion listaAvion[], int tam, eAerolinea aerolineas[], int tamA,eTipo tipos[], int tamT) {

	int todoOk = 0;
	int indice;
	int id;
	char confirma;
	char seguir = 's';
	char auxTipo[20];
	int idtipoAvion;
	if (listaAvion != NULL && tam > 0) {
		limpiarPantalla();

		printf("      *** Modificar Avion ***     \n \n");
		//subMenuModificar();
		if(utn_getNumeroReintentos(&id, "Ingrese el ID : \n", "ERROR - ID ingresado no pudo validarse.\n", 2)== 0)
		{
			printf("Su numero fue valido correctamente!\n");
		}

		indice = buscarAvionId(listaAvion, tam, id);

		if (indice == -1) {
			printf("ERROR - El ID: %d no está registrado\n", id);
		} else {
			mostrarAvion(listaAvion[indice], aerolineas, tamA,tipos, tamT);
			printf("Confirma que quiere modificar esta Avion? (s/n)");
			fflush(stdin);
			//scanf("%c", &confirma);
			confirma= tolower(getchar());
			while(!validarCaracter(confirma, 's', 'n'))
			{
				printf("Caracter Invalido. Reingrese caracter valido para confirmar (s para confirmar - n para no confirmar): \n");
				fflush(stdin);
				confirma= tolower(getchar());
			}
			printf("\n\n");
			if(confirma == 's')
			{
				do {
					switch (subMenuModificar()) {
						case 1:
							mostrarTipos(tipos, tamT, 1);
							printf("Ingrese el ID del nuevo tipo de avion:");
							scanf("%d", &idtipoAvion);
							cargarDescripcionTipo(tipos, tamT, idtipoAvion, auxTipo);
							strcpy(tipos[indice].descripcionTipo,auxTipo);
						break;
						case 2:

						break;
						case 3:
							printf("\t**Desea seguir realizando modificacioens?**\n(s/n)");
							fflush(stdin);
							(gets(&seguir));
						break;
						default:
							printf("La opcion ingresada no es valida\n");
						break;
					}
					system("pause");
				} while (seguir == 's');
			}
			else
			{
				printf("Se ha cancelado la modificacion de los datos de la Avion\n");
			}


		}
	}

	return todoOk;
}
//-----------------------------------------

int subMenuModificar() {
	int opcion;


	printf("     *** Que datos desea modificar?  ***\n\n");
	printf("1- Tipo avion\n");
	printf("2- Capacidad de avion\n");
	printf("5- Salir\n");
	printf("\tIngrese opcion: ");
	scanf("%d", &opcion);

	return opcion;

}
/*
int ordenarAvions(eAvion listaAvion[], int tam, int* pCriterio, int* pCampo){
	int todoOk = 0;
	char seguirCriterio = 's';
	char seguirCampo = 's';
	eAvion auxAvion;
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


	if(listaAvion != NULL && tam > 0 &&  *pCriterio >= 0 &&  *pCriterio <=1 && *pCampo >= 1 && *pCampo <= 5){
		for(int i= 0; i < tam - 1; i++){
			for(int j = i + 1; j < tam; j++){
				if(( *pCriterio && *pCampo == 1 && listaAvion[i].id < listaAvion[j].id )
				   ||(! *pCriterio && *pCampo == 1 && listaAvion[i].id > listaAvion[j].id )
				   ||( *pCriterio && *pCampo == 2 && strcmp(listaAvion[i].nombre, listaAvion[j].nombre) < 0)
				   ||(! *pCriterio && *pCampo == 2 && strcmp(listaAvion[i].nombre, listaAvion[j].nombre) > 0 )
				   ||( *pCriterio && *pCampo == 3 && listaAvion[i].sexo < listaAvion[j].sexo )
				   ||(! *pCriterio && *pCampo == 3 && listaAvion[i].sexo > listaAvion[j].sexo )
				   ||( *pCriterio && *pCampo == 4 && listaAvion[i].edad < listaAvion[j].edad )
				   ||(! *pCriterio && *pCampo == 4 && listaAvion[i].edad > listaAvion[j].edad )
				   ||( *pCriterio && *pCampo == 5 && listaAvion[i].altura < listaAvion[j].altura )
				   ||(! *pCriterio && *pCampo == 5 && listaAvion[i].altura > listaAvion[j].altura )
				){
					auxAvion = listaAvion[i];
					listaAvion[i] = listaAvion[j];
					listaAvion[j] = auxAvion;

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


int mostrarMujeres(eAvion listaAvion[], int tam, eCarrera carreras[], int tamC){

	int flag = 1;
		int todoOk = 0;
	//	char descripcion [20];
		if (listaAvion != NULL && tam > 0) {
			limpiarPantalla();
			printf("                  *** listaAvion de Mujeres ***        \n");
			printf(
					"---------------------------------------------------------------------------\n");
			printf(
					" ID        Nombre        Sexo          Edad           Altura       Carrera\n");
			printf(
					"---------------------------------------------------------------------------\n");

			for (int i = 0; i < tam; i++) {
				if (!(listaAvion[i].isEmpty) && listaAvion[i].sexo == 'f') {
					//obtenerDescripcionCarrera(listaAvion[i].id, descripcion, carreras, 10);
					mostrarAvion(listaAvion[i], carreras, tamC);
					flag = 0;
				}

			}
			if (flag) {
				printf("No hay Avions para mostrar\n");
			}

			todoOk = 1;
		}

		return todoOk;
}
*/
