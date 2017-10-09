#include <stdio.h>
#include <stdlib.h>
#include "lista_ordenada.h"
#include "constantes.h"
#include "lista.h"

TListaOrdenada crearlistaordenada(int (*f)(void *,void *)){

    //Asingo el espacio en memoria para la lista
    TLista lista=(TLista) malloc(sizeof(TListaOrdenada));

    //Creo la lista.
    lista->cantidad_elementos=0;

}

int lo_insertar(TListaOrdenada lista, TElemento elem){

    if(lista==NULL){
        exit(LST_NO_INI);
    }

    if(lista->cantidad_elementos==0){
        l_insertar(lista, NULL,elem);
    }

    else{
        TElemento actual=lista->lista->l_recuperar(elemento);
        TPosicion pos;
        while(actual!=l_ultima(lista)->elemento){
            if((*f)(actual,elemento)==-1 || (*f)(actual,elemento)==0){
                TCelda anterior =lista->lista->l_anterior(lista,pos);
                TCeldanuevaCelda->proxima_celda=pos;
                anterior->proxima_celda=nuevaCelda;
            }

        }
    }


    return TRUE;
}
