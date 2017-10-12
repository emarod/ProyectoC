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
            int menor=comparator(elem,pos->elemento);
            if(menor==-1){
                l_insertar(lista->lista,pos,elem);
                encontre=TRUE;
            }
            else{
                if(menor==0){
                    encontre=TRUE;
                }
                else{
                    if(pos!=lo_ultima(lista)){
                        pos=lo_siguiente(lista,pos);
                    }
                    else{
                        //printf("El elemento es mayor a todos en la lista \n");
                        TPosicion nueva_pos= (TPosicion) malloc(sizeof(TPosicion));
                        nueva_pos->elemento=elem;
                        nueva_pos->proxima_celda=NULL;
                        pos->proxima_celda=nueva_pos;
                        encontre=TRUE;
                    }
                }


            }

        }
        lista->cantidad_elementos++;
    }
    return TRUE;
}

int lo_eliminar(TListaOrdenada lista, TPosicion pos){
    l_eliminar(lista->lista,pos);
    lista->cantidad_elementos--;
    if(lista->cantidad_elementos==0){
        free(lista->lista);
    }
    return TRUE;
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
    return lista->cantidad_elementos;
}
