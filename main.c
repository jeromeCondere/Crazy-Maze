#include <stdio.h>
#include <stdlib.h>
#include"param.h"
#include"plateau.h"
int main()
{
SDL_Surface *ecran=NULL;
paramStruct param,*p;
mapStruct mapParam,*mp;



p=&param;
mp=&mapParam;
initParam(p,mp,"data/settings1.param",0);
printParam(&param);

int wpb=p->widthWindow/p->widthMap;
int hpb=p->heightWindow/p->heightMap;
printf("%d\n\n\¬",mp->success[0]);
ecran=SDL_SetVideoMode(param.widthWindow,param.heightWindow,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
if(ecran==NULL)
{
printf("il y eu une erreur lors du chargement");
exit(EXIT_FAILURE);
}

int choix=-1;
charger_menu(ecran,param,&choix,mp);
if (choix==0)
{
pause(ecran,&param,&mapParam,0);
}
else if (choix>0)
{
pause(ecran,&param,&mapParam,choix);
}
printf("%d",choix);
//freePlateau(plateau,&param);
freeMapParam(p,mp);

    return 0;
}
