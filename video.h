#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED
#include<SDL/SDL.h>

#include<stdlib.h>
#include<stdio.h>
#include"param.h"
#include"resize.h"

enum brick_type{
ROUGE,
VERT,
BLEU,
NOIR,
VIDE,
CLASSIC,
SORTIE,
ENTREE

};
typedef enum brick_type brick_type;
void carre_en_long(int x,int y,SDL_Surface *ecran,SDL_Surface *mur,SDL_Surface *fond_carre,int ind_couleur);
void dessiner_brique(int x,int y,SDL_Surface*ecran,SDL_Surface**briques, brick_type type);
void dessiner_map(SDL_Surface*ecran,char**plateau,paramStruct*p,SDL_Surface**briques);
void pause();
SDL_Surface**load_brick(paramStruct*param,SDL_Surface *ecran);
void free_brick(SDL_Surface**s);



#endif // VIDEO_H_INCLUDED
