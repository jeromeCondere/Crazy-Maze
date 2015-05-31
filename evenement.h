#include "param.h"
#include<string.h>
#include <SDL/SDL_ttf.h>

enum couleur
{
 rouge,
 vert,
 bleu,
};
typedef enum couleur couleur;

enum touche
{
haut,
bas,
gauche,
droite
};
typedef enum touche touche;

typedef struct personnage
{
  SDL_Surface *image;
  SDL_Rect position;//pixel
  SDL_Rect positionPlateau;//plateau
  couleur  couleur_actuelle;
  int nbr_coup;
}personnage;
//void dynamique(SDL_Surface *image,couleur a,int indice);
void Avancer(SDL_Surface *ecran,paramStruct *p,personnage *actuelle,SDL_Surface ***matrice,char **matrice_lecture,SDL_Surface **s);
void Reculer(SDL_Surface *ecran,paramStruct *p,personnage *actuelle,SDL_Surface ***matrice,char **matrice_lecture,SDL_Surface **s);
void Droite(SDL_Surface *ecran,paramStruct *p,personnage *actuelle,SDL_Surface ***matrice,char **matrice_lecture,SDL_Surface **s);
void Gauche(SDL_Surface *ecran,paramStruct *p,personnage *actuelle,SDL_Surface ***matrice,char **matrice_lecture,SDL_Surface **s);
void charger_perso(SDL_Surface ***matrice,paramStruct*p);
void freematrice(SDL_Surface ***matrice);
SDL_Surface *chargement_personnage(SDL_Surface ***matrice,couleur a,touche b,int *indice);
void evenement(SDL_Surface *ecran,SDL_Surface ***matrice,paramStruct*p,mapStruct*mp,int level,SDL_Surface **s);
void pause(SDL_Surface *ecran,paramStruct*p,mapStruct*mp,int level);
SDL_Surface *changer_couleur(couleur c_actuelle,couleur c_achanger,SDL_Surface ***matrice,SDL_Surface *image_actuelle);
int trouver_sorti(personnage a,int *continuer,char **matrice_lecture,paramStruct *p);
void placer_encadre(SDL_Surface *ecran,int nbr_coup,paramStruct *p);
void ecrire_reussite(int level);
void depart(personnage *actuelle,char **matrice_lecture,paramStruct *p);
void montrer_niveau(SDL_Surface *ecran,int level,paramStruct p);
