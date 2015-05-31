#include "menu.h"


void charger_menu (SDL_Surface *ecran,paramStruct p,int *choix,mapStruct *mp)
{
  TTF_Init();
  if (TTF_Init()==-1)
  {
    printf("erreur lors du chargement de la SDL_TTf");
  }
 TTF_Font *police_continuer=NULL,*police_jouer=NULL,*police_instructions=NULL,*police_quitter=NULL;

 police_jouer=TTF_OpenFont("data/police/brush.ttf",60);
 police_continuer=TTF_OpenFont("data/police/brush.ttf",60);
 police_instructions=TTF_OpenFont("data/police/brush.ttf",60);
 police_quitter=TTF_OpenFont("data/police/brush.ttf",60);

 //police et taille des phrases
 SDL_Color couleurBlanche={255,255,255};
 SDL_Surface *Jouer,*Continuer,*Instructions,*Quitter,*Titre,*image_bas;
 SDL_Rect position_jouer;
 SDL_Rect position_continuer;
 SDL_Rect position_instructions;
 SDL_Rect position_quitter;
 SDL_Rect position_titre;
 SDL_Rect position_image;
 SDL_Rect position_perso;

 placer_texte(&position_jouer,p.widthWindow/3,p.heightWindow/3);
 placer_texte(&position_continuer,p.widthWindow/3,p.heightWindow/3+70);
 placer_texte(&position_instructions,p.widthWindow/3,p.heightWindow/3+140);
 placer_texte(&position_quitter,p.widthWindow/3,p.heightWindow/3+210);
 placer_texte(&position_titre,p.widthWindow/2-664/2,0);
 placer_texte(&position_image,0,p.heightWindow-59);
 position_perso.x=0;
 position_perso.y=p.heightWindow-100;

 Jouer=TTF_RenderText_Blended(police_jouer,"> jouer",couleurBlanche);
 Continuer=TTF_RenderText_Blended(police_continuer,"> continuer",couleurBlanche);
 Instructions=TTF_RenderText_Blended(police_instructions,"> instructions",couleurBlanche);
 Quitter=TTF_RenderText_Blended(police_quitter,"> quitter",couleurBlanche);
 Titre=IMG_Load("data/menu/crazy_maze.bmp");
 image_bas=IMG_Load("data/menu/brique.bmp");
 image_bas=SDL_ResizeXY (image_bas,p.widthWindow,70,1);
 SDL_Surface *perso_marcheg=NULL,*perso_marched=NULL;
 perso_marcheg=IMG_Load("data/character/perso_marchedd.png");
 perso_marched=IMG_Load("data/character/perso_marchedg.png");

 int envie_de_jouer=0;
 int continuer=1;
 int marcher=0;
 SDL_Event event;
 int instruct=1;
 while (continuer)
 {
   SDL_WaitEvent(&event);
   switch(event.type)
   {
     case SDL_QUIT:
     continuer=0;
     *choix=-1;
     break;

     case SDL_MOUSEBUTTONUP:
         if (event.button.button == SDL_BUTTON_LEFT)
         {
            if(event.button.x>=position_jouer.x && event.button.x<=position_jouer.x+250 &&
               event.button.y>=position_jouer.y+20 && event.button.y<=position_jouer.y+70)
              {
                *choix=0;
                 continuer=0; // si on appuie sur jouer
                 envie_de_jouer=1;
                 page_chargement(ecran,p,1);
              }
               else if (event.button.x>=position_instructions.x && event.button.x<=position_instructions.x+250 &&
                       event.button.y>=position_instructions.y+20 && event.button.y<=position_instructions.y+70)
             {
                      int v=0;
                     while (instruct)
                     {
                     donner_instruction(ecran,&instruct,p,&continuer);
                     }
                    instruct=1;

             }
                 else if (event.button.x>=position_continuer.x && event.button.x<=position_continuer.x+250 &&
                       event.button.y>=position_continuer.y+20 && event.button.y<=position_continuer.y+70)
             {
                 if (sauvegarde(mp,&p)!=-1)
                 {
                 *choix=sauvegarde(mp,&p);
                 }
                 continuer=0;
             }
              else if(event.button.x>=position_quitter.x && event.button.x<=position_quitter.x+250 &&
               event.button.y>=position_quitter.y+20 && event.button.y<=position_quitter.y+70)
               {
                 *choix=-1;
                 continuer=0;
               }
         }
         break;
      case SDL_MOUSEMOTION:

            if(event.button.x>=position_jouer.x && event.button.x<=position_jouer.x+250 &&
                event.button.y>=position_jouer.y+20 && event.button.y<=position_jouer.y+70)
              {
                changer_police(&Jouer,"> jouer");

              }
              else if (event.button.x>=position_continuer.x && event.button.x<=position_continuer.x+250 &&
                       event.button.y>=position_continuer.y+20 && event.button.y<=position_continuer.y+70)
             {
                 changer_police(&Continuer,"> continuer");

             }
             else if (event.button.x>=position_instructions.x && event.button.x<=position_instructions.x+250 &&
                       event.button.y>=position_instructions.y+20 && event.button.y<=position_instructions.y+70)
             {
                 changer_police(&Instructions,"> instructions");

             }
             else if (event.button.x>=position_quitter.x && event.button.x<=position_quitter.x+250 &&
                       event.button.y>=position_quitter.y+20 && event.button.y<=position_quitter.y+70)
             {
                  changer_police(&Quitter,"> quitter");

             }
             else
             {
                mettre_texte_normal(&Jouer,"> jouer");
                mettre_texte_normal(&Continuer,"> continuer");
                mettre_texte_normal(&Instructions,"> instructions");
                mettre_texte_normal(&Quitter,"> quitter");

             }


     break;

   }
   if (envie_de_jouer==0)
   {
   SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,120,0,0));
   position_titre.x=p.widthWindow/2-664/2;
   position_titre.y=0;
   SDL_SetColorKey(Titre,SDL_SRCCOLORKEY,SDL_MapRGB(ecran->format,0,0,0));
   SDL_BlitSurface(Titre,NULL,ecran,&position_titre);
   SDL_BlitSurface(image_bas,NULL,ecran,&position_image);
   SDL_BlitSurface(Jouer,NULL,ecran,&position_jouer);
   SDL_BlitSurface(Continuer,NULL,ecran,&position_continuer);
   SDL_BlitSurface(Instructions,NULL,ecran,&position_instructions);
   SDL_BlitSurface(Quitter,NULL,ecran,&position_quitter);
   marche(ecran,&marcher,&position_perso, perso_marcheg, perso_marched,p);
   }

   SDL_Flip(ecran);

 }
 SDL_FreeSurface(perso_marcheg);
 SDL_FreeSurface(perso_marched);
 SDL_FreeSurface(Jouer);
 SDL_FreeSurface(Quitter);
 SDL_FreeSurface(Instructions);
 SDL_FreeSurface(Continuer);
 SDL_FreeSurface(Titre);
 SDL_FreeSurface(image_bas);

 TTF_CloseFont(police_jouer);
 TTF_CloseFont(police_continuer);
 TTF_CloseFont(police_instructions);
 TTF_CloseFont(police_quitter);
 TTF_Quit();
}

void placer_texte(SDL_Rect *position,int x,int y)
{
 (*position).x=x;
 (*position).y=y;
}

void page_chargement(SDL_Surface *ecran,paramStruct p,int indice)
{
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,120,0,0));
    SDL_Rect position;
    SDL_Surface *perso,*chargement,*titre,*image_bas;
    SDL_Rect position_titre;
    SDL_Rect position_image;

    titre=IMG_Load("data/menu/crazy_maze.bmp");
    image_bas=IMG_Load("data/menu/brique.bmp");
    placer_texte(&position_titre,p.widthWindow/2-664/2,0);
    placer_texte(&position_image,0,p.heightWindow-59);
    image_bas=SDL_ResizeXY (image_bas,p.widthWindow,70,1);
    position.x=(p.widthWindow/3)-30;
    position.y=( p.heightWindow/3)+10;
    perso=IMG_Load("data/character/perso_debout.png");
    SDL_SetColorKey(perso,SDL_SRCCOLORKEY,SDL_MapRGB(ecran->format,255,255,255));
    SDL_BlitSurface(perso,NULL,ecran,&position);
    SDL_SetColorKey(titre,SDL_SRCCOLORKEY,SDL_MapRGB(ecran->format,0,0,0));
    SDL_BlitSurface(titre,NULL,ecran,&position_titre);
    SDL_BlitSurface(image_bas,NULL,ecran,&position_image);
    TTF_Font *police=NULL;
    police=TTF_OpenFont("data/police/brush.ttf",65);
    SDL_Color couleurNoir={255,255,255};
    position.x=(p.widthWindow/2.5)-50;
    position.y=(p.heightWindow/3);
    switch(indice)
    {
    case 1:
    chargement=TTF_RenderText_Blended(police,"chargement.",couleurNoir);
    break;
    case 2:
     chargement=TTF_RenderText_Blended(police,"chargement..",couleurNoir);
    break;
    case 3:
     chargement=TTF_RenderText_Blended(police,"chargement...",couleurNoir);
    break;
    }
     SDL_BlitSurface(chargement,NULL,ecran,&position);
     TTF_CloseFont(police);
     SDL_FreeSurface(perso);
     SDL_FreeSurface(chargement);
     SDL_FreeSurface(titre);
     SDL_FreeSurface(image_bas);

}

void changer_police(SDL_Surface **Texte,char *ecrit)
{
                TTF_Font *police=NULL;
                police=TTF_OpenFont("data/police/brush.ttf",70);
                SDL_Color couleur_rouge={255,255,255};
               (*Texte)=TTF_RenderText_Blended(police,ecrit,couleur_rouge);
               TTF_CloseFont(police);
}

void mettre_texte_normal(SDL_Surface **Texte,char *ecrit)
{
  TTF_Font *police=NULL;
  police=TTF_OpenFont("data/police/brush.ttf",65);
  SDL_Color couleurBlanche={255,255,255};
  (*Texte)=TTF_RenderText_Blended(police,ecrit,couleurBlanche);
  TTF_CloseFont(police);
}

void marche(SDL_Surface *ecran,int *a,SDL_Rect *pos,SDL_Surface *image1,SDL_Surface *image2,paramStruct p)
{
 switch (*a)
 {
    case 0:
    SDL_SetColorKey(image1,SDL_SRCCOLORKEY,SDL_MapRGB(ecran->format,255,255,255));
    SDL_BlitSurface(image1,NULL,ecran,pos);
    (*pos).x+=3;
    (*a)=1;
    break;
    case 1:
    SDL_SetColorKey(image2,SDL_SRCCOLORKEY,SDL_MapRGB(ecran->format,255,255,255));
    SDL_BlitSurface(image2,NULL,ecran,pos);
    (*a)=0;
    (*pos).x+=3;
    break;
 }
if ((*pos).x==p.widthWindow)
{
 (*pos).x=0;
}
}

void instruc(SDL_Surface *ecran)
{
 TTF_Font *police;
 SDL_Surface *texte;
 police=TTF_OpenFont("data/police/brush.ttf",45);
 SDL_Rect position;
}

int sauvegarde(mapStruct *mp,paramStruct *p)
{
 int i=0;
 for (i=0;i<p->nb_map;i++)
 {
   if (mp->success[i]==0)
   {
     return i;
   }
 }
 return -1;
}

void donner_instruction(SDL_Surface *ecran,int *instruc,paramStruct p,int *cont)
{
  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,120,0,0));
  SDL_Surface *titre=NULL,*texte=NULL,*image_bas=NULL;
  image_bas=IMG_Load("data/menu/brique.bmp");
  image_bas=SDL_ResizeXY (image_bas,p.widthWindow,70,1);
  SDL_Rect position_bas;
  placer_texte(&position_bas,0,p.heightWindow-59);
  SDL_BlitSurface(image_bas,NULL,ecran,&position_bas);
  SDL_Rect position_titre;
  placer_texte(&position_titre,p.widthWindow/2-664/2,0);
  titre=IMG_Load("data/menu/crazy_maze.bmp");

  SDL_Rect position_texte;
  position_texte.x=30;
  position_texte.y=200;
  SDL_SetColorKey(titre,SDL_SRCCOLORKEY,SDL_MapRGB(ecran->format,0,0,0));
  SDL_BlitSurface(titre,NULL,ecran,&position_titre);
  TTF_Font *police=NULL;
  SDL_Color couleurBlanche={255,255,255};
  police=TTF_OpenFont("data/police/brush.ttf",20);
  int a=0;
  SDL_Event event;
  int continuer=1;
  while (continuer)
  {


    SDL_PollEvent(&event);

     switch(event.type)
   {
     case SDL_QUIT:
      continuer=0;
      *instruc=0;
      *cont=0;
     break;

     case SDL_KEYDOWN:
       switch (event.key.keysym.sym)
          {
            case SDLK_l:
             continuer=0;
             *instruc=0;
            break;
          }
      break;
   }
   SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,120,0,0));
   SDL_BlitSurface(titre,NULL,ecran,&position_titre);
   SDL_BlitSurface(image_bas,NULL,ecran,&position_bas);
    texte=TTF_RenderText_Blended(police,"Le but du jeu est de trouver la sortie en un nombre de coup limite.Pour se diriger,",couleurBlanche);
  SDL_BlitSurface(texte,NULL,ecran,&position_texte);
  SDL_FreeSurface(texte);
  position_texte.y+=50;
  texte=TTF_RenderText_Blended(police,"utilisez fleches. Vous pouvez passer sur une brique que si vous avez la meme couleur ",couleurBlanche);
  SDL_BlitSurface(texte,NULL,ecran,&position_texte);
  SDL_FreeSurface(texte);

  position_texte.y+=50;
  texte=TTF_RenderText_Blended(police,"que cette derniere. Pour vous mettre respectivement en rouge, vert et bleu utilisez ",couleurBlanche);
   SDL_BlitSurface(texte,NULL,ecran,&position_texte);
  SDL_FreeSurface(texte);

   position_texte.y+=50;
  texte=TTF_RenderText_Blended(police,"les touches r,v et b. Vous pouvez passer sur les zones blanches quelque soit votre couleur.",couleurBlanche);
   SDL_BlitSurface(texte,NULL,ecran,&position_texte);
  SDL_FreeSurface(texte);

    position_texte.y+=50;
  texte=TTF_RenderText_Blended(police,"Attention, certaines zones blanches sont des pieges, il est impossible de les traverser",couleurBlanche);
   SDL_BlitSurface(texte,NULL,ecran,&position_texte);
  SDL_FreeSurface(texte);

  position_texte.y+=50;
  texte=TTF_RenderText_Blended(police,"Lorsque vous n'avez plus de coup, appuyez sur la touche l pour recommencer le niveau.",couleurBlanche);
  SDL_BlitSurface(texte,NULL,ecran,&position_texte);
  SDL_FreeSurface(texte);

  position_texte.y+=100;
  texte=TTF_RenderText_Blended(police,"Appuyez sur la touche l pour revenir au menu.",couleurBlanche);
  SDL_BlitSurface(texte,NULL,ecran,&position_texte);
  SDL_FreeSurface(texte);
  position_texte.y=200;
  continuer=0;
   SDL_Flip(ecran);
  }
  SDL_FreeSurface(image_bas);
  TTF_CloseFont(police);
  SDL_FreeSurface(titre);

}
