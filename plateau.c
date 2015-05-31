#include "main.h"
#include "plateau.h"
#include <SDL/SDL.h>
#include"param.h"


char**lecture2(char*filename,paramStruct*p){


FILE* fichier = NULL;
fichier =fopen(filename,"r");
 if (fichier!=NULL)
 {
   char lettre=0;
   int i=0;
   int j=0;
   int k=0;
   int sortie=0;
   int entree=0;


   char**matrice=(char**)malloc(sizeof(char*)*(p->heightMap));
   if(matrice==NULL)
   {
       printf("erreur lors de l'allocation du plateau");
       return NULL;
   }
   for(k=0;k<p->heightMap;k++ )
   {
       matrice[k]=(char*)malloc(sizeof(char)*(p->widthMap));
      if(matrice[k]==NULL)
      {
       printf("\n erreur lors de l'allocation du plateau\n");
       return NULL;
      }


   }


   for(i=0;i<p->heightMap;i++)
   {
     for (j=0;j<p->widthMap;j++)
     {
       matrice[i][j]='m';


       }

     }

i=0;
j=0;

   for(i=0;i<p->heightMap;i++)
   {

     for (j=0;j<p->widthMap;j++)
     {
      if(!feof(fichier))
     lettre=fgetc(fichier);
        if(lettre=='s')
          {
            sortie++;
          }
          if(lettre=='$')
          {
              entree++;
          }
     if(lettre!='\n' )
     {
         if(lettre!=EOF)
     matrice[i][j]=lettre;
     }
     else{
        i++;
        j=-1;
       }

     }
     if(!feof(fichier))
     {
     while(fgetc(fichier)!='\n' );//on saute de ligne

     }
     else{
        i=p->heightMap+1;//on sort de la boucle
     }
   }
fclose(fichier);


   return matrice;
 }
 else
 {
   printf("erreur lors de l'ouverture du fichier!!!");
   return NULL;
 }


}

// place les briques sur l'écran => la parti à modifier pour mettre les bonne brique
void insertion(SDL_Surface *ecran,char** matrice,SDL_Surface *image,int x,int y)
{

   SDL_Rect position;
   position.x=x;
   position.y=y;
   SDL_BlitSurface(image,NULL,ecran,&position);
}
// insert dans l'écran les briques précédente et une image (le personnage) à une position x y




void freePlateau(char**plateau,paramStruct*p){
int k=0;
if(plateau==NULL||p==NULL)
{
    printf("erreur lors de la liberation de la memoire");
    return;
}
for(k=0;k<p->heightMap;k++ )
   {
      if(plateau[k]!=NULL)
      {
       free(plateau[k]);
      }
}
free(plateau);
}




int loadLevel(paramStruct*p,mapStruct*mp,int level)
{
   if(p==NULL || mp==NULL)
        return -1;

   if(!(level>=0 && level<p->nb_map))
      return -1;

    if(mp->mapList==NULL)
        return -1;


    mp->activeLevel=lecture2(mp->mapList[level],p);

return 0;

}
int checkLevel(paramStruct*p,mapStruct*mp)
{
    int sortie=0;
    int entree=0;
    if(p==NULL || mp==NULL )
        return -1;

    if(mp->activeLevel==NULL)
        return -1;

int i,j;
 for(i=0;i<p->heightMap;i++)
   {

     for (j=0;j<p->widthMap;j++)
     {
         if(mp->activeLevel[i][j]='s')
            sortie++;
         if(mp->activeLevel[i][j]='$')
            entree++;
     }
   }

//un niveau contient au moins une entree et une sortie
if(!entree)
{
    printf("il n y a pas de point de respawn \n");
    return -1;
}
if(entree>1)
{
    printf("il y plus d'un point de respawn !! \n");
    return -1;
}

if(!sortie)
{
    printf("attention il n'y a pas de sortie dans ce niveau\n");
    return -1;
}
if(sortie>1)
{
    printf("il y a plus d'une sortie\n");
}




return 0;
}

void freeLevel(paramStruct*p,mapStruct*mp)
{
  freePlateau(mp->activeLevel,p);
  mp->activeLevel=NULL;



}
