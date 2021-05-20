/*
 * biblioteca.h
 *
 *  Created on: 13 may. 2021
 *      Author: Franco Vivas
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_
#define S 4

typedef struct
{
	int id;
	char descripcion[25];
	float precio;

}eServicio;

void HardcodeoServicio(eServicio lista[], int* idServicio);
void MostrarServicio(eServicio servicio);
int MostrarListaServicios(eServicio servicios[], int tam);
int GetDescripcionServicio(eServicio lista[], int tam, int buscarCodigo,char descripcion[]);

typedef struct
{
	int id;
	char marca[25];
	int rodado;
	char color;
}eBicicleta;


#endif /* SERVICIO_H_ */
