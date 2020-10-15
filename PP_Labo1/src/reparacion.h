#ifndef REPARACION_H_
#define REPARACION_H_

typedef struct {
	int dia;
	int mes;
	int anio;
} eFecha;

typedef struct {
	int id; //PK Empieza en 20000
	char descripcion[26];
	int precio;
	int isEmpty;
} eServicio;

typedef struct {
	int id; //PK
	int serieElectrodomestico; //FK
	int idServicio; //FK
	eFecha fecha;
	int isEmpty;
} eReparacion;

#endif /* REPARACION_H_ */

/*
 *
 *
 */
int initReparaciones(eReparacion *array, int len);

/*
 *
 *
 */
int hardcodearReparaciones(eReparacion *array, int len, int cantidad);

/*
 *
 *
 */
void printReparacion(eReparacion reparacion);

/*
 *
 *
 */
void printReparaciones(eReparacion *array, int len);

/*
 *
 *
 */
void printServicio(eServicio servicio);

/*
 *
 *
 */
void printServicios(eServicio *array, int len);

/*
 *
 *
 */
int cargarDescripcionServicioPorId(int idServicio, eServicio *array, int len,
		char *descripcion);

/*
 *
 *
 */
int cargarIdServicioPorDescripcion(char *descripcion, eServicio *array, int len,
		int *idServicio);

/*
 *
 *
 */
int buscarLibre(eReparacion *array, int len, int *posicion);
