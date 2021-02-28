#include <stdio.h>
#include <stdlib.h>

void affiche(){
}

void menu_exit(int *continuer){
   
   SDL_Surface *background=NULL, *yes=NULL, *no=NULL; 
   SDL_Event event;
   int s=1;
   
   /*Load_image
   
   */
   while(s){
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
