#include "electrodomestico.h"
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
 * brief Inicializa todas las posiciones del array como vacias
 * param array Array que se desea inicializar
 * param len Tamaño del array
 * return Retorna 0 si salio OK y -1 si no
 */
int initReparaciones(eReparacion *array, int len);

/*
 * brief Hardcodea uno o varios datos de tipo eReparacion con un maximo de 5 elementos
 * param array Array de reparaciones
 * param len Tamaño del array de reparaciones
 * return Retorna 0 si salio OK y -1 si no
 */
int hardcodearReparaciones(eReparacion *array, int len, int cantidad);

/*
 * brief Recibe una estructura e imprime los datos guardados en sus campos
 * param reparacion Estructura que se desea imprimir
 * param arrayElec Array de electrodomesticos
 * param lenElec Tamaño del array de electrodomesticos
 * param arrayServ Array de servicios
 * param lenServ Tamaño del array de servicios
 */
void printReparacion(eReparacion reparacion, eElectrodomestico *arrayElec,
		int lenElec, eServicio *arrayServ, int lenServ);

/*
 * brief Recibe un array de estructuras e imprime los datos guardados en sus campos
 * param array Array que se desea imprimir
 * param arrayElec Array de electrodomesticos
 * param lenElec Tamaño del array de electrodomesticos
 * param arrayServ Array de servicios
 * param lenServ Tamaño del array de servicios
 */
void printReparaciones(eReparacion *array, int len,
		eElectrodomestico *arrayElec, int lenElec, eServicio *arrayServ,
		int lenServ);

/*
 * brief Recibe una estructura e imprime los datos de sus campos
 * param servicio Estructura a imprimir
 */
void printServicio(eServicio servicio);

/*
 * brief Recibe un array de estructuras e imprime los datos guardados en sus campos
 * param array Array de servicios a imprimir
 * param len Tamaño del array de servicios
 */
void printServicios(eServicio *array, int len);

/*
 * brief Recibe el numero de id del servicio y devuelve su descripcion
 * param idServicio Numero de id del servicio
 * param array Array de servicios
 * param len Tamaño del array de servicios
 * param descripcion Puntero al espacio de memoria donde se va a guardar la descripcion del servicio
 * return Retorna 0 si se cargo la descripcion y -1 si no
 */
int cargarDescripcionServicioPorId(int idServicio, eServicio *array, int len,
		char *descripcion);

/*
 * brief Recibe la descripcion de un servicio y devuelve su numero de id
 * param descripcion Descripcion del servicio
 * param array Array de servicios
 * param len Tamaño del array de servicios
 * param idServicio Puntero al espacio de memoria donde se guardara el id del servicio
 * return Retorna 0 si se cargo el id y -1 si no
 */
int cargarIdServicioPorDescripcion(char *descripcion, eServicio *array, int len,
		int *idServicio);

/*
 * brief Recibe un array de estructuras y busca la primera posicion libre
 * param array Array de estructuras
 * param len Tamaño del array de estructuras
 * param posicion Puntero al espacio de memoria donde se va a guardar la posicion libre
 * return Retorna 0 si salio OK y -1 si no
 */
int buscarLibre(eReparacion *array, int len, int *posicion);

/*
 * brief En un array existente de reparaciones agrega los datos pasados por parametro en la primera posicion libre
 * param arrayRepa Array de reparaciones
 * param lenRepa Tamaño del array de reparaciones
 * param arrayServ Array de servicios
 * param lenServ Tamaño del array de servicios
 * param arrayElec Array de electrodomesticos
 * param lenElec Tamaño del array de electrodomesticos
 * param arrayMarc Array de marcas
 * param lenMarc Tamaño del array de marcas
 * param contadorId Puntero al espacio de memoria donde se va a guardar el contador de id
 * return Retorna 0 si se pudo agregar OK la reparacion y -1 si no
 */
int addReparacion(eReparacion *arrayRepa, int lenRepa, eServicio *arrayServ,
		int lenServ, eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc, int *contadorId);

/*
 * brief Recibe un array de estructuras y la recorre para fijarse si tiene al menos un dato cargado
 * param list Array de reparaciones
 * param len Longitud del array
 * return Retorna 1 si esta completamente vacio y 0 si tiene al menos una reparacion guardada
 */
int arrayReparacionVacio(eReparacion *list, int len);

/*
 * brief Recibe un array de estructuras y la recorre para fijarse si tiene al menos un dato cargado
 * param list Array de servicios
 * param len Longitud del array
 * return Retorna 1 si esta completamente vacio y 0 si tiene al menos un servicio guardado
 */
int arrayServicioVacio(eServicio *list, int len);
