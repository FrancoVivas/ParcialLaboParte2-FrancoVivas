/*
 * Parcial 1
 * Franco Vivas
 * Division 1°B
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#define REALIZADO 1
#define NO_REALIZADO 0


int main(void) {
	setbuf(stdout,NULL);
	char confirmar[4]="no";
	int cantidad;
	int flag;
	int i;
	eTrabajo unTrabajo[T];
	eServicio unServicio[S];
	int idServicio=20000;

	Inicializar(unTrabajo,T);
	HardcodeoServicio(unServicio,&idServicio);

	do
	{
		switch(Menu())
		{
			case 0:
				utn_getString("\n¿Desea salir?[si/no]\n","\nRespuesta invalida, ingresar [si/no]\n",4,2,confirmar);
				break;
			case 1:
				i=0;
				printf(" \n\t\t>ALTAS<\t\t\n");
				utn_getInt("\n¿Cuantos trabajos desea dar de alta?\n","\nError, cantidad invalida\n",1,1000,2,&cantidad);
				do
				{
					if(!(AltaTrabajo(unTrabajo,T,unServicio,S)))
					{
						flag=REALIZADO;
					}
					else
					{
						flag=NO_REALIZADO;
					}
					i++;
				}while(cantidad!=i);
				break;
			case 2:
				printf("\t\t>MODIFICAR<\t\t\n");
				if(flag==REALIZADO)
				{
					 ModificarTrabajo(unTrabajo,T,unServicio,S);
				}
				else
				{
					printf("Error, no se dio de alta el trabajo\n");
				}
				break;
			case 3:
				i=0;
				printf("\t\t>BAJAS<\t\t\n");
				if(flag==REALIZADO)
				{
					utn_getInt("¿Cuantos trabajos quiere dar de baja?\n","Error, cantidad invalida\n",1,1000,2,&cantidad);
					do
					{
						if(BajaTrabajo(unTrabajo,T,unServicio,S))
						{
							printf("No se realizo ningun cambio\n");
						}
						i++;
					}while(cantidad!=i);
				}
				else
				{
					printf("Error, no se dio ningun alta\n");
				}
				break;
			case 4:
				printf("\t\t>LISTA DE TRABAJOS<<\t\t\n");
				if(flag==REALIZADO)
				{
					OrdenarTrabajosPorAnio(unTrabajo,T);
					MostrarListaTrabajosConServicio(unTrabajo,T,unServicio,S);
				}
				else
				{
					printf("Error, no se dio nungun alta\n");
				}
				break;
			case 5:
				printf("\t\t>Lista de servicios<<\t\t\n");
				MostrarListaServicios(unServicio,S);
				break;
			case 6:
				printf("\t\t>TOTAL<<\t\t\n");
				TotalPesosServicio(unTrabajo,T,unServicio,S);
				break;
		}
	}while(stricmp(confirmar,"si"));
	printf("Gracias, hasta luego");

	return EXIT_SUCCESS;
}
