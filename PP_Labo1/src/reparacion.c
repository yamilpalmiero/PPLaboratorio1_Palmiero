#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "reparacion.h"
#include "electrodomestico.h"
#include "utn.h"

//---------------------------------------------------------------------------------------------------------------------------------------
int initReparaciones(eReparacion *array, int len) {
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
int hardcodearReparaciones(eReparacion *array, int len, int cantidad) {
	int contador = 0;
	int i;

	if (array != NULL && len > 0 && cantidad > 0) {
		eReparacion arrayAuxiliar[] = { { 0, 0, 20000, { 10, 12, 2019 }, 0 }, {
				1, 1, 20001, { 11, 2, 2017 }, 0 }, { 2, 2, 20002,
				{ 1, 1, 2016 }, 0 }, { 3, 3, 20003, { 8, 7, 2020 }, 0 }, { 4, 4,
				20004, { 18, 2, 2018 }, 0 } };

		if (cantidad <= len && cantidad <= 5) {
			for (i = 0; i < len; i++) {
				array[i] = arrayAuxiliar[i]; //Puede asignar asi porque ambas estructuras son identicas. Guardo toda la informacion que tengo en mi array auxiliar adentro de mi array verdadero que se pasa por parametro
				contador++;
			}
		}
	}
	return contador;
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printReparacion(eReparacion reparacion, eElectrodomestico *arrayElec,
		int lenElec, eServicio *arrayServ, int lenServ) {

	printf("\n%d\t\t%d\t\t%d\t\t%d/%d/%d", reparacion.id,
			reparacion.serieElectrodomestico, reparacion.idServicio,
			reparacion.fecha.dia, reparacion.fecha.mes, reparacion.fecha.anio);
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printReparaciones(eReparacion *array, int len,
		eElectrodomestico *arrayElec, int lenElec, eServicio *arrayServ,
		int lenServ) {
	int i;

	if (array != NULL && len > 0 && arrayElec != NULL && lenElec > 0
			&& arrayServ != NULL && lenServ > 0) {
		printf("\nId\t\tSerie electrodomestico\t\tId servicio\t\tFecha");
		for (i = 0; i < len; i++) {
			if (array[i].isEmpty == 0) {
				printReparacion(array[i], arrayElec, lenElec, arrayServ,
						lenServ);
			}
		}
		printf("\n");
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printServicio(eServicio servicio) {

	printf("\n%d\t\t%s\t\t%d", servicio.id, servicio.descripcion,
			servicio.precio);
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printServicios(eServicio *array, int len) {
	int i;

	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			printServicio(array[i]);
		}
		printf("\n");
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------
int cargarDescripcionServicioPorId(int idServicio, eServicio *array, int len,
		char *descripcion) {
	int retorno = -1;
	int i;

	if (array != NULL && len > 0 && descripcion != NULL) {
		for (i = 0; i < len; i++) {
			if (array[i].id == idServicio) {
				strncpy(descripcion, array[i].descripcion, 25);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int cargarIdServicioPorDescripcion(char *descripcion, eServicio *array, int len,
		int *idServicio) {
	int retorno = -1;
	int i;

	if (array != NULL && len > 0 && descripcion != NULL) {
		for (i = 0; i < len; i++) {
			if (strcmp(array[i].descripcion, descripcion) == 0) {
				*idServicio = array[i].id;
				retorno = 0;
				break; //Breakeo para que no siga corriendo el for porque ya encontre el id
			}
		}
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int buscarLibre(eReparacion *array, int len, int *posicion) {
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
int addReparacion(eReparacion *arrayRepa, int lenRepa, eServicio *arrayServ,
		int lenServ, eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc, int *contadorId) {
	int retorno = -1;
	int posicion;

	if (arrayRepa != NULL && lenRepa > 0 && contadorId != NULL) {
		if (buscarLibre(arrayRepa, lenRepa, &posicion) == -1) {
			printf("\nNo hay lugares vacios.");
		} else {
			(*contadorId)++;
			arrayRepa[posicion].id = *contadorId; //El id coincide con el indice y es autoincremental
			printElectrodomesticos(arrayElec, lenElec, arrayMarc, lenMarc);
			utn_getEntero(&arrayRepa[posicion].serieElectrodomestico,
					"\nNumero de serie del electrodomestico: ", "\nError.", 0,
					100000, 2);
			printServicios(arrayServ, lenServ);
			utn_getEntero(&arrayRepa[posicion].serieElectrodomestico,
					"\nId del servicio: ", "\nError.", 20000, 20003, 2);
			utn_getEntero(&arrayRepa[posicion].serieElectrodomestico, "\nDia: ",
					"\nError.", 1, 31, 2); //dia
			utn_getEntero(&arrayRepa[posicion].serieElectrodomestico, "\nMes: ",
					"\nError.", 1, 12, 2); //mes
			utn_getEntero(&arrayRepa[posicion].serieElectrodomestico,
					"\nAnio: ", "\nError.", 1900, 2020, 2); //anio
			arrayRepa[posicion].isEmpty = 0;
			printReparacion(arrayRepa[posicion], arrayElec, lenElec, arrayServ,
					lenServ);
			retorno = 0;
		}
	}

	return retorno;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int arrayReparacionVacio(eReparacion *list, int len) {
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
int arrayServicioVacio(eServicio *list, int len) {
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
