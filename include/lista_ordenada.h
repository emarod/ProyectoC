#ifndef LISTAORDENADA_H_INCLUDED
#define LISTAORDENADA_H_INCLUDED
#include "lista.h"

//typedef struct lista * TLista;
typedef struct celda * TPosicion;
typedef void * TElemento;

typedef struct lista_ordenada {
    unsigned int cantidad_elementos;
    TLista lista;
} * TListaOrdenada;

//Crea y retorna una lista vacia.
//Parámetros: el orden de los elementos insertados será dado por la función de comparacíon int f(void *,void *)
//(f devuelve -1 si el orden del primer argumento es menor que el orden del segundo, 0 si el orden es el mismo,y 1 si el orden del primer argumento es mayor que el orden del segundo)
TListaOrdenada crearlistaordenada(int (*f)(void *,void *));


//Agrega el elemento en la posicíon correspondiente de la lista, de modo que la misma quede siempre ordenada de forma ascendente.
//Retorna verdadero si procede con  ́exito, falso en caso contrario.
int lo_insertar(TListaOrdenada lista, TElemento elem);

//Elimina el elemento en la posición pos. Reacomoda la lista adecuadamente al eliminar en posiciones intermedias.
//Retorna verdadero si procede con éxito, falso en caso contrario.
int lo_eliminar(TListaOrdenada lista, TPosicion pos);

//Retorna la primera posición de la lista.
//Si la lista parametrizada no est́a inicializada, se debe abortar con exit status LST_NO_INI.
TPosicion lo_primera(TListaOrdenada lista);

//Retorna la última posición de la lista.
//Si la lista parametrizada no est́a inicializada, se debe abortar con exit status LST_NO_INI.
TPosicion lo_ultima(TListaOrdenada lista);

//Retorna la posición siguiente a pos en la lista.
//Si la lista parametrizada no est́a inicializada, se debe abortar con exit status LST_NO_INI.
TPosicion lo_siguiente(TListaOrdenada lista, TPosicion pos);

//Retorna la cantidad de elementos de la lista.
//Si la lista parametrizada no esta inicializada, se debe abortar con exit status LST_NO_INI.
int lo_size(TListaOrdenada lista);

#endif // LISTAORDENADA_H

