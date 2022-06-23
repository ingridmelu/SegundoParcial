/*
 * inputs.h
 *
 *  Created on: 22 jun 2022
 *      Author: Familia
 */

#ifndef INPUTS_H_
#define INPUTS_H_

//void pedirEntero(int *variableRecibida, char textoAMostrar[]);
int utn_getNumEntero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int cadenaValidada(char arrayRecibido[], char textoAMostrar[]);
int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);


#endif /* INPUTS_H_ */
