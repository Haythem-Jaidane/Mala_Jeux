#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "../header/menu_option.h"

void affiche(){
}

/*void modifier_son(SDL_Surface *ecran,int *continuer,int *screen,Mix_Chunk *son){
    SDL_Surface *option_background = NULL , *image_Sound_on = NULL , *image_Sound_off = NULL,*image_sound_level0 = NULL,*image_sound_level20 = NULL ;
    SDL_Surface  *image_sound_level50 = NULL ,*image_sound_level100 = NULL , *image_sound_level = NULL ,*texte =NULL ;
    SDL_Rect position_soundon , position_soundoff  , position_Level_up_sound , position_Level_down_sound , Var_Cadre , position_sound_level , position_texte  ;
    SDL_Event event;	
    image_Sound_on=IMG_Load("assets/button/soundon.jpg");
    image_Sound_off=IMG_Load("assets/bouton/soundoff.jpg");
    image_sound_level50=IMG_Load("assets/bouton/3.jpg");
    image_sound_level100=IMG_Load("assets/bouton/5.jpg");	
		
    position_soundon.x = 100;
    position_soundon.y = 350;
    position_soundoff.x = 235;
    position_soundoff.y = 355;
    position_Level_up_sound.x=450;
    position_Level_up_sound.y=200;
    int svar,sound;
    switch(event.type){		
        case SDL_MOUSEBUTTONUP :
            SDL_PollEvent(&event);
	    if(event.motion.x > position_soundon.x && event.motion.x < position_soundon.x+100  && event.motion.y > position_soundon.y && event.motion.y < position_soundon.y+99){	
	        Mix_PlayChannel(-1,son,0);
		if (sound == 0){
		    svar = 1 ;
		    Mix_VolumeMusic(MIX_MAX_VOLUME / svar); //Mix_ResumeMusic();
		  //image_sound_level = image_sound_level100 ;
		    sound = 1 ;
		}
					}	
	    if (event.motion.x > position_soundoff.x && event.motion.x < position_soundoff.x + 100 && event.motion.y > position_soundoff.y && event.motion.y < position_soundoff.y +84){ 	
	        Mix_PlayChannel(-1,son,0);
		if (sound == 1){
		    svar = 100 ;
		    Mix_VolumeMusic(MIX_MAX_VOLUME / svar); //Mix_PauseMusic();
		  //image_sound_level = image_sound_level0 ;
		    sound = 0 ;
		}

            }
            if (event.motion.x > position_Level_down_sound.x && event.motion.x < position_Level_down_sound.x + 75  && event.motion.y > position_Level_down_sound.y && event.motion.y < position_Level_down_sound.y + 55){ 	
                Mix_PlayChannel(-1,son,0);
		 if (svar == 1 ){
		    svar = 50 ;
		    Mix_VolumeMusic(MIX_MAX_VOLUME / svar);
		    image_sound_level = image_sound_level50 ; 	
							}
						
		    if (svar == 2 )
							{
						svar = 25 ;
						Mix_VolumeMusic(MIX_MAX_VOLUME / svar); 
						image_sound_level = image_sound_level20 ; 	
							}

						if (svar == 3 )
							{
						svar = 100 ;
						Mix_VolumeMusic(MIX_MAX_VOLUME / svar); 
						image_sound_level = image_sound_level0 ; 	
							}
					
					}
				if (event.motion.x > position_Level_up_sound.x && event.motion.x < position_Level_up_sound.x+ 103  && event.motion.y > position_Level_up_sound.y && event.motion.y < position_Level_up_sound.y + 55 )
					{ 	Mix_PlayChannel(-1,son,0);
						if (svar == 100 )
							{
						svar = 25 ;
						Mix_VolumeMusic(MIX_MAX_VOLUME / svar); 
						image_sound_level = image_sound_level20 ;	
							}
						
						if (svar == 3 )
							{
						svar = 50 ;
						image_sound_level = image_sound_level50 ;
						Mix_VolumeMusic(MIX_MAX_VOLUME / svar); 	
							}

						if (svar == 2 )
							{
						svar = 1 ;
						image_sound_level = image_sound_level100 ;
						Mix_VolumeMusic(MIX_MAX_VOLUME / svar); 	
							}
					}
				
		SDL_BlitSurface(image_sound_level,NULL,ecran,&position_Level_up_sound);
		SDL_Flip(ecran);
			
    }
}*/

void full_screen(SDL_Surface *ecran){
    ecran=SDL_SetVideoMode(1360, 768, 32, SDL_FULLSCREEN);
}

void simple_screen(SDL_Surface *ecran){
    ecran=SDL_SetVideoMode(1219, 914, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
}

void menu_option(SDL_Surface *ecran,int *continuer,int *screen,Mix_Chunk *son,TTF_Font *police,SDL_Color color){
    SDL_Surface  *image_sound_level0 =NULL,*image_sound_level50 = NULL ,*image_sound_level100 = NULL , *image_sound_level = NULL;
    SDL_Surface *background=NULL, *FULLSCREEN=NULL, *FULLSCREEN1=NULL, *NormalScreen=NULL, *NormalScreen1=NULL; 
    SDL_Surface *return_menu=NULL, *return_menu1=NULL, *option=NULL;
    SDL_Rect pos,full_pos,normal_pos,return_pos,option_pos,position_Level_up_sound;
    SDL_Event event;
    int s=1,x,y,m=3;
   
    background=IMG_Load("assets/background/backflou.png");
    FULLSCREEN=IMG_Load("assets/bouton/fullscreen.png");
    FULLSCREEN1=IMG_Load("assets/bouton/fullscreen1.png");
    NormalScreen=IMG_Load("assets/bouton/normalscreen.png");
    NormalScreen1=IMG_Load("assets/bouton/normalscreen1.png");
    return_menu=IMG_Load("assets/bouton/return.png");
    return_menu1=IMG_Load("assets/bouton/return1.png");
    image_sound_level0=IMG_Load("assets/bouton/1.png");
    image_sound_level100=IMG_Load("assets/bouton/5.png");
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
    position_Level_up_sound.x=275;
    position_Level_up_sound.y=100;
    
    image_sound_level=image_sound_level0;
    
    while(s){
        SDL_BlitSurface(background,NULL,ecran,&pos);
        SDL_BlitSurface(option,NULL,ecran,&option_pos);
        SDL_BlitSurface(image_sound_level,NULL,ecran,&position_Level_up_sound);
        switch(m){
            case 0:
   	        SDL_BlitSurface(FULLSCREEN1,NULL,ecran,&full_pos);
   	        SDL_BlitSurface(NormalScreen,NULL,ecran,&normal_pos);
   	        SDL_BlitSurface(return_menu,NULL,ecran,&return_pos);
                break;
            case 1:
   	         SDL_BlitSurface(FULLSCREEN,NULL,ecran,&full_pos);
   	         SDL_BlitSurface(NormalScreen1,NULL,ecran,&normal_pos);
   	         SDL_BlitSurface(return_menu,NULL,ecran,&return_pos);
                break;
            case 2:
   	        SDL_BlitSurface(FULLSCREEN,NULL,ecran,&full_pos);
   	        SDL_BlitSurface(NormalScreen,NULL,ecran,&normal_pos);
   	        SDL_BlitSurface(return_menu1,NULL,ecran,&return_pos);
                break;
            case 3:
            	
   	        SDL_BlitSurface(FULLSCREEN,NULL,ecran,&full_pos);
   	        SDL_BlitSurface(NormalScreen,NULL,ecran,&normal_pos);
   	        SDL_BlitSurface(return_menu,NULL,ecran,&return_pos);
                break;
        }
   	SDL_PollEvent(&event);
   	switch(event.type){
   	    case SDL_QUIT:
   	        s=0;
   	        *continuer=0;
   	        break;
   	    case SDL_KEYDOWN:
   	        if(event.key.keysym.sym==SDLK_LEFT){
   	            image_sound_level=image_sound_level0;
   	            Mix_VolumeMusic(0);
   	        }
   	        if(event.key.keysym.sym==SDLK_RIGHT){
   	            image_sound_level=image_sound_level100;
   	            Mix_VolumeMusic(MIX_MAX_VOLUME);
   	        }
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
   	            m=0;
   	        }
   	        else if((x>650)&&(x<950)&&(y>400)&&(y<450)&&(*screen==2)){
   	            m=1;
   	        }
   	        else if((x>475)&&(x<775)&&(y>500)&&(y<550)){
   	            m=2;
   	        }
   	        else{
   	            m=3;
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
   //SDL_FreeSurface(image_sound_level);
   SDL_FreeSurface(image_sound_level0);
   //SDL_FreeSurface(image_sound_level50);
   SDL_FreeSurface(image_sound_level100);
   SDL_FreeSurface(option);
   
}
