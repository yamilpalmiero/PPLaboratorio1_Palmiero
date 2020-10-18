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
 * brief Recorre el array y encuentra la primera posicion libre
 * param array Array de electrodomesticos
 * param len Tamaño del array de electrodomesticos
 * param posicion Puntero al espacio de memoria donde se va a guardar la posicion libre encontrada
 * return Retorna 0 si encontro una posicion libre y -1 si no
 */
int buscarLibreElectrodomestico(eElectrodomestico *array, int len,
		int *posicion);

/*
 * brief Inicializa todas las posiciones del array como vacias
 * param array Array que se desea inicializar
 * param len Tamaño del array
 * return Retorna 0 si salio OK y -1 si no
 */
int initElectrodomesticos(eElectrodomestico *array, int len);

/*
 * brief Hardcodea uno o varios datos de tipo eElectrodomestico con un maximo de 5 elementos
 * param array Array de electrodomesticos
 * param len Tamaño del array de electrodomesticos
 * return Retorna 0 si salio OK y -1 si no
 */
int hardcodearElectrodomesticos(eElectrodomestico *array, int len, int cantidad);

/*
 * brief Recibe una estructura e imprime los datos guardados en sus campos
 * param electrodomestico Estructura que se desea imprimir
 * param arrayMarc Array de marcas
 * param lenMarc Tamaño del array de marcas
 */
void printElectrodomestico(eElectrodomestico electrodomestico, eMarca *array,
		int len);

/*
 * brief Recibe un array de estructuras e imprime los datos guardados en sus campos
 * param arrayElec Array de electrodomesticos
 * param lenElec Tamaño del array de electrodomesticos
 * param arrayMarc Array de marcas
 * param lenMarc Tamaño del array de marcas
 */
void printElectrodomesticos(eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc);

/*
 * brief Recibe una estructura e imprime los datos de sus campos
 * param marca Estructura a imprimir
 */
void printMarca(eMarca marca);

/*
 * brief Recibe un array de estructuras e imprime los datos guardados en sus campos
 * param array Array de marcas a imprimir
 * param len Tamaño del array de marcas
 */
void printMarcas(eMarca *array, int len);

/*
 * brief Recibe el numero de id del servicio y devuelve su descripcion
 * param idMarca Numero de id de la marca
 * param array Array de marcas
 * param len Tamaño del array de marcas
 * param descripcion Puntero al espacio de memoria donde se va a guardar la descripcion de la marca
 * return Retorna 0 si se cargo la descripcion y -1 si no
 */
int cargarDescripcionMarcaPorId(int idMarca, eMarca *array, int len,
		char *descripcion);

/*
 * brief Recibe la descripcion de una marca y devuelve su numero de id
 * param descripcion Descripcion de la marca
 * param array Array de marcas
 * param len Tamaño del array de marcas
 * param idServicio Puntero al espacio de memoria donde se guardara el id de la marca
 * return Retorna 0 si se cargo el id y -1 si no
 */
int cargarIdMarcaPorDescripcion(char *descripcion, eMarca *array, int len,
		int *idMarca);

/*
 * brief Recorre el array de electrodomesticos y devuelve el electrodomestico que su serie coincida con la serie pasado por parametro
 * param array Array de electrodomesticos
 * param len Tamaño del array de electrodomesticos
 * param serieElectrodomestico Dato serie del electrodomestico buscado
 * return Retorna la estructura con los datos del electrodomestico buscado
 */
eElectrodomestico buscarElectrodomesticoPorSerie(eElectrodomestico *array,
		int len, int serieElectrodomestico);

/*
 * brief En un array existente de electrodomesticos agrega los datos pasados por parametro en la primera posicion libre
 * param arrayElec Array de electrodomesticos
 * param lenElec Tamaño del array de electrodomesticos
 * param arrayMarc Array de marcas
 * param lenMarc Tamaño del array de marcas
 * return Retorna 0 si se pudo agregar el electrodomestico y -1 si no
 */
int addElectrodomestico(eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc);

/*
 * brief Busca un electrodomestico por si id y modifica los campos requeridos
 * param list Array de electrodomesticos
 * param len Tamaño del array de electrodomesticos
 * param arrayMarc Array de marcas
 * param lenMarc Tamaño del array de marcas
 * return Retorna 0 si se pudo modificar el campo y -1 si no pudo
 */
int modifyElectrodomestico(eElectrodomestico *list, int len, eMarca *arrayMarc,
		int lenMarc);

/*
 * brief Recibe el id de un electrodomestico y devuelve su posicion en el array
 * param list Array de electrodomesticos
 * param len Tamaño del array de electrodomesticos
 * param id Numero de id del electrodomestico para saber su posicion en el array
 * param posicion Puntero al espacio de memoria donde se va a guardar la posicion del electrodomestico en el array
 * return Retorna 0 si salio OK y -1 si no
 */
int findElectrodomesticoById(eElectrodomestico *list, int len, int id,
		int *posicion);

/*
 * brief Recibe un array de estructuras y la recorre para fijarse si tiene al menos un dato cargado
 * param list Array de electrodomesticos
 * param len Longitud del array
 * return Retorna 1 si esta completamente vacio y 0 si tiene al menos un electrodomestico guardado
 */
int arrayElectrodomesticoVacio(eElectrodomestico *list, int len);

/*
 * brief Recibe un array de estructuras y la recorre para fijarse si tiene al menos un dato cargado
 * param list Array de marcas
 * param len Longitud del array
 * return Retorna 1 si esta completamente vacio y 0 si tiene al menos una marca guardada
 */
int arrayMarcaVacio(eMarca *list, int len);

/*
 * brief Elimina a un electrodomestico por su id (pone el campo isEmpty en 1)
 * param list Array de electrodomesticos
 * param len Tamaño del array de electrodomesticos
 * param arrayMarc Array de marcas
 * param lenMarc Tamaño del array de marcas
 * reuturn Retorna 0 si se realizo OK la baja y -1 si no
 */
int removeElectrodomestico(eElectrodomestico *list, int len, eMarca *arrayMarc,
		int lenMarc);

/*
 * brief Ordena los electrodomesticos por modelo de manera ascendente y si es el mismo modelo los ordena por serie (tambien ascendente)
 * param list Array de electrodomesticos
 * param len Tamaño del array de electrodomesticos
 * return Retorna 0 si pudo ordenar OK y -1 si no
 */
int sortElectrodomesticos(eElectrodomestico *list, int len);
