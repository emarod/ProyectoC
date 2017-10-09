#include <stdio.h>
#include <stdlib.h>
#include "lista_ordenada.h"
#include "constantes.h"
#include "lista.h"

TListaOrdenada crearlistaordenada(int (*f)(void *,void *)){

    //Asingo el espacio en memoria para la lista
    TListaOrdenada lista_ordenada=(TListaOrdenada) malloc(sizeof(TListaOrdenada));

    //Creo la lista.
    lista_ordenada->cantidad_elementos=0;
    lista_ordenada->lista=crear_lista();
    

}

int lo_insertar(TListaOrdenada lista, TElemento elem){

    if(lista==NULL){
        exit(LST_NO_INI);
    }

    if(lista->cantidad_elementos==0){
        l_insertar(lista, NULL,elem);
    }

    else{
        //TElemento actual=lista->lista->l_recuperar(elemento);
        /**TPosicion pos;
        while(actual!=l_ultima(lista)->elemento){
            if((*f)(actual,elemento)==-1 || (*f)(actual,elemento)==0){
                TCelda anterior =l_anterior(lista,pos);
                TCeldanuevaCelda->proxima_celda=pos;
                anterior->proxima_celda=nuevaCelda;
            }

        }**/
    }


    return TRUE;
}

int lo_eliminar(TListaOrdenada lista, TPosicion pos){

    return l_eliminar(lista,pos);
}

TPosicion lo_primera(TListaOrdenada lista){

    return l_primera(lista);
}

TPosicion lo_ultima(TListaOrdenada lista){
    return l_ultima(lista);
}

TPosicion lo_siguiente(TListaOrdenada lista,TPosicion pos){

    return l_siguiente(lista,pos);
}

TPosicion lo_anterior(TListaOrdenada lista, TPosicion pos){
    return l_anterior(lista,pos);
}

int lo_size(TListaOrdenada lista){
    return l_size(lista);
}
