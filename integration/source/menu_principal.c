#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "../header/menu_principal.h"

void initialisation(){
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
}

void bouton(SDL_Surface* new_game,SDL_Surface* option,
            SDL_Surface* scoreboard,SDL_Surface* exit,SDL_Surface* ecran,
            SDL_Rect *pos, SDL_Rect *pos1, 
            SDL_Rect *pos2, SDL_Rect *pos3){
    SDL_BlitSurface(new_game, NULL, ecran, pos);
    SDL_BlitSurface(option, NULL, ecran, pos1);
    SDL_BlitSurface(scoreboard, NULL, ecran, pos2);
    SDL_BlitSurface(exit,NULL,ecran,pos3);
}

void animation_background(int *frame, SDL_Surface* back,SDL_Surface* ecran,SDL_Rect *positionFond){
    
    char str1[30]="assets/background/back";
    char str[20] = "";
    
    if(*frame==11){
        *frame=0;
    }
    sprintf(str,"%d",*frame);
    strcat(str,".png");
    strcat(str1,str);
    back=IMG_Load(str1);
    SDL_BlitSurface(back, NULL, ecran, positionFond);
}
