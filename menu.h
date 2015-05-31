#include "main.h"
#include <SDL/SDL_ttf.h>
void charger_menu (SDL_Surface *ecran,paramStruct p,int *choix,mapStruct *mp);
void page_chargement(SDL_Surface *ecran,paramStruct ,int indice);
void changer_police(SDL_Surface **Texte,char *ecrit);
void mettre_texte_normal(SDL_Surface **Texte,char *ecrit);
void placer_texte(SDL_Rect *position,int x,int y);
void grossir(TTF_Font *police);
void marche(SDL_Surface *ecran,int *a,SDL_Rect *pos,SDL_Surface *image1,SDL_Surface *image2,paramStruct p);
void instruc(SDL_Surface *ecran);
int sauvegarde(mapStruct *mp,paramStruct *p);
void donner_instruction(SDL_Surface *ecran,int *instruc,paramStruct p,int *d);
