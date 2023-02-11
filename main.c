#include <stdio.h>
#include <stdlib.h>
#include"voyageur.h"
int main()
{
    //Lorsque l'agent de l'agence lance l'application,
    // toutes les données existantes dans le fichier de sauvegarde doivent être
    // chargées dans un tableau sur lequel des opérations d'ajout de suppression, de recherche ..., sont effectuées.

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
