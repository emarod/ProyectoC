#include <stdio.h>
#include <stdlib.h>
#include "lista_ordenada.h"
#include "constantes.h"
#include "lista.h"

TListaOrdenada crearlistaordenada(int (*f)(void *,void *)){

    //Asingo el espacio en memoria para la lista
    TListaOrdenada lista=(TListaOrdenada) malloc(sizeof(TListaOrdenada));

    //Creo la lista.
    lista->cantidad_elementos=0;
	lista->primera_celda=POS_NULA;

	//Asingo la funcion de comparaciopn a una variable.
	int comp=(*f)

}

int lo_insertar(TListaOrdenada lista, TElemento elem){



}
