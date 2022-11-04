/*
 * biblioteca.h
 *
 *  Created on: 13 oct 2022
 *      Author: Franco Ramirez
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
int confirmarSalida(char *pControl);
void limpiarPantalla();
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo);
int validarCaracter(char caracterIngresado,char opcionA, char opcionB);
int getFloat(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo);

//static
int getInt(int *pResultado);
int getAnyFloat(float *pResultado);


#endif /* BIBLIOTECA_H_ */
