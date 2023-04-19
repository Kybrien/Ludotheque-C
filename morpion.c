#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void afficher_grille(char grille[3][3]); //On annonce notre fonction a l'avance

int morpion(){
    
    int fin_partie=0; //On initialise nos valeurs
    char joueur1 = 'X';
    char joueur2 = 'O';
    int coord_x, coord_y;
    int joueur = 1;

    char grille[3][3]= { //On cree notre grille
    {'.','.','.'},
    {'.','.','.'},
    {'.','.','.'}
    };
    

    while (!fin_partie)
    {
        afficher_grille(grille);


        // On demande au joueur courant de jouer
        printf("C'est au tour du joueur %d (%c)\n", joueur, joueur == 1 ? joueur1 : joueur2);
        printf("Entrez les coordonnees: (x y) > ");
        scanf("%d %d", &coord_x, &coord_y);

        // On verifie si les coordonnees sont valides
        if (coord_x < 0 || coord_x > 2 || coord_y < 0 || coord_y > 2)
        {
            printf("ERREUR. Ressayez !\n");
            continue;
        }

        // On verifier si la case est déjà occupée
        if (grille[coord_x][coord_y] != '.')
        {
            printf("La case est deja occupee. Veuillez reessayer.\n");
            continue;
        }

        // On place le symbole sur la grille
        grille[coord_x][coord_y] = joueur == 1 ? joueur1 : joueur2;


        // On verifie si le joueur a gagné (toutes les possibilites possibles)
        char symbole = joueur == 1 ? joueur1 : joueur2;
        if ((grille[0][0] == symbole && grille[0][1] == symbole && grille[0][2] == symbole) ||
            (grille[1][0] == symbole && grille[1][1] == symbole && grille[1][2] == symbole) ||
            (grille[2][0] == symbole && grille[2][1] == symbole && grille[2][2] == symbole) ||
            (grille[0][0] == symbole && grille[1][0] == symbole && grille[2][0] == symbole) ||
            (grille[0][1] == symbole && grille[1][1] == symbole && grille[2][1] == symbole) ||
            (grille[0][2] == symbole && grille[1][2] == symbole && grille[2][2] == symbole) ||
            (grille[0][0] == symbole && grille[1][1] == symbole && grille[2][2] == symbole) ||
            (grille[0][2] == symbole && grille[1][1] == symbole && grille[2][0] == symbole))
        {
            printf("Le joueur %d (%c) a gagne ! GG\n", joueur, symbole);
            fin_partie = 1;
        }
        else
        {
            // Vérifier si la grille est pleine
            int grille_pleine = 1;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (grille[i][j] == '.')
                    {
                        grille_pleine = 0;
                        break;
                    }
                }
                if (!grille_pleine)
                {
                    break;
                }
            }
            // On fait en sorte que dans le cas ou la grille est pleine on annonce match nul
            if (grille_pleine)
            {
                printf("La grille est pleine ! Match nul.\n");
                fin_partie = 1;
            }
        }

        // On passe au joueur suivant
        joueur = joueur == 1 ? 2 : 1;
    }

    // Afficher la grille finale
    printf("Grille finale :\n");

    afficher_grille(grille);

    return 0;
}

// On fait la fonction pour afficher graphiquement la grille
void afficher_grille(char grille[3][3]){
    printf("\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf(" %c ", grille[i][j]);
            if(j != 2){
                printf("|");
            }
        }
        printf("\n");
        if(i != 2){
            printf("---|---|---\n");
        }
    }
    printf("\n");
}