/*
 * destinos.h
 *
 *  Created on: 21 oct 2022
 *      Author: Franc
 */

#ifndef DESTINOS_H_
#define DESTINOS_H_

	typedef struct{
		int id; // PK - Primary key
		char descripcionDestino[25];
		float precio;
	}eDestino;


	int mostrarDestinos(eDestino destinos[], int tam, int clear);
	int cargarDescripcionDestino(eDestino destinos[], int tam, int idLocalidad, char descripcion[]);
	int obtenerDescripcionDestino(int id, char descripcionDestino [], eDestino destinos[], int tamD);
#endif /* DESTINOS_H_ */
