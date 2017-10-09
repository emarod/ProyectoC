#include <stdio.h>
#include <stdlib.h>
#include "lista_ordenada.h"
#include "constantes.h"
#include "lista.h"

int (*comparador)(void*, void*);

TListaOrdenada crearlistaordenada(int (*f)(void *,void *)){



    //Asingo el espacio en memoria para la lista
    TListaOrdenada lista_ordenada=(TListaOrdenada) malloc(sizeof(TListaOrdenada));

    //Creo la lista.
    lista_ordenada->cantidad_elementos=0;
    lista_ordenada->lista=crear_lista();

    //Creo variable para comparador.
    comparador=f;

    return lista_ordenada;

}

int lo_insertar(TListaOrdenada lista, TElemento elem){

    TCelda nuevaCelda = (TCelda) malloc(sizeof(TCelda));
    nuevaCelda->elemento=elem;
    nuevaCelda->proxima_celda=POS_NULA;

    if(lista==NULL){
        exit(LST_NO_INI);
    }

    if(lista->cantidad_elementos==0){
        lo_insertar(lista->lista,elem);
    }

    else{
        TPosicion pos=lo_primera(lista);

        while(pos!=lo_ultima(lista)){
            if(comparador(pos->elemento,nuevaCelda->elemento)==-1 || comparador(pos->elemento,nuevaCelda->elemento)==0){
                nuevaCelda->proxima_celda=pos->proxima_celda;
                pos->proxima_celda=nuevaCelda;
            }
            else{
                pos=lo_siguiente(lista,pos);
            }

        }
    }


    return TRUE;
}

int lo_eliminar(TListaOrdenada lista, TPosicion pos){

    return l_eliminar(lista->lista,pos);
}

TPosicion lo_primera(TListaOrdenada lista){

    return l_primera(lista->lista);
}

TPosicion lo_ultima(TListaOrdenada lista){
    return l_ultima(lista->lista);
}

TPosicion lo_siguiente(TListaOrdenada lista,TPosicion pos){

    return l_siguiente(lista->lista,pos);
}

int lo_size(TListaOrdenada lista){
    return l_size(lista->lista);
}
