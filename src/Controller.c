/*
 * Controller.c
 *
 *  Created on: 22 jun 2022
 *      Author: Familia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parser.h"
#include "LinkedList.h"
#include "eServicio.h"
#include "inputs.h"



/** \brief Carga los datos de los servicios desde un archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList* pArrayListServicio)
{
	FILE *pFile;
	int retorno;
	pFile = fopen(path, "r");
	if (pFile == NULL) {
		retorno = 0;
	} else {
		parser_PassengerFromText(pFile, pArrayListServicio);
		fclose(pFile);
		retorno = 1;
	}
	return retorno;
}
/**
 * @brief
 *
 * @pre
 * @post
 * @param pArrayeServicio
 * @return
 */
int controllerAddServicio(LinkedList *pArrayeServicio)
{
    ll_map(pArrayeServicio, servicioMap);

    return 0;
}



/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListServi(LinkedList* pArrayListServicio)
{
		Node *posicionIndice = pArrayListServicio->pFirstNode;
		eServicio *leer;

		printf("[ID :  ][ descripcion: ][ tipo servicio:    ][ precio:  ][ cantidad: ][  total del servicio:  ]\n");
		for (; posicionIndice != NULL; posicionIndice = posicionIndice->pNextNode)
		{
			leer = posicionIndice->pElement;
			ServicioLista(leer);
		}
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortServi(LinkedList* pArrayListServicio)
{
	ll_sort(pArrayListServicio, comparacion, 1);

	return 0;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListServicio)
{
	FILE *pArchivo;

		int retorno = 1;
		pArchivo = fopen(path, "w");
		if (pArchivo == NULL)
		{
			retorno = 0;
		}

		int idServiAux;
		char descripcionAux[50];
		char tipoServiAux[20];
		float precioUnitarioAux;
		int cantantidadAux;
		float totalServiAux;

		int tipoServi;

		Node *indice = pArrayListServicio->pFirstNode;

		fprintf(pArchivo, "%s,%s,%s,%s,%s,%s\n", "id", "descripcion", "tipo servicio", "precio","cantidad", "total del servio");

		for (; indice != NULL; indice = indice->pNextNode)
		{

			Servicio_getIdServicio(indice->pElement, &idServiAux);
			Servicio_getDescripcion(indice->pElement, descripcionAux);
			Servicio_getTipos(indice->pElement, &tipoServi);
			Servicio_getPrecioUnitario(indice->pElement, &precioUnitarioAux);
			Servicio_getCantidad(indice->pElement, &cantantidadAux);
			Servicio_getTotalServicio(indice->pElement, &totalServiAux);


			switch(tipoServi)
			{
				case 1:
					strcpy(tipoServiAux, "Minorista");
					break;
				case 2:
					strcpy(tipoServiAux, "Mayorista");
					break;
				case 3:
					strcpy(tipoServiAux, "Exportar");
					break;
			}

			fprintf(pArchivo, "%d,%s,%s,%f,%d,%f\n", idServiAux,descripcionAux,tipoServiAux,precioUnitarioAux,cantantidadAux,totalServiAux);

		}

		fclose(pArchivo);

		return retorno;
}
int Controller_aniadir(LinkedList* pArrayListServicio)
{
	ll_map(pArrayListServicio, servicioMap);

	return 0;
}
int Controller_filtrar(LinkedList* pArrayListServicio)
{
	LinkedList *nuevaList;
	char path[20];
	int filtrar;

	utn_getNumEntero(&filtrar, "Ingesar el filtro -1 -2 -3", "Error,Ingesar el filtro -1 -2 -3", 1, 3, 5);

	switch(filtrar)
	{
	case 1:
		nuevaList = ll_filter(pArrayListServicio, filtarUno);
		break;
	case 2:
		nuevaList = ll_filter(pArrayListServicio, filtarDos);
		break;
	case 3:
		nuevaList = ll_filter(pArrayListServicio, filtarTres);
		break;
	}
	controller_ListServi(nuevaList);

	printf("Ingrese el nombre del archivo que desa guardar");
	fflush(stdin);
	gets(path);
	controller_saveAsText(path, nuevaList);
	return 0;
}

