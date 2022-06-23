/*
 * LinkedList.c
 *
 *  Created on: 22 jun 2022
 *      Author: Familia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* index;
	int len;
	int i;

	index = NULL;

	if(this != NULL)
	{
		len = ll_len(this);

		if(nodeIndex >= 0 && nodeIndex < len)
		{
			index = this->pFirstNode;

			if(nodeIndex != 0)
			{
				for(i = 0; i < nodeIndex; i++)
				{
					index = index->pNextNode;
					if(i == nodeIndex)
					{
						break;
					}
				}
			}
		}

	}
	return index;
}


/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
	return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo;
    Node* anteriorNodo;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(nodeIndex >= 0 && nodeIndex <= len)
    	{
    		nuevoNodo = (Node*)malloc(sizeof(Node));
    		nuevoNodo->pElement = pElement;
    		nuevoNodo->pNextNode = NULL;

    		if(nuevoNodo != NULL)
    		{
    			if(nodeIndex == 0)
    			{
    				nuevoNodo->pNextNode = this->pFirstNode;
    				this->pFirstNode = nuevoNodo;
    			}
    			else
    			{
    				anteriorNodo = getNode(this, nodeIndex - 1);
    				nuevoNodo->pNextNode = anteriorNodo->pNextNode;
    				anteriorNodo->pNextNode = nuevoNodo;
    			}
    			this->size = len + 1;
    			returnAux = 0;
    		}
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);
    	addNode(this, len, pElement);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodo;

    if(this != NULL && index >= 0)
    {
    	nodo = getNode(this, index);

    	if(nodo != NULL)
    	{
    		returnAux = nodo->pElement;
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len;
    Node* cambiar;
    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	cambiar = getNode(this, index);

    	if(cambiar != NULL)
    	{
    		cambiar->pElement = pElement;
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len;
    Node* actualNodo;
    Node* anteriorNodo;
    Node* proximoNodo;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(index >= 0 && index < len)
    	{
    		actualNodo = getNode(this, index);

    		if(actualNodo != NULL)
    		{
    			proximoNodo = getNode(this, index + 1);

    			if(index == 0){
    				this->pFirstNode = proximoNodo;
    			}
    			else
    			{
    				anteriorNodo = getNode(this, index - 1);

    				if(anteriorNodo != NULL)
    				{
    					anteriorNodo->pNextNode = proximoNodo;
    				}
    			}
    			this->size = len - 1;
    			free(actualNodo);
    			returnAux = 0;
    		}
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int len;
    int removeRetorno;

    if(this != NULL)
    {
    	len = ll_len(this);

    	for(i = 0; i < len; i++)
    	{
    		removeRetorno = ll_remove(this, i);

    		if( removeRetorno == -1)
    		{
    			returnAux = -1;
    			break;
    		}
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	ll_clear(this);
    	this->pFirstNode= NULL;
    	free(this);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    int i;
	Node* nodos;

    if(this != NULL)
    {
    	len = ll_len(this);
    	nodos = this->pFirstNode;

    	for(i = 0; i < len; i++)
    	{
    		if(nodos->pElement == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    		nodos = nodos->pNextNode;
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

	if(this!=NULL)
	{
		returnAux =0;

		if(this->pFirstNode==NULL)
		{
			returnAux =1;
		}
	}
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo;
    Node* anteriorNodo;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(index >= 0 && index <= len)
    	{
    		nuevoNodo = (Node*)malloc(sizeof(Node));
    		nuevoNodo->pElement = pElement;
    		nuevoNodo->pNextNode = NULL;

    		if(nuevoNodo != NULL)
    		{
    			if(index == 0)
    			{
    				nuevoNodo->pNextNode = this->pFirstNode;
    				this->pFirstNode = nuevoNodo;
    			}
    			else
    			{
    				anteriorNodo = getNode(this, index - 1);
    				nuevoNodo->pNextNode = anteriorNodo->pNextNode;
    				anteriorNodo->pNextNode = nuevoNodo;
    			}
    			this->size = len + 1;
    			returnAux = 0;
    		}
    	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* nodo;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(index >= 0&& index <= len)
    	{
    		nodo = ll_get(this, index);
    		ll_remove(this, index);

    		returnAux = nodo;
    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;

    if(this != NULL)
    {
    	index = ll_indexOf(this, pElement);

    	if(index != -1)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}

    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	void *index;
	int len;
	int i;
	int banderaIndex = 0;
	int comparativeIndex;
    int returnAux = -1;

    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	len = ll_len(this2);

    	for(i = 0; i < len; i++)
    	{
    		index = ll_get(this2, i);
    		comparativeIndex = ll_contains(this, index);

    		if(comparativeIndex == 0)
    		{
    			banderaIndex = 1;
    		}
    	}
    	if(banderaIndex == 1)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	int i;
	LinkedList* clonArray = NULL;
	if(this!=NULL && from>=0 && to<=ll_len(this) && to>from)
	{
		clonArray=ll_newLinkedList();
		if(clonArray!=NULL)
		{
			for(i=from;i<to;i++)
			{
				ll_add(clonArray,ll_get(this,i));
			}
		}
	}

	return clonArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = this;
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* elementoAux;
    int i;
    int j;
    int len;

    len = ll_len(this);

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
    	for(i = 0; i < len-1; i++)
    	{
        	for(j = i + 1; j < len; j++)
        	{
        		if(order == 1)
        		{
					if(pFunc(ll_get(this,i), ll_get(this,j)) > 0)
					{
						elementoAux = ll_get(this, i);
						ll_set(this, i, ll_get(this, j));
						ll_set(this, j, elementoAux);
					}
        		}
        		else
        		{
        			if(pFunc(ll_get(this,i), ll_get(this,j)) < 0)
					{
						elementoAux = ll_get(this, i);
						ll_set(this, i, ll_get(this, j));
						ll_set(this, j, elementoAux);
					}
        		}
        	}
    	}
    	returnAux = 0;
    }

    return returnAux;

}

/*
 * Completa un campo del elemento, recibiendo como parámetro
 * la función que sera la encargada de calcular el valor de ese campo.
 * Verificando que tanto el puntero this como el puntero a la funcion
 * fn sean distintos de NULL. Retorna la lista completa.
 */
LinkedList* ll_map(LinkedList* this, void (*fn)(void* element))
{
	int i;
	int tam;
	tam=ll_len(this);
	if(this!=NULL && fn!=NULL)
	{
		for(i=0;i<tam;i++)
		{
			fn(ll_get(this,i));
		}
	}
	return 0;
}



/*
 * Filtra la lista con una condición, recibiendo como parámetro
 * la función que sera la encargada de decidir si cada elemento
 * cumple la condición (1) o no (0) y si se agrega a una nueva lista filtrada.
 * Verificando que tanto el puntero this como el puntero a la funcion
 * fn sean distintos de NULL. Retorna la lista nueva lista filtrada.
 * */
LinkedList* ll_filter(LinkedList* this, int(*fn)(void*))
{

LinkedList* listaFiltrada = NULL;
int i, tam;
void* eElemento=NULL;

if(this!=NULL && fn !=NULL)
{
    listaFiltrada= ll_newLinkedList();
    if(listaFiltrada != NULL)
    {
		tam = ll_len(this);
		for(i=0; i<tam;i++)
		{
			eElemento= ll_get(this,i);
			if(fn(eElemento))
			{
				ll_add(listaFiltrada, eElemento);
			}
		}
    }
}

return listaFiltrada;

}

