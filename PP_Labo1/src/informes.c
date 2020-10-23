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
void printElectrodomesticoConMarca(eElectrodomestico electrodomestico,
		eMarca *arrayMarc, int lenMarc) {
	char descripcionMarca[21];

	if (arrayMarc != NULL && lenMarc > 0
			&& (cargarDescripcionMarcaPorId(electrodomestico.idMarca, arrayMarc,
					lenMarc, descripcionMarca) == 0)) {
		printf("%d\t%d\t%d\t%d\t%s\n", electrodomestico.id,
				electrodomestico.serie, electrodomestico.idMarca,
				electrodomestico.modelo, descripcionMarca);
	}
}
//----------------------------------------------------------------------------------------------------------------------------------------
void printElectrodomesticoPorModelo(eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc, int modelo) {
	int i;
	int flag = 0;

	if (arrayElec != NULL && lenElec > 0) {
		for (i = 0; i < lenElec; i++) {
			if (arrayElec[i].modelo == modelo && arrayElec[i].isEmpty == 0) {
				printElectrodomestico(arrayElec[i], arrayMarc, lenMarc);
				flag = 1;
			}
		}
		if (flag == 0) {
			printf("\nNo hay electrodomesticos modelo 2020");
		}
	}
}
//----------------------------------------------------------------------------------------------------------------------------------------
int listarReparacionesPorElectrodomestico(eReparacion *arrayRepa, int lenRepa,
		eElectrodomestico *arrayElec, int lenElec, eMarca *arrayMarc,
		int lenMarc, eServicio *arrayServ, int lenServ) {
	int retorno = -1;
	int serieElectro;

	if (arrayRepa != NULL && lenRepa > 0 && arrayElec != NULL && lenElec > 0
			&& arrayMarc != NULL && lenMarc > 0 && arrayServ != NULL
			&& lenServ > 0) {
		printElectrodomesticos(arrayElec, lenElec, arrayMarc, lenMarc);
		utn_getEntero(&serieElectro,
				"\nIngrese numero de serie del electrodomestico:", "\nError.",
				1, 100000, 2);
		cargarReparacionesPorElectrodomestico(arrayRepa, lenRepa, arrayElec,
				lenElec, arrayServ, lenServ, serieElectro);

		retorno = 0;
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------
int cargarReparacionesPorElectrodomestico(eReparacion *arrayRepa, int lenRepa,
		eElectrodomestico *arrayElec, int lenElec, eServicio *arrayServ,
		int lenServ, int serieElectro) {
	int retorno = -1;
	int i;
	int flag = 0;

	if (arrayRepa != NULL && lenRepa > 0 && arrayElec != NULL && lenElec > 0
			&& arrayServ != NULL && lenServ > 0) {
		for (i = 0; i < lenRepa; i++) {
			if (arrayRepa[i].serieElectrodomestico == serieElectro //Encuentro el electrodomestico
			&& arrayRepa[i].isEmpty == 0) { //Esa posicion no esta dada de baja
				printReparacion(arrayRepa[i], arrayElec, lenElec, arrayServ,
						lenServ);
				flag = 1; //Indica que existe una reparacion
			}
		}
		if (flag == 0) { //No existe ninguna reparacion para ese electrodomestico
			printf(
					"\nNo se realizaron reparaciones a ese electrodomestico.\n\n");
			system("pause");
		}
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------
void listarElectrodomesticosSinReparacion(eReparacion *arrayRepa, int lenRepa,
		eElectrodomestico *arrayElec, int lenElec, eMarca *arrayMarc,
		int lenMarc, eServicio *arrayServ, int lenServ) {
	int i;
	if (arrayRepa != NULL && lenRepa > 0 && arrayElec != NULL && lenElec > 0
			&& arrayMarc != NULL && lenMarc > 0 && arrayServ != NULL
			&& lenServ > 0) {
		for (i = 0; i < lenRepa; i++) { //Recorre cada reparacion
			if (!(arrayRepa[i].serieElectrodomestico != 0)
					&& arrayRepa[i].isEmpty == 0) {
				cargarElectrodomesticoPorSerie(arrayElec, lenElec, arrayMarc,
						lenMarc, arrayElec[i].serie);
			}
		}
	}
}
//----------------------------------------------------------------------------------------------------------------------------------------
int cargarElectrodomesticoPorSerie(eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc, int serieElectro) {
	int retorno = -1;
	int i;

	if (arrayElec != NULL && lenElec > 0 && arrayMarc != NULL && lenMarc > 0) {
		for (i = 0; i < lenElec; i++) {
			if (arrayElec[i].serie == serieElectro //Encuentro el electrodomestico
			&& arrayElec[i].isEmpty == 0) { //Esa posicion no esta dada de baja
				printElectrodomestico(arrayElec[i], arrayMarc, lenMarc);
				retorno = 0;
			}
		}
	}
	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------
int sumarReparacionesPorElectrodomestico(eReparacion *arrayRepa, int lenRepa,
		eElectrodomestico *arrayElec, int lenElec, eMarca *arrayMarc,
		int lenMarc, eServicio *arrayServ, int lenServ) {
	int retorno = -1;
	int i;
	int suma = 0;
	int serieElectro;

	if (arrayRepa != NULL && lenRepa > 0 && arrayElec != NULL && lenElec > 0
			&& arrayMarc != NULL && lenMarc > 0 && arrayServ != NULL
			&& lenServ > 0) {
		printElectrodomesticos(arrayElec, lenElec, arrayMarc, lenMarc);
		utn_getEntero(&serieElectro,
				"\nIngrese numero de serie del electrodomestico:", "\nError.",
				1, 100000, 2);
		for (i = 0; i < lenRepa; i++) {
			if (arrayRepa[i].serieElectrodomestico == serieElectro
					&& arrayRepa[i].isEmpty == 0) {
				if (arrayRepa[i].idServicio == 20000) {
					suma = suma + 250;
				} else if (arrayRepa[i].idServicio == 20001) {
					suma = suma + 500;
				} else if (arrayRepa[i].idServicio == 20002) {
					suma = suma + 400;
				} else if (arrayRepa[i].idServicio == 20003) {
					suma = suma + 600;
				}
			}
		}
		printf("\nEl importe total es: %d", suma);
		retorno = 0;
	}
	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------
int contadorServicios(eReparacion *arrayRepa, int lenRepa,
		eElectrodomestico *arrayElec, int lenElec, eMarca *arrayMarc,
		int lenMarc, eServicio *arrayServ, int lenServ) {
	int retorno = -1;
	int i;
	int contador0 = 0;
	int contador1 = 0;
	int contador2 = 0;
	int contador3 = 0;
	char maximo[21];

	if (arrayRepa != NULL && lenRepa > 0 && arrayElec != NULL && lenElec > 0
			&& arrayMarc != NULL && lenMarc > 0 && arrayServ != NULL
			&& lenServ > 0) {

		for (i = 0; i < lenRepa; i++) {
			if (arrayRepa[i].idServicio == 20000 && arrayRepa[i].isEmpty == 0) {
				contador0++;
			} else if (arrayRepa[i].idServicio == 20001
					&& arrayRepa[i].isEmpty == 0) {
				contador1++;
			} else if (arrayRepa[i].idServicio == 20002
					&& arrayRepa[i].isEmpty == 0) {
				contador2++;
			} else if (arrayRepa[i].idServicio == 20003
					&& arrayRepa[i].isEmpty == 0) {
				contador3++;
			}
		}
		strcpy(maximo, "Garantia");
		if (contador1 > contador0 && contador1 > contador2
				&& contador1 > contador3) {
			strcpy(maximo, "Mantenimiento");
		} else if (contador2 > contador0 && contador2 > contador1
				&& contador2 > contador3) {
			strcpy(maximo, "Repuestos");
		} else if (contador3 > contador0 && contador3 > contador1
				&& contador3 > contador2) {
			strcpy(maximo, "Refaccion");
		}
		printf("\nEl servicio mas pedido es: %s", maximo);
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------
void printRecaudacionPorFecha(eReparacion *arrayRepa, int lenRepa,
		eElectrodomestico *arrayElec, int lenElec, eMarca *arrayMarc,
		int lenMarc, eServicio *arrayServ, int lenServ) {
	int i;
	eFecha fechaIngresada;
	int precioServicio;
	int suma = 0;

	if (arrayRepa != NULL && lenRepa > 0 && arrayElec != NULL && lenElec > 0
			&& arrayMarc != NULL && lenMarc > 0 && arrayServ != NULL
			&& lenServ > 0) {
		utn_getEntero(&fechaIngresada.dia, "\nIngrese dia: ", "\nError.", 1, 31,
				2);
		utn_getEntero(&fechaIngresada.mes, "\nIngrese mes: ", "\nError.", 1, 12,
				2);
		utn_getEntero(&fechaIngresada.anio, "\nIngrese anio: ", "\nError.",
				1900, 2020, 2);
		for (i = 0; i < lenRepa; i++) {
			if (arrayRepa[i].fecha.dia == fechaIngresada.dia
					&& arrayRepa[i].fecha.mes == fechaIngresada.mes
					&& arrayRepa[i].fecha.anio == fechaIngresada.anio) {
				cargarPrecioServicioPorId(arrayRepa[i].idServicio, arrayServ,
						lenServ, &precioServicio);
				suma = suma + precioServicio;
			}
		}
	}
	printf("\nLa recaudacion para la fecha es: %d", suma);
}
//---------------------------------------------------------------------------------------------------------------------------------------
int cargarPrecioServicioPorId(int idServicio, eServicio *array, int len,
		int *precioServicio) {
	int retorno = -1;
	int i;

	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (array[i].id == idServicio) {
				*precioServicio = array[i].precio;
				retorno = 0;
				break; //Breakeo para que no siga corriendo el for porque ya encontre el precio
			}
		}
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------
int listarReparacionesPorSerieElectrodomestico(eReparacion *arrayRepa,
		int lenRepa, eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc, eServicio *arrayServ, int lenServ) {
	int retorno = -1;
	int i;

	if (arrayRepa != NULL && lenRepa > 0 && arrayElec != NULL && lenElec > 0
			&& arrayMarc != NULL && lenMarc > 0 && arrayServ != NULL
			&& lenServ > 0) {
		for (i = 0; i < lenRepa; i++) {
			if (arrayRepa[i].idServicio == 20000 && arrayRepa[i].isEmpty == 0) {
				cargarElectrodomesticoPorSerie(arrayElec, lenElec, arrayMarc,
						lenMarc, arrayRepa[i].serieElectrodomestico);
				printf("\nFecha de reparacion: %d/%d/%d",
						arrayRepa[i].fecha.dia, arrayRepa[i].fecha.mes,
						arrayRepa[i].fecha.anio);
			}
		}

		retorno = 0;
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------
int sumarMantenimientos(eReparacion *arrayRepa, int lenRepa,
		eElectrodomestico *arrayElec, int lenElec, eMarca *arrayMarc,
		int lenMarc, eServicio *arrayServ, int lenServ) {
	int retorno = -1;
	int i;
	int suma = 0;

	if (arrayRepa != NULL && lenRepa > 0 && arrayElec != NULL && lenElec > 0
			&& arrayMarc != NULL && lenMarc > 0 && arrayServ != NULL
			&& lenServ > 0) {
		for (i = 0; i < lenRepa; i++) {
			if (arrayRepa[i].idServicio == 20001 && arrayRepa[i].isEmpty == 0) {
				suma = suma + 500;
			}
		}
		printf("\nLa facturacion total por mantenimiento es: %d", suma);
		retorno = 0;
	}
	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------
void listarElectrodomesticosPorFechaReparacion(eReparacion *arrayRepa,
		int lenRepa, eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc, eServicio *arrayServ, int lenServ) {
	int i;
	eFecha fechaIngresada;

	if (arrayRepa != NULL && lenRepa > 0 && arrayElec != NULL && lenElec > 0
			&& arrayMarc != NULL && lenMarc > 0 && arrayServ != NULL
			&& lenServ > 0) {
		utn_getEntero(&fechaIngresada.dia, "\nIngrese dia: ", "\nError.", 1, 31,
				2);
		utn_getEntero(&fechaIngresada.mes, "\nIngrese mes: ", "\nError.", 1, 12,
				2);
		utn_getEntero(&fechaIngresada.anio, "\nIngrese anio: ", "\nError.",
				1900, 2020, 2);
		for (i = 0; i < lenRepa; i++) {
			if (arrayRepa[i].fecha.dia == fechaIngresada.dia
					&& arrayRepa[i].fecha.mes == fechaIngresada.mes
					&& arrayRepa[i].fecha.anio == fechaIngresada.anio) {
				cargarElectrodomesticoPorSerie(arrayElec, lenElec, arrayMarc,
						lenMarc, arrayRepa[i].serieElectrodomestico);
			}
		}
	}
}
