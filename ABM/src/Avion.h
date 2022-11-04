/*
 * Avion.h
 *
 *  Created on: 13 oct 2022
 *      Author: Franco Ramirez
 */

#ifndef AVION_H_
#define AVION_H_

#include "aerolineas.h"
#include "tipos.h"




typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int id; // PK - Primary key
	int idAerolinea;
	int idTipo;
	int capacidad;
	eFecha fVuelo;
	int isEmpty; //cero cuando es falso, var que se responde como pregunta: es vacio?
}eAvion;
											/*
											typedef struct {

												int id;
												char nombre[20];
												char sexo;
												int edad;
												float altura;
												int isEmpty;   //1 esta vacio, 0 esta lleno
												int idCarrera;
											} ePersona; */


int hardcodearAviones(int* pLegajo, eAvion vec[], int tam, int cantAviones);

int menu();
int inicializarAviones(eAvion lista[], int tam);
int buscarLibre(eAvion lista[], int tam);
int altaAvion(eAvion listaAvion[], int tam, int *pId,eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT);
int bajaAvion(eAvion lista[], int tam, eAerolinea aerolineas[], int tamA);
int buscarAvionId(eAvion[], int tam, int id);
int modificarAvion(eAvion lista[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT);
int subMenuModificar();
//int ordenarAvions(eAvion lista[], int tam, int* pCriterio, int* pCampo);
//int submenuCriterioOrdenamiento();
//int subenuCampoOrdenamiento();
void mostrarAvion(eAvion p, eAerolinea aerolineas[], int tam,eTipo tipos[], int tamT);
int mostrarAviones(eAvion listaAvion[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT);
//int mostrarMujeres(eAvion lista[], int tam, eCarrera carreras[], int tamC);

int obtenerDescripcionCarrera(int id, char descripcion[], eAerolinea aerolineas[], int tamA);


#endif /* AVION_H_ */
