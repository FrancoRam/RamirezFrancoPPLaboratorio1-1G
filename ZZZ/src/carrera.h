/*
 * carrera.h
 *
 *  Created on: 17 oct 2022
 *      Author: Franco Ramirez
 */

#ifndef CARRERA_H_
#define CARRERA_H_


typedef struct {
	int id;
	char descripcion [20];
}eCarrera;


#endif /* CARRERA_H_ */
int cargarDescripcionCarrera(eCarrera carreras[], int tam, int idLocalidad, char descripcion[]);
int mostrarCarreras(eCarrera carreras[], int tam, int clear);
