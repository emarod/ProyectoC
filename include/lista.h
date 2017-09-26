//Lista.h
#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct celda * TPosicion;
typedef void * TElemento;

//Estructura celda que modela un componente de la lista.
typedef struct celda {
	TElemento elemento;
	struct celda* proxima_celda;
} * TCelda;

//Cabecera de la estructura lista, posee una referencia a la primera celda y la cantidad de elementos de la lista.
typedef struct lista {
	unsigned int cantidad_elementos;
	TCelda primera_celda;
} *TLista;



//Crea y retorna una lista vacia.
TLista crear_lista();

//Agrega el elemento elem en la posición anterior a pos, dentro de la lista.
//Si pos es POS_NULA, inserta el elemento en la primer posición de la lista.
//Retorna verdadero si procedo con éxito, falso caso contrario
int l_insertar(TLista lista, TPosicion pos, TElemento elem);

//Elimina el elemento en la posición pos. Reacomoda la lista adecuadamente.
//Retorna verdadero si procede con éxito, falso en caso contrario.
//Si la posicion no es válida finaliza la ejecucion con error LST_POS_INV
int l_eliminar(TLista lista, TPosicion pos);

//Retorna la primera posición de la lista.
//Si la lista es vacia retornar POS_NULA.
TPosicion l_primera(TLista lista);

//Retorna la última posición de la lista.
//Si la lista es vacia retornar POS_NULA.
TPosicion l_ultima(TLista lista);

//Retorna la posición anterior a pos en la lista.
//Si pos es la primer posición de la lista, retornar POS_NULA.
TPosicion l_anterior(TLista lista, TPosicion pos);

//Retorna la posición siguiente a pos en la lista.
//Si pos es la ultima posición de la lista o POS_NULA, retornar POS_NULA.
TPosicion l_siguiente(TLista lista, TPosicion pos);

//Retorna el elemento correspondiente a la posición pos.
//Si la posición es POS_NULA, rerotnar ELE_NULO
TElemento l_recuperar(TLista lista, TPosicion pos);

//Retorna la cantidad de elementos de la lista.
//Si la lista no esta inicializada finaliza la ejecucion con error LST_NO_INI
int l_size(TLista lista);

#endif // LISTA_H_INCLUDED
