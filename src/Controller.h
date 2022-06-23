/*
 * Controller.h
 *
 *  Created on: 22 jun 2022
 *      Author: Familia
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char *path, LinkedList* pArrayListServicio);
int controllerAddServicio(LinkedList *pArrayeServicio);

int controller_TotalPrecioServi(LinkedList* pArrayListServicio);
int controller_ListServi(LinkedList* pArrayListServicio);
int controller_sortServi(LinkedList* pArrayListServicio);
int controller_saveAsText(char* path , LinkedList* pArrayListServicio);
int Controller_aniadir(LinkedList* pArrayListServicio);
int Controller_filtrar(LinkedList* pArrayListServicio);


#endif /* CONTROLLER_H_ */
