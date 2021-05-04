#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "sauvegarde.h"

int main(int argc, char const *argv[])
{
    SDL_Rect posperso,posenemi,camera;
    int sc;
//----------------------on ajoute des valeurs pour tester les fonctions------------//
    posperso.x =100;
    posperso.y=160;
    posenemi.x=10;
    posenemi.y=400;
    camera.x=300;
    camera.y=360;
    sc=259;
//---------------------------------------------------//  
printf("enregistrement ...\n")  ;
    sauvegarder(posperso,posenemi,sc,camera,"sauvegarde");

printf("\nlecture a partie du fichier");
    charger(&posperso,&posenemi,&sc,&camera,"sauvegarde");
    return 0;
}