/*
 * bibliotecaAbm.h
 *
 *  Created on: 17 oct 2022
 *      Author: Franc
 */

#ifndef BIBLIOTECAABM_H_
#define BIBLIOTECAABM_H_

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int legajo; // PK - Primary key
	char nombre[20];
	char sexo;
	int edad;
	eFecha fNac;
	int idCarrera; // FK CLAVE FORANEA
	int isEmpty; //cero cuando es falso, var que se responde como pregunta: es vacio?
}eAlumno;

int menu();
int subMenu();

int inicializarAlumnos(eAlumno vec[], int tam);
int mostrarAlumnos(eAlumno vec[], int tam, int clear);
int buscarLibre(int* pIndice, eAlumno vec[], int tam);
int buscarAlumno(int* pIndice,int* pLegajo, eAlumno vec[], int tam);
int altaAlumno(eAlumno vec[], int tam, int* pLegajo);
int bajaAlumno(eAlumno vec[], int tam);
int modificarAlumno(eAlumno vec[], int tam);
void mostrarAlumno(eAlumno alumno);

int getSexo(char pValor[], char* mensaje, char* msjError, int reintentos);

int hardcodearAlumnos(int* pLegajo, eAlumno vec[], int tam, int cantAlumnos);
int ordenarAlumnos(eAlumno pVec[], int tam,int criterio); //AGREGAR CRITERIO (0 ASC -  1 DESC)

#endif /* BIBLIOTECAABM_H_ */
