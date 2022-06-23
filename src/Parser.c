/*
 * Parser.c
 *
 *  Created on: 22 jun 2022
 *      Author: Familia
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eServicio.h"
#include <string.h>
#include "ctype.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pArchivo, LinkedList* pArrayListServicio)
{
	eServicio *nuevo;

	char idAux[30];
	char descAux[30];
	char tipoAux[30];
	char precioAux[30];
	char cantAux[30];
	char totalAux[30];

	int r;
	int validar = 0;

	if (pArchivo == NULL) {
		printf("El archivo no existe");
		exit(EXIT_FAILURE);
	}
	do {
		r = fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux,descAux, tipoAux, precioAux, cantAux, totalAux);
		if (r == 6) {
			nuevo = Servicio_newParametros(idAux, cantAux, tipoAux, precioAux,descAux, totalAux);
			if (nuevo != NULL) {
				ll_add(pArrayListServicio, nuevo);
				validar = 1;
			}

		}

	} while (!feof(pArchivo));

	fclose(pArchivo);

	return validar;

}


