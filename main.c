#include <stdio.h>
#include <stdlib.h>
#include"voyageur.h"
int main()
{
    //Lorsque l'agent de l'agence lance l'application,
    // toutes les données existantes dans le fichier de sauvegarde doivent être
    // chargées dans un tableau sur lequel des opérations d'ajout de suppression, de recherche ..., sont effectuées.
   int choix;
    char *nomFich = "voyageur.bin";
    int n=0;
    int *ptr_n=&n;
    voyageur *tab_voyageurs;
    tab_voyageurs = charger_donnees_sans_nbVoyageurs (nomFich,ptr_n);
            do{

            printf("\n*********  MENU  *********\n\n");
                printf("\t\ 1: Trouver voyageur\n ");
                printf("\t\ 2: Ajouter voyageur\n");
                printf("\t\ 3: Supprimer voyageur\n");
                printf("\t\ 0: Quittez\n");
                printf("\n************************\n\n");
                printf("tapez votre choix:\n");
                scanf("%d",&choix);
                switch(choix)
                {
                    case 1:{

                    break;}

                    case 2:{
                    break;}
                    case 3:{
                    break;}
                 case 0:{
                    break;}

                     default: printf("choix invalide\n");
                }

            }while(choix!=0);



    //Avant de quitter l'application, vous devez effectuer une sauvegarde dans le fichier.
    sauvegarder_donnees ( nomFich, tab_voyageurs, *ptr_n );
    // liberer
    liberer(tab_voyageurs);

    return 0;
}
