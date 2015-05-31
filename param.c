

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "param.h"

paramStruct loadParam(char* filename)
{

    paramStruct param;
    FILE*fr=NULL;
    fr=fopen(filename,"r");//lecture seule
//on lit dans le fichier et on stoccke les parametres

  if(fr==NULL)
  {
    printf("erreur lors de l'ouverture du fichier");

    return param;
  }





  fscanf(fr,"%*s %d %d",&param.heightWindow,&param.widthWindow);//paramètre fenetre
  fscanf(fr,"%*s %d %d",&param.heightMap,&param.widthMap);//paramètre carte
  fscanf(fr,"%*s %s",param.mapList);
  fscanf(fr,"%*s %s",param.ImgData.imgMapDirectory);
  fscanf(fr,"%*s %s",param.ImgData.imgCharacterDirectory);

fclose(fr);

return param;
  }
  char** loadMapList(paramStruct*p)//cree un tableau de chaine de caractere dans lesquelle on met le c
  {
    char**mapListName=NULL;

     if(p==NULL)
     {
       printf("erreur!!");
       return NULL;
     }

  FILE*f=fopen(p->mapList,"r");
  if(f==NULL)
  {
      printf("erreur lors de l'ouverture du fichier");
      return NULL;
  }
  int i=0;
  while(!feof(f))
  {
     i++;
     fscanf(f,"%*s") ;

  }
  i--;
  p->nb_map=i;

  mapListName=(char**)malloc(i*sizeof(char*));
  int w;
  for( w=0;w<i;w++)
  {
      mapListName[w]=(char*)malloc(50*sizeof(char));
  }

  fseek(f,0,SEEK_SET);//on revient au debut
int k=0;
 while(!feof(f))
  {
     fscanf(f,"%s",mapListName[k]) ;
     k++;
  }

fclose(f);

  return mapListName;
  }


void printParam(paramStruct*p)
{
    if(p)
    {


    int wpb,hpb;
    wpb=p->widthWindow/p->widthMap;
    hpb=p->heightWindow/p->heightMap;
    printf("\n\nfenetre--  taille : %d X %d\n",p->widthWindow,p->heightWindow);
    printf("taille carte : %d X %d (briques)\n",p->widthMap,p->heightMap);
    printf("\nhauteur brique = %d pixels ",hpb);
    printf("\nlargeur  brique = %d pixels \n",wpb);
    printf("Liste des cartes  %s \n",p->mapList);//-->mapdata

    printf("repertoire image_carte: %s \n",p->ImgData.imgMapDirectory);
    printf("repertoire image_personnage: %s\n\n",p->ImgData.imgCharacterDirectory);



    }


}
void freeMapList(char**l,paramStruct*p)
{
    if(l==NULL)
        return;
        if(p==NULL)
            return;

    int i=0;
    for(i=0;i<p->nb_map;i++)
    {
        if(l[i]!=NULL)
            free(l[i]);

    }
    free(l);





}
int loadMapParam(paramStruct*p,mapStruct*mp)
{
    if(p==NULL || mp==NULL)
    {
        printf("\nerreur lors du chargement des parametres\n");
        return -1;
    }


  FILE*f=fopen(p->mapList,"r");
  if(f==NULL)
  {
      printf("erreur lors de l'ouverture du fichier");
      return -1;
  }
  int i=0;
  while(!feof(f))
  {
      if(fgetc(f)!=EOF)
      {
     i++;
     while(fgetc(f)!='\n');
      }

  }
  //si le fichier est bien formé le nbre de lignes est le nbre de niveaux
  p->nb_map=i;
  //allocation dynamique
  mp->mapList=(char**)malloc(i*sizeof(char*));
  mp->nb_coups=(int*)malloc(i*sizeof(int));
  mp->success=(int*)malloc(i*sizeof(int));

    if(mp->mapList==NULL || mp->nb_coups==NULL||mp->success==NULL)
    {
        printf("erreur lors de l'allocation dynamique\n");
        return -1;
    }




  int w;
  for( w=0;w<i;w++)
  {
      mp->mapList[w]=(char*)malloc(60*sizeof(char));
  }

  fseek(f,0,SEEK_SET);//on revient au debut
int k=0;
 while(!feof(f))
  {

     fscanf(f,"%s %d %d",mp->mapList[k],&mp->nb_coups[k],&mp->success[k]) ;
     k++;
  }

fclose(f);








    return 0;
}


void freeMapParam(paramStruct*p,mapStruct*mp)
{
    if(p==NULL || mp==NULL)
        return;
    int i;
   if(mp->mapList)
   {
    for(i=0;i<p->nb_map;i++)
    {
        if(mp->mapList[i]!=NULL)
        {
            free(mp->mapList[i]);
            mp->mapList[i]=NULL;
        }
    }
   }
    free(mp->mapList);
   if(mp->nb_coups)
    free(mp->nb_coups);
   if(mp->success)
    free(mp->success);

}

void printMapList(paramStruct*p,mapStruct*mp)
{
    if(p==NULL || mp==NULL)
      return;

    int i;
    for(i=0;i<p->nb_map;i++)
    {
       printf("%s\n",mp->mapList[i]);

    }
}

int initParam(paramStruct*p,mapStruct*mp,char*paramFile,int verbose)
{
    if(p==NULL || mp==NULL)
    {
        if(verbose)
            printf("erreur lors de l'initialisation\n");
        return -1;
    }

    *p=loadParam(paramFile);
    if(verbose)
    printParam(p);

    if(loadMapParam(p,mp))
    {
        if(verbose)
        printf("erreur lors du chargement des paramètres de map\n");
        freeMapParam(p,mp);//on libère la mémoire allouée
        return -1;

    }
    if(verbose)
        printMapList(p,mp);




 return 0;

}

