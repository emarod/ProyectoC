#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"


int main()
{
    printf("Hello world!\n");

    printf("Ingrese nombre del archivo a utilizar junto (sin extension .txt):\n\n");

    char nombre[50];

    scanf("%s",&nombre);

    strcat(nombre,".txt");

    FILE * arch=fopen(nombre,"rb");

    if(arch==NULL){

    printf("\n\nEl archivo tiene error.\n\n");
    }
    else { printf("\n\nEl archivo esta abeirto para leer.\n\n");}

    char *car;

    TTrie trie=crear_trie();

    while(feof(arch)==0){

        fscanf(arch,"%s",car);
        tr_insertar(trie,car);
        printf("%s ",car);
    }


    printf("\n\nEl archivo se ha leido correctamente.\n\n");

    printf("----------------MENU DE PROGRAMA----------------\n");
    printf("Elija una opcion del (1) al (6):\n\n");
    printf("(1) Mostrar Palabras.\n");
    printf("(2) Consultar.\n");
    printf("(3) Comienzan con:\n");
    printf("(4) Es prefijo:\n");
    printf("(5) Porcentaje prefijo:\n");
    printf("(6) Salir.\n");

    int opcion;
    scanf("%i",&opcion);

    switch(opcion){
    case 1:{
            while(feof(arch)==0){

            fscanf(arch,"%s",car);
            tr_insertar(trie,car);
            printf("%s                         %i\n",car,tr_recuperar(trie,car));
            }

            break;}
    case 2:{
            char *palabra;
            printf("Ingrese palabra para consultar si pertenece: \n");
            scanf("%s", palabra);
            if(tr_pertenece(trie,palabra)==1) {
                printf("La palabra %s pertenece al archivo y aparece %i veces.\n\n",palabra,tr_recuperar(trie,palabra));
            }
            else{
                printf("La palabra %s no pertenec al archivo.\n\n",palabra);
            }
            break;}


    }










    fclose(arch);
}
