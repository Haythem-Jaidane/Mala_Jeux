#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "../header/menu_newgame.h"

void affichage(){

}

void affichage_button(){

}

void single_player(SDL_Surface *ecran,Mix_Chunk *son,TTF_Font *police,SDL_Color color,int *continuer)
{
SDL_Surface *background=NULL , *easy=NULL , *medium=NULL  ,*singleplayer=NULL , *easy1=NULL , *medium1=NULL  , *newgame1=NULL , *hard=NULL , *hard1=NULL ;
    SDL_Rect pos , easy_pos , medium_pos , hard_pos , singleplayer_pos ;
    SDL_Event event;
    int s=1,x,y;
   
    background=IMG_Load("assets/background/backflou.png");
    easy=IMG_Load("assets/bouton/easy.png");
    easy1=IMG_Load("assets/bouton/easy1.png");
    medium=IMG_Load("assets/bouton/meduim.png");
    medium1=IMG_Load("assets/bouton/meduim1.png");
    hard=IMG_Load("assets/bouton/hard.png");
    hard1=IMG_Load("assets/bouton/hard1.png");
    singleplayer=TTF_RenderText_Blended(police,"Single Game",color);
    
    pos.x=0;
    pos.y=0;
    easy_pos.x = 470;
    easy_pos.y = 250;
    medium_pos.x = 470;
    medium_pos.y = 350;
    hard_pos.x = 470;
    hard_pos.y = 450;
    
    
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
              	if((x>450)&&(x<750)&&(y>250)&&(y<300)){
   	            continue;
   	        }
   	        else if((x>450)&&(x<750)&&(y>350)&&(y<400)){
   	            continue;
   	        }
   	        else if((x>450)&&(x<750)&&(y>450)&&(y<500)){
   	            continue;
   	        }
   	        break;
   	    case SDL_MOUSEMOTION:
   	        SDL_GetMouseState(&x,&y);
   	         if((x>450)&&(x<750)&&(y>250)&&(y<300)){
   	            SDL_BlitSurface(easy1,NULL,ecran,&easy_pos);
   	            SDL_BlitSurface(medium,NULL,ecran,&medium_pos);
   	            SDL_BlitSurface(hard,NULL,ecran,&hard_pos);
   	        }
   	        else if((x>450)&&(x<750)&&(y>350)&&(y<400)){
   	            SDL_BlitSurface(easy,NULL,ecran,&easy_pos);
   	            SDL_BlitSurface(medium1,NULL,ecran,&medium_pos);
   	            SDL_BlitSurface(hard,NULL,ecran,&hard_pos);
   	        }
   	        else if((x>450)&&(x<750)&&(y>450)&&(y<500)){
   	            SDL_BlitSurface(easy,NULL,ecran,&easy_pos);
   	            SDL_BlitSurface(medium,NULL,ecran,&medium_pos);
   	            SDL_BlitSurface(hard1,NULL,ecran,&hard_pos);
   	        }
   	        else{
   	            SDL_BlitSurface(easy,NULL,ecran,&easy_pos);
   	            SDL_BlitSurface(medium,NULL,ecran,&medium_pos);
   	            SDL_BlitSurface(hard,NULL,ecran,&hard_pos);
   	        }
   	        break;
   	    
   	}
   	SDL_Flip(ecran);
   }
   SDL_FreeSurface(background);
   SDL_FreeSurface(easy);
   SDL_FreeSurface(easy1);
   SDL_FreeSurface(medium);
   SDL_FreeSurface(medium1);
   SDL_FreeSurface(hard);
   SDL_FreeSurface(hard1);
   SDL_FreeSurface(singleplayer);


}

void multiplayer(){

}

void menu_newgame(SDL_Surface *ecran,int *continuer,Mix_Chunk *son,TTF_Font *police,SDL_Color color){
    SDL_Surface *background=NULL , *singleplayer=NULL , *multiplayer=NULL , *return_menu=NULL , *newgame=NULL , *singleplayer1=NULL , *multiplayer1=NULL , *return_menu1=NULL , *newgame1=NULL ,*text=NULL;
    SDL_Rect pos , single_pos , multi_pos , return_pos , newgame_pos ,pos_text;
    SDL_Event event;
    int s=1,x,y;
   
    background=IMG_Load("assets/background/backflou.png");
    singleplayer=IMG_Load("assets/bouton/singleplayer.png");
    singleplayer1=IMG_Load("assets/bouton/singleplayer1.png");
    multiplayer=IMG_Load("assets/bouton/multiplayer.png");
    multiplayer1=IMG_Load("assets/bouton/multiplayer1.png");
    return_menu=IMG_Load("assets/bouton/return.png");
    return_menu1=IMG_Load("assets/bouton/return1.png");
    text=TTF_RenderText_Blended(police,"NEW GAME",color);
    
    pos.x=0;
    pos.y=0;
    pos_text.x=400;
    pos_text.y=100;
    single_pos.x = 470;
    single_pos.y = 250;
    multi_pos.x = 470;
    multi_pos.y = 350;
    return_pos.x = 470;
    return_pos.y = 450;
    
    
    while(s){
        SDL_BlitSurface(background,NULL,ecran,&pos);
        SDL_BlitSurface(text,NULL,ecran,&pos_text);
   	SDL_PollEvent(&event);
   	switch(event.type){
   	    case SDL_QUIT:
   	        s=0;
   	        *continuer=0;
   	        break;
   	    case SDL_MOUSEBUTTONDOWN:
   	        Mix_PlayChannel(1,son,0);
   	        SDL_GetMouseState(&x,&y);
              	if((x>450)&&(x<750)&&(y>250)&&(y<300)){
   	            single_player(ecran,son,police,color,continuer);
   	        }
   	        else if((x>450)&&(x<750)&&(y>4350)&&(y<400)){
   	            continue;
   	        }
   	        else if((x>450)&&(x<750)&&(y>450)&&(y<500)){
   	            s=0;
   	        }
   	        break;
   	    case SDL_MOUSEMOTION:
   	        SDL_GetMouseState(&x,&y);
   	         if((x>450)&&(x<750)&&(y>250)&&(y<300)){
   	            SDL_BlitSurface(singleplayer1,NULL,ecran,&single_pos);
   	            SDL_BlitSurface(multiplayer,NULL,ecran,&multi_pos);
   	            SDL_BlitSurface(return_menu,NULL,ecran,&return_pos);
   	        }
   	        else if((x>450)&&(x<750)&&(y>350)&&(y<400)){
   	            SDL_BlitSurface(singleplayer,NULL,ecran,&single_pos);
   	            SDL_BlitSurface(multiplayer1,NULL,ecran,&multi_pos);
   	            SDL_BlitSurface(return_menu,NULL,ecran,&return_pos);
   	        }
   	        else if((x>450)&&(x<750)&&(y>450)&&(y<500)){
   	            SDL_BlitSurface(singleplayer,NULL,ecran,&single_pos);
   	            SDL_BlitSurface(multiplayer,NULL,ecran,&multi_pos);
   	            SDL_BlitSurface(return_menu1,NULL,ecran,&return_pos);
   	        }
   	        else{
   	            SDL_BlitSurface(singleplayer,NULL,ecran,&single_pos);
   	            SDL_BlitSurface(multiplayer,NULL,ecran,&multi_pos);
   	            SDL_BlitSurface(return_menu,NULL,ecran,&return_pos);
   	        }
   	        break;
   	    
   	}
   	SDL_Flip(ecran);
   }
   SDL_FreeSurface(background);
   SDL_FreeSurface(singleplayer);
   SDL_FreeSurface(singleplayer1);
   SDL_FreeSurface(multiplayer);
   SDL_FreeSurface(multiplayer1);
   SDL_FreeSurface(return_menu);
   SDL_FreeSurface(return_menu1);
   SDL_FreeSurface(text);
   
}

