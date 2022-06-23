/*
 * eServicio.h
 *
 *  Created on: 22 jun 2022
 *      Author: Familia
 */

#ifndef ESERVICIO_H_
#define ESERVICIO_H_

#include "LinkedList.h"


typedef struct
{
	int idServicio;
	char descripcion[50];
	int tipos;
	float precioUnitario;
	int cantidad;
	float totalServicio;

} eServicio;

/**
 * @brief new abre la memoria dinamica y la cacia
 *
 * @pre
 * @post
 * @return nuevoPasajero
 */
eServicio* Servicio_new();
/**
 * @brief llena los datos del pasajero
 *
 * @pre
 * @post
 * @param idStr
 * @param nombreStr
 * @param apellidoStr
 * @param tipoPasajeroStr
 * @param precioStr
 * @param flycodeStr
 * @param estadoDeVuelo
 * @return nuevoPasajero
 */
eServicio* Servicio_newParametros(char* idStr, char* cantidadStr,char* tiposStr,char* precioStr,char* descripcionStr, char* totalStr);
/**
 * @brief setea id
 *
 * @pre
 * @post
 * @param this
 * @param id
 * @return
 */
int Servicio_setIdServicio(eServicio* this,int id);
/**
 * @brief guarda el id
 *
 * @pre
 * @post
 * @param this
 * @param id
 * @return retorno
 */
int Servicio_getIdServicio(eServicio* this,int* id);
/**
 * @brief setea el nombre
 *
 * @pre
 * @post
 * @param this
 * @param nombre
 * @return
 */
int Servicio_setDescripcion(eServicio *this, char *describe);
/**
 * @brief guarda el nombre
 *
 * @pre
 * @post
 * @param this
 * @param nombre
 * @return
 */
int Servicio_getDescripcion(eServicio* this,char* describe);
/**
 * @brief setea el apellido
 *
 * @pre
 * @post
 * @param this
 * @param apellido
 * @return
 */
int Servicio_setTipos(eServicio *this, int tipoServi);
/**
 * @brief guarda el apellido
 *
 * @pre
 * @post
 * @param this
 * @param apellido
 * @return
 */
int Servicio_getTipos(eServicio* this,int *tipoServi);
/**
 * @brief setea el codigo de vuelo
 *
 * @pre
 * @post
 * @param this
 * @param codigoVuelo
 * @return
 */
int Servicio_setCantidad(eServicio *this, int amount);
/**
 * @brief guarda el codigo del vuelo
 *
 * @pre
 * @post
 * @param this
 * @param codigoVuelo
 * @return
 */
int Servicio_getCantidad(eServicio* this,int *amount);
/**
 * @brief seta al tipo de pasajero
 *
 * @pre
 * @post
 * @param this
 * @param tipoPasajero
 * @return
 */
int Servicio_setTotalServicio(eServicio *this, float total);
/**
 * @brief guarda al tipo de pasajero
 *
 * @pre
 * @post
 * @param this
 * @param tipoPasajero
 * @return
 */
int Servicio_getTotalServicio(eServicio* this,float* total);
/**
 * @brief setea el precio
 *
 * @pre
 * @post
 * @param this
 * @param precio
 * @return
 */
int Servicio_setPrecioUnitario(eServicio *this, float precio);
/**
 * @brief guarda el precio
 *
 * @pre
 * @post
 * @param this
 * @param precio
 * @return
 */
int Servicio_getPrecioUnitario(eServicio* this,float* precio);

/**
 * @brief muestra la lista
 *
 * @pre
 * @post
 * @param lecturaDeDato
 */
void* ServicioLista(eServicio *lista);
int servicioMap(void *elemento);
int filtarUno(void *elemento);
int filtarDos(void *elemento);
int filtarTres(void *elemento);
int comparacion(void* datoUno, void* datoDos);



#endif /* ESERVICIO_H_ */
