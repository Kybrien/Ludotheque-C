#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int pendu(){

    // On initialise tous nos tableaux et nos valeurs
    int vie = 10;
    char user[1];
    char pendu[20] = {'C','L','A','V','I','E','R'};
    int size = strlen(pendu);
    char found[size + 1];


    for (int i = 0 ; i<size ; i++){ //On cree le tableaux dans lequel on remplacera les lettres trouvees par le joueur
        found[i] = '-';
    }

    printf("Votre mot : \n | %s | \n ", found); //On montre le tableau vide avec les - 

    while (vie>0) {

        printf("\n Quelle lettre voulez-vous essayer (1 a la fois) ? \n> "); //On demande au joueur quelle lettre il veut essayer
        fflush(stdin);
        scanf("%c", &user);

        for( int j = 0 ; j < size ; j++ ){ // on remplace le caractere dans le tableau si l'entree de l'utilisateur est comprise dans le mot secret
            if ( pendu[j] == *user ){
                found[j] = *user;
                printf("\n Bien joue cette lettre est dans le mot cache !\n",user);
                printf("| %s |\n\n", found); 
            }
        }

        vie--; //a chaque essai on baisse la vie du l'utilisateur

        if( strcmp( found , pendu) == 0){ //Si les mot scret et trouve sont les meme, alors le joueur a gagne
            printf("GG c'est gagne, le mot etait donc %s !", found);
            break;
        }
    }

    return 0;
}