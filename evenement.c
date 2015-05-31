#include "main.h"
#include <SDL/SDL_image.h>
#include "video.h"
#include "param.h"
#include "resize.h"
void printPosition(personnage*perso)
{
    printf("\nposition x= %d    y= %d \n",perso->positionPlateau.x,perso->positionPlateau.y);


}

void pause(SDL_Surface *ecran,paramStruct*p,mapStruct*mp,int level)
{
SDL_Surface ***tab=(SDL_Surface***)malloc(3*sizeof(SDL_Surface**));
int i;
for (i=0;i<3;i++)
{
tab[i]= (SDL_Surface**)malloc(12*sizeof(SDL_Surface*));
}
int wpb=p->widthWindow/p->widthMap;
int hpb=p->heightWindow/p->heightMap;

charger_perso(tab,p);
SDL_Surface **s=load_brick(p,ecran);
evenement(ecran,tab,p,mp,level,s);
free_brick(s);
freematrice(tab);
}

void charger_perso(SDL_Surface ***tab,paramStruct*p)
{

    char *color[3]={"","r","v"};
    char* pos[12]={"marche_droit","marche_gauche","perso_coted","perso_coteg",
                    "perso_debout","perso_dos","perso_dosd","perso_dosg",
                    "perso_marchedd","perso_marchedg","perso_marchegd","perso_marchegg"

                        };

char *tabStr[3][12];
int i1,j1;
printf("\n");
for(i1=0;i1<3;i1++)
{
    for(j1=0;j1<12;j1++)
    {
        tabStr[i1][j1]=(char*)malloc(sizeof(char)*100);
        if(tabStr[i1][j1])
        {
        strcpy(tabStr[i1][j1],p->ImgData.imgCharacterDirectory);
        strcat(tabStr[i1][j1],"/");
        strcat(tabStr[i1][j1],pos[j1]);
        strcat(tabStr[i1][j1],color[i1]);
        strcat(tabStr[i1][j1],".png");
        }


    }


}
//printf("%s\n%s\n",tabst])
/*
tab[0][0]= IMG_Load("data/character/marche_droit.png");
tab[0][1]= IMG_Load("data/character/marche_gauche.png");
tab[0][2]= IMG_Load("data/character/perso_coted.png");
tab[0][3]= IMG_Load("data/character/perso_coteg.png");
tab[0][4]= IMG_Load("data/character/perso_debout.png");
tab[0][5]= IMG_Load("data/character/perso_dos.png");
tab[0][6]= IMG_Load("data/character/perso_dosd.png");
tab[0][7]= IMG_Load("data/character/perso_dosg.png");
tab[0][8]= IMG_Load("data/character/perso_marchedd.png");
tab[0][9] =IMG_Load("data/character/perso_marchedg.png");
tab[0][10]= IMG_Load("data/character/perso_marchegd.png");
tab[0][11]= IMG_Load("data/character/perso_marchegg.png");


tab[1][0]= IMG_Load("data/character/marche_droiter.png");
tab[1][1]= IMG_Load("data/character/marche_gaucher.png");
tab[1][2]= IMG_Load("data/character/perso_cotedr.png");
tab[1][3]= IMG_Load("data/character/perso_cotegr.png");
tab[1][4]= IMG_Load("data/character/perso_deboutr.png");
tab[1][5]= IMG_Load("data/character/perso_dosr.png");
tab[1][6]= IMG_Load("data/character/perso_dosdr.png");
tab[1][7]= IMG_Load("data/character/perso_dosgr.png");
tab[1][8]= IMG_Load("data/character/perso_coteddr.png");
tab[1][9]=IMG_Load("data/character/perso_cotedgr.png");
tab[1][10]= IMG_Load("data/character/perso_marchegdr.png");
tab[1][11]= IMG_Load("data/character/perso_marcheggr.png");

tab[2][0]= IMG_Load("data/character/marche_droitv.png");
tab[2][1]= IMG_Load("data/character/marche_gauchev.png");
tab[2][2]= IMG_Load("data/character/perso_cotedv.png");
tab[2][3]= IMG_Load("data/character/perso_cotegv.png");
tab[2][4]= IMG_Load("data/character/perso_deboutv.png");
tab[2][5]= IMG_Load("data/character/perso_dosv.png");
tab[2][6]= IMG_Load("data/character/perso_dosdv.png");
tab[2][7]= IMG_Load("data/character/perso_dosgv.png");
tab[2][8]= IMG_Load("data/character/perso_coteddv.png");
tab[2][9] =IMG_Load("data/character/perso_cotedgv.png");
tab[2][10]= IMG_Load("data/character/perso_cotegdv.png");
tab[2][11]= IMG_Load("data/character/perso_coteggv.png");
*/
int i;
int j;
int wpb=p->widthWindow/p->widthMap;
int hpb=p->heightWindow/p->heightMap;
for(i=0;i<3;i++)
{
for(j=0;j<12;j++)
{
    tab[i][j]=IMG_Load(tabStr[i][j]);
    if(tab[i][j]==NULL)
    {
        printf("\nerreur lors du chargement de l'image %d %d\n",i,j);
        printf("chemin= %s\n\n",tabStr[i][j]);
    }

}


}
for(i=0;i<3;i++)
{
for(j=0;j<12;j++)
{
tab[i][j]=SDL_ResizeXY(tab[i][j],wpb,hpb,6);
}


}

  for(i1=0;i1<3;i1++)
{
    for(j1=0;j1<12;j1++)
    {   if(tabStr[i1][j1])
        {
            free(tabStr[i1][j1]);
        tabStr[i1][j1]=NULL;
        }
    }

}



}

//charge tous les personnages dans une matrice
SDL_Surface *chargement_personnage(SDL_Surface ***matrice,couleur a,touche b,int *indice)
{
   SDL_Surface *image=NULL;
   switch(a)
               {
                   case vert:
                      switch (b)
                      {
                        case haut:
                        if (*indice==1)
                        {
                         image=matrice[2][6];
                         *indice=0;
                        }
                        else if(*indice==0)
                        {
                          image=matrice[2][7];
                          *indice=1;
                        }
                        break;


                        case bas:
                         if (*indice==1)
                        {
                         image=matrice[2][0];
                         *indice=0;
                        }
                        else if(*indice==0)
                        {
                          image=matrice[2][1];
                          *indice=1;
                        }
                        break;


                        case gauche:
                         if (*indice==1)
                        {
                         image=matrice[2][10];
                         *indice=0;
                        }
                        else if(*indice==0)
                        {
                          image=matrice[2][11];
                           *indice=1;
                        }
                        break;


                        case droite:
                         if (*indice==1)
                        {
                         image=matrice[2][8];
                          *indice=0;
                        }
                        else if(*indice==0)
                        {
                          image=matrice[2][9];
                           *indice=1;
                        }
                        break;
                      }
                   break;
                   case rouge:
                         switch (b)
                      {
                        case haut:
                         if (*indice==1)
                        {
                         image=matrice[1][6];
                          *indice=0;
                        }
                        else if(*indice==0)
                        {
                          image=matrice[1][7];
                           *indice=1;
                        }
                        break;

                        case bas:
                         if (*indice==1)
                        {
                         image=matrice[1][0];
                          *indice=0;
                        }
                        else if(*indice==0)
                        {
                          image=matrice[1][1];
                           *indice=1;
                        }
                        break;


                        case gauche:
                         if (*indice==1)
                        {
                         image=matrice[1][10];
                          *indice=0;
                        }
                        else if(*indice==0)
                        {
                          image=matrice[1][11];
                           *indice=1;
                        }
                        break;

                        case droite:
                         if (*indice==1)
                        {
                         image=matrice[1][8];
                          *indice=0;
                        }
                        else if(*indice==0)
                        {
                          image=matrice[1][9];
                          *indice=1;
                        }
                        break;
                      }
                   break;
                   case bleu:
                     switch (b)
                      {
                        case haut:
                         if (*indice==1)
                        {
                         image=matrice[0][6];
                          *indice=0;
                        }
                        else if(*indice==0)
                        {
                          image=matrice[0][7];
                           *indice=1;
                        }
                        break;

                        case bas:
                         if (*indice==1)
                        {
                         image=matrice[0][0];
                          *indice=0;
                        }
                        else if(*indice==0)
                        {
                          image=matrice[0][1];
                           *indice=1;
                        }
                        break;

                        case gauche:
                         if (*indice==1)
                        {
                         image=matrice[0][10];
                          *indice=0;
                        }
                        else if(*indice==0)
                        {
                          image=matrice[0][11];
                           *indice=1;
                        }
                        break;

                        case droite:
                         if (*indice==1)
                        {
                         image=matrice[0][8];
                          *indice=0;
                        }
                        else if(*indice==0)
                        {
                          image=matrice[0][9];
                           *indice=1;
                        }
                        break;
                      }
                   break;
               }
               return image;
}
//charge le personnage principal dans une image
void evenement(SDL_Surface *ecran,SDL_Surface ***matrice,paramStruct*p,mapStruct*mp,int level,SDL_Surface **s)
{
loadLevel(p,mp,level);
char **matrice_lecture=mp->activeLevel;


int i2;
int j2;
for (i2=0;i2<p->heightMap;i2++)
{
  for (j2=0;j2<p->widthMap;j2++)
  {
    printf("%c",mp->activeLevel[i2][j2]);
  }
  printf("\n");
}


int recommencer=0;
int wpb=p->widthWindow/p->widthMap;
int hpb=p->heightWindow/p->heightMap;
SDL_Surface *image=NULL;

//intialisation du personnage
personnage actuelle;
depart(&actuelle,matrice_lecture,p);


actuelle.nbr_coup=mp->nb_coups[level];
actuelle.couleur_actuelle=bleu;
int marcher=0;
actuelle.image=matrice[0][4];
int trouver;
int indice;
//-----------------------------------------------
int continuer=1;
int a=1;
SDL_Event event;
SDL_EnableKeyRepeat(10,50);
montrer_niveau(ecran,level+1,*p);
  while(continuer)
  {
    if (a==0)
    {
    SDL_WaitEvent(&event);
    }
    switch(event.type)
    {
      case SDL_QUIT:
      continuer=0;
      indice=0;
      break;
      case SDL_KEYDOWN:
          printPosition(&actuelle);
          switch (event.key.keysym.sym)
          {
            case SDLK_UP:

              Avancer(ecran,p,&actuelle,matrice,mp->activeLevel,s);
               break;
            case SDLK_DOWN:

              Reculer(ecran,p,&actuelle,matrice,matrice_lecture,s);
            break;
             case SDLK_RIGHT:

             Droite(ecran,p,&actuelle,matrice,matrice_lecture,s);
            break;
             case SDLK_LEFT:

              Gauche(ecran,p,&actuelle,matrice,matrice_lecture,s);
             break;
             case SDLK_b:
                 if(actuelle.couleur_actuelle!=bleu &&actuelle.nbr_coup>0)
                 {
                 if (changer_couleur(actuelle.couleur_actuelle,bleu,matrice,actuelle.image)!=NULL)
                 {
                 actuelle.image=changer_couleur(actuelle.couleur_actuelle,bleu,matrice,actuelle.image);
                 }
                 actuelle.couleur_actuelle=bleu;
                 actuelle.nbr_coup--;
                 }

                 break;
             case SDLK_v:
                 if(actuelle.couleur_actuelle!=vert && actuelle.nbr_coup>0)
                 {

                   if (changer_couleur(actuelle.couleur_actuelle,vert,matrice,actuelle.image)!=NULL)
                 {
                 actuelle.image=changer_couleur(actuelle.couleur_actuelle,vert,matrice,actuelle.image);
                 }
                  actuelle.couleur_actuelle=vert;
                  actuelle.nbr_coup--;
                 }

                  break;
             case SDLK_r:
                 if(actuelle.couleur_actuelle!=rouge  && actuelle.nbr_coup>0 )
                 {

                   if (changer_couleur(actuelle.couleur_actuelle,rouge,matrice,actuelle.image)!=NULL)
                 {
                 actuelle.image=changer_couleur(actuelle.couleur_actuelle,rouge,matrice,actuelle.image);
                 }
                  actuelle.couleur_actuelle=rouge;
                  actuelle.nbr_coup--;
                 }

                  break;
              case SDLK_l:
              continuer=0;
              recommencer=1;
              break;
        }
          break;

    }
  Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
  SDL_FillRect(ecran,NULL,blanc);
  SDL_SetColorKey(actuelle.image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle.image)->format,255,255,255));
  dessiner_map(ecran,matrice_lecture,p,s);
  insertion(ecran,matrice_lecture,actuelle.image,(actuelle.position).x,(actuelle.position).y);
  a=0;
  trouver=trouver_sorti(actuelle,&continuer,matrice_lecture,p);
  placer_encadre(ecran,actuelle.nbr_coup,p);
  SDL_Flip(ecran);


  }
  freeLevel(p,mp);
  if (trouver==1 && level<p->nb_map)
  {
    ecrire_reussite(level);
    evenement(ecran,matrice,p,mp,level+1,s);
  }
  else if (recommencer==1)
  {
    evenement(ecran,matrice,p,mp,level,s);
  }
}

SDL_Surface*getFix(SDL_Surface***matrice,personnage*p,touche direction)
{
    int i,j;

    switch(direction)
    {
    case haut :
        j=5;
        break;

    case bas :
        j=4;

        break;

    case gauche :
         j=3;
        break;

    case droite :
        j=2;

        break;


    }

    switch(p->couleur_actuelle)
    {
     case rouge :
          i=1;

        break;

      case vert :
          i=2;

        break;

    case bleu :
        i=0;

        break;
    default :
        break;

    }


    if(matrice==NULL)
    return NULL;


return matrice[i][j];
}

//gestion de déplacement du personnage
void Avancer(SDL_Surface *ecran,paramStruct *p,personnage *actuelle,SDL_Surface ***matrice,char **matrice_lecture,SDL_Surface **s)
{
int i=actuelle->positionPlateau.y;
int j=actuelle->positionPlateau.x;

int wpb=p->widthWindow/p->widthMap;
int hpb=p->heightWindow/p->heightMap;
int marcher=0;

if(actuelle->positionPlateau.y==0)//on est a la frontiere
{
    return;
}
switch(actuelle->couleur_actuelle)//collision
{
  case rouge :
        if(matrice_lecture[i-1][j]!='r' && matrice_lecture[i-1][j]!='m' && matrice_lecture[i-1][j]!=' ' && matrice_lecture[i-1][j]!='$'
           && matrice_lecture[i-1][j]!='e')
        {
              actuelle->image=getFix(matrice,actuelle,haut);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);

            return;
        }
       break;
  case bleu :
        if(matrice_lecture[i-1][j]!='b' && matrice_lecture[i-1][j]!='m' && matrice_lecture[i-1][j]!=' ' && matrice_lecture[i-1][j]!='$'
           && matrice_lecture[i-1][j]!='e')
        {
              actuelle->image=getFix(matrice,actuelle,haut);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);
              return;
        }
       break;
  case vert :
         if(matrice_lecture[i-1][j]!='v' && matrice_lecture[i-1][j]!='m' && matrice_lecture[i-1][j]!=' ' && matrice_lecture[i-1][j]!='$'
            && matrice_lecture[i-1][j]!='e')
         {

                printf("salut");

              printf("%c",matrice_lecture[j][i-1]);
              actuelle->image=getFix(matrice,actuelle,haut);

              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);

            return;
         }

       break;
  default :
    break;


}


actuelle->positionPlateau.y--;

  do{

              (actuelle->position).y-=(int)(hpb/6);
              actuelle->image=chargement_personnage(matrice,actuelle->couleur_actuelle,haut,&marcher);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);
              placer_encadre(ecran,actuelle->nbr_coup,p);
              SDL_Delay(30);
              SDL_Flip(ecran);
              }

              while((actuelle->position.y%hpb)!=0 &&(actuelle->position.y)>hpb*(i-1));
             // actuelle->position.y=(i-1)*hpb;

              actuelle->image=getFix(matrice,actuelle,haut);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);
              placer_encadre(ecran,actuelle->nbr_coup,p);
              SDL_Flip(ecran);
              SDL_Delay(30);

}

void Reculer(SDL_Surface *ecran,paramStruct *p,personnage *actuelle,SDL_Surface ***matrice,char **matrice_lecture,SDL_Surface **s)
{

    int i=actuelle->positionPlateau.y;
int j=actuelle->positionPlateau.x;
int wpb=p->widthWindow/p->widthMap;
int hpb=p->heightWindow/p->heightMap;
int marcher=0;

if(actuelle->positionPlateau.y==(p->heightMap-1))//on est a la frontiere
    return;
switch(actuelle->couleur_actuelle)//collisions
{
  case rouge :
        if(matrice_lecture[i+1][j]!='r' && matrice_lecture[i+1][j]!='m' && matrice_lecture[i+1][j]!=' ' && matrice_lecture[i+1][j]!='$'
           && matrice_lecture[i+1][j]!='e')
        {
               actuelle->image=getFix(matrice,actuelle,bas);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              return;
        }

       break;
  case bleu :
        if(matrice_lecture[i+1][j]!='b' && matrice_lecture[i+1][j]!='m' && matrice_lecture[i+1][j]!=' ' && matrice_lecture[i+1][j]!='$'
           && matrice_lecture[i+1][j]!='e')
        {
               actuelle->image=getFix(matrice,actuelle,bas);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);

            return;
        }
       break;
  case vert :
         if(matrice_lecture[i+1][j]!='v' && matrice_lecture[i+1][j]!='m' && matrice_lecture[i+1][j]!=' ' && matrice_lecture[i+1][j]!='$'
            && matrice_lecture[i+1][j]!='e')
         {
               actuelle->image=getFix(matrice,actuelle,bas);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);

            return;
         }

       break;
  default :
    break;


}






actuelle->positionPlateau.y++;

  do{

              (actuelle->position).y+=(int)(hpb/6);
              actuelle->image=chargement_personnage(matrice,actuelle->couleur_actuelle,bas,&marcher);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);
              SDL_Delay(30);
              placer_encadre(ecran,actuelle->nbr_coup,p);
              SDL_Flip(ecran);
              }

              while((actuelle->position.y%hpb)!=0 &&(actuelle->position.y)<hpb*(i+1));

              //(actuelle->position.y)=hpb*(i+1);
               actuelle->image=getFix(matrice,actuelle,bas);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);
              placer_encadre(ecran,actuelle->nbr_coup,p);
              SDL_Flip(ecran);
              SDL_Delay(30);
}


void Gauche(SDL_Surface *ecran,paramStruct *p,personnage *actuelle,SDL_Surface ***matrice,char **matrice_lecture,SDL_Surface **s)
{

int i=actuelle->positionPlateau.y;
int j=actuelle->positionPlateau.x;
int wpb=p->widthWindow/p->widthMap;
int hpb=p->heightWindow/p->heightMap;
int marcher=0;
if(actuelle->positionPlateau.x==0)//on est a la frontiere
    return;
switch(actuelle->couleur_actuelle)//collisions
{
  case rouge :
        if(matrice_lecture[i][j-1]!='r' && matrice_lecture[i][j-1]!='m' && matrice_lecture[i][j-1]!=' ' && matrice_lecture[i][j-1]!='$'
           && matrice_lecture[i][j-1]!='e' )
        {
               actuelle->image=getFix(matrice,actuelle,gauche);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);

            return;
        }
       break;
  case bleu :
        if(matrice_lecture[i][j-1]!='b' && matrice_lecture[i][j-1]!='m' && matrice_lecture[i][j-1]!=' ' && matrice_lecture[i][j-1]!='$'
            && matrice_lecture[i][j-1]!='e')
        {
               actuelle->image=getFix(matrice,actuelle,gauche);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);

            return;
        }
       break;
  case vert :
         if(matrice_lecture[i][j-1]!='v' && matrice_lecture[i][j-1]!='m' && matrice_lecture[i][j-1]!=' ' && matrice_lecture[i][j-1]!='$'
            && matrice_lecture[i][j-1]!='e')
         {
               actuelle->image=getFix(matrice,actuelle,gauche);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);

            return;
         }

       break;
  default :
    break;


}







actuelle->positionPlateau.x--;

  do{

              (actuelle->position).x-=(int)(wpb/6);
              actuelle->image=chargement_personnage(matrice,actuelle->couleur_actuelle,gauche,&marcher);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);
              SDL_Delay(30);
              placer_encadre(ecran,actuelle->nbr_coup,p);
              SDL_Flip(ecran);
              }

              while((actuelle->position.x%wpb)!=0 &&(actuelle->position.x)>(j-1)*wpb);

              //(actuelle->position.x)=(j-1)*wpb;
               actuelle->image=getFix(matrice,actuelle,gauche);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);
              SDL_Delay(30);
              placer_encadre(ecran,actuelle->nbr_coup,p);
              SDL_Flip(ecran);

              SDL_Delay(30);

}


void Droite(SDL_Surface *ecran,paramStruct *p,personnage *actuelle,SDL_Surface ***matrice,char **matrice_lecture,SDL_Surface **s)
{

int i=actuelle->positionPlateau.y;
int j=actuelle->positionPlateau.x;
int wpb=p->widthWindow/p->widthMap;
int hpb=p->heightWindow/p->heightMap;
int marcher=0;

if(actuelle->positionPlateau.x==(p->widthMap-1))//on est a la frontiere
    return;
switch(actuelle->couleur_actuelle)//collision
{
  case rouge :
        if(matrice_lecture[i][j+1]!='r' && matrice_lecture[i][j+1]!='m' && matrice_lecture[i][j+1]!=' ' && matrice_lecture[i][j+1]!='$'
           && matrice_lecture[i][j+1]!='e')
        {
               actuelle->image=getFix(matrice,actuelle,droite);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);

            return;
        }
       break;
  case bleu :
        if(matrice_lecture[i][j+1]!='b' && matrice_lecture[i][j+1]!='m' && matrice_lecture[i][j+1]!=' ' && matrice_lecture[i][j+1]!='$'
           && matrice_lecture[i][j+1]!='e')
        {
               actuelle->image=getFix(matrice,actuelle,droite);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);

            return;
        }
            break;
  case vert :
         if(matrice_lecture[i][j+1]!='v' && matrice_lecture[i][j+1]!='m' && matrice_lecture[i][j+1]!=' ' && matrice_lecture[i][j+1]!='$'
            && matrice_lecture[i][j+1]!='e')
         {
              actuelle->image=getFix(matrice,actuelle,droite);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);

            return;
         }

       break;
  default :
    break;


}







actuelle->positionPlateau.x++;

  do{

              (actuelle->position).x+=(int)(wpb/6);
              actuelle->image=chargement_personnage(matrice,actuelle->couleur_actuelle,droite,&marcher);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);
              SDL_Delay(30);
              placer_encadre(ecran,actuelle->nbr_coup,p);
              SDL_Flip(ecran);
              }

              while((actuelle->position.x%wpb)!=0 && (actuelle->position.x)<(j+1)*wpb );


             // (actuelle->position.x)=(j+1)*wpb;

               actuelle->image=getFix(matrice,actuelle,droite);
              Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
              SDL_FillRect(ecran,NULL,blanc);
              SDL_SetColorKey(actuelle->image,SDL_SRCCOLORKEY,SDL_MapRGB((actuelle->image)->format,255,255,255));
              dessiner_map(ecran,matrice_lecture,p,s);
              insertion(ecran,matrice_lecture,actuelle->image,(actuelle->position).x,(actuelle->position).y);
              placer_encadre(ecran,actuelle->nbr_coup,p);
              SDL_Flip(ecran);
              SDL_Delay(30);
}


SDL_Surface *changer_couleur(couleur c_actuelle,couleur c_achanger,SDL_Surface ***matrice,SDL_Surface *image_actuelle)
{

  int i;
  int j;
  for(i=0;i<3;i++)
  {
    for (j=0;j<12;j++)
    {
       if(matrice[i][j]==image_actuelle)
       {
         switch (c_actuelle)
         {
            case bleu:
               switch (c_achanger)
               {
                 case rouge:
                return matrice[i+1][j];
                 break;
                 case vert:
                 return  matrice[i+2][j];
                 break;
               }
            break;
            case rouge:
                switch (c_achanger)
               {
                 case bleu:
                 return matrice[i-1][j];
                 break;
                 case vert:
                 return matrice[i+1][j];
                 break;
               }
            break;
            case vert:
             switch (c_achanger)
               {
                 case bleu:
                 return matrice[i-2][j];
                 break;
                 case rouge:
                 return matrice[i-1][j];
                 break;
               }
            break;
         }
       }
    }
  }
  return NULL;
}
//change la couleur du personnage à l'aide d'une matrice
void freematrice(SDL_Surface ***matrice)
{

int i;
for(i=0;i<=2;i++)
{
  free(matrice[i]);
}
free(matrice);
}
//vide la mémoire

int trouver_sorti(personnage a,int *continuer,char **matrice_lecture,paramStruct *p)
{



int x1;
int y1;
int i=a.positionPlateau.y;
int j=a.positionPlateau.x;


if (matrice_lecture[i][j]=='$')
{
*continuer=0;
return 1;
}
return 0;
}
void placer_encadre(SDL_Surface *ecran,int nbr_coup,paramStruct *p)
{
SDL_Rect position_encadre;
SDL_Surface *encadre=NULL;
encadre=SDL_CreateRGBSurface(SDL_HWSURFACE,p->widthWindow,50,32,0,0,0,0);
position_encadre.x=0;
position_encadre.y=(p->heightWindow)-40;
SDL_BlitSurface(encadre,NULL,ecran,&position_encadre);
TTF_Init();
if (TTF_Init()==-1)
{
 printf("erreur lors du chargement de la SDL_TTf");
}
TTF_Font *police;
police=TTF_OpenFont("data/police/brush.ttf",20);
SDL_Color couleurBlanche={255,255,255};
SDL_Surface *coup=NULL,*chiffre=NULL;
SDL_Rect position_coup;
position_coup.y=((p->heightWindow)-40)+(40/2)-10;
position_coup.x=0;
char chaine[256]="yoo";
sprintf(chaine,"%d",nbr_coup);
chiffre=TTF_RenderText_Blended(police,chaine,couleurBlanche);
coup=TTF_RenderText_Blended(police,"nombre de coup restant :",couleurBlanche);
SDL_BlitSurface(coup,NULL,ecran,&position_coup);
position_coup.y=((p->heightWindow)-50)+(50/2)-12;
position_coup.x=220;
SDL_BlitSurface(chiffre,NULL,ecran,&position_coup);
SDL_FreeSurface(chiffre);
SDL_FreeSurface(coup);
SDL_FreeSurface(encadre);
TTF_CloseFont(police);
TTF_Quit();
}

void ecrire_reussite(int level)
{
  FILE *fichier=NULL;
  fichier = fopen("data/mapList29.txt","r+");
  if (fichier!=NULL)
  {
 int i=0;
 char chaine[256];
 for (i=0;i<level;i++)
 {
   fgets(chaine,256,fichier);
 }
 }

 int v=0;
 while (v<2)
    {
     char caractere=fgetc(fichier);
     if (caractere==' ')
        {
          v++;
        }
    }
fputc('1',fichier);
fclose(fichier);
  }

void depart(personnage *actuelle,char **matrice_lecture,paramStruct *p)
{
  int i=0;
  int j=0;
  for(i=0;i<p->heightMap;i++)
   {
     for (j=0;j<p->widthMap;j++)
     {
       if (matrice_lecture[i][j]=='e')
       {
         actuelle->positionPlateau.x=j;
         actuelle->positionPlateau.y=i;
       }
     }
   }
   int wpb=p->widthWindow/p->widthMap;
   int hpb=p->heightWindow/p->heightMap;

   actuelle->position.x=actuelle->positionPlateau.x*wpb;
   actuelle->position.y=actuelle->positionPlateau.y*hpb;
}

void montrer_niveau(SDL_Surface *ecran,int level,paramStruct p)
{
   TTF_Init();
   if (TTF_Init()==-1)
   {
    printf("erreur lors du chargement de la SDL_TTf");
   }
   SDL_Surface *titre,*image_bas;
   SDL_Rect position_titre;
   SDL_Rect position_image;
   titre=IMG_Load("data/menu/crazy_maze.bmp");
    image_bas=IMG_Load("data/menu/brique.bmp");
    image_bas=SDL_ResizeXY (image_bas,p.widthWindow,70,1);
    placer_texte(&position_titre,p.widthWindow/2-664/2,0);
    placer_texte(&position_image,0,p.heightWindow-59);
   SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,120,0,0));
    SDL_SetColorKey(titre,SDL_SRCCOLORKEY,SDL_MapRGB(ecran->format,0,0,0));
    SDL_BlitSurface(titre,NULL,ecran,&position_titre);
    SDL_BlitSurface(image_bas,NULL,ecran,&position_image);
   SDL_Rect position;
   TTF_Font *police=NULL;
   SDL_Color couleurBlanche={255,255,255};
   police=TTF_OpenFont("data/police/brush.ttf",65);
   SDL_Surface *texte=NULL,*chiffre=NULL;
   texte=TTF_RenderText_Blended(police,"niveau",couleurBlanche);
   char chaine[256]=" ";
   sprintf(chaine,"%d",level);
   chiffre=TTF_RenderText_Blended(police,chaine,couleurBlanche);
   position.x=(p.widthWindow/3)+5;
   position.y=( p.heightWindow/3)+10;
   SDL_BlitSurface(texte,NULL,ecran,&position);
   position.x+=200;
   SDL_BlitSurface(chiffre,NULL,ecran,&position);

   SDL_FreeSurface(titre);
   SDL_FreeSurface(image_bas);
   SDL_FreeSurface(texte);
   SDL_FreeSurface(chiffre);
   TTF_CloseFont(police);
   TTF_Quit();
   SDL_Flip(ecran);
   SDL_Delay(3000);
}
