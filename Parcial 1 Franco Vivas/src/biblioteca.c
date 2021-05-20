#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"

int Menu()
{
	int opciones;

	printf("\n\t>ABM TRABAJOS<\t\n");
	printf("1. ALTA\n");
	printf("2. MODIFICAR\n");
	printf("3. BAJA\n");
	printf("4. MOSTRAR lista trabajos\n");
	printf("5. MOSTRAR lista servicios\n");
	printf("6. TOTAL en pesos por los servicios prestados\n");
	printf("0. SALIR\n");
	utn_getInt("\nIngrese una opcion: \n","Error, opcion invalida",0,6,2,&opciones);

	return opciones;
}

int MenuModificaciones()
{
	int opciones;

	printf("\n\t>MODIFICAR<\t\n");
	printf("1. Marca de la bicicleta\n");
	printf("2. Servicio\n");
	printf("0. SALIR\n");
	utn_getInt("\nIngrese una opcion para modificar: \n","Error, opcion invalida",0,2,2,&opciones);

	return opciones;
}

int AltaTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS)
{
	int isOk=-1;
	int index;
	if(lista!=NULL && tam>0 && listaS!=NULL && tamS>0)
	{
		index=BuscarLibre(lista,tam);

		if(index<0)
		{
			printf("No hay espacio libre\n");
		}
		else
		{
			lista[index].id=ObtenerId();
			utn_getString("Ingrese la marca: \n","Error, reingrese\n",25,2,lista[index].marcaBicicleta);
			utn_getInt("Ingrese el rodado: \n","Error, reingrese\n",12,29,2,&lista[index].rodadoBicicleta);
			MostrarListaServicios(listaS,tamS);
			utn_getInt("Ingrese el ID del servicio: \n","Error, reingrese\n",20000,20004,2,&lista[index].idServicio);
			printf("Ingrese fecha de ingreso dd/mm/aaaa: \n");
			utn_getInt("Ingrese dia \n","Error, reingrese\n",1,31,2,&lista[index].fecha.dia);
			utn_getInt("Ingrese mes \n","Error, reingrese\n",1,12,2,&lista[index].fecha.mes);
			utn_getInt("Ingrese año [1970-2021]\n","Error, reingrese [1970-2021]\n",1970,2021,2,&lista[index].fecha.anio);
			lista[index].isEmpty=OCUPADO;

			isOk=0;
		}
	}

	return isOk;
}

int MostrarTrabajoConServicio(eTrabajo unTrabajo, eServicio servicios[], int tamS)
{
	int isOk=-1;
	char descripcionS[25];

	if(servicios != NULL && tamS>0)
	{
		GetDescripcionServicio(servicios,tamS,unTrabajo.idServicio,descripcionS);
		printf("ID de trabajo: %d\n"
			   "Marca bicicleta: %s\n"
			   "Numero de rodado: %d\n"
			   "ID servicio: %d\n"
			   "Descripcion: %s\n"
			   "Fecha: %02d/%02d/%d\n", unTrabajo.id
			   	   	   	   	   	   	  , unTrabajo.marcaBicicleta
									  , unTrabajo.rodadoBicicleta
								      , unTrabajo.idServicio
									  , descripcionS
									  , unTrabajo.fecha.dia
								  	  , unTrabajo.fecha.mes
									  , unTrabajo.fecha.anio);
		isOk=0;
	}

	return isOk;
}

int MostrarListaTrabajosConServicio(eTrabajo lista[], int tam, eServicio servicios[], int tamS)
{
	int isOk=-1;
	int i;

	if(lista!=NULL && tam>0 && servicios!=NULL && tamS>0)
	{
		printf("\n> LISTA DE TRABAJOS: \n");
		for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==OCUPADO)
			{
				MostrarTrabajoConServicio(lista[i],servicios,tamS);
				isOk=0;
			}
		}
	}

	return isOk;
}

int BajaTrabajo(eTrabajo lista[], int tam,eServicio servicios[], int tamS)
{
	int isOk=-1;
	char respuesta[4];
	int index;
	int id;

	if(lista != NULL && tam>0)
	{
		MostrarListaTrabajosConServicio(lista,tam,servicios,tamS);
		utn_getInt("Ingrese el ID para dar de baja\n","Error, ID invalido\n",1,tam,2,&id);
		index=BuscarTrabajoPorId(lista,tam,id);
		MostrarTrabajoConServicio(lista[index],servicios,tamS);
		utn_getString("\n¿Esta seguro que desea eliminar este trabajo?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,2,respuesta);
		if(!(stricmp(respuesta,"si")))
		{
			lista[index].isEmpty=VACIO;
			printf("\nEl trabajo de la bicicleta marca %s y rodado %d con ID %d se ha dado de baja correctamente\n",lista[index].marcaBicicleta
																												   ,lista[index].rodadoBicicleta
																												   ,lista[index].id);
			isOk=0;
		}
	}

	return isOk;
}

int ModificarTrabajo(eTrabajo lista[], int tam, eServicio servicios[], int tamS)
{
	int isOk=-1;
	char respuesta[4];
	char confirmar[4]="no";
	int index;
	int auxId;
	char auxMarca[25];
	int auxIdServicio;

	MostrarListaTrabajosConServicio(lista,tam,servicios,tamS);
	utn_getInt("Ingrese el ID del trabajo a modificar: \n","Error, ID invalido\n",1,tam,2,&auxId);
	index=BuscarTrabajoPorId(lista, tam, auxId);
	MostrarTrabajoConServicio(lista[index],servicios,tamS);
	utn_getString("¿Esta seguro que desea modificar este trabajo? [si/no]\n","Error, ingrese [si/no]\n",4,2,respuesta);

	if(!(stricmp(respuesta,"si")))
	{
		do
		{
			switch(MenuModificaciones())
			{
				case 0:
					utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,2,confirmar);
					break;
				case 1:
					printf("\t****MODIFICAR MARCA****\t\n");
					utn_getString("Ingrese la nueva marca\n","Error, nombre invalido\n",25,2,auxMarca);
					strcpy(lista[index].marcaBicicleta,auxMarca);
					break;
				case 2:
					printf("\t****MODIFICAR SERVICIO****\t\n");
					MostrarListaServicios(servicios,tamS);
					utn_getInt("Ingrese el ID del nuevo servicio\n","Error, id invalido\n",20000,20004,2,&auxIdServicio);
					lista[index].idServicio=auxIdServicio;
					break;
			}
		}while(stricmp(confirmar,"si"));

		isOk=0;
	}
	else
	{
		printf("No se realizo ningun cambio\n");
	}

	return isOk;
}

int TotalPesosServicio(eTrabajo lista[], int tam, eServicio servicios[], int tamS)
{
	int isOk=-1;
	int i;
	int j;
	float auxPrecio;

	for(i=0; i<tam-1 ; i++)
	{
		for(j=i+1; j<tamS ; j++)
		{
			if(lista[i].idServicio==servicios[j].id)
			{
				auxPrecio += servicios[j].precio;
				isOk=0;
			}
		}
	}

	printf("El total en pesos por los servicios prestados es: $%.2f ",auxPrecio);

	return isOk;
}
