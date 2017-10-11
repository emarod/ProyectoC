#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "trie.h"
#include "lista_ordenada.h"

void cargar_trie(TTrie t,FILE* file){

    char buf[4096];
    ssize_t n;
    char *str = NULL;
    size_t len = 0;
    while ((n = read(STDIN_FILENO, buf, sizeof buf))) {
        if (n < 0) {
            if (errno == EAGAIN)
                continue;
            perror("read");
            break;
        }
        str = realloc(str, len + n + 1);
        memcpy(str + len, buf, n);
        len += n;
        str[len] = '\0';
    }
    printf("%.*s\n", len, str);

}


void imprimir_aux(TListaOrdenada l){
    TPosicion pos_tr = lo_primera(l);
    int ii=0;
    while (pos_tr != NULL) {
        TNodo nodo = (TNodo) pos_tr->elemento;
        printf("pos %i-> letra:%c\n", ii, nodo->rotulo);
        pos_tr = lo_siguiente(l,pos_tr);
        imprimir_aux(nodo->hijos);
        ii++;
    }
}

void imprimir_trie(TTrie tr){
    imprimir_aux(tr->raiz->hijos);
}

int main()
{
    printf("Proyecto C TRIE\n");

    printf("Ingrese nombre del archivo a utilizar junto (sin extension .txt):\n\n");

    char nombre[50];
    char *cadena1=NULL;
    char *cadena2=NULL;
    char *cadena3=NULL;
    char *cadena4=NULL;
    char *cadena5=NULL;
    //char *cadena6;

    scanf("%s",nombre);

    strcat(nombre,".txt");

    FILE * arch=fopen(nombre,"rb");

    if(arch==NULL){

    printf(
        "\n\nEl archivo tiene error.\n\n");
    }
    else {
        printf("\n\nEl archivo esta abeirto para leer.\n\n");
    }

    char *car=NULL;

    TTrie trie=crear_trie();

    while(feof(arch)==0){

        fscanf(arch,"%s",car);
        tr_insertar(trie,car);
        printf("%s ",car);
    }
    imprimir_trie(trie);


        //fclose(arch);



    printf("\n\nEl archivo se ha leido correctamente.\n\n");

    arch=fopen(nombre,"rb");
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

    switch(opcion){
    case 1:{
            printf("%i",opcion);
            while(feof(arch)==0){
                fscanf(arch,"%s",cadena1);
                printf("%s                         %i\n",cadena1,tr_recuperar(trie,cadena1));
            }

            break;}
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
}

printf("Adiós.\n");










    fclose(arch);
}
