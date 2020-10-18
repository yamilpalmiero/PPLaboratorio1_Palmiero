#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "electrodomestico.h"
#include "utn.h"

//---------------------------------------------------------------------------------------------------------------------------------------
int buscarLibreElectrodomestico(eElectrodomestico *array, int len,
		int *posicion) {
	int retorno = -1;
	int i;

	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (array[i].isEmpty == 1) {
				*posicion = i;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
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
void printElectrodomestico(eElectrodomestico electrodomestico, eMarca *array,
		int len) {
	char descripcionMarca[21];

	if (array != NULL && len > 0
			&& (cargarDescripcionMarcaPorId(electrodomestico.idMarca, array,
					len, descripcionMarca) == 0)) {

		printf("\n%d\t\t%d\t\t%d\t\t%s\t\t%d", electrodomestico.id,
				electrodomestico.serie, electrodomestico.idMarca,
				descripcionMarca, electrodomestico.modelo);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printElectrodomesticos(eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc) {
	int i;

	if (arrayElec != NULL && lenElec > 0) {
		printf("\nId\t\tSerie\t\tId marca\tMarca\t\tModelo");
		for (i = 0; i < lenElec; i++) {
			if (arrayElec[i].isEmpty == 0) {
				printElectrodomestico(arrayElec[i], arrayMarc, lenMarc);
			}
		}
		printf("\n");
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printMarca(eMarca marca) {

	printf("\n%d\t\t%s", marca.id, marca.descripcion);
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printMarcas(eMarca *array, int len) {
	int i;

	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (array[i].isEmpty == 0) {
				printMarca(array[i]);
			}
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
//---------------------------------------------------------------------------------------------------------------------------------------
int addElectrodomestico(eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc) {
	int retorno = -1;
	int posicion;

	if (arrayElec != NULL && lenElec > 0 && arrayMarc != NULL && lenMarc > 0) {
		if (buscarLibreElectrodomestico(arrayElec, lenElec, &posicion) == -1) {
			printf("\nNo hay lugares vacios.");
		} else {
			utn_getEntero(&arrayElec[posicion].id, "Ingrese id: ", "\nError.",
					1, 10000, 2);
			utn_getEntero(&arrayElec[posicion].serie,
					"Ingrese numero de serie: ", "\nError.", 1, 100000, 2);
			printMarcas(arrayMarc, lenMarc);
			utn_getEntero(&arrayElec[posicion].idMarca,
					"Ingrese el id de la marca: ", "\nError.", 1000, 1004, 2);
			utn_getEntero(&arrayElec[posicion].modelo, "Ingrese modelo: ",
					"\nError.", 1, 10000, 2);
			arrayElec[posicion].isEmpty = 0;
			printf(
					"\nPosicion: %d\nId: %d\nSerie: %d\nId marca: %d\nModelo: %d",
					posicion, arrayElec[posicion].id, arrayElec[posicion].serie,
					arrayElec[posicion].idMarca, arrayElec[posicion].modelo);
			retorno = 0;
		}
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int modifyElectrodomestico(eElectrodomestico *list, int len, eMarca *arrayMarc,
		int lenMarc) {
	int retorno = -1;
	int posicion;
	int id;
	int opcion;

	if (list != NULL && len > 0) {
		printElectrodomesticos(list, len, arrayMarc, lenMarc);
		utn_getEntero(&id, "\nId a modificar: ", "\nError", 1, 10000, 2);
		if (findElectrodomesticoById(list, len, id, &posicion) == -1) {
			printf("\nEl id ingresado no existe.");
		} else {
			do {
				printf(
						"\nPosicion: %d\nId: %d\nNumero de serie: %d\nId de la marca: %d\nModelo: %d\n",
						posicion, list[posicion].id, list[posicion].serie,
						list[posicion].idMarca, list[posicion].modelo);
				utn_getEntero(&opcion,
						"\nModificar: \n\n1-Numero de serie \n2-Modelo \n3-Salir\n",
						"\nError", 1, 3, 2);
				switch (opcion) {
				case 1:
					utn_getEntero(&list[posicion].serie, "\nNumero de serie: ",
							"\nError", 1, 100000, 2);
					break;
				case 2:
					utn_getEntero(&list[posicion].modelo, "\nModelo: ",
							"\nError", 1, 10000, 2);
					break;
				case 3:
					break;
				default:
					printf("\nOpcion invalida");
				}
			} while (opcion != 3);
			retorno = 0;
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int findElectrodomesticoById(eElectrodomestico *list, int len, int id,
		int *posicion) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == 1) {
				continue;
			} else if (list[i].id == id) {
				*posicion = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int arrayElectrodomesticoVacio(eElectrodomestico *list, int len) {
	int retorno = 1;
	int i;

	if (list != NULL && len >= 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == 0) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int arrayMarcaVacio(eMarca *list, int len) {
	int retorno = 1;
	int i;

	if (list != NULL && len >= 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == 0) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int removeElectrodomestico(eElectrodomestico *list, int len, eMarca *arrayMarc,
		int lenMarc) {
	int retorno = -1;
	int posicion;
	int id;

	if (list != NULL && len > 0) {
		printElectrodomesticos(list, len, arrayMarc, lenMarc);
		utn_getEntero(&id, "\nId a eliminar: ", "\nError.", 0, 10000, 2);
		if (findElectrodomesticoById(list, len, id, &posicion) == -1) {
			printf("\nEl id ingresado no existe.");
		} else {
			list[posicion].isEmpty = 1;
			retorno = 0;
		}
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int sortElectrodomesticos(eElectrodomestico *list, int len) {
	int retorno = -1;
	int i, j;
	eElectrodomestico buffer;

	if (list != NULL && len > 0) {
		for (i = 0; i < len - 1; i++) {
			for (j = i + 1; j < len; j++) {
				if (list[i].modelo > list[j].modelo) {
					buffer = list[i];
					list[i] = list[j];
					list[j] = buffer;
				} else if (list[i].modelo < list[j].modelo) {
					buffer = list[i];
					list[i] = list[j];
					list[j] = buffer;
				} else if (list[i].modelo == list[j].modelo) {
					if (list[i].serie > list[j].serie) {
						buffer = list[i];
						list[i] = list[j];
						list[j] = buffer;
					}
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}
