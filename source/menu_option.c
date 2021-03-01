#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "../header/menu_option.h"

void affiche(){
}

void modifier_son(){
}

void full_screen(SDL_Surface *ecran){
    ecran=SDL_SetVideoMode(1360, 768, 32, SDL_FULLSCREEN);
}

void simple_screen(SDL_Surface *ecran){
    ecran=SDL_SetVideoMode(1219, 914, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
}

void menu_option(SDL_Surface *ecran,int *continuer,int *screen,Mix_Chunk *son,TTF_Font *police,SDL_Color color){

    SDL_Surface *background=NULL, *FULLSCREEN=NULL, *FULLSCREEN1=NULL, *NormalScreen=NULL, *NormalScreen1=NULL; 
    SDL_Surface *return_menu=NULL, *return_menu1=NULL, *option=NULL; 
    SDL_Rect pos,full_pos,normal_pos,return_pos,option_pos;
    SDL_Event event;
    int s=1,x,y;
   
    background=IMG_Load("assets/background/backflou.png");
    FULLSCREEN=IMG_Load("assets/bouton/fullscreen.png");
    FULLSCREEN1=IMG_Load("assets/bouton/fullscreen1.png");
    NormalScreen=IMG_Load("assets/bouton/normalscreen.png");
    NormalScreen1=IMG_Load("assets/bouton/normalscreen1.png");
    return_menu=IMG_Load("assets/bouton/return.png");
    return_menu1=IMG_Load("assets/bouton/return1.png");
    option=TTF_RenderText_Blended(police,"OPTION",color);
    
    pos.x=0;
    pos.y=0;
    option_pos.x=450;
    option_pos.y=100;
    full_pos.x=300;
    full_pos.y=400;
    normal_pos.x=650;
    normal_pos.y=400;
    return_pos.x=475;
    return_pos.y=500;
    
    
    while(s){
        SDL_BlitSurface(background,NULL,ecran,&pos);
        SDL_BlitSurface(option,NULL,ecran,&option_pos);
   	SDL_PollEvent(&event);
   	switch(event.type){
   	    case SDL_QUIT:
   	        s=0;
   	        *continuer=0;
   	        break;
   	    case SDL_MOUSEBUTTONDOWN:
   	        Mix_PlayChannel(1,son,0);
   	        SDL_GetMouseState(&x,&y);
   	        if((x>300)&&(x<600)&&(y>400)&&(y<450)&&(*screen==1)){
   	            *screen=2;
   	            full_screen(ecran);
   	        }
   	        else if((x>650)&&(x<950)&&(y>400)&&(y<450)&&(*screen==2)){
   	            *screen=1;
   	            simple_screen(ecran);
   	        }
   	        else if((x>475)&&(x<775)&&(y>500)&&(y<550)){
   	            s=0;
   	        }
   	        break;
   	    case SDL_MOUSEMOTION:
   	        SDL_GetMouseState(&x,&y);
   	        if((x>300)&&(x<600)&&(y>400)&&(y<450)&&(*screen==1)){
   	            SDL_BlitSurface(FULLSCREEN1,NULL,ecran,&full_pos);
   	            SDL_BlitSurface(NormalScreen,NULL,ecran,&normal_pos);
   	            SDL_BlitSurface(return_menu,NULL,ecran,&return_pos);
   	        }
   	        else if((x>650)&&(x<950)&&(y>400)&&(y<450)&&(*screen==2)){
   	            SDL_BlitSurface(FULLSCREEN,NULL,ecran,&full_pos);
   	            SDL_BlitSurface(NormalScreen1,NULL,ecran,&normal_pos);
   	            SDL_BlitSurface(return_menu,NULL,ecran,&return_pos);
   	        }
   	        else if((x>475)&&(x<775)&&(y>500)&&(y<550)){
   	            SDL_BlitSurface(FULLSCREEN,NULL,ecran,&full_pos);
   	            SDL_BlitSurface(NormalScreen,NULL,ecran,&normal_pos);
   	            SDL_BlitSurface(return_menu1,NULL,ecran,&return_pos);
   	        }
   	        else{
   	            SDL_BlitSurface(FULLSCREEN,NULL,ecran,&full_pos);
   	            SDL_BlitSurface(NormalScreen,NULL,ecran,&normal_pos);
   	            SDL_BlitSurface(return_menu,NULL,ecran,&return_pos);
   	        }
   	        break;
   	    
   	}
   	SDL_Flip(ecran);
   }
   SDL_FreeSurface(background);
   SDL_FreeSurface(FULLSCREEN);
   SDL_FreeSurface(FULLSCREEN1);
   SDL_FreeSurface(NormalScreen);
   SDL_FreeSurface(NormalScreen1);
   SDL_FreeSurface(return_menu);
   SDL_FreeSurface(return_menu1);
   SDL_FreeSurface(option);
   
}
