/*
 * funcionesBasic1.h
 *
 *  Created on: 3 sept 2022
 *      Author: Franc
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef FUNCIONESBASIC1_H_
#define FUNCIONESBASIC1_H_

int dividirEnteros(int num1, int num2, float* resultado);
int sumarEnteros(int num1,int num2);
int esPar(int numero);
int getIntRange(int* pValor, char* mensaje, char* msjError, int min, int max);
int getFactorialNumero();
int utn_getNumero(int* pValor, char* mensaje, char* msjError, int reintentos);
void limpiarPantalla();
int getFloatRange(float *pValor, char *mensaje, char *msjError, float min,float max, int reintentos);
int getChar(char* pValor, char* mensaje, char* msjError, char min, char max, int reintentos);
int getInt_(int* pInt);
int getIntRange_(int *pValor, char *mensaje, char *msjError, int min, int max);
int esNumerica(char cadena[]);
int myGets(char* cadena, int len);
int utn_getNombre(char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos);
int isValidNombre(char *pBuffer, int limite);
int isValidFecha(int dia, int mes, int anio);
int getString(char *pBuffer, int limite);

int getSexo(char pValor[], char* mensaje, char* msjError, int reintentos);
int getSexoFOM(char* pValor, char* mensaje, char* msjError, int reintentos);

int sortSimple(int pVec[], int tam, int criterio);

#endif /* FUNCIONESBASIC1_H_ */
