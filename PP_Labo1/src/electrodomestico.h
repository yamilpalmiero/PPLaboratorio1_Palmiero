#ifndef ELECTRODOMESTICO_H_
#define ELECTRODOMESTICO_H_

typedef struct {
	int id; //PK Empieza en 1000
	char descripcion[21];
	int isEmpty;
} eMarca;

typedef struct {
	int id; //PK
	int serie; //PK
	int idMarca; //FK
	int modelo;
	int isEmpty;
} eElectrodomestico;

#endif /* ELECTRODOMESTICO_H_ */

/*
 *
 *
 */
int initElectrodomesticos(eElectrodomestico *array, int len);

/*
 *
 *
 */
int hardcodearElectrodomesticos(eElectrodomestico *array, int len, int cantidad);

/*
 *
 *
 */
void printElectrodomestico(eElectrodomestico reparacion);

/*
 *
 *
 */
void printElectrodomesticos(eElectrodomestico *array, int len);

/*
 *
 *
 */
int cargarDescripcionMarcaPorId(int idMarca, eMarca *array, int len,
		char *descripcion);

/*
 *
 *
 */
int cargarIdMarcaPorDescripcion(char *descripcion, eMarca *array, int len,
		int *idMarca);

/*
 *
 *
 */
eElectrodomestico buscarElectrodomesticoPorSerie(eElectrodomestico *array,
		int len, int serieElectrodomestico);
