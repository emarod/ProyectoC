#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

const int LST_POS_INV=1;
const int LST_NO_INI=2;
const int POS_NULA=3;
const int ELE_NULO=4;

TLista crear_lista() {
    //Asigno la cantidad de memoria necesaria.
    TLista lista =(TLista) malloc(sizeof(TLista));

    //Creo la lista.
	lista->cantidad_elementos=0;
	lista->primera_celda=NULL;
	printf("Creando lista \n");
	printf("Cantidad de elementos=%i \n",lista->cantidad_elementos);

  return lista;
}

int l_insertar2(TLista lista, TPosicion pos, TElemento elem){
    TCelda celdaPos = lista->primera_celda;
    TCelda celdaAnterior = celdaPos;
    TCelda nuevaCelda = (TCelda) malloc(sizeof(TCelda));
    nuevaCelda->elemento=elem;
    if(pos!=NULL){
        while(&celdaPos != &pos){
            celdaAnterior=celdaPos;
            celdaPos= celdaPos->proxima_celda;
        };
        nuevaCelda->proxima_celda=celdaPos;
        celdaAnterior->proxima_celda= nuevaCelda;
    }
    else{
        nuevaCelda->proxima_celda=celdaPos;
        lista->primera_celda=nuevaCelda;
    }
    lista->cantidad_elementos++;

    return 0;
}

int l_insertar(TLista lista, TPosicion pos, TElemento elem){
    TCelda nuevaCelda = (TCelda) malloc(sizeof(TCelda));
    nuevaCelda->elemento=elem;
    nuevaCelda->proxima_celda=NULL;

    if(pos==NULL || (l_anterior(lista,pos)==pos)){
        nuevaCelda->proxima_celda=lista->primera_celda;
        lista->primera_celda=nuevaCelda;
    }
    else{
        TCelda anterior = l_anterior(lista,pos);
        nuevaCelda->proxima_celda=pos;
        anterior->proxima_celda=nuevaCelda;
    }
    lista->cantidad_elementos++;
    return 0;
}

int l_eliminar(TLista lista, TPosicion pos){

    if(lista->cantidad_elementos==0){
        exit(LST_NO_INI);
    }

    if(pos==NULL){
        exit(POS_NULA);
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

    if(lista->primera_celda==NULL){
        printf("Elimino mal");
        exit(LST_POS_INV);
    }

    return lista->primera_celda;
}

TPosicion l_ultima(TLista lista){
    TCelda celdaPos = lista->primera_celda;
    while(celdaPos->proxima_celda!=NULL){
        celdaPos= celdaPos->proxima_celda;
    };

    return celdaPos;
}

TPosicion l_anterior(TLista lista, TPosicion pos){
    if(lista->cantidad_elementos== 0){
        exit(LST_NO_INI);
    }
    if(pos!=NULL){
        exit(POS_NULA);
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
    if(lista->cantidad_elementos == 0){
        exit(LST_NO_INI);
    }
    if(pos!=NULL){
        exit(POS_NULA);
    }
    return pos->proxima_celda;

}

TElemento l_recuperar(TLista lista, TPosicion pos){
    if(lista->cantidad_elementos == 0){
        exit(LST_NO_INI);
    }
    if(pos!=NULL){
        exit(ELE_NULO);
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








