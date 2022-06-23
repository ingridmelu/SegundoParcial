/*
 ============================================================================
 Name        : 2do.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "eServicio.h"

int main()
{
    int option = 0;
    int bandera = 0;
    int flagSave = 0;
    char path[20];
    setbuf(stdout, NULL);


    LinkedList* listaServicio = ll_newLinkedList();
    do{
    	printf("---------------------------------------------------\n"
    		   "Menu:\n"
    		   "---------------------------------------------------\n"
    		   "1. Cargar Archivo.\n"
			   "2. Imprimir Lista.\n"
			   "3. Asignar Totales.\n"
			   "4. Filtrar por tipo.\n"
			   "5. Mostrar servicios.\n"
			   "6. Guardar servicios.\n"
			   "7. Salir.\n");
    	scanf("%d", &option);
    	fflush(stdin);
        switch(option)
        {
            case 1:
            	printf("Ingrese el archivo que desea cargar(csv).");
            	fflush(stdin);
            	gets(path);
                controller_loadFromText(path, listaServicio);
                bandera = 1;
                break;
            case 2:
            	if(bandera == 0)
            	{
                	printf("primero ingrese la opcion numero 1. /n");
            	}
            	else
            	{
                	controller_ListServi(listaServicio);
            	}
            	break;
           case 3:
            	if(bandera == 0)
            	{
            		printf("primero ingrese la opcion numero 1. /n");
            	}
            	else
            	{
            		controllerAddServicio(listaServicio);
            	}
            	break;
            case 4:
            	if(bandera == 0)
            	{
            		printf("Primero ingrese datos");
            	}
            	else
            	{
            		Controller_filtrar(listaServicio);
            	}
            	break;
            case 5:
            	if(bandera == 0)
            	{
            		printf("Primero ingrese datos\n");
            	}
            	else
            	{
            		controller_sortServi(listaServicio);
            		controller_ListServi(listaServicio);
            	}
            	break;
             case 6:
            	 if(bandera == 0)
            	 {
            		 printf("Primero ingrese la opcion 5.\n");
            	 }
            	 else
            	 {
            		 printf("Ingrese el nombre del archivo que dea guardar\n");
            		 fflush(stdin);
            		 gets(path);

            		 controller_saveAsText(path, listaServicio);
            		 flagSave = 1;
            	 }
            	 break;
            case 7:
            	if(flagSave == 0 && bandera == 0)
            	{
            		printf("Error, primero ingrese datos");
            	}
            	else
            	{
            		printf("Muchas gracias, hasta luego.");
            	}
            	break;
            default:
            	printf("Error, Opcion Incorrecta");
        }
    }while(option != 7);
    return 0;
}


