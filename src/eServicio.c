/*
 * eServicio.c
 *
 *  Created on: 22 jun 2022
 *      Author: Familia
 */

#include <stdio.h>
#include <stdlib.h>
#include "eServicio.h"
#include "Controller.h"
#include "LinkedList.h"
#include "Parser.h"
#include <string.h>

eServicio* Servicio_new()
{
	eServicio *nuevoServi = NULL;
	nuevoServi = (eServicio*) malloc(sizeof(eServicio));
	if (nuevoServi != NULL)
	{
		nuevoServi->idServicio = 0;
    	strcpy(nuevoServi->descripcion, "");
		nuevoServi->tipos = 0;
		nuevoServi->precioUnitario = 0;
		nuevoServi->cantidad = 0;
		nuevoServi->totalServicio = 0;

	}
	return nuevoServi;
}

eServicio* Servicio_newParametros(char* idStr, char* cantidadStr,char* tiposStr,char* precioStr,char* descripcionStr, char* totalStr)
{
	eServicio *nuevoServi = Servicio_new();
	int idAux;
	int tipoAux;
	float precioUnitarioAux;
	int cantidadAux;
	int totalAux;

	idAux = atoi(idStr);
	tipoAux = atoi(tiposStr);
	cantidadAux=atoi(cantidadStr);

	precioUnitarioAux = atof(precioStr);
	totalAux = atof(totalStr);


	int validacion = 0;

	if (nuevoServi != NULL)
	{

		if (Servicio_setIdServicio(nuevoServi, idAux) == 0)
		{
			validacion++;
			if (Servicio_setDescripcion(nuevoServi, descripcionStr) == 0)
			{
				validacion++;
				if (Servicio_setTipos(nuevoServi, tipoAux) == 0)
				{
					validacion++;
					if (Servicio_setPrecioUnitario(nuevoServi,precioUnitarioAux) == 0)
					{
						validacion++;
						if (Servicio_setCantidad(nuevoServi, cantidadAux) == 0)
						{
							validacion++;
							if(Servicio_setTotalServicio(nuevoServi, totalAux) == 0)
							{
								validacion++;

							}
						}
					}
				}
			}

			if (validacion != 6)
			{
				free(nuevoServi);
				nuevoServi = NULL;
			}
		}

	}
	return nuevoServi;

}

int Servicio_setIdServicio(eServicio* this,int id)
{
	this->idServicio = id;
	if(this->idServicio != id)
	{
		return 1;
	}
	return 0;
}

int Servicio_getIdServicio(eServicio *this, int *id)
{
	*id = this->idServicio;
	if(*id != this->idServicio)
	{
		return 1;
	}
	return 0;
}

int Servicio_setDescripcion(eServicio *this, char *describe)
{
	strcpy(this->descripcion, describe);
	if(strcmp(this->descripcion, describe) != 0)
	{
		return 1;
	}

	return 0;

}

int Servicio_getDescripcion(eServicio *this, char *describe)
{
	strcpy(describe, this->descripcion);
	if(strcmp(this->descripcion, describe) != 0)
	{
		return 1;
	}
	return 0;
}

int Servicio_setTipos(eServicio *this, int tipoServi)
{
	this->tipos = tipoServi;
	if(this->tipos != tipoServi)
	{
		return 1;
	}

	return 0;
}

int Servicio_getTipos(eServicio *this, int *tipoServi)
{
	*tipoServi = this->tipos;
	if(this->tipos != *tipoServi)
	{
		return 1;
	}
	return 0;
}

int Servicio_setCantidad(eServicio *this, int amount)
{

	this->cantidad = amount;
	if(this->cantidad != amount)
	{
		return 1;
	}

	return 0;
}

int Servicio_getCantidad(eServicio *this, int *amount)
{

	*amount=this->cantidad;
	if(*amount != this->cantidad)
	{
		return 1;
	}

	return 0;
}

int Servicio_setTotalServicio(eServicio *this, float total)
{
	this->totalServicio = total;
	if(this->totalServicio != total)
	{
		return 1;
	}
	return 0;
}

int Servicio_getTotalServicio(eServicio *this, float *total)
{
	*total = this->totalServicio;
	if(this->totalServicio != *total)
	{
		return 1;
	}
	return 0;
}

int Servicio_setPrecioUnitario(eServicio *this, float precio)
{
	this->precioUnitario = precio;
	if(this->precioUnitario != precio)
	{
		return 1;
	}
	return 0;
}

int Servicio_getPrecioUnitario(eServicio *this, float *precio)
{
	*precio = this->precioUnitario;
	if(this->precioUnitario != *precio)
	{
		return 1;
	}
	return 0;
}

void* ServicioLista(eServicio *lista)
{
	char tipoServicioAux[15];
	if (lista != NULL)
	{
		switch (lista->tipos)
		{
		case 1:
			strcpy(tipoServicioAux, "Minorista");
			break;
		case 2:
			strcpy(tipoServicioAux, "Mayorista");
			break;
		case 3:
			strcpy(tipoServicioAux, "Exportar");
			break;
		}

		printf("%d   ||   ", lista->idServicio);
		printf(lista->descripcion);
		printf("   ||   ");
		printf(tipoServicioAux);
		printf("     ||   ");
		printf("%.2f", lista->precioUnitario);
		printf("   ||    ");
		printf("%d", lista->cantidad);
		printf("    ||   ");
		printf("%.2f", lista->totalServicio);
		printf("\n");
	}
	return 0;

}
int servicioMap(void *elemento)
{
    eServicio* FinalPrecio;
    FinalPrecio = elemento;
    float PasarPrecio;

    PasarPrecio = FinalPrecio->precioUnitario * FinalPrecio->cantidad;
    Servicio_setTotalServicio(FinalPrecio, PasarPrecio);

    return 0;
}
int filtarUno(void *elemento)
{
	eServicio *filtrado = elemento;

	if(filtrado->tipos == 1)
	{
		return 1;
	}
	return 0;
}
int filtarDos(void *elemento)
{
	eServicio *filtrado = elemento;

	if(filtrado->tipos == 2)
	{
		return 1;
	}
	return 0;
}
int filtarTres(void *elemento)
{
	eServicio *filtrado = elemento;

	if(filtrado->tipos == 3)
	{
		return 1;
	}
	return 0;
}
int comparacion(void* datoUno, void* datoDos)
{
	int retorno;
	char comparacionAuxA[50];
	char comparacionAuxB[50];

	eServicio* comparacionA;
	eServicio* comparacionB;

	comparacionA = (eServicio*) datoUno;
	comparacionB = (eServicio*) datoDos;

	Servicio_getDescripcion(comparacionA, comparacionAuxA);
	Servicio_getDescripcion(comparacionB, comparacionAuxB);

	if (strcmp(comparacionAuxA, comparacionAuxB) == 0)
	{
		retorno = 0;
	}
	else
	{
		if (strcmp(comparacionAuxA, comparacionAuxB) > 0)
		{
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}
	}
	return retorno;
}



