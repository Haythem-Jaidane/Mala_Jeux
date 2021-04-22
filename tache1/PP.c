/**
*	@file PP.c
*	@brief fonction of the main charactere
*       @author haythem jaidane 
*       @version 0.6 
*       @date Apr 20, 2021 
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "PP.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
* @brief pour initialisier un personnage principal ( cette fonction est inisialiser sur le Spritesheet de test )
* @param tab_p un tableau de 2 personnage    
* @return Nothing
*/

void initPerso(Personnage_Principal *p)
{

TTF_Font *police = NULL;

SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
police = TTF_OpenFont("Monoton-Regular.ttf", 20);

p->Direction = 0 ;

// SCORE :

char s[10];
p->Score_perso.S=1000;
//strcat(s,"Score : ");
sprintf(s, "%d", p->Score_perso.S);

p->Score_perso.Score = TTF_RenderText_Blended(police,s, couleurBlanche);

// LIFE :
p->Vie_perso.Nbr_Life = 5 ;
p->Vie_perso.Life_img = IMG_Load("vie/1.png");

// SPRITE SHEET : 
p->frame = 0 ;
p->max_frame = 1;
p->Sprite_sheet = IMG_Load("personage.png") ;
p->Pos_Sprite.x = 0 ; 
p->Pos_Sprite.y = 0 ;
p->Pos_Sprite.w = 920/8 ;
p->Pos_Sprite.h = 460/4 ;

// Deplacement :
p->acceleration = 1 ;
p->Mouvement = 0;

// SAUT : 
p->jump=0;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
* @brief pour initialisier le mode de jeu (single ou multiplayer) on initialise la position initial, les vies et le score de chaque charactere 
* @param tab_p un tableau de 2 personnage  
* @param mode 0 pour le mode singleplayer et 1 pour le mode multiplayer  
* @return Nothing
*/

void init (Personnage_Principal tab_p[], int mode){
    
    // single player
    initPerso(&tab_p[0]);
    tab_p[0].Position_intiale.x = 50 ;
    tab_p[0].Position_intiale.y = 350 ;
    tab_p[0].Vie_perso.Position_life.x = 20;
    tab_p[0].Vie_perso.Position_life.y = 80;
    if(mode==0)
    	tab_p[0].Score_perso.Position_score.x = 1000 ;
    else
	tab_p[0].Score_perso.Position_score.x = 400 ;
    tab_p[0].Score_perso.Position_score.y = 80 ;
    
    if(mode==1){
        // multiplayer
        initPerso(&tab_p[1]);
        tab_p[1].Position_intiale.x = 550 ;
        tab_p[1].Position_intiale.y = 350 ;
	tab_p[1].Vie_perso.Position_life.x = 500;
	tab_p[1].Vie_perso.Position_life.y = 80;
	tab_p[1].Score_perso.Position_score.x = 1000 ;
        tab_p[1].Score_perso.Position_score.y = 80 ;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** 
* @brief pour afficher le peronnage , les vies et le score sans screen flip . 
* @param p la variable du personnage 
* @param screen la variable de l'ecran  
* @return Nothing 
*/ 


void afficherPerso(Personnage_Principal p , SDL_Surface *screen) 
{ 
    SDL_BlitSurface(p.Vie_perso.Life_img, NULL,screen,&p.Vie_perso.Position_life);
    SDL_BlitSurface(p.Score_perso.Score, NULL,screen,&p.Score_perso.Position_score);
    SDL_BlitSurface(p.Sprite_sheet,&p.Pos_Sprite,screen,&p.Position_intiale);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** 
* @brief pour deplacer le personnage principal . 
* @param p la variable du personnage   
* @return Nothing 
*/ 

void deplacerPerso(Personnage_Principal *p)
{
    if(((p->Position_intiale.x<p->limite_max-10)&&(p->Direction==1))||((p->Position_intiale.x>p->limite_min)&&(p->Direction==2))){
        switch (p->Direction){
            case 1 :
                p->Position_intiale.x += 7*p->acceleration ;
                break ;
            case 2 :
                p->Position_intiale.x -= 7*p->acceleration ;
                break ;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** 
* @brief pour animer le personnage principal en deplacent frame par frame. 
* @param p la variable du personnage  
* @return Nothing 
*/ 


void animerPerso(Personnage_Principal*p)
{
    if (p->frame==p->max_frame-1)
        p->frame = 0 ;
    else
        p->frame++ ;
    p->Pos_Sprite.x = p->Pos_Sprite.w*p->frame;
    p->Pos_Sprite.y= p->Pos_Sprite.h*p->Mouvement;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** 
* @brief pour faire sauter le peronnage ( cette fonction est faite pour un saut de 5 frame ). 
* @param p la variable du personnage  
* @return Nothing 
*/ 

void saut(Personnage_Principal *p){

    // saut
    if(p->frame==1 || p->frame == 2)
    {
        p->Position_intiale.y -= 30;
    }
    // chute
    else if(p->frame==3 || p->frame == 4)
    {
        
        p->Position_intiale.y += 30;
    }
    if(p->Direction>0){
        deplacerPerso(p);
    }
    p->jump=1;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** 
* @brief pour faire le controle du personnage. 
* @param tab_p un tableau de 2 personnage
* @param screen variable SDL_Surface de l'ecran
* @param background variable SDL_Surface du background
* @param position_bakcground variable SDL_Rect de la position du background
* @param mode 0 pour le mode singleplayer et 1 pour le mode multiplayer
* @return Nothing 
*/ 


void mouvement_personnage(Personnage_Principal tab_p[], SDL_Surface *screen,SDL_Surface *background,SDL_Rect position_bakcground,int mode){

    int i=0,j=0;

    p[0].frame=0;
    if(mode)
        p[1].frame=0;
    else
	p[1].max_frame=0;
    while((i<p[0].max_frame)||(j<p[1].max_frame)){
	if(i<p[0].max_frame)
            animerPerso(&p[0]);
        if(p[0].jump){
            saut(&p[0]);   
        }
        else{
            deplacerPerso(&p[0]) ;
        }
	if(mode){
	    if(j<p[1].max_frame)
	        animerPerso(&p[1]);
	    if(p[1].jump){
            	saut(&p[1]);   
            }
            else{
            	deplacerPerso(&p[1]) ;
            }
	}
        SDL_BlitSurface(background,NULL,screen,&position_bakcground);
        afficherPerso(p[0],screen);
	if(mode){
            afficherPerso(p[1],screen);
	}
        SDL_Flip(screen);

	i++;
        j++;

    }

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** 
* @brief pour remettre a zero tout les paramettre du jeu apres boucle de jeu. 
* @param tab_p un tableau de 2 personnage
* @param mode 0 pour le mode singleplayer et 1 pour le mode multiplayer
* @return Nothing 
*/ 

void remis_a_zero(Personnage_Principal tab_p[], int mode){
    tab_p[0].Direction=0;
    tab_p[0].max_frame=1;
    tab_p[0].Mouvement=0;	
    tab_p[0].acceleration=1;
    tab_p[0].jump=0;
    if(mode==1){
        tab_p[1].Direction=0;
    	tab_p[1].max_frame=1;
    	tab_p[1].Mouvement=0;	
    	tab_p[1].acceleration=1;
    	tab_p[1].jump=0;
    }
}










