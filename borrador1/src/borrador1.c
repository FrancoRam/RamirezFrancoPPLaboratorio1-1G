/*
 ============================================================================
 Name        : borrador1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	//int numero;
	int* p; //está en la mem estátic
	char* q; //está en la mem estátic
	float* pi; //está en la mem estátic
	p = (int*)malloc(sizeof(int)); // malloc devuelve una direccion de memoria / con la cantidad de bytes, en este caso 4.

	*p=48; // estoy hablando del VALOR de la direccion de memoria que tomó p
	printf("variable p: %d\n", *p);

	q = (char*)malloc(sizeof(char));
	*q = 'A';
	printf("caracter q: %c\n", *q);

	pi=(float*) malloc(sizeof(float));
	*pi=3.14;

	printf("pi: %.2f", *pi);

		//malloc devuelve una dirección de MEMORIA y es de tipo void*

	free(p); //esta función libera la memoria reservada por malloc().
	free(q); //esta función libera la memoria reservada por malloc().

	return EXIT_SUCCESS;
}
