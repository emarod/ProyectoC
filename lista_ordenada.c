#include <stdio.h>
#include <stdlib.h>
#include "lista_ordenada.h"
#include "constantes.h"
#include "lista.h"

int comp;

TListaOrdenada crearlistaordenada(int (*f)(void *,void *)){



    //Asingo el espacio en memoria para la lista
    TListaOrdenada lista_ordenada=(TListaOrdenada) malloc(sizeof(TListaOrdenada));

    //Creo la lista.
    lista_ordenada->cantidad_elementos=0;
    lista_ordenada->lista=crear_lista();

    //Creo variable para comparador.
    void* num,*num2;
    int comp=(*f)(num, num2);

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
            if(comp==1){
                lista->lista->primera_celda=nuevaCelda;
            }
            else{
                pos=lo_siguiente(lista,pos);
                nuevaCelda->proxima_celda=pos;
                anterior->proxima_celda=nuevaCelda;
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
