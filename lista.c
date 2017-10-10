#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "constantes.h"

TLista crear_lista() {
    //Asigno la cantidad de memoria necesaria.
    TLista lista_nueva =malloc(sizeof(struct lista));

    //Creo la lista.
	lista_nueva->cantidad_elementos=0;
	lista_nueva->primera_celda=POS_NULA;

  return lista_nueva;
}

int l_insertar(TLista lista, TPosicion pos, TElemento elem){
    TCelda nuevaCelda = (TCelda) malloc(sizeof(struct celda));
    nuevaCelda->elemento=elem;
    nuevaCelda->proxima_celda=POS_NULA;

    if(lista==NULL){
        exit(LST_NO_INI);
    }

    if(pos==POS_NULA || (l_anterior(lista,pos)==pos)){
        printf("Insertado primera pos");
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

    if(lista->cantidad_elementos==0){
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
    free(pos);
    lista->cantidad_elementos--;
    return 0;
}

TPosicion l_primera(TLista lista){
    //printf("Accediendo al l_primera de lista \n");
    if(lista->primera_celda==NULL){
        return POS_NULA;
    }
    TElemento pos_e = lista->primera_celda->elemento;
    int y = *((int*)pos_e);
    //printf("Tus primer pos es pos es %i \n",y);
    return lista->primera_celda;
}

TPosicion l_ultima(TLista lista){
    TCelda celdaPos = lista->primera_celda;
    while(celdaPos->proxima_celda!=POS_NULA){
        celdaPos= celdaPos->proxima_celda;
    };
    //printf("Accediendo al l_ultima de lista \n");
    //TElemento pos_e = celdaPos->elemento;
    //int y = *((int*)pos_e);
    //printf("La ultima pos es %i \n",y);

    return celdaPos;
}

TPosicion l_anterior(TLista lista, TPosicion pos){
    //printf("Accediendo a l_anterior de lista \n");
    if(lista->cantidad_elementos== 0){
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
    //TElemento pos_e = pos->elemento;
    //int y = *((int*)pos_e);
    //TElemento pos_x = celdaAnterior->elemento;
    //int x = *((int*)pos_x);
    //printf("El anterior a %i es %i \n",y,x);

    return celdaAnterior;

}

TPosicion l_siguiente(TLista lista, TPosicion pos){
    if(lista->cantidad_elementos == 0){
        exit(LST_NO_INI);
    }
    return pos->proxima_celda;

}

TElemento l_recuperar(TLista lista, TPosicion pos){
    if(lista->cantidad_elementos == 0){
        exit(LST_NO_INI);
    }
    if(pos!=NULL){
       return ELE_NULO;
    }
    TCelda celdaPos = lista->primera_celda;
    while(celdaPos != pos){
        celdaPos= celdaPos->proxima_celda;
        if(celdaPos->proxima_celda == NULL){
            exit(LST_POS_INV);
        }
    };
    return celdaPos->elemento;

}

int l_size(TLista lista){
    if(lista->cantidad_elementos == 0){
        exit(LST_NO_INI);
    }
    return lista->cantidad_elementos;
}








