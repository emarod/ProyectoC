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
        //printf("%s ",car);
    }

    fclose(arch);



    printf("\n\nEl archivo se ha leido correctamente.\n\n");

    char *cadena1;
    char *cadena2;
    char *cadena3;
    char *cadena4;
    char *cadena5;
    char *cadena6;

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
            scanf("%s", &cadena2);
            printf("%s",cadena2);
            if(tr_pertenece(trie,cadena2)==1) {
                printf("La palabra %s pertenece al archivo y aparece %i veces.\n\n",cadena2,tr_recuperar(trie,cadena2));
            }
            else{
                printf("La palabra %s no pertenece al archivo.\n\n",cadena2);
            }
            break;}

    case 3:{
            char c=NULL;
            int cant=0;

            printf("Ingrese letra:\n");
            scanf("%c",&c);

            rewind(arch);
            while(feof(arch)==0){
            fscanf(arch,"%s",cadena3);
            printf("%s \n",cadena3);
            //if(cadena3̣[0]==c) {cant++;}
            }
            printf("La cantidad de veces que %c aparece en el archivo es %i.",c,cant);
            }

    case 4:{

            }




    }
}

printf("Adiós.\n");










    fclose(arch);
}
