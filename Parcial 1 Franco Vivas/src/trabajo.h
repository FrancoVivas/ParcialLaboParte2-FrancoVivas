/*
 * biblioteca.h
 *
 *  Created on: 13 may. 2021
 *      Author: Franco Vivas
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_
#define T 100
#define VACIO 0
#define OCUPADO 1

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int id;
	char marcaBicicleta[25];
	int rodadoBicicleta;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;

int ObtenerId(void);
void Inicializar(eTrabajo lista[], int tam);
int BuscarLibre(eTrabajo lista[], int tam);
int BuscarTrabajoPorId(eTrabajo lista[], int tam, int id);
int OrdenarTrabajosPorAnio(eTrabajo lista[], int tam);


#endif /* TRABAJO_H_ */
