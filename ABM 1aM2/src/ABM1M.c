/*
 ============================================================================
 Name        : EJERCICIOSCLASE7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesBasic1.h"
#include "ctype.h"
#include "string.h"
#include "bibliotecaAbm.h"

#include "carrera.h"

#define TAM 11
#define TAM_C 5



typedef struct{
	int id; // PK
	char descripcion[20];

}eCarrera;

int hardcodearCarreras(int* pId, eCarrera vec[], int tam, int cantCarreras);
int mostrarCarreras(eCarrera vec[], int tam, int clear);
int obtenerDescripcionCarrera(int id, char desc[], eCarrera carreras[], int tam);
int mostrarMujeres(eAlumno vec[], int tam);



int main(void) {
	setbuf(stdout, NULL);
	char salir='n';
	int varLegajo=1000; //VARIABLE INCREMENTAL
	int varCarrera=500; //VARIABLE INCREMENTAL


	eAlumno lista[TAM];
	eCarrera carreras[TAM_C];
	inicializarAlumnos(lista, TAM);
	hardcodearAlumnos(&varLegajo, lista, TAM, 10);
	hardcodearCarreras(&varCarrera, carreras, TAM_C, 5);


	do
	{
		switch(menu())
		{
		case 1:
			altaAlumno(lista, TAM, &varLegajo);
			break;

		case 2:
			modificarAlumno(lista, TAM);
			break;

		case 3:
			bajaAlumno(lista, TAM);
			break;

		case 4:
			mostrarAlumnos(lista, TAM, 1);
			break;

		case 5:
			ordenarAlumnos(lista, TAM, 1);
			//LISTAR

			break;

		case 6:
			//mostrarCarreras(carreras, TAM_C, 1);
			mostrarMujeres(lista, TAM);
			break;

		case 10:
			salir = 's';
					break;

		}

		//printf("\ndesea salir del programa?");
		//fflush(stdin);
		//scanf("%c", &salir);
	}while(salir!='s');

	return EXIT_SUCCESS;
}




int hardcodearCarreras(int* pId, eCarrera vec[], int tam, int cantCarreras)
{
	int ret=-1;

	eCarrera carreras[TAM_C]={
	{500,"Programacion"},
	{501,"Sistemas"},
	{502,"Arquitectura"},
	{503,"Idiomas"},
	{504,"Biología Marina"}
	};
	if(vec!=NULL && tam>0 && pId != NULL && cantCarreras<=tam && cantCarreras<=10)
		{
			for(int i=0; i<cantCarreras; i++)
			{
				vec[i]=carreras[i];
				*pId=*pId+1;
			}
		}
	return ret;
}












int mostrarCarreras(eCarrera vec[], int tam, int clear)
{
	int ret=-1;

	if(vec !=NULL && tam >0 && (clear==1 || clear ==0))
	{
		if(clear==1)
		{
			//LIMPIAR PANTALLA

		}
		printf( "/t*** LISTA DE CARRERAS ***\n");
		printf("    ID    DESCRIPCION\n");
		printf("---------------------\n");
		for(int i=0; i<tam; i++)
		{
			printf("   %d    %s\n", vec[i].id, vec[i].descripcion);
		}
	}

	return ret;
}

int obtenerDescripcionCarrera(int id, char desc[], eCarrera carreras[], int tam)
{
	int ret=-1;
	if(carreras!=NULL && desc != NULL && tam >0 )
	{
		for( int i=0; i<tam; i++)
		{
			if(carreras[i].id == id)
			{
				strcpy(desc, carreras[i].descripcion);
				ret=0;
				break;
			}
		}
	}

	return ret;
}

//INFORMES
int listarAlumnosCarreras(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
	int ret=-1;
	if(alumnos != NULL ) //etc validaciones
	{
		limpiarPantalla();
		printf( "/t*** LISTA DE ALUMNOS POR CARRERAS ***\n");
		printf("    ID    DESCRIPCION\n");
		printf("---------------------\n");
		//Recorro vec de carreras
		for(int c=0; c<tamC; c++)
		{
			printf("Carrera: %s", carreras[c].descripcion);
			for(int i=0; i<tam; i++)
			{
				if(alumnos[i].isEmpty==0 && carreras[c].id==alumnos[i].idCarrera)
				{
					printf("\tAlumno: %s\n", alumnos[i].nombre);
					//mostrarAlumno() para suplantar al printf.
				}

			}

		}
	}
	return ret;
}

//--------
int mostrarMujeres(eAlumno vec[], int tam)
{
	int ret=-1;
	int flag=1;
	if(vec!=NULL && tam>0)
	{
		printf("**lista de mujeres**\n");
		for(int i=0; i<tam; i++)
		{
			if(vec[i].isEmpty==0 && vec[i].sexo == 'f')
			{
				printf("** Legajo	Nombre		Sexo	Edad	Fecha nac.	\n");
				printf("   %d		%s		 %c	 %d	%02d/%02d/%d\n\n",
									vec[i].legajo,
									vec[i].nombre,
									vec[i].sexo,
									vec[i].edad,
									vec[i].fNac.dia,
									vec[i].fNac.mes,
									vec[i].fNac.anio);
				flag=0;
			}
		}
		ret=0;
		if(flag==1)
		{
			printf("\t**-- NO HAY mujeres para mostrar! --**");
		}
	}
	system("pause");
	return ret;
}
