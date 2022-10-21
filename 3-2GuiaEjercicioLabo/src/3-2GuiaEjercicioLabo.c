/*
 ============================================================================
 Name        : 3-2GuiaEjercicioLabo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
Ejercicio 3-2:
Crear una función que permita determinar si un número es par o no. La función retorna 1 en caso
afirmativo y 0 en caso contrario. Probar en el main.
*/

#include <stdio.h>
#include <stdlib.h>

//header
int esPar(int numero);

//funcion principal
int main ()
{
	setbuf(stdout, NULL);
	int numeroUno;
	int numeroDos;

	numeroUno=esPar(32);
	numeroDos=esPar(43);

	puts("\n");
	printf("el numero uno es (1 - par / 0 - impar):  %d\n", numeroUno);
	printf("el numero dos es (1 - par / 0 - impar):  %d\n", numeroDos);



	return EXIT_SUCCESS;
}

//desarrollo de sub-tareas
int esPar(int numero)
{
	int ret=0; // 0 IMPAR
	if(numero%2 == 0)
	{
		ret=1;
	}
	return ret;
}
