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
int buscarLibreElectrodomestico(eElectrodomestico *array, int len,
		int *posicion);

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
void printElectrodomestico(eElectrodomestico electrodomestico, eMarca *array,
		int len);

/*
 *
 *
 */
void printElectrodomesticos(eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc);

/*
 *
 *
 */
void printMarca(eMarca marca);

/*
 *
 *
 */
void printMarcas(eMarca *array, int len);

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

/*
 *
 *
 */
int addElectrodomestico(eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc);

/*
 *
 *
 */
int modifyElectrodomestico(eElectrodomestico *list, int len, eMarca *arrayMarc,
		int lenMarc);

/*
 *
 *
 */
int findElectrodomesticoById(eElectrodomestico *list, int len, int id,
		int *posicion);

/*
 *
 *
 */
int arrayElectrodomesticoVacio(eElectrodomestico *list, int len);

/*
 *
 *
 */
int arrayMarcaVacio(eMarca *list, int len);

/*
 *
 *
 */
int removeElectrodomestico(eElectrodomestico *list, int len, eMarca *arrayMarc,
		int lenMarc);

/*
 *
 *
 */
int sortElectrodomesticos(eElectrodomestico *list, int len);
