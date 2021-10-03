#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
//  int numero_roulette[37] = {0,32,15,19,4,21,2,25,17,34,6,27,13,36,11,30,8,23,10,5,24,16,33,1,20,14,31,9,22,18,29,7,28,12,35,3,26};

//int laRoueTourne (){  //cette fonction retourne le numéro gagnant

   // int numero_gagnant = rand();

   // printf("Le numéro gagnant est : %d ", numero_gagnant);

   // return numero_gagnant;
//}

int main()
{
    printf("Roulette Multiplayer\n");
    printf("On va demarrer la partie\n");
    printf("Vous commencez avec une somme de 2000$. Bonne chance!\n");
    int cash1 = 2000;
    int cash2 = 2000;
    int mise1;
    int mise2;
    int numero_choisi1;
    int numero_choisi2;
    int type_mise1;
    int type_mise2;
    char couleur_gagnante[5];
    int numero_gagnant;
    char reponse[3];
    int reset = 1;

    while(reset){

        printf("Joueur 1, merci d'ecrire votre mise.\n");
        scanf("%d", &mise1);
        printf("mise 1 = %d\n", mise1);
        cash1 = cash1 - mise1;

        printf("Merci d'ecrire le numero choisi.\n");
        scanf("%d", &numero_choisi1);

        printf("\nMerci d'indiquer votre type de mise, voici la liste:\n");
        printf(" Plein : 1\n Cheval : 2\n Transversale : 3\n En carre : 4\n En sixain : 5\n");
        printf(" Rouge : 6\n Noire : 7\n Pair : 8\n Impair : 9\n Manque : 10\n Passe : 11\n");
        printf(" Douzaine :\n  DP : 12\n  DM : 13\n  DD : 14\n Douzaines a cheval : 15\n Colonne : 16\n Colonne a cheval : 17\n\n");

        scanf("%d", &type_mise1);

        printf("Joueur 2, merci d'ecrire votre mise.\n");
        scanf("%d", &mise2);
        cash2 = cash2 - mise2;


        printf("Merci d'ecrire le numero choisi.\n");
        scanf("%d", &numero_choisi2);

        printf("\nMerci d'indiquer votre type de mise, voici la liste:\n");
        printf("Plein : 1\n Cheval : 2\n Transversale : 3\n En carre : 4\n En sixain : 5\n");
        printf(" Rouge : 6\n Noire : 7\n Pair : 8\n Impair : 9\n Manque : 10\n Passe : 11\n");
        printf("Douzaine :\n DP : 12\n DM : 13\n DD : 14\n Douzaines a cheval : 15\n Colonne : 16\n Colonne a cheval : 17\n");

        scanf("%d", &type_mise2);

        //numero_gagnant = (int)(rand() / (double)RAND_MAX * 36);
        numero_gagnant = 5;
        printf("le numero et couleur gagnants sont : %d ", numero_gagnant);

        couleurNumeroGagnant(numero_gagnant, couleur_gagnante);

        cash1 = calculSommeFinale(cash1, mise1, type_mise1, numero_gagnant, couleur_gagnante, numero_choisi1);
        cash2 = calculSommeFinale(cash2,mise2, type_mise2, numero_gagnant, couleur_gagnante, numero_choisi2);
        printf("CASH JOUEUR1 = %d$$$\n", cash1);
        printf("CASH JOUEUR2 = %d$$$\n", cash2);

        printf("Voulez-vous continuer a jouer? (oui = 1, non = 0)\n");
        scanf("%d",&reset);
        
    }

    return 0;
}
