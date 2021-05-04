#ifndef PP_H_INCLUDED
#define PP_H_INCLUDED

#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
//#include<SDL/SDL_mixer.h>
//#include <SDL/SDL_ttf.h>

typedef struct
{

int Nbr_Life ;
SDL_Surface Life_img , Life_remaining_number ;
SDL_Rect Position_life , Position_remaining_life ;

}	Life ;

typedef struct
{

int Nbr_Score ;
SDL_Surface Score_img , Score_Reach ;
SDL_Rect Position_score , Position_score_reach ;

}	Score ;

typedef struct
{

SDL_Surface *Sprite_sheet ;
SDL_Rect Position_intiale , Pos_Sprite;
Life Vie_perso ;
Score Score_perso ;
int Direction ;
int Mouvement;
int acceleration ;
int max_frame ;
int frame ;
int jump;
}Personnage_Principal;

void init (Personnage_Principal * p, int numperso);
void initPerso(Personnage_Principal*p) ;
void afficherPerso(Personnage_Principal *p , SDL_Surface *screen)  ;
void afficher_score_vie(Personnage_Principal *p , SDL_Surface *screen) ;
void deplacerPerso(Personnage_Principal *p) ;
void animerPerso(Personnage_Principal *p) ;
void saut(Personnage_Principal *p) ;
void mouvement_personnage(Personnage_Principal *p, SDL_Surface *screen,SDL_Surface *background,SDL_Rect position_bakcground);



#endif // PP_H_INCLUDED
