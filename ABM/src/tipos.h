/*
 * tipos.h
 *
 *  Created on: 21 oct 2022
 *      Author: Franc
 */

#ifndef TIPOS_H_
#define TIPOS_H_
	typedef struct{
		int id; // PK - Primary key
		char descripcionTipo[20];
	}eTipo;

	int cargarDescripcionTipo(eTipo tipos[], int tam, int idLocalidad, char descripcion[]);
	int mostrarTipos(eTipo tipos[], int tam, int clear);
	int obtenerDescripcionTipo(int id, char descripcionTipo [], eTipo tipos[], int tamT);
#endif /* TIPOS_H_ */
