#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "reparacion.h"
#include "electrodomestico.h"
#include "utn.h"
#include "informes.h"

#define CANT_REPA 5
#define CANT_ELEC 5
#define CANT_SERV 4
#define CANT_MARC 5

int main(void) {
	setbuf(stdout, NULL);

	eReparacion reparaciones[CANT_REPA];
	eElectrodomestico electrodomesticos[CANT_ELEC];
	eServicio servicios[] = { { 20000, "Garantia", 250, 0 }, { 20001,
			"Mantenimiento", 500, 0 }, { 20002, "Repuestos", 400, 0 }, { 20003,
			"Refaccion", 600, 0 } };
	eMarca marcas[] = { { 1000, "Whirlpool", 0 }, { 1001, "Sony", 0 }, { 1002,
			"Liliana", 0 }, { 1003, "Gafa", 0 }, { 1004, "Phillips", 0 } };
	int idReparacion = 0;
	int opcionMenu;
	int opcionInformes;

	if (initReparaciones(reparaciones, CANT_REPA) == 0) {
		printf("\nEl array de reparaciones se inicializo correctamente.");
	} else {
		printf("\nError al inicializar reparaciones.");
	}

	if (initElectrodomesticos(electrodomesticos, CANT_ELEC) == 0) {
		printf(
				"\nEl array de electrodomesticos se inicializo correctamente.\n");
	} else {
		printf("\nError al inicializar reparaciones.\n");
	}

	/*idReparacion = idReparacion
	 + hardcodearReparaciones(reparaciones, CANT_REPA, 5);

	 printReparaciones(reparaciones, CANT_REPA);
	 system("pause");*/

	do {
		utn_getEntero(&opcionMenu,
				"\n\n***MENU PRINCIPAL***\nElija una opcion:\n\n1) Alta electrodomestico \n2) Modificar electrodomestico\n3) Baja electrodomestico\n4) Listar electrodomesticos \n5) Listar marcas\n6) Listar servicios\n7) Alta reparacion\n8) Listar reparaciones\n9) Informes\n0) Salir\n",
				"\nError", 0, 9, 2);

		system("cls");

		switch (opcionMenu) {
		case 1:
			addElectrodomestico(electrodomesticos, CANT_ELEC, marcas,
			CANT_MARC);
			break;
		case 2:
			if (arrayElectrodomesticoVacio(electrodomesticos, CANT_ELEC)) {
				printf("\nAun no se cargo ningun electrodomestico.\n\n");
				system("pause");
			} else {
				modifyElectrodomestico(electrodomesticos, CANT_ELEC, marcas,
				CANT_MARC);
			}
			break;
		case 3:
			if (arrayElectrodomesticoVacio(electrodomesticos, CANT_ELEC)) {
				printf("\nAun no se cargo ningun electrodomestico.\n\n");
				system("pause");
			} else {
				removeElectrodomestico(electrodomesticos, CANT_ELEC, marcas,
				CANT_MARC);
			}
			break;
		case 4:
			if (arrayElectrodomesticoVacio(electrodomesticos, CANT_ELEC)) {
				printf("\nAun no se cargo ningun electrodomestico.\n\n");
				system("pause");
			} else {
				sortElectrodomesticos(electrodomesticos, CANT_ELEC);
			}
			printElectrodomesticos(electrodomesticos, CANT_ELEC, marcas,
			CANT_MARC);
			break;
		case 5:
			if (arrayMarcaVacio(marcas, CANT_MARC)) {
				printf("\nAun no se cargo ninguna marca.\n\n");
				system("pause");
			} else {
				printMarcas(marcas, CANT_MARC);
			}
			break;
		case 6:
			if (arrayServicioVacio(servicios, CANT_SERV)) {
				printf("\nAun no se cargo ningun servicio.\n\n");
				system("pause");
			} else {
				printServicios(servicios, CANT_SERV);
			}
			break;
		case 7:
			addReparacion(reparaciones, CANT_REPA, servicios, CANT_SERV,
					electrodomesticos, CANT_ELEC, marcas, CANT_MARC,
					&idReparacion);
			break;
		case 8:
			if (arrayReparacionVacio(reparaciones, CANT_REPA)) {
				printf("\nAun no se cargo ninguna reparacion.\n\n");
				system("pause");
			} else {
				printReparaciones(reparaciones, CANT_REPA, electrodomesticos,
				CANT_ELEC, servicios, CANT_SERV);
			}
			break;
		case 9:
			do {
				utn_getEntero(&opcionInformes,
						"\n***MENU INFORMES***\nElija una opcion:\n\n1) Mostrar electrodomesticos del anio 2020 \n2) Mostrar electrodomesticos de una marca seleccionada\n3) Mostrar todas las reparaciones efectuadas al electrodomestico seleccionado\n4) Listar los electrodomesticos que no tuvieron reparaciones\n5) Informar importe total de las reparaciones realizadas a un electrodomestico seleccionado\n6) Mostrar el servicio mas pedido\n7) Mostrar la recaudacion en una fecha en particular\n8) Mostrar todos los electrodomesticos que realizaron una garantia y la fecha\n9) Trabajos realizados a electrodomesticos del anio 2018\n10) Facturacion total por los mantenimientos\n11) Informar la marca de electrodomesticos que efectuaron mas refacciones\n12) Listar los electrodomesticos que recibieron reparacion en una fecha determinada\n13) Salir\n",
						"\nError", 1, 13, 2);

				system("cls");

				switch (opcionInformes) {
				case 1:
					if (arrayElectrodomesticoVacio(electrodomesticos,
					CANT_ELEC)) {
						printf(
								"\nAun no se cargo ningun electrodomestico.\n\n");
						system("pause");
					} else {
						printElectrodomesticoPorModelo(electrodomesticos,
						CANT_ELEC, marcas, CANT_MARC, 2020);
					}
					break;
				case 2:
					if (arrayElectrodomesticoVacio(electrodomesticos,
					CANT_ELEC)) {
						printf(
								"\nAun no se cargo ningun electrodomestico.\n\n");
						system("pause");
					} else {
						printElectrodomesticoPorMarca(electrodomesticos,
						CANT_ELEC, marcas, CANT_MARC);
					}
					break;
				case 3:
					if (arrayElectrodomesticoVacio(electrodomesticos,
					CANT_ELEC)) {
						printf(
								"\nAun no se cargo ningun electrodomestico.\n\n");
						system("pause");
					} else {
						listarReparacionesPorElectrodomestico(reparaciones,
						CANT_REPA, electrodomesticos, CANT_ELEC, marcas,
						CANT_MARC, servicios, CANT_SERV);
					}
					break;
				case 4:
					if (arrayElectrodomesticoVacio(electrodomesticos,
					CANT_ELEC)) {
						printf(
								"\nAun no se cargo ningun electrodomestico.\n\n");
						system("pause");
					} else {
						listarElectrodomesticosSinReparacion(reparaciones,
						CANT_REPA, electrodomesticos, CANT_ELEC, marcas,
						CANT_MARC, servicios, CANT_SERV);
					}
					break;
				case 5:
					if (arrayElectrodomesticoVacio(electrodomesticos,
					CANT_ELEC)) {
						printf(
								"\nAun no se cargo ningun electrodomestico.\n\n");
						system("pause");
					} else {
						sumarReparacionesPorElectrodomestico(reparaciones,
						CANT_REPA, electrodomesticos, CANT_ELEC, marcas,
						CANT_MARC, servicios, CANT_SERV);
					}
					break;
				case 6:
					if (arrayElectrodomesticoVacio(electrodomesticos,
					CANT_ELEC)) {
						printf(
								"\nAun no se cargo ningun electrodomestico.\n\n");
						system("pause");
					} else {
						contadorServicios(reparaciones,
						CANT_REPA, electrodomesticos, CANT_ELEC, marcas,
						CANT_MARC, servicios, CANT_SERV);
					}
					break;
				case 7:
					if (arrayElectrodomesticoVacio(electrodomesticos,
					CANT_ELEC)) {
						printf(
								"\nAun no se cargo ningun electrodomestico.\n\n");
						system("pause");
					} else {
						printRecaudacionPorFecha(reparaciones,
						CANT_REPA, electrodomesticos, CANT_ELEC, marcas,
						CANT_MARC, servicios, CANT_SERV);
					}
					break;
				case 8:
					if (arrayElectrodomesticoVacio(electrodomesticos,
					CANT_ELEC)) {
						printf(
								"\nAun no se cargo ningun electrodomestico.\n\n");
						system("pause");
					} else {
						listarReparacionesPorElectrodomestico(reparaciones,
						CANT_REPA, electrodomesticos, CANT_ELEC, marcas,
						CANT_MARC, servicios, CANT_SERV);
					}
					break;
				case 9:
					if (arrayElectrodomesticoVacio(electrodomesticos,
					CANT_ELEC)) {
						printf(
								"\nAun no se cargo ningun electrodomestico.\n\n");
						system("pause");
					} else {
						sumarReparacionesPorElectrodomestico(reparaciones,
						CANT_REPA, electrodomesticos, CANT_ELEC, marcas,
						CANT_MARC, servicios, CANT_SERV);
					}
					break;
				case 10:
					if (arrayElectrodomesticoVacio(electrodomesticos,
					CANT_ELEC)) {
						printf(
								"\nAun no se cargo ningun electrodomestico.\n\n");
						system("pause");
					} else {
						sumarMantenimientos(reparaciones,
						CANT_REPA, electrodomesticos, CANT_ELEC, marcas,
						CANT_MARC, servicios, CANT_SERV);
					}
					break;
				case 11:
					if (arrayElectrodomesticoVacio(electrodomesticos,
					CANT_ELEC)) {
						printf(
								"\nAun no se cargo ningun electrodomestico.\n\n");
						system("pause");
					} else {
						sumarReparacionesPorElectrodomestico(reparaciones,
						CANT_REPA, electrodomesticos, CANT_ELEC, marcas,
						CANT_MARC, servicios, CANT_SERV);
					}
					break;
				case 12:
					if (arrayElectrodomesticoVacio(electrodomesticos,
					CANT_ELEC)) {
						printf(
								"\nAun no se cargo ningun electrodomestico.\n\n");
						system("pause");
					} else {
						listarElectrodomesticosPorFechaReparaciono(reparaciones,
						CANT_REPA, electrodomesticos, CANT_ELEC, marcas,
						CANT_MARC, servicios, CANT_SERV);
					}
					break;
				case 13:
					printf("\nSalio de Informes!\n\n");
					system("pause");
					break;
				}
			} while (opcionInformes != 13);

			break;
		case 0:
			printf("\nSalio!\n\n");
			system("pause");
			break;
		}

	} while (opcionMenu != 0);

	return EXIT_SUCCESS;
}
