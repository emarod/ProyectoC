#include <stdio.h>
#include <stdlib.h>
#include "lista_ordenada.h"
#include "constantes.h"
#include "lista.h"
#include "trie.h"

int (*comparator)(void *,void *);
TListaOrdenada crear_lista_ordenada(int (*f)(void *,void *)){

    //Asingo el espacio en memoria para la lista
    TListaOrdenada lista_nueva=malloc(sizeof(struct lista_ordenada));

    //Creo la lista.
    lista_nueva->cantidad_elementos=0;
    lista_nueva->lista=crear_lista();

    //Creo variable para comparador.
    comparator=f;

    return lista_nueva;

}

int lo_insertar(TListaOrdenada lista, TElemento elem){

    if(lista==NULL){
        exit(LST_NO_INI);
    }

    if(lista->cantidad_elementos==0){
        //printf("insertando el primero \n");
        l_insertar(lista->lista,POS_NULA,elem);
        lista->cantidad_elementos++;
    }
    else{
        TPosicion pos=lo_primera(lista);
        int encontre = FALSE;
        while(encontre==FALSE){
        //La funcion caparator devuelve -1 si el primer parametro es menor,0 s
            int menor=comparator(elem,pos->elemento);
            switch(menor) {
                case -1  :
                    l_insertar(lista->lista,pos,elem);
                    encontre=TRUE;
                break;

                case 0  :
                    encontre=TRUE;
                break;

                case 1 :
                    if(pos!=lo_ultima(lista)){
                        pos=lo_siguiente(lista,pos);
                    }
                    else{
                        //Como el elemento es mayor a todos, lo agrego anteultimo, guardo el ultimo, lo borro
                        //y lo agrego en la pos anterior al elemento;
                        l_insertar(lista->lista,pos,elem);
                        TElemento aux = l_ultima(lista->lista)->elemento;
                        l_eliminar(lista->lista,l_ultima(lista->lista));
                        l_insertar(lista->lista,l_ultima(lista->lista),aux);
                        encontre=TRUE;
                    }
                break;
            }

        }
        lista->cantidad_elementos++;

    }
    return TRUE;
}

int lo_eliminar(TListaOrdenada lista, TPosicion pos){

    if(lista==NULL){
        exit(LST_NO_INI);
    }

    l_eliminar(lista->lista,pos);
    lista->cantidad_elementos--;
    if(lista->cantidad_elementos==0){
        free(lista->lista);
    }
    return TRUE;
}

TPosicion lo_primera(TListaOrdenada lista){
    if(lista==NULL){
        exit(LST_NO_INI);
    }

    return l_primera(lista->lista);
}

TPosicion lo_ultima(TListaOrdenada lista){
    if(lista==NULL){
        exit(LST_NO_INI);
    }
    return l_ultima(lista->lista);
}

TPosicion lo_siguiente(TListaOrdenada lista,TPosicion pos){
    if(lista==NULL){
        exit(LST_NO_INI);
    }
    return l_siguiente(lista->lista,pos);
}

int lo_size(TListaOrdenada lista){
    if(lista==NULL){
        exit(LST_NO_INI);
    }
    return lista->cantidad_elementos;
}
