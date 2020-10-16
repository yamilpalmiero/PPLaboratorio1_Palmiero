#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "reparacion.h"
#include "electrodomestico.h"
#include "utn.h"

#define CANT_REPA 3
#define CANT_ELEC 3
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
				"\n\n***MENU PRINCIPAL***\nElija una opcion:\n\n1) Alta electrodomestico \n2) Modificar electrodomestico\n3) Baja electrodomestico\n4) Listar electrodomesticos \n5) Listar marcas\n6) Listar servicios\n7) Alta reparacion\n8) Listar reparaciones\n9) Salir\n",
				"\nError", 1, 9, 2);

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
			printf("\nSalio!\n\n");
			system("pause");
			break;
		}

	} while (opcionMenu != 9);

	return EXIT_SUCCESS;
}
