#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "mastermind.h"
#include "morpion.h"
#include "pendu.h"

void afficherBibliotheque();
int selectionJeu(int choix);

int main(){
    int choix = 0;

    do { 
        afficherBibliotheque();
        printf("\nA quel jeu voulez-vous jouer? \n > ");
        fflush(stdin);
        scanf("%d", &choix);
        selectionJeu(choix);
    }
    while(choix != 0);

    return 0;
}

void afficherBibliotheque(){

    printf("\n-------------------------\n");
    printf("Ma bibliotheque de Jeux :\n");
    printf("1 - Morpion\n");
    printf("2 - Mastermind\n");
    printf("3 - Pendu\n");
    printf("0 - Quitter\n");
    printf("\n-------------------------\n");

    return;
}

int selectionJeu(int choix){
    if(choix == 1){
        printf("\n-> Vous avez lance le Morpion <-\n");
        morpion();
    }
    if(choix == 2){
        printf("\n-> Vous avez lance le Mastermind <-\n");
        mastermind();
    }
    if(choix == 3){
        printf("\n-> Vous avez lance le Pendu <-\n");
        pendu();
    }
    if(choix == 0){
        printf("\n-> Merci a vous et a tres bientot <-\n");
    }
    return choix;
}