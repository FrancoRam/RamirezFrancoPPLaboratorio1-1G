/*
 * bibliotecaAbm.c
 *
 *  Created on: 17 oct 2022
 *      Author: Franc
 */
#include "bibliotecaAbm.h"
#include "funcionesBasic1.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
int menu()
{
	int opcion;
	printf("\tMENU DE OPCIONES\n");
	printf("1- Alta\n");
	printf("2- MODIFICAR \n");
	printf("3- BAJA\n");
	printf("4- LISTAR ALUMNOS\n");
	printf("5- ORDENAR\n");
	printf("6- LISTAR CARRERAS\n");
	printf("10- SALIR\n");

	printf("ingrese una opcion");
	scanf("%d", &opcion);
	//printf("\nel numero de opcion es: %d", opcion);

	puts("\n\n");
	return opcion;
}

//-----------------------------------

int subMenu()
{
	int opcion;
	printf("\tSUB-MENU DE OPCIONES\n");
	printf("1- Nombre\n");
	printf("2- Sexo\n");
	printf("3- Edad \n");
	printf("4- Fecha de nacimiento\n");
	printf("5- Regresar al Menu principal\n");

	printf("ingrese una opcion");
	scanf("%d", &opcion);

	printf("\n* El numero de campo que desea modificar es: %d *\n", opcion);

	return opcion;
}
//-----------------------------------

int hardcodearAlumnos(int* pLegajo, eAlumno vec[], int tam, int cantAlumnos)
{
	int ret=-1;
	eAlumno auxAlumno[10]={
		{1000,"Alvaro", 'm',25, {14,02,1997},500, 0},
		{1001,"Brisa", 'f',27, {1,02,1987},501, 0},
		{1002,"Carla", 'f',22, {14,02,2000},500, 0},
		{1003,"Dario", 'm',18, {14,02,2001},500, 0},
		{1004,"Gabi", 'f',19, {31,04,1986},505, 0},
		{1005,"Franco", 'm',25, {14,2,1997},503, 0},
		{1006,"Zaira", 'f',27, {3,10,2007},500, 0},
		{1007,"Xavier", 'm',44, {14,2,1997},502, 0},
		{1008,"Valeria", 'f',43, {7,12,2004},500, 0},
		{1009,"Evelin", 'f',34, {5,02,1998},501, 0}
	};
	if(vec!=NULL && tam>0 && pLegajo != NULL && cantAlumnos<=tam && cantAlumnos<=10)
	{
		for(int i=0; i<cantAlumnos; i++)
		{
			vec[i]=auxAlumno[i];
			*pLegajo=*pLegajo+1;
		}
	}
	return ret;
}

//-----------------------------------
int inicializarAlumnos(eAlumno vec[], int tam)
{
	int ret=-1;
	if(vec!=NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			vec[i].isEmpty = 1;
		}
		ret=0;
	}
	return ret;
}

//-----------------------------------
void mostrarAlumno(eAlumno alumno)
{
	printf("** Legajo	Nombre		Sexo	Edad	Fecha nac.	ID carrera	\n");
	printf("   %d		%s		 %c	 %d	%02d/%02d/%d\n\n", alumno.legajo,alumno.nombre,alumno.sexo,alumno.edad,alumno.fNac.dia,alumno.fNac.mes,alumno.fNac.anio);
}
//-----------------------------------

int mostrarAlumnos(eAlumno vec[], int tam, int clear)
{
	int ret=-1;
	int flag=1;
	if(vec!=NULL && tam>0 && (clear ==1 || clear==0))
	{
		if(clear==1)//limpiar
		{
			printf("**lista de alumnos**\n");
			for(int i=0; i<tam; i++)
			{
				if(vec[i].isEmpty==0)
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
				printf("\t**-- NO HAY alumnos para mostrar! --**");
			}
		}

	}
	system("pause");
	return ret;
}

//-----------------------------------

int buscarLibre(int* pIndice, eAlumno vec[], int tam)
{
	int ret=-1;
	if(vec!=NULL && tam>0 && pIndice!=NULL)
	{
		*pIndice =-1;
		for(int i=0; i<tam; i++)
		{
			if(vec[i].isEmpty == 1)
			{
				*pIndice = i;
				ret=0;
			}
		}
	}
	return ret;
}

//-----------------------------------

int altaAlumno(eAlumno vec[], int tam, int* pLegajo)
{
	int ret=-1;
	int indice;
	eAlumno auxAlumno;
	char auxAlum[50];
	if(vec!=NULL && tam>0 && pLegajo != NULL)
	{
		buscarLibre(&indice, vec, tam);
		if(indice==-1) //no hay lugar
		{
			printf("no hay lugar en el sistema");
		}
		else // hay
		{
			auxAlumno.legajo=*pLegajo;
			if(
					(utn_getNombre(auxAlum, 50, "Ingrese el nombre: ", "ERROR-Ingrese el nombre: ", 3)==0)
					&&
					(getSexoFOM(&auxAlumno.sexo, "Ingrese el sexo: ", "ERROR-Ingrese el sexo: ", 3)==0)
					&&
					getIntRange_(&auxAlumno.edad,"Ingrese la edad: ", "ERROR-Ingrese la edad: ", 5, 100)==0
			  	  	  )
			{
				printf("%s\n", auxAlum);
				system("pause");

				vec[indice].sexo=auxAlumno.sexo;
				vec[indice].edad=auxAlumno.edad;
			}
			else
			{
				printf("\t***ERROR EN LA CARGA DE DATOS***");
			}

				printf("ingrese fecha de nacimiento: dd/mm/aaaa");
				scanf("%02d/%02d/%d", &auxAlumno.fNac.dia, &auxAlumno.fNac.mes, &auxAlumno.fNac.anio);

				if(isValidFecha(auxAlumno.fNac.dia, auxAlumno.fNac.mes, auxAlumno.fNac.anio)==1)
				{
					vec[indice].fNac.dia=auxAlumno.fNac.dia;
					vec[indice].fNac.mes=auxAlumno.fNac.mes;
					vec[indice].fNac.anio=auxAlumno.fNac.anio;
				}
				else
				{
					printf("\t***ERROR EN LA CARGA DE DATOS***");
				}
			auxAlumno.isEmpty=0;
			vec[indice]=auxAlumno;
			strcpy(vec[indice].nombre,auxAlum);
			*pLegajo= *pLegajo +1;
			printf("Alta exitosa");
			ret=0;
		}
	}
	system("pause");
	return ret;
}

//-----------------------------------

int bajaAlumno(eAlumno vec[], int tam)
{
	int ret=-1;
	int legajo;
	int indic;
	int auxiliarBuscar;
	char baja;
	if(vec!=NULL && tam>0)
	{
		limpiarPantalla();
		printf("*******BAJA ALUMNO********");
		mostrarAlumnos(vec, tam, 1); //MODIFICAR EL CLEAR DE MOSTRAR ALUMNOS
		printf("Seleccione un legajo: ");
		scanf("%d", &legajo);
		auxiliarBuscar = buscarAlumno(&indic, &legajo, vec, tam);

		if( auxiliarBuscar == -1)
		{
			//informa que no se encontró legajo
			printf("No se encontró ese número de Legajo");
		}
		else
		{
			puts("\n******\n");
			mostrarAlumno(vec[indic]);
			printf("desea dar de baja al alumno: %s? -- ingrese (s/n)", vec[indic].nombre);
			fflush(stdin);
			scanf("%c", &baja);
			if(baja=='s')
			{
				vec[indic].isEmpty = 1;
			}
			else
			{
				printf("\n** Baja del alumno: %s se ha cancelado **\n", vec[indic].nombre);
			}
		}
	}
	system("pause");
	return ret;
}

//-----------------------------------

int buscarAlumno(int* pIndice,int* pLegajo, eAlumno vec[], int tam)
{
	int ret=-1;
	if(vec!=NULL && tam>0 && pIndice!=NULL)
	{
		*pIndice =-1;
		for(int i=0; i<tam; i++)
		{
			if(vec[i].isEmpty == 0 && vec[i].legajo == *pLegajo)
			{
				*pIndice = i;
				ret=0;
			}
		}
	}
	return ret;
}

//-----------------------------------

int modificarAlumno(eAlumno vec[], int tam)
{
	int ret=-1;
	int legajo;
	int indic;
	int auxiliarBuscar;
	int opcionSubMenu;
	int confirmacion;
	int confirmacion2;
	int confirmacion3;

	char auxNombre[50];
	char auxChar;
	int auxInt;
	int auxIntDia;
	int auxIntMes;
	int auxIntAnio;


	if(vec!=NULL && tam>0)
	{
		limpiarPantalla();
		printf("*******MODIFICAR ALUMNO********");

		mostrarAlumnos(vec, tam, 1); //MODIFICAR EL CLEAR DE MOSTRAR ALUMNOS
		printf("Seleccione un legajo: ");
		scanf("%d", &legajo);
		auxiliarBuscar = buscarAlumno(&indic, &legajo, vec, tam);

		if( auxiliarBuscar == -1)
		{
			//informa que no se encontró legajo
			printf("No se encontró ese número de Legajo");
		}
		else
		{
			puts("\n******\n");
			mostrarAlumno(vec[indic]);

			opcionSubMenu=subMenu();
			if(opcionSubMenu==5)
			{
				printf("\n** Modificación del alumno: %s se ha cancelado **\n", vec[indic].nombre);
			}
			else
			{
				switch(opcionSubMenu)
				{
				case 1:
					confirmacion=utn_getNombre(auxNombre,50, "Ingrese el nombre: ", "Error - ingrese el nombre: ",2);
					if(confirmacion==0)
					{
						strcpy(vec[indic].nombre,auxNombre);
						printf("\t**Modificacion exitosa**\n");
					}
					else
					{
						printf("\n** La modificacion se ha cancelado **\n");
					}
				break;
				case 2:
					confirmacion=getSexoFOM(&auxChar, "Ingrese el sexo", "Error - ingrese el sexo (f, m)",2);
					if(confirmacion==0)
					{
						vec[indic].sexo=auxChar;
						printf("\t**Modificacion exitosa**\n");
					}
					else
					{
						printf("\n** La modificacion se ha cancelado **\n");
					}
				break;

				case 3:
					confirmacion=getIntRange_(&auxInt, "Ingrese una edad: ", "ERROR-Ingrese una edad (5-120 años): ", 5, 120);
					if(confirmacion==0)
					{
						vec[indic].edad=auxInt;
						printf("\n\t**Modificacion exitosa**\n\n");

					}
					else
					{
						printf("\n** La modificacion se ha cancelado **\n");
					}
				break;

				case 4:
					printf("INGRESE FECHA DE NACIMIENTO: \n");
					confirmacion=getIntRange_(&auxIntDia, "Ingrese el día: ", "ERROR-Ingrese el DIA: ", 1, 31);
					confirmacion2=getIntRange_(&auxIntMes, "Ingrese el mes: ", "ERROR-Ingrese el MES: ", 1, 12);
					confirmacion3=getIntRange_(&auxIntAnio,"Ingrese el año: ", "ERROR-Ingrese el AÑO: ", 1900, 2022);
					if(confirmacion==0 && confirmacion2==0 && confirmacion3==0)
					{
						vec[indic].fNac.dia=auxIntDia;
						vec[indic].fNac.mes=auxIntMes;
						vec[indic].fNac.anio=auxIntAnio;
						printf("\n\t**Modificacion exitosa**\n\n");

					}
					else
					{
						printf("\n** La modificacion se ha cancelado **\n");
					}
				break;

				case 5:
					printf("\n** La modificacion se ha cancelado **\n");
				break;
				}
			}
		}
	}
	system("pause");
	return ret;
}

//-----------------------------------
/// @fn int ordenarAlumnos(eAlumno[], int, int)
/// @brief Ordena un vector por sexo(f / m) y a su vez alfabéticamente de manera
/// 	   ascendente(0) o de manera descendente(1) en base al criterio ingresado(1-0)
///
/// @param pVec - de tipo eAlumno
/// @param tam - de tipo entero
/// @param criterio - de tipo entero
/// @return
int ordenarAlumnos(eAlumno pVec[], int tam,int criterio) //AGREGAR CRITERIO (0 ASC -  1 DESC)
{
	int ret=-1;
	eAlumno aux;
	if(pVec!=NULL && tam>0 && (criterio == 1 || criterio == 0))
	{
		for(int i=0; i<tam-1; i++)
		{
			for(int j=i+1; j<tam;j++)
			{
				if(criterio==0) //ORDENAMIENTO ASCENDENTE
				{
					if((pVec[i].sexo>pVec[j].sexo) //ordenamiento por sexo
							||
					  ((pVec[i].sexo == pVec[j].sexo)
							  &&
					   strcmp(pVec[i].nombre,pVec[j].nombre)>0)//ordenamiento por nombre
					   )
					{
						aux=pVec[i];
						pVec[i]=pVec[j];
						pVec[j]=aux;
					}
				}
				else			//ORDENAMIENTO DESCENDENTE
				{
					if((pVec[i].sexo<pVec[j].sexo) //ordenamiento por sexo
							||
					  ((pVec[i].sexo == pVec[j].sexo)
							  &&
					   strcmp(pVec[i].nombre,pVec[j].nombre)<0)//ordenamiento por nombre
					   )
					{
						aux=pVec[i];
						pVec[i]=pVec[j];
						pVec[j]=aux;
					}
				}

			}
		}
		ret=0;
	}
	printf("\t\n** El ordenamiento se ha realizado con éxito **\n");
	system("pause");
	return ret;
}
