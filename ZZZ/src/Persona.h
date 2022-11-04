/*
 * Persona.h
 *
 *  Created on: 13 oct 2022
 *      Author: Agustín
 */

#ifndef PERSONA_H_
#define PERSONA_H_
#include "carrera.h"



typedef struct {

	int id;
	char nombre[20];
	char sexo;
	int edad;
	float altura;
	int isEmpty;   //1 esta vacio, 0 esta lleno
	int idCarrera;
} ePersona;


int menu();
int inicializarPersonas(ePersona lista[], int tam);
int buscarLibre(ePersona lista[], int tam);
int altaPersona(ePersona lista[], int tam, int *pId,eCarrera carreras[], int tamC);
int bajaPersona(ePersona lista[], int tam, eCarrera carreras[], int tamC);
int buscarPersonaId(ePersona[], int tam, int id);
int modificarPersona(ePersona lista[], int tam, eCarrera carreras[], int tamC);
int submenuModificar();
int ordenarPersonas(ePersona lista[], int tam, int* pCriterio, int* pCampo);
int submenuCriterioOrdenamiento();
int submenuCampoOrdenamiento();
void mostrarPersona(ePersona p, eCarrera carreras[], int tam);
int mostrarPersonas(ePersona lista[], int tam, eCarrera carreras[], int tamC);
int mostrarMujeres(ePersona lista[], int tam, eCarrera carreras[], int tamC);

int obtenerDescripcionCarrera(int id, char descripcion[], eCarrera carreras [], int tam);
#endif /* PERSONA_H_ */
