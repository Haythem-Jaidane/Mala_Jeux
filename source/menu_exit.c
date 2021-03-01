#include <stdio.h>
#include <stdlib.h>

void affiche(){
}

void menu_exit(int *continuer){
   
   SDL_Surface *background=NULL, *yes=NULL, *no=NULL;
   SDL_Rect pos;
   SDL_Event event;
   int s=1;
   
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
   	    case SDL_KEYDOWN:
   	        break;
   	    case SDL_MOUSEBUTTONDOWN:
   	        break;
   	    case SDL_MOUSEMOTION:
   	        break;
   	    
   	}
   }
   
}
