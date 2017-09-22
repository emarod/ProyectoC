#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

const int LST_POS_INV=1;

//Retorna una nueva lista vacia.
TLista crear_lista() {
    //Asigno la cantidad de memoria necesaria.
    TLista lista=(TLista) malloc(sizeof(struct lista));

    //Creo la lista.
	lista->cantidad_elementos=0;
	lista->primera_celda=NULL;

  return lista;
}

int l_insertar(TLista lista, TPosicion pos, TElemento elem){
    //Si la posicion es mayor que la cantidad de elementos salgo con error de posicion invalida.
    int p = (int) pos->elemento;
    if((p> lista->cantidad_elementos) || pos!=NULL){
        exit(LST_POS_INV);
    }
    TCelda celdaPos = lista->primera_celda;
    TCelda celdaAnterior = celdaPos;
    if(pos!=NULL){
        while(&celdaPos != &pos){
            celdaAnterior=celdaPos;
            celdaPos= celdaPos->proxima_celda;
        };
        TCelda nuevaCelda = (TCelda) malloc(sizeof(struct celda));
        nuevaCelda->elemento=elem;
        nuevaCelda->proxima_celda=celdaPos;
        celdaAnterior->proxima_celda= nuevaCelda;
        lista->cantidad_elementos++;

    }

    return 0;
}

int l_eliminar(TLista lista, TPosicion pos){
    TCelda celdaPos = lista->primera_celda;
    TCelda celdaAnterior = celdaPos;
    if(pos!=NULL){
        while(&celdaPos != &pos){
            celdaAnterior=celdaPos;
            celdaPos= celdaPos->proxima_celda;
            if (celdaPos == NULL){
                exit(LST_POS_INV);
            }
        };
        celdaAnterior->proxima_celda = celdaPos->proxima_celda;
        free(celdaPos);
    }
    return 0;
}


