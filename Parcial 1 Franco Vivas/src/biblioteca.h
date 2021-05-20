/*
 * biblioteca.h
 *
 *  Created on: 13 may. 2021
 *      Author: Franco Vivas
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include "trabajo.h"
#include "servicio.h"
#include "utn.h"


int Menu();
int MenuModificaciones();
int AltaTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS);
int MostrarTrabajoConServicio(eTrabajo unTrabajo, eServicio servicios[], int tamS);
int MostrarListaTrabajosConServicio(eTrabajo lista[], int tam, eServicio servicios[], int tamS);
int BajaTrabajo(eTrabajo lista[], int tam,eServicio servicios[], int tamS);
int ModificarTrabajo(eTrabajo lista[], int tam, eServicio servicios[], int tamS);
int TotalPesosServicio(eTrabajo lista[], int tam, eServicio servicios[], int tamS);

#endif /* BIBLIOTECA_H_ */
