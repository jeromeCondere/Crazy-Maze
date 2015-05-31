#include"video.h"
#include<string.h>



void dessiner_brique(int x,int y,SDL_Surface*ecran,SDL_Surface**briques, brick_type type)
{
  /*char*redfile=p->ImgData.imgMapDirectory;
  char*greenfile=p->ImgData.imgMapDirectory;
  char* bluefile=p->ImgData.imgMapDirectory;
  strcat(redfile,"/R_brick.png");
  strcat(greenfile,"/V_brick.png");
  strcat(bluefile,"/B_brick.png");

*/


 SDL_Rect pBrick;
pBrick.x=x;
pBrick.y=x;


if(ecran==NULL)
    return;

switch (type)
{
    case ROUGE :
        SDL_BlitSurface(briques[0], NULL, ecran, &pBrick);
        break;

    case VERT :
        SDL_BlitSurface(briques[1], NULL, ecran, &pBrick);
        break;

    case BLEU :
        SDL_BlitSurface(briques[2], NULL, ecran, &pBrick);
        break;

    default :

      break;



}

}
void dessiner_map(SDL_Surface*ecran,char**plateau,paramStruct*p,SDL_Surface**briques)
{

    int wpb=p->widthWindow/p->heightMap;
    int hpb=p->heightWindow/p->widthMap;
    int i=0;
    int j=0;
    int x=0;
    int y=0;


 SDL_Rect pBrick;
pBrick.x=x;
pBrick.y=y;
    for(i=0;i<p->heightMap;i++)
    {
      y=i*hpb;
      x=j*wpb;
      pBrick.x=x;
      pBrick.y=y;
        for(j=0;j<p->widthMap;j++)
        {
          x=j*wpb;
          y=i*hpb;
          pBrick.x=x;
          pBrick.y=y;
            switch(plateau[i][j])
            {
              case 'r' :
                  SDL_BlitSurface(briques[0], NULL, ecran, &pBrick);

                  break;
               case 'v' :
                  SDL_BlitSurface(briques[1], NULL, ecran, &pBrick);
                  break;
              case 'b' :
                  SDL_BlitSurface(briques[2], NULL, ecran, &pBrick);
                  break;
              case 'n' :
                  SDL_BlitSurface(briques[3], NULL, ecran, &pBrick);
                  break;
               case 'c':
                  SDL_BlitSurface(briques[4], NULL, ecran, &pBrick);
                  break;
              case '$':
                  SDL_BlitSurface(briques[5],NULL,ecran,&pBrick);
                  break;
              default :
                break;



            }


        }


    }





}

SDL_Surface**load_brick(paramStruct*param,SDL_Surface *ecran)
{
    if(param==NULL)
        return NULL;
//-------------------------
/*
SDL_Surface *brickB=NULL;
SDL_Surface *brickR=NULL;
SDL_Surface *brickV=NULL;
SDL_Surface *brickN=NULL;
SDL_Surface *brickC=NULL;
*/
//-------------------------

SDL_Surface *brickBr=NULL;
SDL_Surface *brickRr=NULL;
SDL_Surface *brickVr=NULL;
SDL_Surface *brickNr=NULL;
SDL_Surface *brickCr=NULL;
SDL_Surface *brickSr=NULL;
//-------------------------
int i=0;
char tab[6][50]={"","","","","",""};
for(i=0;i<6;i++)
{
    strcpy(tab[i],param->ImgData.imgMapDirectory);
}

strcat(tab[0],"/R_brick.png");
strcat(tab[1],"/V_brick.png");
strcat(tab[2],"/B_brick.png");
strcat(tab[3],"/N_brick.png");
strcat(tab[4],"/C_brick.png");
strcat(tab[5],"/porte.png");
//chargement des images

brickRr=IMG_Load(tab[0]);
page_chargement(ecran,*param,2);
SDL_Flip(ecran);
brickVr=IMG_Load(tab[1]);
page_chargement(ecran,*param,3);
SDL_Flip(ecran);
brickBr=IMG_Load(tab[2]);
page_chargement(ecran,*param,1);
SDL_Flip(ecran);
brickNr=IMG_Load(tab[3]);
page_chargement(ecran,*param,2);
SDL_Flip(ecran);
brickCr=IMG_Load(tab[4]);
page_chargement(ecran,*param,3);
brickSr=IMG_Load(tab[5]);
SDL_Flip(ecran);


int widthpixel=param->widthWindow/param->widthMap;
int heightpixel=param->heightWindow/param->heightMap;
printf ("%d",widthpixel);
brickBr=SDL_ResizeXY (brickBr,widthpixel,heightpixel,6);
page_chargement(ecran,*param,1);
SDL_Flip(ecran);
brickVr=SDL_ResizeXY (brickVr,widthpixel,heightpixel,6);
page_chargement(ecran,*param,2);
SDL_Flip(ecran);
brickRr=SDL_ResizeXY (brickRr,widthpixel,heightpixel,6);
page_chargement(ecran,*param,3);
SDL_Flip(ecran);
brickNr=SDL_ResizeXY (brickNr,widthpixel,heightpixel,6);
page_chargement(ecran,*param,1);
SDL_Flip(ecran);
brickCr=SDL_ResizeXY (brickCr,widthpixel,heightpixel,6);
page_chargement(ecran,*param,2);
brickSr=SDL_ResizeXY(brickSr,widthpixel,heightpixel,6);
page_chargement(ecran,*param,3);
SDL_Flip(ecran);

SDL_Surface**res=(SDL_Surface**)malloc(6*sizeof(SDL_Surface*));
res[0]=brickRr;
res[1]=brickVr;
res[2]=brickBr;
res[3]=brickNr;
res[4]=brickCr;
res[5]=brickSr;
/*
SDL_FreeSurface(brickV);
SDL_FreeSurface(brickB);
SDL_FreeSurface(brickR);
SDL_FreeSurface(brickN);
SDL_FreeSurface(brickC);
*/

page_chargement(ecran,*param,3);
SDL_Flip(ecran);
return res;
}
void free_brick(SDL_Surface**s)
{
    if(s==NULL)
        return;
    int i;
    for(i=0;i<6;i++)
    {
        if(s[i])
            SDL_FreeSurface(s[i]);
    }

free(s);
}





