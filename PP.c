#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include "PP.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// a tester

void init (Personnage_Principal * p, int numperso){
    
    if(numperso==1){
        // single player
        initPerso(p);
        p->Position_intiale.x = 50 ;
        p->Position_intiale.y = 350 ;
    }
    
    else if(numperso==2){
        // multiplayer
        p=(Personnage_Principal*)malloc(2*sizeof(Personnage_Principal));
        initPerso(p);
        p->Position_intiale.x = 50 ;
        p->Position_intiale.y = 350 ;
        initPerso(p+1);
        (p+1)->Position_intiale.x = 550 ;
        (p+1)->Position_intiale.y = 350 ;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initPerso(Personnage_Principal *p)
{

p->Direction = 0 ;

// Position_intiale
p->Position_intiale.x = 50 ;
p->Position_intiale.y = 350 ;


// SCORE :
p->Score_perso.Nbr_Score = 0 ;
p->Score_perso.Position_score.x = 10 ;
p->Score_perso.Position_score.y = 200 ;
//p->Score_perso.Score = TTF_RenderText_Shaded(police, temps, couleurNoire, couleurBlanche);

// LIFE :
p->Vie_perso.Nbr_Life = 3 ;
p->Vie_perso.Life_img = IMG_Load("vie/1.png");
//p->Vie_perso.Life_remaining_number = IMG_Load("Life_restante.PNG");
p->Vie_perso.Position_life.x = 20 ;
p->Vie_perso.Position_life.y = 120 ;
//p->Vie_perso.Position_remaining_life.x = 25 ;
//p->Vie_perso.Position_remaining_life.y = 30 ;

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
p->Mouvement=0;

// SAUT : 
p->jump=0;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void afficherPerso(Personnage_Principal *p , SDL_Surface *screen) 
{ 

    SDL_BlitSurface(p->Sprite_sheet,&p->Pos_Sprite,screen,&p->Position_intiale);
    SDL_Flip(screen);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void afficher_score_vie(Personnage_Principal *p , SDL_Surface *screen)
{
    //SDL_BlitSurface(p->Score_perso.Score_img, NULL,screen,&p->Score_perso.Position_score);
    SDL_BlitSurface(p->Vie_perso.Life_img, NULL,screen,&p->Vie_perso.Position_life);
    SDL_Flip(screen);
    //SDL_BlitSurface(p->Vie_perso.Life_remaining_number, NULL,screen,&p->Vie_perso.Position_remaining_life);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deplacerPerso(Personnage_Principal *p)
{
    if(((p->Position_intiale.x<p->limite-10)&&(p->Direction==1))||((p->Position_intiale.x>10)&&(p->Direction==2))){
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


void mouvement_personnage(Personnage_Principal *p, SDL_Surface *screen,SDL_Surface *background,SDL_Rect position_bakcground){

    int i;
    p->frame=0;
    for(i=0;i<p->max_frame;i++){
        animerPerso(p);
        if(p->jump){
            saut(p);   
        }
        else{
            deplacerPerso(p) ;
        }
        SDL_BlitSurface(background,NULL,screen,&position_bakcground);
        SDL_BlitSurface(p->Vie_perso.Life_img, NULL,screen,&p->Vie_perso.Position_life);
        SDL_Delay(25/p->acceleration);
        afficherPerso(p , screen) ;
    }
    //afficher_score_vie(p,screen);

}











