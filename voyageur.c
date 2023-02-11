#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"voyageur.h"
int nbVoyageurs(char nomFich[])
{
    int nb=0;
    voyageur v;

   FILE*fichier= fopen(nomFich,"rb");
   while(fread(&v,sizeof(voyageur),1,fichier))
   {
       nb+=1;
   }
   fclose(fichier);
   return nb;
}
void saisirVoyageur (voyageur * ptv)
{
    printf("donner l identifiant: ");
    scanf("%s",(*ptv).id);
     printf("donner le nom: ");
    scanf("%s",(*ptv).nom);
     printf("donner adresse: ");
    scanf("%s",(*ptv).adresse);
     printf("donner nombre total des voyages : ");
    scanf("%d",&(*ptv).nbt_voyage);
}
// Remarque: Impl�mentez cette fonction avec 2 fa�ons.(avec et sans l'appel de nbVoyageurs
voyageur * charger_donnees_avec_nbVoyageurs (char nomFich[], int * n)
{
     voyageur *ptr_v;

    FILE*fichier=fopen(nomFich,"rb");

    if(fichier==NULL)
    {
        printf("erreur");
    }
    else{
            *n = nbVoyageurs(nomFich);
            ptr_v=(voyageur*)malloc((*n)*sizeof(voyageur)); //   La fonction malloc permet la recherche d�un bloc contig�e libre en m�moire qui peut contenir n  voyageur et retourne l�adresse de d�but de ce bloc. Elle retourne NULL en cas d��chec (pas assez de m�moire
            int i=0;
               while(fread(ptr_v+i,sizeof(voyageur),1,fichier))
   {

       i+=1;
   }
    }

    return ptr_v;
}

voyageur * charger_donnees_sans_nbVoyageurs (char nomFich[], int * n)
{
     voyageur *ptr_v;
    FILE*fichier=fopen(nomFich,"rb");

    if(fichier==NULL)
    {
        printf("erreur");
    }
    else{
            *n = 0;
             //   La fonction malloc permet la recherche d�un bloc contig�e libre en m�moire qui peut contenir n  voyageur et retourne l�adresse de d�but de ce bloc. Elle retourne NULL en cas d��chec (pas assez de m�moire
               while(!feof(fichier))
   {
       voyageur v_tmp;
       if(fread(&v_tmp,sizeof(voyageur),1,fichier))
{
    if(n!=0) ptr_v=(voyageur*)malloc(sizeof(voyageur));

    else{
            ptr_v = realloc(ptr_v,(*n)*sizeof(voyageur));
    }

    *(ptr_v+(*n))=v_tmp;
(*n)++;

}
   }

   (*n)--;
    }

    return ptr_v;
}
void sauvegarder_donnees (char nomFich[], voyageur * tab, int n)
{
    FILE *fichier=fopen(nomFich,"wb");
    if(fichier!=NULL){
    fwrite(tab,sizeof(voyageur),n,fichier);
    }
    else{
        printf("erreur\n");
    }
    fclose(fichier);

}
int trouver(voyageur * tab, char id[], int n)
{
    int indice=-1;
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(id,(char *)(tab+i)->id==0))
           {
               indice=i;
               break;
           }

    }
   return indice ;
}
 voyageur * ajouter (voyageur v, voyageur * tab, int * n)
 {
     int indice = trouver(tab, v.id, *n);
     if(indice==-1){
            (*n)++;
            /// ici
            tab=realloc(tab,(*n)*sizeof(voyageur));
     *(tab+*n)=v;

     }else{
         ((tab+indice)->nbt_voyage)++;


     }
return tab;
 }

// qui permet de supprimer le voyageur dont l�identifiant est pass� en param�tre.
void  supprimer (voyageur * tab , char id[], int * n)
{
      int indice = trouver(tab, id, *n);
     if(indice==-1){
           printf("le voyageur de indentifiant %s n existe pas\n", id);
     }
     else if(indice+1==*n){
        (*n)--;
     }
     else{
         /*
*tableau tableau[0] acc�s au 1er �l�ment

*(tableau+i) tableau[i] acc�s � l'�l�ment i

tableau &tableau[0] adresse du 1er �l�ment

(tableau + i)  &(tableau[i]) adresse de l'�l�ment i

         */

         *(tab+indice) = *(tab+(*n)-1);

         (*n)--;


     }

}


void liberer (voyageur * tab)
{
    if(tab!=NULL)
        free(tab);
}
