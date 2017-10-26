#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "constantes.h"

TLista crear_lista() {
    //Asigno la cantidad de memoria necesaria.
    TLista lista_nueva =malloc(sizeof(struct lista));

    //Creo la lista y seteo la primera celda en nulo.
	lista_nueva->cantidad_elementos=0;
	lista_nueva->primera_celda=POS_NULA;

  return lista_nueva;
}

//Inserta un nuevo elemento ubicandolo antes que pos. Y si pos es nula inserto en la primer pos.
int l_insertar(TLista lista, TPosicion pos, TElemento elem){
    if(lista==NULL){
        exit(LST_NO_INI);
    }
    //Almaceno memoria para el nuevo nodo, añado el elemento y
    TCelda nuevaCelda = (TCelda) malloc(sizeof(struct celda));
    nuevaCelda->elemento=elem;
    nuevaCelda->proxima_celda=POS_NULA;

    if(pos==POS_NULA || lista->primera_celda==pos){
        nuevaCelda->proxima_celda=lista->primera_celda;
        lista->primera_celda=nuevaCelda;
    }
    else{
        TCelda anterior = l_anterior(lista,pos);
        nuevaCelda->proxima_celda=pos;
        if(anterior==POS_NULA){
            lista->primera_celda=nuevaCelda;
        }
        else{
            anterior->proxima_celda=nuevaCelda;
        }

    }
    lista->cantidad_elementos++;
    return TRUE;
}

int l_eliminar(TLista lista, TPosicion pos){

    if(lista==NULL && lista->cantidad_elementos == 0){
        exit(LST_NO_INI);
    }

    if(pos==NULL){
        return (int )POS_NULA;
    }

    if(l_primera(lista)==pos){
        lista->primera_celda = pos->proxima_celda;
    }
    else{
        TCelda anterior = l_anterior(lista,pos);
        anterior->proxima_celda = pos->proxima_celda;
    }
    pos->elemento=NULL;
    pos->proxima_celda=NULL;
    free(pos);
    lista->cantidad_elementos--;
    if(lista->cantidad_elementos==0){
        lista->primera_celda=NULL;
    }
    return TRUE;
}

TPosicion l_primera(TLista lista){
    if(lista==NULL && lista->cantidad_elementos == 0){
        exit(LST_NO_INI);
    }
    if(lista->primera_celda==NULL){
        return POS_NULA;
    }
    return lista->primera_celda;
}

TPosicion l_ultima(TLista lista){
    if(lista==NULL && lista->cantidad_elementos == 0){
        exit(LST_NO_INI);
    }
    TCelda celdaPos = lista->primera_celda;
    while(celdaPos->proxima_celda!=POS_NULA){
        celdaPos= celdaPos->proxima_celda;
    };
    return celdaPos;
}

TPosicion l_anterior(TLista lista, TPosicion pos){

    if(lista==NULL && lista->cantidad_elementos == 0){
        exit(LST_NO_INI);
    }
    if(pos==NULL){
        return POS_NULA;
    }
    TCelda celdaPos = lista->primera_celda;
    TCelda celdaAnterior = celdaPos;
    while(celdaPos != pos){
        celdaAnterior=celdaPos;
        celdaPos= celdaPos->proxima_celda;
    };

    return celdaAnterior;

}

TPosicion l_siguiente(TLista lista, TPosicion pos){
    if(lista==NULL && lista->cantidad_elementos == 0){
        exit(LST_NO_INI);
    }
    return pos->proxima_celda;

}

TElemento l_recuperar(TLista lista, TPosicion pos){

    if(lista==NULL && lista->cantidad_elementos == 0){
        exit(LST_NO_INI);
    }
    if(pos==NULL){
       return ELE_NULO;
    }
    TCelda celdaPos = lista->primera_celda;

    while(celdaPos != pos && celdaPos !=NULL){
        celdaPos= celdaPos->proxima_celda;
    };

    if(celdaPos== NULL){
        exit(LST_POS_INV);
    }
    return celdaPos->elemento;

}

int l_size(TLista lista){
    if(lista==NULL && lista->cantidad_elementos == 0){
        exit(LST_NO_INI);
    }
    return lista->cantidad_elementos;
}
