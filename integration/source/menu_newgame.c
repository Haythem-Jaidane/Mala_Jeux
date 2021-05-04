#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "../header/menu_newgame.h"
#include "../header/scrolling.h"
#include "../header/PP.h"
#include "../header/fml.h"
#include "../header/collision.h"
#include "../header/minimap.h"
#include "../header/temps.h"
#include "../header/enig.h"

/*void affichage(){

}*/

void affichage_button(){

}

void single_player(SDL_Surface *ecran,Mix_Chunk *son,TTF_Font *police,SDL_Color color,int *continuer)
{
SDL_Surface *background=NULL , *easy=NULL , *medium=NULL  ,*singleplayer=NULL , *easy1=NULL , *medium1=NULL  , *newgame1=NULL , *hard=NULL , *hard1=NULL ,*mask=NULL,*easy0=NULL , *medium0=NULL,*hard0=NULL;
    SDL_Rect pos , easy_pos , medium_pos , hard_pos , singleplayer_pos ;
    SDL_Event event;
    int s=1,x,y;
    int level=0;
    Uint8 *keystate = NULL;

    int r=1;
    int sp=200;
    char image[30]="";
    int alea,running=1,so,si;

    Personnage_Principal p[2];
    Objet map,wood,boat,map2,failed,perso;
    Ennemy e;
    box b;
    minimap m;
    enigme  en;

    srand(time(NULL));

    SDL_Rect camera;
    camera.x=0;
    camera.y=0;
    camera.w=1300;
    camera.h=700;

    mask=IMG_Load("stage1Mask.bmp");
    init_map (&m);

    p[0].limite_min=0;
    p[0].limite_max=1024/2;
   
    background=IMG_Load("assets/background/backflou.png");
    easy=IMG_Load("assets/bouton/easy.png");
    easy1=IMG_Load("assets/bouton/easy1.png");
    medium=IMG_Load("assets/bouton/meduim.png");
    medium1=IMG_Load("assets/bouton/meduim1.png");
    hard=IMG_Load("assets/bouton/hard.png");
    hard1=IMG_Load("assets/bouton/hard1.png");
    //singleplayer=TTF_RenderText_Blended(police,"Single Game",color);

    mask=SDL_LoadBMP("stage1Mask.bmp");
    
    pos.x=0;
    pos.y=0;
    easy_pos.x = 470;
    easy_pos.y = 250;
    medium_pos.x = 470;
    medium_pos.y = 350;
    hard_pos.x = 470;
    hard_pos.y = 450;

    temps t;
    
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
		    level=1;
   	        }
   	        else if((x>450)&&(x<750)&&(y>350)&&(y<400)){
   	            level=2;
   	        }
   	        else if((x>450)&&(x<750)&&(y>450)&&(y<500)){
   	            level=3;
   	        }
		init(p,0);
		initialiser_ennemy(&e,"2.png");
		initialiser (&perso,&map ,&wood ,&boat,&map2,&failed) ;
		initialiser_temps(&t);
                init_enigme(&en);
  		setup (ecran,&map ,&wood,&boat,&map2,&perso) ;
		afficherPerso(p[0],ecran);
		SDL_Flip(ecran);
		while(level){
			SDL_Event event;

  			SDL_PollEvent(&event);

  			switch (event.type){
  				case SDL_QUIT:
				     s=0;
   	        		     *continuer=0;
    				     level = 0;
    				     break;
  				case SDL_KEYDOWN:

    					keystate = SDL_GetKeyState(NULL);

    						if(keystate[SDLK_RIGHT]){ // Flèche droite
							
							if(p[0].Position_intiale.x>p[0].limite_max-50){
      							    scrolling_droit(ecran, &map2, &pos, &boat);
							    p[0].Position_intiale.x=p[0].Position_intiale.x-10;
							}
							p[0].Direction=1;
			        			p[0].max_frame=8;
		                			p[0].Mouvement=1;
							
						}

    						else if(keystate[SDLK_LEFT]){ // Flèche gauche
      							scrolling_gauche(ecran, &map2, &pos, &boat);
							p[0].Direction=2;
							p[0].max_frame=8;
							p[0].Mouvement=2;

      						}
						if(keystate[SDLK_UP]){
			        			p[0].jump=1;
			        			p[0].max_frame=7;
                                			p[0].Mouvement=3;
			    			}
						if(keystate[SDLK_SPACE]){
			        			p[0].acceleration = 2;
			    			}
  
    					break;
  				}
				if(map2.pos.x>3800){
				    generate_afficher ( ecran  , image ,&en,&alea) ;


      				    s=solution_e (image );
				    do{
					r=resolution (&running,&s);
				    }while((r>3 || r<1) && running!=0) ;


      				while(running){

				afficher_resultat (ecran,so,si,&en) ;
			       	SDL_WaitEvent(&event);
                     		switch(event.type)
                       		{
					     case SDL_QUIT :
                              			      running =0 ;
						      s=0;
   	        		     		      *continuer=0;
    				                      level = 0;
					              break ;
                                              case SDL_KEYDOWN :

                             			switch( event.key.keysym.sym )
                                  		{
			                        case  SDLK_ESCAPE:
			                           running= 0 ;
			                           break ;
			                         }
						 break ;
                                 }
                                }
                            }
				
				int i=0;
					p[0].frame=0;
    					while(i<p[0].max_frame){
						if(i<p[0].max_frame){
            						animerPerso(&p[0]);
        						if(p[0].jump){
            						    saut(&p[0],mask,map2.pos);   
        						}
        						else{
            						    deplacerPerso(&p[0],mask,map2.pos) ;
        						}
						}
        					affichage(ecran, &boat, &wood, &map, &map2,&perso);
						afficherminimap(m,ecran,&camera);
						afficher_temps(&t, ecran);
						if((map2.pos.x+1219>2000)&&(map2.pos.x<2400)){
						    if((collision_parfaite_right(mask,e.pos)==1)||(collision_parfaite_left(mask,e.pos)==1)){
							if(r==1)
							    r=-1;
							else
							    r=1;
						    }
						    animation(&e,ecran);
						    deplacement(&e,&sp,&r,ecran);
                                                    afficher(&e,ecran);
						}
        					afficherPerso(p[0],ecran);
						MAJMinimap(p[0].Position_intiale ,&m, camera, 20);
						
        					SDL_Flip(ecran);
						
						i++;
					}
				remis_a_zero(p,0);
			}
   	        break;
   	    case SDL_MOUSEMOTION:
   	        SDL_GetMouseState(&x,&y);
   	         if((x>450)&&(x<750)&&(y>250)&&(y<300)){
   	            easy0=easy1;
		    medium0=medium;
		    hard0=hard;
   	        }
   	        else if((x>450)&&(x<750)&&(y>350)&&(y<400)){
   	            easy0=easy;
		    medium0=medium1;
		    hard0=hard;
   	        }
   	        else if((x>450)&&(x<750)&&(y>450)&&(y<500)){
   	            easy0=easy;
		    medium0=medium;
		    hard0=hard1;
   	        }
   	        else{
		    easy0=easy;
		    medium0=medium;
		    hard0=hard;
   	        }
		
   	        break;
   	    
   	}
   	SDL_BlitSurface(easy0,NULL,ecran,&easy_pos);
   	SDL_BlitSurface(medium0,NULL,ecran,&medium_pos);
   	SDL_BlitSurface(hard0,NULL,ecran,&hard_pos);
   	SDL_Flip(ecran);
   }
   SDL_FreeSurface(background);
   SDL_FreeSurface(easy);
   SDL_FreeSurface(easy1);
   SDL_FreeSurface(medium);
   SDL_FreeSurface(medium1);
   SDL_FreeSurface(hard);
   SDL_FreeSurface(hard1);


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

