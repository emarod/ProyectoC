#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "lista_ordenada.h"

//Ordena los elementos de Menor a Mayor
int comparador(TElemento a,TElemento b)
{
    TNodo charA = ((TNodo) a)->rotulo;
	TNodo charB = ((TNodo) b)->rotulo;
    if(charA>charB) {return 1;}
    else
    {
        if(charA<charB) {return -1;}
        else {return 0;}
    }
}

//  Retorna un nuevo trie vacio, esto es, con nodo raiz que mantiene el ŕotulo nulo y contador en cero.
TTrie crear_trie(){
    //Asigno la cantidad de memoria necesaria.
    TTrie trie =(TTrie) malloc(sizeof(TTrie));

    //Creo el trie.
	trie->cantidad_elementos=0;
    //Creo el TNodo

	TNodo nodo_trie = (TNodo) malloc(sizeof(TTrie));
	nodo_trie->rotulo=NULL;
	nodo_trie->contador=0;
	nodo_trie->padre=NULL;
    nodo_trie->hijos=crearlistaordenada(comparador);

    //Agrego el nodo a la raiz del trie.
    trie->raiz=nodo_trie;

	printf("Creando el trie \n");
	printf("Cantidad de elementos=%i \n",trie->cantidad_elementos);

  return trie;
}

//  Inserta el string str en el trie, inicializando el valor de contador asociado en uno.
//  En caso de que el string ya se encuentre representado en el trie,
//  aumenta el valor del contador asociado a dicho string en una unidad.
//  Retorna verdadero si la insercíon fue exitosa, falso en caso de que el string ya perteneciera al trie.
int tr_insertar(TTrie tr, char* str){
    int long_str= strlen(str);
    int pos_str=0;
    TNodo cursor_trie = tr->raiz;
    TListaOrdenada  hijos_cursor;
    TNodo nuevo;
    //Cicla hasta leer todos los characteres del string.
    while(pos_str<long_str){
        hijos_cursor= cursor_trie->hijos;
        TPosicion pos_nuevo=lo_primera(hijos_cursor);
        int existe_nuevo=FALSE;
        if(lo_size(hijos_cursor)>0){
            //Busca si hay un elemento (TNODO) que tenga como rotulo el char actual del string.
            while(existe_nuevo==FALSE && pos_nuevo!=POS_NULA){
                char letra_nuevo= ((TNodo) nuevo->elemento)->rotulo;
                if(letra_nuevo!=str[i]){
                    pos_nuevo= lo_siguiente(pos_nuevo);
                }
                else{
                    existe_nuevo=TRUE;
                }
            }
        }
        if(existe_nuevo==FALSE){
            nuevo = (TNodo) malloc(sizeof(TNodo));
            nuevo->contador=1;
            nuevo->hijos=crearlistaordenada(comparador);
            nuevo->rotulo=str[i];
            nuevo->padre=cursor_trie;
            lo_insertar(hijos_cursor,nuevo);
            cursor_trie=nuevo;
        }
        else{
            ((TNodo)pos_nuevo->elemento)->contador++;
        }
        tr->cantidad_elementos++;
        pos_str++;
        cursor_trie=(TNodo)pos_nuevo->elemento;

    }

    return TRUE;

}

//  Retorna verdadero si el string srt pertenece al trie, falso en caso contrario.
int tr_pertenece(TTrie tr, char* str){
    int pertenece= TRUE;
    TNodo cursor_trie= tr->raiz;
    int i=0;
    while(i<srtlen(str) && pertenece==TRUE){
        TListaOrdenada hijos_cursor=cursor_trie->hijos;
        if(lo_size(hijos_cursor)>0){
            TPosicion pos_actual=lo_primera(hijos_cursor);
            char letra_trie = ((TNodo)pos_actual->elemento)->rotulo;
            int encontre= FALSE;
            while(encontre==FALSE && pos_actual!=POS_NULA){
                if(letra_trie!=str[i]){
                    pos_actual= lo_siguiente(pos_actual);
                }
                else{
                    encontre=TRUE;

                }
            }
            if (encontre==FALSE){
                pertenece=FALSE;
            }
        }
        i++;
        cursor_trie= lo_siguiente(pos_actual);
    }
    return pertenece;
}

//  Retorna  el  entero  asociado  al  string str dentro del trie.
//  Si el string no pertenece al trie, retorna STR_NO_PER.
int tr_recuperar(TTrie tr, char* str){
    int recuperar;
    TNodo cursor_trie= tr->raiz;
    while(i<srtlen(str)){
        TListaOrdenada hijos_cursor=cursor_trie->hijos;
        if(lo_size(hijos_cursor)>0){
            TPosicion pos_actual=lo_primera(hijos_cursor);
            char letra_trie = ((TNodo)pos_actual->elemento)->rotulo;
            int encontre= FALSE;
            while(encontre==FALSE && pos_actual!=POS_NULA){
                if(letra_trie!=str[i]){
                    pos_actual= lo_siguiente(pos_actual);
                }
                else{
                    encontre=TRUE;

                }
            }
            if (encontre==FALSE){
                recuperar=STR_NO_PER;
            }
            else{
                recuperar=((TNodo) pos_actual->elemento)->contador;
            }
        }
        i++;
        cursor_trie= lo_siguiente(pos_actual);
    }
    return pertenece;
}

}

//  Retorna la cantidad de palabras almacenadas en el trie.
int tr_size(TTrie tr){
    return tr->cantidad_elementos;
}

//  Elimina el string str dentro del trie, liberando la memoria utilizada.
//  Retorna verdadero en caso de operacion exitosa, y falso en caso contrario.
int tr_eliminar(TTrie tr, char* str);
