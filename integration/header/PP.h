/**
*	@file PP.h
*	@brief headers and strctures 
*       @author haythem jaidane 
*       @version 0.6 
*       @date Apr 20, 2021 
*/

#ifndef PP_H_INCLUDED
#define PP_H_INCLUDED

#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

/**
*  @struct Life
*  @brief structure pour l'affichage les vies du joueur
*
*/


typedef struct
{

int Nbr_Life ;/*!< nombre de vie restant au joueur*/
SDL_Surface *Life_img ;/*!< la variable SDL_Surface des vies*/
SDL_Rect Position_life ;/*!< position des vies de joueur*/

}Life ;

/**
*  @struct Score
*  @brief structure pour l'affichage du score
*
*/


typedef struct
{

SDL_Surface *Score; /*!< la variable SDL_Surface du score */
SDL_Rect Position_score; /*!< la position du score dans l'ecran */
int S; /*!< la valeur du score du joueur */

}Score ;

/**
*  @struct Personnage_Principal
*  @brief structure pour le personnage principal
*
*/

typedef struct
{

SDL_Surface *Sprite_sheet ; /*!< la variabel SDL_Surface du spritesheet du personnage */
SDL_Rect Position_intiale;/*!< position du personage*/
SDL_Rect Pos_Sprite;/*!< la position du frame actuelle dans le spritesheet*/
Life Vie_perso ;/*!< les vies du personnage*/
Score Score_perso ;/*!< score du personnage*/
int limite_min;/*!< la limit a gauche du mouvement du personnage */
int limite_max;/*!< la limit a droite du mouvement du personnage */
int Direction ;/*!< la variable de direction 1 a droit 2 a gauche*/
int Mouvement;/*!< le type de mouvement du personnage */
int acceleration ;/*!< confession d'acceleration */
int max_frame ;/*!< max frame du personnage dans le spritsheet */
int frame ;/*!< le frame actuel du personnage */
int jump;/*!< la variable du saut 1 ou 0*/
}Personnage_Principal;

void initPerso(Personnage_Principal*p) ;
void init (Personnage_Principal tab_p[], int mode);
void afficherPerso(Personnage_Principal p , SDL_Surface *screen);
void deplacerPerso(Personnage_Principal *p,SDL_Surface *mask);
void animerPerso(Personnage_Principal *p) ;
void saut(Personnage_Principal *p,SDL_Surface *mask) ;
void mouvement_personnage(Personnage_Principal tab_p[], SDL_Surface *screen,SDL_Surface *background,SDL_Rect position_bakcground,int mode);
void remis_a_zero(Personnage_Principal tab_p[],int mode);


#endif // PP_H_INCLUDED
