#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "reparacion.h"
#include "electrodomestico.h"
#include "utn.h"
#include "informes.h"

//----------------------------------------------------------------------------------------------------------------------------------------
int printElectrodomesticoPorMarca(eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc) {
	int retorno = -1;
	char nombreMarca[21];
	int idMarca;

	if (arrayElec != NULL && lenElec > 0 && arrayMarc != NULL && lenMarc > 0) {
		printMarcas(arrayMarc, lenMarc);
		utn_getCadena(nombreMarca, "\nIngrese nombre de la marca:",
				"\nError, debe escribir el nombre tal cual se muestra en la lista.",
				1, 21, 2);
		cargarIdMarcaPorDescripcion(nombreMarca, arrayMarc, lenMarc, &idMarca);
		cargarElectrodomesticosPorMarca(arrayElec, lenElec, arrayMarc, lenMarc,
				idMarca);
		retorno = 0;
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------
int cargarElectrodomesticosPorMarca(eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc, int idMarca) {
	int retorno = -1;
	int i;
	int flag = 0;

	if (arrayElec != NULL && lenElec > 0 && arrayMarc != NULL && lenMarc > 0) {
		for (i = 0; i < lenElec; i++) {
			if (arrayElec[i].idMarca == idMarca //Encuentro el id de la marca
			&& arrayElec[i].isEmpty == 0) { //Esa posicion no esta dada de baja
				printElectrodomesticoConMarca(arrayElec[i], arrayMarc, lenMarc);
				flag = 1; //Indica que existe un electrodomestico de esa marca
			}
		}
		if (flag == 0) { //No existe ningun electrodomestico de esa marca
			printf("\nNo hay electrodomesticos de esa marca.\n\n");
			system("pause");
		}
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------
int contarElectrodomesticosPorMarca(eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc) {
	int retorno = -1;
	int i;
	char nombreMarca[21];
	int idMarca;
	int contador = 0;

	if (arrayElec != NULL && lenElec > 0 && arrayMarc != NULL && lenMarc > 0) {
		printMarcas(arrayMarc, lenMarc);
		utn_getCadena(nombreMarca, "\nIngrese nombre de la marca:",
				"\nError, debe escribir el nombre tal cual se muestra en la lista.",
				1, 21, 2);
		cargarIdMarcaPorDescripcion(nombreMarca, arrayMarc, lenMarc, &idMarca);
		for (i = 0; i < lenElec; i++) { //Agarra todos los electrodomesticos de esa marca
			if (arrayElec[i].idMarca == idMarca && arrayElec[i].isEmpty == 0) {
				contador++;
			}
		}
		if (contador == 0) {
			printf("\nNo hay Electrodomesticos de esa marca.");
		} else {
			printf("\nHay %d electrodomesticos %s.", contador, nombreMarca);
		}

		retorno = 0;
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------
void printElectrodomesticoConMarca(eElectrodomestico electrodomestico, eMarca *arrayMarc, int lenMarc) {
	char descripcionMarca[21];

	if (arrayMarc != NULL && lenMarc > 0
			&& (cargarDescripcionMarcaPorId(electrodomestico.idMarca, arrayMarc, lenMarc,
					descripcionMarca) == 0)) {
		printf("%d\t%d\t%d\t%d\t%s\n", electrodomestico.id, electrodomestico.serie, electrodomestico.idMarca, electrodomestico.modelo, descripcionMarca);
	}
}
