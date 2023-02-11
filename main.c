#include <stdio.h>
#include <stdlib.h>
#include"voyageur.h"
int main()
{
    //Lorsque l'agent de l'agence lance l'application,
    // toutes les donn�es existantes dans le fichier de sauvegarde doivent �tre
    // charg�es dans un tableau sur lequel des op�rations d'ajout de suppression, de recherche ..., sont effectu�es.

    char *nomFich = "voyageur.bin";
    int n=0;
    int *ptr_n=&n;
    voyageur *tab_voyageurs;
    tab_voyageurs = charger_donnees_sans_nbVoyageurs (nomFich,ptr_n);

    //Avant de quitter l'application, vous devez effectuer une sauvegarde dans le fichier.
    sauvegarder_donnees ( nomFich, tab_voyageurs, *ptr_n );
    // liberer
    liberer(tab_voyageurs);
    return 0;
}
