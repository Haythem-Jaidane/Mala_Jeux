#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <unistd.h>
#include <string.h>
#include "header/menu_principal.h"
#include "header/menu_option.h"
#include "header/menu_newgame.h"

int main(){
    
    SDL_Surface *ecran=NULL, *text=NULL, *back=NULL, *back1=NULL, *new_game=NULL, *new_game1=NULL ;
    SDL_Surface *option=NULL, *option1=NULL,  *exit=NULL, *exit1=NULL,  *Load=NULL, *Load1=NULL;
    SDL_Rect positionFond,pos,pos1,pos2,pos3,pos_title;
    Mix_Music *theme=NULL;
    Mix_Chunk *son_bouton=NULL;
    SDL_Color gris={100, 100, 100};
    TTF_Font *police=NULL;
    SDL_Event event;
    
    initialisation();
    
    ecran = SDL_SetVideoMode(1219, 914, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    
    theme=Mix_LoadMUS("assets/music/music.mp3");
    son_bouton=Mix_LoadWAV("assets/music/son_bouton.wav");
    Mix_PlayMusic(theme,1);
    int continuer = 1,screen=1;
    
    new_game=IMG_Load("assets/bouton/new_game.png");
    new_game1=IMG_Load("assets/bouton/new_game1.png");
    option=IMG_Load("assets/bouton/options.png");
    option1=IMG_Load("assets/bouton/options1.png");
    Load=IMG_Load("assets/bouton/load.png");
    Load1=IMG_Load("assets/bouton/load1.png");
    exit=IMG_Load("assets/bouton/exit.png");
    exit1=IMG_Load("assets/bouton/exit1.png");

    
    positionFond.x = 0;
    positionFond.y = 0;
    pos.x = 470;
    pos.y = 250;
    pos2.x = 470;
    pos2.y = 350;
    pos1.x = 470;
    pos1.y = 450;
    pos3.x = 470;
    pos3.y = 550;
    pos_title.x=410;
    pos_title.y=100;
    
    
    police=TTF_OpenFont("assets/fonts/Monoton/Monoton-Regular.ttf",64);
    text=TTF_RenderText_Blended(police,"Mala  Jeux",gris);

    int i=0,x,y;
    while(continuer){
        animation_background(&i,back,ecran,&positionFond);
    	SDL_PollEvent(&event);
    	switch(event.type){
            case SDL_QUIT:
            	continuer = 0;
            	break;
            case SDL_KEYDOWN:
                
                if(event.key.keysym.sym==SDLK_j)
                {
                    bouton(new_game1,option,Load,exit,ecran,&pos,&pos1,&pos2,&pos3);
                    menu_newgame(ecran,&continuer,son_bouton);
                }
                else if(event.key.keysym.sym==SDLK_o)
                {
                    bouton(new_game,option1,Load,exit,ecran,&pos,&pos1,&pos2,&pos3);
                    menu_option(ecran,&continuer,&screen,son_bouton,police,gris);
        	 }
                else if(event.key.keysym.sym==SDLK_q)
                {
                    bouton(new_game,option,Load,exit1,ecran,&pos,&pos1,&pos2,&pos3);
                    continuer = 0;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                Mix_PlayChannel(1,son_bouton,0);
                SDL_GetMouseState(&x,&y);
            	if((x>450)&&(x<750)&&(y>250)&&(y<300)){
		    menu_newgame(ecran,&continuer,son_bouton);
            	}
            	else if((x>450)&&(x<750)&&(y>350)&&(y<400)){
            	    continue;
            	}
            	else if((x>450)&&(x<750)&&(y>450)&&(y<500)){
            	    menu_option(ecran,&continuer,&screen,son_bouton,police,gris);
            	}
            	else if((x>450)&&(x<750)&&(y>550)&&(y<600)){
            	    continuer = 0;
            	}
            	break;
            case SDL_MOUSEMOTION:
            	SDL_GetMouseState(&x,&y);
            	if((x>450)&&(x<750)&&(y>250)&&(y<300)){
            	    bouton(new_game1,option,Load,exit,ecran,&pos,&pos1,&pos2,&pos3);
            	}
            	else if((x>450)&&(x<750)&&(y>350)&&(y<400)){
            	    bouton(new_game,option,Load1,exit,ecran,&pos,&pos1,&pos2,&pos3);
            	}
            	else if((x>450)&&(x<750)&&(y>450)&&(y<500)){
            	    bouton(new_game,option1,Load,exit,ecran,&pos,&pos1,&pos2,&pos3);
            	}
            	else if((x>450)&&(x<750)&&(y>550)&&(y<600)){
            	    bouton(new_game,option,Load,exit1,ecran,&pos,&pos1,&pos2,&pos3);
            	}
            	else{
            	    bouton(new_game,option,Load,exit,ecran,&pos,&pos1,&pos2,&pos3);
            	}
            	SDL_BlitSurface(text,NULL,ecran,&pos_title);
            	SDL_Flip(ecran);
            	SDL_PollEvent(&event);
            	if(event.type==SDL_QUIT){
            	    continuer=0;
            	}
            	break;
        }
        SDL_FreeSurface(back);
        i++;
    }
    SDL_FreeSurface(text);
    SDL_FreeSurface(new_game);
    SDL_FreeSurface(option);
    SDL_FreeSurface(Load);
    SDL_FreeSurface(exit);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(ecran);
    Mix_FreeMusic(theme);
    Mix_FreeChunk(son_bouton);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}
