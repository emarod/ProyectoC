#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "constantes.h"
#include "trie.h"
#include "lista_ordenada.h"
#include "lista.h"

//Ordena los elementos de Menor a Mayor
int comparador(TElemento a,TElemento b){
    char charA = ((TNodo) a)->rotulo;
	char charB = ((TNodo) b)->rotulo;
    if(charA>charB) {return 1;}
    else
    {
        if(charA<charB) {return -1;}
        else {return 0;}
    }
}

TPosicion buscar_posNodo(TListaOrdenada l,char r){
    TPosicion pos_tr = lo_primera(l);
    int encontre= FALSE;
    while (pos_tr != NULL && encontre==FALSE) {
        TNodo nodo = (TNodo) pos_tr->elemento;
        if(r==nodo->rotulo){
            encontre=TRUE;
        }
        else{
            pos_tr = lo_siguiente(l,pos_tr);
        }

    }
    return pos_tr;
}

//  Retorna un nuevo trie vacio, esto es, con nodo raiz que mantiene el ŕotulo nulo y contador en cero.
TTrie crear_trie(){
    //Asigno la cantidad de memoria necesaria.
    TTrie trie =malloc(sizeof(struct trie));

    //Creo el trie.
	trie->cantidad_elementos=0;
    //Creo el TNodo

	TNodo nodo_trie = malloc(sizeof(struct nodo));
	nodo_trie->rotulo='\0';
	nodo_trie->contador=0;
	nodo_trie->padre=NULL;
    nodo_trie->hijos=crear_lista_ordenada(comparador);

    //Agrego el nodo a la raiz del trie.
    trie->raiz=nodo_trie;

  return trie;
}

//  Inserta el string str en el trie, inicializando el valor de contador asociado en uno.
//  En caso de que el string ya se encuentre representado en el trie,
//  aumenta el valor del contador asociado a dicho string en una unidad.
//  Retorna verdadero si la insercíon fue exitosa, falso en caso de que el string ya perteneciera al trie.
int tr_insertar(TTrie tr, char* str){

    if(tr==NULL){
        exit(TRI_NO_INI);
    }

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
        //printf("hijos cursor %i \n",lo_size(hijos_cursor));
        if(lo_size(hijos_cursor)>0){
            //Busca si hay un elemento (TNODO) que tenga como rotulo el char actual del string.
            while(existe_nuevo==FALSE && pos_nuevo!=POS_NULA){
                char letra_nuevo= ((TNodo) pos_nuevo->elemento)->rotulo;
                if(letra_nuevo!=str[pos_str]){
                    pos_nuevo= lo_siguiente(hijos_cursor,pos_nuevo);
                }
                else{
                    existe_nuevo=TRUE;
                }
            }
        }
        if(existe_nuevo==FALSE){
            nuevo =malloc(sizeof( struct nodo));
            nuevo->contador=1;
            nuevo->hijos=crear_lista_ordenada(comparador);
            nuevo->rotulo=str[pos_str];
            nuevo->padre=cursor_trie;
            lo_insertar(hijos_cursor,nuevo);
            cursor_trie=nuevo;
        }
        else{
            ((TNodo)pos_nuevo->elemento)->contador++;
            cursor_trie=(TNodo)pos_nuevo->elemento;
        }
        pos_str++;
    }
    tr->cantidad_elementos++;
    return TRUE;

}

//  Retorna verdadero si el string srt pertenece al trie, falso en caso contrario.
int tr_pertenece(TTrie tr, char* str){

    if(tr==NULL){
        exit(TRI_NO_INI);
    }
    int pertenece= TRUE;
    TNodo cursor_trie= tr->raiz;
    TListaOrdenada hijos_cursor;
    int i=0;
    int long_str= strlen(str);
    TPosicion pos_actual;
    while(i<long_str && pertenece==TRUE){
        hijos_cursor=cursor_trie->hijos;
        pos_actual=buscar_posNodo(hijos_cursor,str[i]);
        if(pos_actual==POS_NULA){
            pertenece=FALSE;
        }
        else{
            cursor_trie=(TNodo)pos_actual->elemento;
        }
        i++;
    }
    return pertenece;
}

//  Retorna  el  entero  asociado  al  string str dentro del trie.
//  Si el string no pertenece al trie, retorna STR_NO_PER.
int tr_recuperar(TTrie tr, char* str){
    if(tr==NULL){
        exit(TRI_NO_INI);
    }

    int recuperar;
    TNodo cursor_trie= tr->raiz;
    int i=0;
    int long_str= strlen(str);
    TListaOrdenada hijos_cursor;
    TPosicion pos_actual;
    while(i<long_str && recuperar!=STR_NO_PER){
        hijos_cursor=cursor_trie->hijos;
        pos_actual=buscar_posNodo(hijos_cursor,str[i]);
        if (pos_actual==POS_NULA){
            recuperar=STR_NO_PER;
        }
        else{
            cursor_trie= (TNodo) pos_actual->elemento;
            recuperar=((TNodo) pos_actual->elemento)->contador;
        }
        i++;

    }
    return recuperar;
}

//  Retorna la cantidad de palabras almacenadas en el trie.
int tr_size(TTrie tr){
    if(tr==NULL){
        exit(TRI_NO_INI);
    }
    return tr->cantidad_elementos;
}


//  Elimina el string str dentro del trie, liberando la memoria utilizada.
//  Retorna verdadero en caso de operacion exitosa, y falso en caso contrario.

int tr_eliminar(TTrie tr, char* str){
    if(tr==NULL){
        exit(TRI_NO_INI);
    }
    int eliminado=TRUE;
    int i= 0;
    int pertenece = tr_pertenece(tr,str);
    int long_str= strlen(str);
    TListaOrdenada hijos_cursor=((TNodo) tr->raiz)->hijos;
    TPosicion pos_actual;
    TNodo nodo_borrar;
    if(pertenece==TRUE){
        while(i<long_str){
            pos_actual=buscar_posNodo(hijos_cursor,str[i]);
            nodo_borrar = (TNodo) pos_actual->elemento;
            int contador_pos = nodo_borrar->contador;
            if(contador_pos==1){
                lo_eliminar(hijos_cursor,pos_actual);
            }
            else{
                contador_pos--;
            }
            hijos_cursor=nodo_borrar->hijos;
            i++;
        }
        while(nodo_borrar->rotulo!='\0' && nodo_borrar->contador==1){
            TNodo padre= nodo_borrar->padre;
            TListaOrdenada lista_borrar=nodo_borrar->hijos;
            free(lista_borrar);
            free(nodo_borrar);
            nodo_borrar=padre;
        }

    }
    else{
        eliminado=FALSE;
    }
    return eliminado;

}
