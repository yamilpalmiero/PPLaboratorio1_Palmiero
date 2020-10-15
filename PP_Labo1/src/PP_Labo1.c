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
	int opcionSubmenu;

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
	system("pause");

	/*idReparacion = idReparacion
	 + hardcodearReparaciones(reparaciones, CANT_REPA, 5);

	 printReparaciones(reparaciones, CANT_REPA);
	 system("pause");*/

	do {
		utn_getEntero(&opcionMenu,
				"\n\n***MENU PRINCIPAL***\nElija una opcion:\n\n1) Alta\n2) Modificar\n3) Baja\n4) Informar\n5) Salir\n",
				"\nError", 1, 5, 2);
		system("cls");
		switch (opcionMenu) {
		case 1:
			//FUNCION ADD
			break;
		case 2:
			//FUNCION MODIFY
			break;
		case 3:
			//FUNCION REMOVE
			break;
		case 4:
			//INFORMES
			break;
		case 5:
			printf("\nSalio!\n\n");
			system("pause");
			break;
		}

	} while (opcionMenu != 5);

	return EXIT_SUCCESS;
}
