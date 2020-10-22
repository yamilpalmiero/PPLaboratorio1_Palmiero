#include "reparacion.h"
#include "electrodomestico.h"

#ifndef INFORMES_H_
#define INFORMES_H_

#endif /* INFORMES_H_ */

/*
 * brief Imprime todos los electrodomesticos de la marca indicada
 * param arrayElec Array de electrodomesticos
 * param lenElec Tamaño del array de electrodomesticos
 * param arrayMarc Array de marcas
 * param lenMarc Tamaño del array de marcas
 * return Retorna 0 si salio OK y -1 si no
 */
int printElectrodomesticoPorMarca(eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc);

/*
 * brief Muestra todos los electrodomesticos de esa marca en particular
 * param arrayElec Array de electrodomesticos
 * param lenElec Tamaño del array de electrodomesticos
 * param arrayMarc Array de marcas
 * param lenMarc Tamaño del array de marcas
 * param idMarca Dato id de la marca
 * return Retorna 0 si salio OK y -1 si no
 */
int cargarElectrodomesticosPorMarca(eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc, int idMarca);

/*
 * brief Muestra la cantidad de electrodomesticos de la marca indicada
 * param arrayElec Array de electrodomesticos
 * param lenElec Tamaño del array de electrodomesticos
 * param arrayMarc Array de marcas
 * param lenMarc Tamaño del array de marcas
 * return Retorna 0 si salio OK y -1 si no
 */
int contarElectrodomesticosPorMarca(eElectrodomestico *arrayElec, int lenElec,
		eMarca *arrayMarc, int lenMarc);

/*
 * brief Recibe una estructura e imprime sus datos
 * param electrodomestico Estructura a imprimir
 * param arrayMarc Array de marcas
 * param lenMarc Tamaño del array de marcas
 */
void printElectrodomesticoConMarca(eElectrodomestico electrodomestico,
		eMarca *arrayMarc, int lenMarc);
