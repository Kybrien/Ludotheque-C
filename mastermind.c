#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int mastermind() {

    char player1[4];
    char player2[4];
    int count = 0, i = 0, try = 0;
   

   for (int i = 0; i < 4; i++) {   //Permet au joueur 1 de choisir les couleurs qu'il veut
            printf("Choisissez une couleur (en ecrivant R,V,B,J,O) : ");
            fflush(stdin);
            scanf("%c", &player1[i]);
        }

        for (int i = 0; i < 4; i++){  // Si le joueur n'a pas ecrit en majuscule ca la transforme automatiquement

            if (player2[i] >= 97  ) // code ASCII
            {
                player2[i] -= 32;
            }
           
        }

    while (i < 10) // Meme chose pour joueur 2
    {
        for (int i = 0; i < 4; i++)
        {
            printf("Choisissez une couleur (en ecrivant R,V,B,J,O) : ");
            fflush(stdin);
            scanf("%c", &player2[i]);
        }


        for (int i = 0; i < 4; i++){

            if (player2[i] >= 97  ) // code ASCII
            {
                player2[i] -= 32;
            }
           
        }

        if (player1[0] == player2[0] && player1[1] == player2[1] && player1[2] == player2[2] && player1[3] == player2[3]) { // On regarde tout

            printf("Bien joue c'est gagne :D "); 
            break;

        }
        if (player1[0] == player2[0]){

            count++;
        }

         if (player1[1] == player2[1]){

            count++;
        }

        if (player1[2] == player2[2]){

            count++;
        }
       
        if (player1[3] == player2[3]){

            count++;
        }

        try++,

        printf("Il y a donc %d Couleurs qui etaient bonnes et c'est la %de try \n", count, try);

        count = 0;
        i++;
    }   
    return 0 ;
}