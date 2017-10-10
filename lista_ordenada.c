#include <stdio.h>
#include <stdlib.h>
#include "lista_ordenada.h"
#include "constantes.h"
#include "lista.h"
#include "trie.h"

int (*comparador)(void*, void*);



TListaOrdenada crear_lista_ordenada(int (*f)(void *,void *)){

    //Asingo el espacio en memoria para la lista
    TListaOrdenada lista_nueva=(TListaOrdenada) malloc(sizeof(struct lista_ordenada));

    //Creo la lista.
    lista_nueva->cantidad_elementos=0;
    lista_nueva->lista=crear_lista();


    //Creo variable para comparador.
    comparador=f;
    printf("Creando lista ordenada \n");

    return lista_nueva;

}

int lo_insertar(TListaOrdenada lista, TElemento elem){

    if(lista==NULL){
        exit(LST_NO_INI);
    }

    if(lista->cantidad_elementos==0){
        printf("insertando el primero \n");
        l_insertar(lista->lista,POS_NULA,elem);
        lista->cantidad_elementos++;
    }
    else{
        printf("\n insertando un elemento distinto dle primero \n");
        TElemento pos_e = elem;
        int y = *((int*)pos_e);
        printf("Estoy insertando el elemento %i \n",y);

        TPosicion pos=lo_primera(lista);
        int encontre = FALSE;
        while(encontre==FALSE){
            int menor=comparador(elem,pos->elemento);
            if(menor==-1){
                l_insertar(lista->lista,pos,elem);
                encontre=TRUE;
            }
            else{
                if(menor==0){
                    encontre=TRUE;
                }
                else{
                    printf("El elemento es %i \n",y);
                    if(pos!=lo_ultima(lista)){
                        pos=lo_siguiente(lista,pos);
                    }
                    else{
                        printf("El elemento es mayor a todos en la lista \n");
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
    return lista->cantidad_elementos;
}
