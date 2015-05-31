#ifndef PARAM_H_INCLUDED
#define PARAM_H_INCLUDED
#include <SDL/SDL.h>
typedef struct {
char imgMapDirectory[60];
char imgCharacterDirectory[60];
}ImgDataStruct;


typedef struct{
 int heightMap;
 int widthMap;
char mapList[50];
 int heightWindow;
 int widthWindow;
ImgDataStruct ImgData;
int nb_map;
}paramStruct;

typedef struct{
char**mapList;
char**activeLevel;
int*success;
int*nb_coups;
int index_level;//indice du niveau actuel
}mapStruct;


paramStruct loadParam(char* filename);
char**loadMapList(paramStruct*p);
void freeMapList(char**l,paramStruct*p);
void printParam(paramStruct*p);
int loadMapParam(paramStruct*p,mapStruct*mp);
void freeMapParam(paramStruct*p,mapStruct*mp);
void printMapList(paramStruct*p,mapStruct*mp);
int initParam(paramStruct*p,mapStruct*mp,char*paramFile,int verbose);//initialiser les paramètres




#endif // PARAM_H_INCLUDED
