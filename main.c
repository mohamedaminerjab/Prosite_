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
    int n=0,indice;
    int *ptr_n=&n;
    voyageur *tab_voyageurs;
//    tab_voyageurs = charger_donnees_sans_nbVoyageurs (nomFich,ptr_n);
    tab_voyageurs = charger_donnees_avec_nbVoyageurs (nomFich,ptr_n);
    printf(" ptr n  %d ",*ptr_n);
    afficher_voyageurs(tab_voyageurs,*ptr_n);
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
                        char id_trouv[30];
                        printf("saisir l id du voyagur a chercher \n");

                        scanf("%s",&id_trouv);
                        int indice=trouver(tab_voyageurs,id_trouv,*ptr_n);
                        if (indice==-1)
                        {
                            printf("le voyageur d id %s n est pas trouve ",id_trouv);
                        }
                        else
                            {
                            printf("le voyageur d id %s est trouve ",id_trouv);
                        }
                    break;}

                    case 2:{

                            voyageur *voy_ptr, voy;
                        voy_ptr=&voy;
                        saisirVoyageur(voy_ptr);
                        printf("fin saisi\n");


                       tab_voyageurs = ajouter(voy,tab_voyageurs,ptr_n);
                    break;}
                    case 3:{

                        char id_supp[30];
                        printf("saisir l id du voyagur a supprimer \n");

                        scanf("%s",&id_supp);
                        supprimer(tab_voyageurs,id_supp,ptr_n);
                    break;}
                 case 0:{
                    break;}

                     default: printf("choix invalide\n");
                }

            }while(choix!=0);



            afficher_voyageurs(tab_voyageurs,*ptr_n);
    //Avant de quitter l'application, vous devez effectuer une sauvegarde dans le fichier.
    sauvegarder_donnees ( nomFich, tab_voyageurs, *ptr_n );
    // liberer
    liberer(tab_voyageurs);

    return 0;
}
