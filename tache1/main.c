/**
*	@file main.c
*	@brief tester le programme 
*       @author haythem jaidane 
*       @version 0.6 
*       @date Apr 20, 2021 
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include "PP.h"

#define x_screen_size 1150
#define y_screen_size 914
#define mode 0

int main()
{
Personnage_Principal p[2] ;


//intialisation//
Uint32 dt, t_prev;
int continuer=1 , direction = 0 , acceleration=0 ,i;
const int FPS = 30;
Uint32 start;
Uint8 *keystate = NULL;
SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);
SDL_Surface *screen=NULL;
SDL_Surface *image=NULL;
SDL_Surface *background=NULL;
SDL_Rect position_bakcground ;
SDL_Event event;

position_bakcground.x = 0 ;
position_bakcground.y = 0 ;
if(SDL_Init(SDL_INIT_VIDEO)!=0){
    printf("impossible d'initialiser sdl :%s",SDL_GetError());
    return 1;
}
background=IMG_Load("back0.png") ;
screen =SDL_SetVideoMode(x_screen_size,y_screen_size, 32,SDL_HWSURFACE |SDL_DOUBLEBUF|SDL_RESIZABLE);
if(screen==NULL)
{ printf("Unable to set video mod :%s\n",SDL_GetError());
return 1;
}
if(TTF_Init() == -1)
{
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
}

SDL_BlitSurface(background,NULL,screen,&position_bakcground);

init(p,mode);

if(mode==1){
p[0].limite_min=0;
p[0].limite_max=x_screen_size/4;
p[1].limite_min=x_screen_size/2;
p[1].limite_max=x_screen_size*3/4;
}
else{
p[0].limite_min=0;
p[0].limite_max=x_screen_size/2;
}

while(continuer)
{	
SDL_PollEvent(&event);
start = SDL_GetTicks();
		switch(event.type)
			{

			case SDL_QUIT : 
			    continuer = 0 ; 
			    break ;

			case SDL_KEYDOWN :
			    keystate = SDL_GetKeyState(NULL);
			    if ( keystate[SDLK_d]){
			        p[0].Direction=1;
			        p[0].max_frame=8;
		                p[0].Mouvement=1;
			    }
			    else if( keystate[SDLK_q]){
			        p[0].Direction=2;
				p[0].max_frame=8;
				p[0].Mouvement=2;
			    }
			    if(keystate[SDLK_a]){
			        p[0].acceleration = 2;
			    }
			    if(keystate[SDLK_z]){
			        p[0].jump=1;
			        p[0].max_frame=7;
                                p[0].Mouvement=3;
			    }
			    if(mode==1){
			    	if ( keystate[SDLK_k]){
			            p[1].Direction=1;
			            p[1].max_frame=8;
		                    p[1].Mouvement=1;
			    	}
  			    	else if( keystate[SDLK_h]){
			            p[1].Direction=2;
				    p[1].max_frame=8;
				    p[1].Mouvement=2;
			        }
			        if(keystate[SDLK_y]){
			            p[1].acceleration = 2;
			    	}
			        if(keystate[SDLK_u]){
			            p[1].jump=1;
			            p[1].max_frame=7;
                                    p[1].Mouvement=3;
			    	}
			    }        
			       
				
			break ;
			}

mouvement_personnage(p,screen,background,position_bakcground,mode);
remis_a_zero(p,mode);	
if(1000/FPS > SDL_GetTicks()-start) {
    SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
}
}

TTF_Quit();
SDL_FreeSurface(image);
SDL_FreeSurface(background);
SDL_FreeSurface(screen);
SDL_Quit();
return 0;
}
