/*
 * aerolineas.h
 *
 *  Created on: 21 oct 2022
 *      Author: Franc
 */

#ifndef AEROLINEAS_H_
#define AEROLINEAS_H_
	typedef struct{
		int id; // PK - Primary key
		char descripcionAerolinea[20];
	}eAerolinea;
	int mostrarAerolineas(eAerolinea aerolineas[], int tam, int clear);
	int cargarDescripcionAerolinea(eAerolinea aerolineas[], int tam, int idLocalidad, char descripcion[]);

#endif /* AEROLINEAS_H_ */
