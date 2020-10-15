#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "utn.h"
//------------------------------------------------------------------------------------------------------------------------
int utn_getEntero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {

	int retorno = -1;
	int bufferEntero;

	do {

		printf("%s", mensaje);

		if (utn_getInt(&bufferEntero) == 0 && bufferEntero >= minimo
				&& bufferEntero <= maximo) {
			retorno = 0;
			*pResultado = bufferEntero; //VARIABLE DEL MAIN
			break;
		}

		printf("%s", mensajeError);
		reintentos--;

	} while (reintentos <= 0);

	return retorno;
}
//------------------------------------------------------------------------------------------------------------------------
int utn_getFlotante(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos) {

	int retorno = -1;
	float bufferFlotante;

	do {

		printf("%s", mensaje);

		if (utn_getFloat(&bufferFlotante) == 0 && bufferFlotante >= minimo
				&& bufferFlotante <= maximo) {
			retorno = 0;
			*pResultado = bufferFlotante;
			break;
		}

		printf("%s", mensajeError);
		reintentos--;

	} while (reintentos <= 0);

	return retorno;
}
//------------------------------------------------------------------------------------------------------------------------
int utn_getCadena(char *pCadena, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos) {

	int retorno = -1;
	char bufferCadena[101];

	do {

		printf("%s", mensaje);
		fflush(stdin);
		gets(bufferCadena);

		if (strlen(bufferCadena) >= minimo && strlen(bufferCadena) < maximo) { //No puede ser <= maximo por el '\0'
			strcpy(pCadena, bufferCadena); //pResultado no hace falta ponerle el * porque como es cadena ya es puntero
			retorno = 0;
			break;
		}

		printf("%s", mensajeError);
		reintentos--;

	} while (reintentos <= 0);

	return retorno;
}
//------------------------------------------------------------------------------------------------------------------------
int utn_myGets(char *cadena, int longitud) {
	int retorno = -1;
	char bufferString[1000];

	if (cadena != NULL && longitud > 0) {
		fflush(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) { //fgets si sale mal devuelve NULL
			if (bufferString[strlen(bufferString) - 1] == '\n') {
				bufferString[strlen(bufferString) - 1] = '\0';
			}
			if (strlen(bufferString) <= longitud) {
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}

	}
	return retorno;
}
//------------------------------------------------------------------------------------------------------------------------
int utn_esNumericaEnteros(char *cadena, int limite) {
	int retorno = 1; //VERDADERO
	int i;

	for (i = 0; i < limite && cadena[i] != '\0'; i++) {
		if (i == 0 && (cadena[i] == '+' || cadena[i] == '-')) {
			continue; //VUELVE A ITERAR EN FOR osea se saltea el prox if
		}
		if (cadena[i] < '0' || cadena[i] > '9') {
			retorno = 0; //FALSO osea que hay un valor que no es un numero
			break; //SALE DEL FOR
		}
	}
	return retorno;
}
//------------------------------------------------------------------------------------------------------------------------
int utn_getInt(int *pResultado) {
	int retorno = -1;
	char bufferString[50];

	if (pResultado != NULL
			&& utn_myGets(bufferString, sizeof(bufferString)) == 0
			&& utn_esNumericaEnteros(bufferString, strlen(bufferString))) {
		retorno = 0;
		*pResultado = atoi(bufferString);
	}
	return retorno;
}
//------------------------------------------------------------------------------------------------------------------------
int utn_esNumericaFlotantes(char *cadena, int limite) {
	int retorno = 1; //VERDADERO
	int i;

	for (i = 0; i < limite && cadena[i] != '\0'; i++) {
		if (i == 0 && (cadena[i] == '+' || cadena[i] == '-')) {
			continue; //VUELVE A ITERAR EN FOR osea se saltea el prox if
		}
		if ((cadena[i] < '0' || cadena[i] > '9') && cadena[i] != '.') {
			retorno = 0; //FALSO osea que hay un valor que no es un numero
			break; //SALE DEL FOR
		}
	}
	return retorno;
}
//------------------------------------------------------------------------------------------------------------------------
int utn_getFloat(float *pResultado) {
	int retorno = -1;
	char bufferString[50];

	if (pResultado != NULL
			&& utn_myGets(bufferString, sizeof(bufferString)) == 0
			&& utn_esNumericaFlotantes(bufferString, strlen(bufferString))) {
		retorno = 0;
		*pResultado = atof(bufferString);
	}
	return retorno;
}
//------------------------------------------------------------------------------------------------------------------------
int menu() {
	int opcion;

	system("cls");

	printf("\n\n***MENU PRINCIPAL***\n\n");
	printf("1- Alta.\n");
	printf("2- Modificar.\n");
	printf("3- Baja.\n");
	printf("4- Listar alumnos.\n");
	printf("5- Listar alumnos.\n");
	printf("6- Ordenar por carrera.\n\n");
	printf("7- Ordenar por promedio.\n\n");
	printf("9- Salir.\n\n");

	utn_getEntero(&opcion, "Ingrese una opcion: ",
			"Error, debe ingresar un numero entre 1 y 9", 1, 9, 2);

	return opcion;
}
//------------------------------------------------------------------------------------------------------------------------
int submenuInformes() {
	int opcion;

	system("cls");

	printf("\n\n***MENU INFORMES***\n\n");
	printf("1- Listar alumnos de una sola carrera.\n");
	printf("2- Listar alumnos por promedio.\n");
	printf("3- Listar alumnos para cada carrera.\n");
	printf("4- Cantidad de alumnos para cada carrera.\n");
	printf("5- Cantidad de alumnos para una carrera.\n");
	printf("6- Carrera con mayor cantidad de alumnos.\n");
	printf("7- Salir.\n\n");

	utn_getEntero(&opcion, "Ingrese una opcion: ",
			"Error, debe ingresar un numero entre 1 y 7", 1, 7, 2);

	return opcion;
}
//------------------------------------------------------------------------------------------------------------------------

