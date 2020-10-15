#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "electrodomestico.h"
#include "utn.h"

//---------------------------------------------------------------------------------------------------------------------------------------
int initElectrodomesticos(eElectrodomestico *array, int len) {
	int retorno = -1;
	int i;

	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			array[i].isEmpty = 1;
			retorno = 0;
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int hardcodearElectrodomesticos(eElectrodomestico *array, int len, int cantidad) {
	int contador = 0;
	int i;

	if (array != NULL && len > 0 && cantidad > 0) {
		eElectrodomestico arrayAuxiliar[] = { { 0, 0, 1000, 0, 0 }, { 1, 1,
				1001, 1, 0 }, { 2, 2, 1002, 2, 0 }, { 3, 3, 1003, 3, 0 }, { 4,
				4, 1004, 4, 0 } };

		if (cantidad <= len && cantidad <= 5) {
			for (i = 0; i < len; i++) {
				array[i] = arrayAuxiliar[i];
				contador++;
			}
		}
	}
	return contador;
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printElectrodomestico(eElectrodomestico electrodomestico) {

	printf("\nId\t\tSerie\t\tId marca\t\tModelo");
	printf("\n%d\t\t%d\t\t%d\t\t%d", electrodomestico.id,
			electrodomestico.serie, electrodomestico.idMarca,
			electrodomestico.modelo);
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printElectrodomesticos(eElectrodomestico *array, int len) {
	int i;

	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			printElectrodomestico(array[i]);
		}
		printf("\n");
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printMarca(eMarca servicio) {

	printf("\n%d\t\t%s", servicio.id, servicio.descripcion);
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printMarcas(eMarca *array, int len) {
	int i;

	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			printMarca(array[i]);
		}
		printf("\n");
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------
int cargarDescripcionMarcaPorId(int idMarca, eMarca *array, int len,
		char *descripcion) {
	int retorno = -1;
	int i;

	if (array != NULL && len > 0 && descripcion != NULL) {
		for (i = 0; i < len; i++) {
			if (array[i].id == idMarca) {
				strncpy(descripcion, array[i].descripcion, 20);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int cargarIdMarcaPorDescripcion(char *descripcion, eMarca *array, int len,
		int *idMarca) {
	int retorno = -1;
	int i;

	if (array != NULL && len > 0 && descripcion != NULL) {
		for (i = 0; i < len; i++) {
			if (strcmp(array[i].descripcion, descripcion) == 0) {
				*idMarca = array[i].id;
				retorno = 0;
				break; //Breakeo para que no siga corriendo el for porque ya encontre el id
			}
		}
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
eElectrodomestico buscarElectrodomesticoPorSerie(eElectrodomestico *array,
		int len, int serieElectrodomestico) {
	int i;
	eElectrodomestico retorno;

	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (array[i].serie == serieElectrodomestico) {
				retorno = array[i];
			}
		}
	}

	return retorno;
}
