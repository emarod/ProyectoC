#include <stdio.h>
#include <stdlib.h>
#include "lista_ordenada.h"
#include "constantes.h"
#include "lista.h"

int (*comparador)(void*, void*);

TListaOrdenada crearlistaordenada(int (*f)(void *,void *)){

    //Asingo el espacio en memoria para la lista
    TListaOrdenada lista_nueva=(TListaOrdenada) malloc(sizeof(TListaOrdenada));

    //Creo la lista.
    lista_nueva->cantidad_elementos=0;
    lista_nueva->lista=crear_lista();
    printf("Creando");

    //Creo variable para comparador.
    comparador=f;
    printf("Creando elfff trie \n");

    return lista_nueva;

}

int lo_insertar(TListaOrdenada lista, TElemento elem){

    if(lista==NULL){
        exit(LST_NO_INI);
    }

    if(lista->cantidad_elementos==0){
        l_insertar(lista->lista,POS_NULA,elem);
        lista->cantidad_elementos++;
    }
    else{
        TPosicion pos=lo_primera(lista);
        int encontre = FALSE;
        while(pos!=lo_ultima(lista) && encontre==FALSE){
            if(comparador(elem,pos->elemento)==-1){
                l_insertar(lista->lista,pos,elem);
            }
            else{
                if(comparador(elem,pos->elemento)==0){
                    encontre=TRUE;
                }
                pos=lo_siguiente(lista,pos);
            }

        }
        lista->cantidad_elementos++;
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
