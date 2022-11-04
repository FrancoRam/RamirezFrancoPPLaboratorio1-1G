/*
 * funcionesBasic.c
 *
 *  Created on: 3 sept 2022
 *      Author: Franc
 */

#include "funcionesBasic1.h"
#include "string.h"




/**
 * @fn int dividirEnteros(int, int, float*)
 * @brief realiza la division de dos enteros.
 * @param num1 - variable de tipo entero.
 * @param num2 - variable de tipo entero.
 * @param resultado - variable (puntero) de tipo flotante.
 * @return retorna un entero ( 0 si pudo realizar la division - 1 si no pudo)
 */
int dividirEnteros(int num1, int num2, float* resultado)
{
	int ret;

	if(num2 != 0)
	{
		*resultado=(float)num1/num2;
		ret=0;
	}
	else
	{
		ret=-1;
	}


	return ret;
}
//----------------------------------------------------
/**
 * @fn int sumarEnteros(int, int)
 * @brief realiza la suma de dos enteros
 * @param num1 - variable de tipo entero.
 * @param num2 - variable de tipo entero.
 * @return retorna la suma, de tipo entero.
 */
int sumarEnteros(int num1,int num2)
{
	int ret;
	int resultado;

	resultado= num1 + num2;
	ret=resultado;

	return ret;
}

//----------------------------------------------------
/**
 * @fn int esPar(int)
 * @brief evalúa si un entero es PAR
 * @param numero - variable de tipo entero.
 * @return retorna un entero ( 1 si es PAR - 0 si es IMPAR)
 */
int esPar(int numero)
{
	int ret=0 ; // IMPAR 0

	if(numero%2 == 0)
	{
		ret=1;
	}
	return ret;
}
//----------------------------------------------------
/**
 * @fn float calcularPromedio(int, int)
 * @brief calcula un promedio
 *
 * @param num1 - variable de tipo entero.
 * @param num2 - variable de tipo entero.
 * @return retorna un promedio de tipo Flotante
 */

float calcularPromedio(int num1, int num2)
{
	float ret;

	float promedio;

	promedio = (float)(num1+num2)/2;

	ret=promedio;
	return ret;
}
//----------------------------------------------------

/**
 * @fn int getIntRange(int*, char*, char*, int, int)
 * @brief

 * @param pValor - variable puntero donde se asigna el valor pedido,
 * @param mensaje - cadena de caracteres dispuesta para un mensaje.
 * @param msjError - cadena de caracteres dispuesta para un mensaje de error.
 * @param min - tipo entero que denota el mínimo del rango establecido.
 * @param max - tipo entero que denota el máximo del rango establecido.
 * @return retorna 0 en caso de que sea diferente de NULL y sea un número entero dentro del rango establecido, si no retorna -1
 */
int getIntRange_(int *pValor, char *mensaje, char *msjError, int min, int max) {
	int ret = -1;
	int aux;

	if (pValor != NULL && mensaje != NULL && msjError != NULL && min<=max)
	{
		printf("%s", mensaje);
		while (getInt_(&aux)==-1 || (aux < min || aux > max))
		{
			printf("%s", msjError);
		}
		*pValor = aux;
		ret = 0;
	}

	return ret;
}

//----------------------------------------------------

int getFactorialNumero()
{
	setbuf(stdout, NULL);
	int ret=-1;
	int numero;
	int auxNumero;
	int bandera=0;
	int factorial;

	getIntRange_(&numero, "Ingrese un numero natural: ", "ERROR- ingrese un numero natural: ", 0, 100);
	if (numero >= 0 && numero <= 100)
	{
		ret=0;
		auxNumero = numero;

		factorial = 1;
		for (int i = 0; i < numero; i++) {
			if (bandera == 0) {
				factorial = factorial * auxNumero;
				bandera = 1;
			} else {
				auxNumero--;
				factorial = factorial * (auxNumero);
			}
		}
	}
	printf("\nEl factorial de %d es: %d\n", numero, factorial);

	return ret;
}

//----------------------------------------------------

int utn_getNumeroReintentos(int* pValor, char* mensaje, char* msjError, int reintentos)
{
	int ret = -1;
	int aux;
	int retorno;

	if (pValor != NULL && mensaje != NULL && msjError != NULL && reintentos >0)
	{
		printf("%s", mensaje);

		while ((retorno=getInt_(&aux))==-1 && reintentos>0)
		{
			reintentos--;
			printf("%s", msjError);
		}
		if(retorno==0)
		{
			*pValor = aux;
			ret = 0;
		}
	}

	return ret;
}

//----------------------------------------------------

/*
void limpiarPantalla()
{
	int cantidad=40;
	for(int i=0; i<cantidad;i++)
		printf("\n");
}
*/
//----------------------------------------------------

int getChar(char* pValor, char* mensaje, char* msjError, char min, char max, int reintentos)
{
	int ret=-1;
	char aux;
	if(pValor != NULL && mensaje != NULL && msjError != NULL)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &aux);
			if(aux>=min && aux<=max)
			{
				*pValor=aux;
				ret=0;
				break;
			}
			else
			{
				printf("%s\n", msjError);
				reintentos--;
			}
		}while(reintentos>0);
	}
	return ret;
}
//---------------------------------------
/**
 * @fn int getFloatRange(float*, char*, char*, float, float)
 * @brief

 * @param pValor - variable puntero donde se asigna el valor pedido,
 * @param mensaje - cadena de caracteres dispuesta para un mensaje.
 * @param msjError - cadena de caracteres dispuesta para un mensaje de error.
 * @param min - tipo flotante que denota el mínimo del rango establecido.
 * @param max - tipo flotante que denota el máximo del rango establecido.
 * @param reintentos - tipo entero que denota la cantidad de reintentos al haber un ingreso erroneo.
 *
 * @return retorna 0 en caso de que sea diferente de NULL y sea un número entero dentro del rango establecido.
 * 		   caso contrario retorna -1.
 */
int getFloatRange(float *pValor, char *mensaje, char *msjError, float min,float max, int reintentos) {
	int ret = -1;
	float aux;

	if (pValor != NULL && mensaje!=NULL && msjError != NULL && min<max)
	{
		printf("%s", mensaje);
		scanf("%f", &aux);
		while ((aux < min || aux > max) && reintentos>=0)
		{
			printf("%s", msjError);
			fflush(stdin);
			scanf("%f", &aux);
			reintentos--;
		}
		if(aux >= min && aux <= max)
		{
			*pValor = aux;
			ret = 0;
		}

	}

	return ret;
}
//---------------------------------------
int getInt_(int* pInt)
{
	int ret=-1;
	char auxTexto[4096];
	if(myGets(auxTexto, sizeof(auxTexto))==0 && esNumerica(auxTexto)==0)
	{
		*pInt=atoi(auxTexto);
		ret=0;
	}
	return ret;
}
//---------------------------------------

int esNumerica(char cadena[])
{
	int ret=0;
	int i=0;
	int banderaCadena=0;
	while(cadena[i]!='\0')
	{
		if(cadena[0]=='-' && banderaCadena==0)
		{
			i++; //EVITA EL PRIMER ÍNDICE PARA QUE UNA CADENA PUEDA SER NEGATIVA
			banderaCadena=1; // evita que vuelva a ingresar
		}
		if(cadena[i]>=48 && cadena[i]<=57)
		{
			i++;
		}
		else
		{
			ret=-1;
			break;
		}
	}
	return ret;
}
//---------------------------------------

int myGets(char* cadena, int len)
{
	int ret=-1;
	char auxCadena[4096];
	if(cadena!=NULL && len >0)
	{
		fflush(stdin);
		scanf("%s", auxCadena); //MEJORAR PARA USAR-> | FGETS(CADENA,LEN,STDIN) |
		strncpy(cadena, auxCadena, len);
		ret=0;
	}
	return ret;
}
//---------------------------------------
//bc
int getString(char *pBuffer, int limite)
{
    int retorno = -1;
    int len;
    char bufferString[4096];
    if(pBuffer != NULL && limite > 0 )
    {
         fflush(stdin);
        fgets(bufferString, 4096, stdin);
        len = strlen(bufferString);
        if(len <= limite)
        {
            if(len != limite-1 || bufferString[limite-2] == '\n')
            {
                bufferString[len-1] = '\0';
            }
            strncpy(pBuffer, bufferString, limite);
            retorno = 0;
        }
        else
        {
            printf("Se admite un maximo de %d caracteres\n", limite - 1);
        }
    }
    return retorno;
}
//---------------------------------------
//bc
int isValidNombre(char *pBuffer, int limite)
{
    int retorno = 0;
    int cantidadEspacios = 0;
    int i;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0 /*&& pBuffer[0]>='A' && pBuffer[0]<='Z'*/)
    {
        retorno = 1;
        for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(pBuffer[i]==' ' && cantidadEspacios == 0)
            {
                cantidadEspacios++;
            }
            else if(!(pBuffer[i] >= 'a' && pBuffer[i] <= 'z' && pBuffer[i-1] != ' ') &&
                    !(/*pBuffer[i] >= 'A' && pBuffer[i] <= 'Z' &&*/ pBuffer[i-1] == ' '))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
//---------------------------------------
//bc
int utn_getNombre(char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pNombre != NULL && limite > 0 && mensaje != NULL && mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 &&
                isValidNombre(buffer, limite))
            {
                strncpy(pNombre, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
//---------------------------------------
int getSexo(char pValor[], char* mensaje, char* msjError, int reintentos)
{
	int ret=-1;
	char aux[50];
	if(pValor != NULL && mensaje != NULL && msjError != NULL)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%s", aux);
			if(aux[0]=='f' || aux[0]=='m' || (aux[0]=='n' || aux[1]=='b'))
			{
				strcpy(pValor,aux);
				ret=0;
				break;
			}
			else
			{
				printf("%s\n", msjError);
				reintentos--;
			}
		}while(reintentos>0);
	}
	return ret;
}
//---------------------------------------

int getSexoFOM(char* pValor, char* mensaje, char* msjError, int reintentos)
{
	int ret=-1;
	char aux;
	if(pValor != NULL && mensaje != NULL && msjError != NULL)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &aux);
			//ideal validar que sea minusculas
			if(aux=='f' || aux=='m')
			{
				*pValor=aux;
				ret=0;
				break;
			}
			else
			{
				printf("%s\n", msjError);
				reintentos--;
			}
		}while(reintentos>0);
	}
	return ret;
}
//---------------------------------------

int sortSimple(int pVec[], int tam,int criterio) //AGREGAR CRITERIO (0 ASC -  1 DESC)
{
	int ret=-1;
	int aux;
	if(pVec!=NULL && tam>0 && (criterio == 1 || criterio == 0))
	{
		for(int i=0; i<tam-1; i++)
		{
			for(int j=i+1; j<tam;j++)
			{
				if(criterio==0) //ORDENAMIENTO ASCENDENTE
				{
					if(pVec[i]>pVec[j])
					{
						aux=pVec[i];
						pVec[i]=pVec[j];
						pVec[j]=aux;
					}
				}
				else			//ORDENAMIENTO DESCENDENTE
				{
					if(pVec[i]<pVec[j])
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
	return ret;
}

//---------------------------------------

/**
* \brief Evalua si es una fecha valida
* \param dia Toma el dia
* \param mes Toma el mes
* \param anio Toma el anio
* \return En caso de exito retorna 1, si no 0
*
*/
int isValidFecha(int dia, int mes, int anio)
{
    int retorno = 0;
    if(dia > 0 && mes > 0 &&  anio > 0)
    {
        if(((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) &&
                (dia > 0 && dia <= 31)) ||
                ((mes == 4 || mes == 6 || mes == 9 || mes == 11) &&
                 (dia > 0 && dia <= 30)) ||
                ((mes == 2 && (anio % 4) == 0) &&
                 (dia > 0 && dia <= 29)) ||
                ((mes == 2 && (anio % 4) != 0) &&
                 (dia > 0 && dia <= 28)))
        {
            retorno = 1;
        }
    }
    return retorno;
}
