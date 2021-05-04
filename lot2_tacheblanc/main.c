#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "PP.h"
#include "es.h"

int main()
{

//intialisation//


Personnage_Principal p ;
Ennemy e;
box b;

int continuer=1 , direction = 0 , acceleration=0 , i , x=1 , sp=200;


Uint8 *keystate = NULL;
Uint32 dt, t_prev;

SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);
SDL_Surface *screen=NULL;
SDL_Surface *image=NULL;
SDL_Surface *background=NULL;
SDL_Rect position_bakcground ;
SDL_Event event;

position_bakcground.x = 0 ;
position_bakcground.y = 0 ;

if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("impossible d'initialiser sdl :%s",SDL_GetError());
return 1;
}

background=IMG_Load("back0.jpg") ;

screen =SDL_SetVideoMode(1200, 800, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);
if(screen==NULL)
{ 
printf("Unable to set video mod :%s\n",SDL_GetError());
return 1;
}

initPerso(&p);
initialiser(&e,"2.png");

srand(time(NULL));
int a=rand()%100;



while(continuer)
{
	//t_prev=SDL_GetTicks();




if (collision(&b,&e)==1)
	{
		
        break;
	}

SDL_PollEvent(&event);

		
		switch(event.type)
			{

			case SDL_QUIT : 
			    continuer = 0 ; 
			    break ;

			case SDL_KEYDOWN :
			    keystate = SDL_GetKeyState(NULL);
			    if ( keystate[SDLK_d]){
			        p.Direction=1;
			        p.max_frame=8;
		                p.Mouvement=1;
			    }
			    else if( keystate[SDLK_q]){
			        p.Direction=2;
				p.max_frame=8;
				p.Mouvement=1;
			    }
			    if(keystate[SDLK_a]){
			        p.acceleration = 3;
			    }
			    if(keystate[SDLK_z]){
			        p.jump=1;
			        p.max_frame=7;
                                p.Mouvement=3;
			    }
				        
			       
				
			break ;
			}

SDL_BlitSurface(background,NULL,screen,&position_bakcground);


mouvement_personnage(&p,screen,background,position_bakcground);
if(p.Position_intiale.x > 400)
{
afficher(&e,screen,image,&sp);
animation(&e,screen);
deplacement(&e,&sp,&x,screen,&a);	
}
SDL_Flip(screen);


p.Direction=0;
p.max_frame=1;
p.Mouvement=0;	
p.acceleration=1;
p.jump=0;
//dt=SDL_GetTicks()-t_prev;	
}



return 0;
}
