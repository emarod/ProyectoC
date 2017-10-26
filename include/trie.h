#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

typedef struct lista_ordenada * TListaOrdenada;

typedef struct nodo {
    char rotulo;
    unsigned int contador;
    struct nodo * padre;
    TListaOrdenada hijos;
} * TNodo;

typedef struct trie {
    unsigned int cantidad_elementos;
    TNodo raiz;
} * TTrie;

//  Retorna un nuevo trie vacio, esto es, con nodo raiz que mantiene el ŕotulo nulo y contador en cero.
TTrie crear_trie();

//  Inserta el string str en el trie, inicializando el valor de contador asociado en uno.
//  En caso de que el string ya se encuentre representado en el trie,
//  aumenta el valor del contador asociado a dicho string en una unidad.
//  Retorna verdadero si la insercíon fue exitosa, falso en caso de que el string ya perteneciera al trie.
int tr_insertar(TTrie tr, char* str);

//  Retorna verdadero si el string srt pertenece al trie, falso en caso contrario.
int tr_pertenece(TTrie tr, char* str);

//  Retorna  el  entero  asociado  al  string str dentro del trie.
//  Si el string no pertenece al trie, retorna STR_NO_PER.
int tr_recuperar(TTrie tr, char* str);

//  Retorna la cantidad de palabras almacenadas en el trie.
int tr_size(TTrie tr);

//  Elimina el string str dentro del trie, liberando la memoria utilizada.
//  Retorna verdadero en caso de operacion exitosa, y falso en caso contrario.
int tr_eliminar(TTrie tr, char* str);



#endif // TRIE_H_INCLUDED
