/*
 ============================================================================
 Name        : progra1parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * 1
crear una funcion llamada
aplicarAumento que reciba como
parametro  el precio de un producto
y devuelva el valor del producto con
 un aumento del 5%.
realizar la llamada desde el main. */

/*2.
 crear una funcion que se llame reemplazar caracteres.
 que reciba una cad de caracteres como primer parametro, un caracter como segundo
 y un terecer caracter como tercero.
 la misma debera reemplazar cada pcurrencia del segundo parametro por el tercero y devolver la cantidad de reemplazos que se realizaron (contador)
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

float aplicarAumento(float precio);

int main(void) {
setbuf(stdout,NULL);

	float precioCA;
	float precioSA=50;

	precioCA=aplicarAumento(precioSA);
	printf("%.2f", precioCA);

	return EXIT_SUCCESS;
}


float aplicarAumento(float precio)
{
	float ret=-1;

	ret= precio * 1.05;
	return ret;
}

//2
int reemplazarCaracteres(char cadena[], char caracter1, char caracter2)
{
	int contador=-1;
	int ret;
	if(cadena!=NULL)
	{

		for(int i; cadena[i]!='\0'; i++)
		{
			if(cadena[i]==caracter1)
			{
				cadena[i]=caracter2;
				contador++;
			}
		}


	}
	ret=contador;
	return ret;
}

//3
/*
 dada la siguiente estructura generar una funcion que permita ordenar un array de dicha estructura por tipo y ante igualdad de tipo deberá ordenarse por efecetividad creciente
hardcorear datos y mostrarlos desde el main
*/

typedef struct{
	int id;
	char nombre[20];
	char tipo;
	float efectividad;

}eVacuna;

int ordenarVacunas(int vec[], int tam);

int ordenarVacunas(eVacuna vec[], int tam)
{
	int ret=-1;
	eVacuna aux;
	if (vec!=NULL && tam>0)
	{
		for(int i=0; i<tam-1;i++)
		{
			for(int j=i+1; j<tam; j++){

				if((vec[i].tipo == vec[j].tipo)
						&&
						(vec[i].efectividad>vec[j].efectividad
								|| vec[i].tipo<vec[j].tipo))
				{
					aux=vec[i];
					vec[i]=vec[j];
					vec[j]=aux;
				}
			}
		}


		ret=0;

	}

	return ret;
}
