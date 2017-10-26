#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "trie.h"
#include "lista_ordenada.h"
#include "lista.h"

void imprimir_hojas(TLista lista){
    int i = 0;
    //La lista contiene hojas por ende son ultimas letras.
    TPosicion ultima_letra = l_primera(lista);
    while (i<l_size(lista)){
        TNodo n_letra= (TNodo) ultima_letra->elemento;
        int apariciones=n_letra->contador;
        char palabra[20];
        int letra_pos=19;
        while (n_letra->rotulo!='\0' && letra_pos>=0){
            palabra[letra_pos]=n_letra->rotulo;
            letra_pos--;
            n_letra=n_letra->padre;
        }
        printf("La palabra '%s' aperecio %i veces",palabra, apariciones);
        i++;
        ultima_letra= l_siguiente(lista,ultima_letra);
    }
}

void guardar_hojas_aux(TNodo nodo,TLista lista){
    while(nodo!=NULL){
        if (lo_size(nodo->hijos)==0){
            l_insertar(lista,NULL,nodo);
        }
        else{
            int i=0;
            while(i<lo_size(nodo->hijos)){
                guardar_hojas_aux(nodo,lista);
            }
        }
    }
}

//Guarda en una lista todas las hojas del trie. De esta forma se tiene la última letra de cada palabra.
TLista guardar_hojas(TTrie tr){
    TLista lista = crear_lista();
    guardar_hojas_aux(tr->raiz,lista);
    return lista;
}

int main(){

    printf("Proyecto C TRIE\n");

    printf("Ingrese nombre del archivo a utilizar junto (sin extension .txt):\n\n");

    char nombre[50];

    scanf("%s",nombre);

    strcat(nombre,".txt");

    FILE * arch=fopen(nombre,"rb");

    if(arch==NULL){

    printf(
        "\n\nEl archivo tiene error.\n\n");
    }
    else {
        printf("\n\nEl archivo esta abierto para leer.\n\n");
    }

    TTrie trie=crear_trie();
    TLista hojas= guardar_hojas(trie);

    char palabra[100];

    while(feof(arch)==0){
        fscanf(arch,"%s",palabra);

        //printf("%s ",palabra);
        tr_insertar(trie,palabra);
    }

    fclose(arch);

    //printf("%i esta",tr_pertenece(trie,"empalmes"));
    printf("\n\nEl archivo se ha leido correctamente.\n\n");

    int opcion=0;
    while (opcion!=6){
    printf("----------------MENU DE PROGRAMA----------------\n");

    printf("(1) Mostrar Palabras.\n");
    printf("(2) Consultar.\n");
    printf("(3) Comienzan con:\n");
    printf("(4) Es prefijo:\n");
    printf("(5) Porcentaje prefijo:\n");
    printf("(6) Salir.\n");

    printf("Elija una opcion del (1) al (6):\n");

    scanf("%i",&opcion);
    //int termine = FALSE;
    switch(opcion){
        case 1:
            printf("Opcion 1. Se imprime todas las palabras y apariciones");
            imprimir_hojas(hojas);
        break;
    }
/**
    case 2:{
            printf("Ingrese palabra para consultar si pertenece: \n");
            scanf("%s", cadena2);
            printf("%s",cadena2);
            if(tr_pertenece(trie,cadena2)==1) {
                printf("La palabra %s pertenece al archivo y aparece %i veces.\n\n",cadena2,tr_recuperar(trie,cadena2));
            }
            else{
                printf("La palabra %s no pertenece al archivo.\n\n",cadena2);
            }
            break;}

    case 3:{
            rewind(arch);
            char *caracter=NULL;
            int cant=0;

            printf("Ingrese letra:\n");
            scanf("%s",caracter);
            printf("letra ingresada.\n");


            while(feof(arch)==0){
                fscanf(arch,"%s",cadena3);
                printf("%s ",cadena3);
                //if(cadena3[0]==caracter[0]){                cant=cant+1;                }
            }
            printf("La cantidad de veces que %s aparece al principio de una palabra es %i.",caracter,cant);
            break;
            }


    case 4:{
            rewind(arch);
            char *prefijo=NULL;
            int cant2=0;
            printf("Ingrese palabra prefijo:\n");
            scanf("%s",prefijo);
            printf("%s ",prefijo);



            while(feof(arch)==0){
                fscanf(arch,"%s",cadena4);
                printf("%c %c ",cadena4[0],cadena4[1]);
                //if((cadena4[0]==prefijo[0]) && (cadena4[1]==prefijo[1])) {cant2=cant2+1;}
            }
            printf("La cantidad de veces que %s aparece en como prefijo es %i.",prefijo,cant2);
            break;
            }

    case 5:{
            rewind(arch);
            char *prefijo2=NULL;
            int cuento=0;
            int tamanio_trie=tr_size(trie);
            double porcentaje;

            printf("Ingrese palabra prefijo:\n");
            scanf("%s",prefijo2);
            printf("%s ",prefijo2);

            while(feof(arch)==0){
                fscanf(arch,"%s",cadena5);
                //printf("%s %s ",cadena4[0],cadena4[1]);
                //if((cadena5[0]==prefijo2[0]) && (cadena5[1]==prefijo2[1])) {cuento=cuento+1;}
            }
            porcentaje=cuento/tamanio_trie;
            printf("El porcentaje de veces que %s aparece en como prefijo es %f.",prefijo2,porcentaje);
            break;


            }



    }
    **/
}

printf("Adiós.\n");


}
