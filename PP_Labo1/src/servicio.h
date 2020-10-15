#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct {
	int id; //PK Empieza en 20000
	char descripcion[26];
	int precio;
	int isEmpty;
} eServicio;

#endif /* SERVICIO_H_ */
