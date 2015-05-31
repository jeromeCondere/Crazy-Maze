#include"param.h"

char**lecture2(char*filename,paramStruct*p);
void freePlateau(char**plateau,paramStruct*p);
int loadLevel(paramStruct*p,mapStruct*mp,int level);//charge un niveau dans mp->activeLevel
int checkLevel(paramStruct*p,mapStruct*mp);
void freeLevel(paramStruct*p,mapStruct*mp);

