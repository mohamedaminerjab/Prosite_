#ifndef VOYAGEUR_H_INCLUDED
#define VOYAGEUR_H_INCLUDED
typedef struct
{
    char id[30];
    char nom[30];
    char  adresse[30];
    int nbt_voyage;

}voyageur;
int nbVoyageurs(char nomFich[]);
void saisirVoyageur (voyageur * ptv);
voyageur * charger_donnees_avec_nbVoyageurs (char nomFich[], int * n);
voyageur * charger_donnees_sans_nbVoyageurs (char nomFich[], int * n);
void sauvegarder_donnees (char nomFich[], voyageur * tab, int n);
int trouver(voyageur * tab, char id[], int n) ;
voyageur * ajouter (voyageur v, voyageur * tab, int * n);
void  supprimer (voyageur * tab , char id[], int * n);

void liberer (voyageur * tab);



#endif // VOYAGEUR_H_INCLUDED
