#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "../header/menu_newgame.h"

void affichage(){

}

void affichage_button(){

}

void single_player(){

}

void multiplayer(){

}

void menu_newgame(SDL_Surface *ecran,int *continuer,Mix_Chunk *son){
    SDL_Surface *background=NULL;
    SDL_Rect pos;
    SDL_Event event;
    int s=1,x,y;
   
    background=IMG_Load("assets/background/backflou.png");
    
    pos.x=0;
    pos.y=0;
    
    
    while(s){
        SDL_BlitSurface(background,NULL,ecran,&pos);
   	SDL_PollEvent(&event);
   	switch(event.type){
   	    case SDL_QUIT:
   	        s=0;
   	        *continuer=0;
   	        break;
   	    case SDL_MOUSEBUTTONDOWN:
   	        Mix_PlayChannel(1,son,0);
   	        SDL_GetMouseState(&x,&y);
   	        break;
   	    case SDL_MOUSEMOTION:
   	        SDL_GetMouseState(&x,&y);
   	        break;
   	    
   	}
   	SDL_Flip(ecran);
   }
   SDL_FreeSurface(background);
   
}

