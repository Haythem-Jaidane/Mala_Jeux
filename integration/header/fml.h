/** 
*        @file fml.h
*        @brief headers and structures
*        @author mohamed khaled baoueb
*        @version 0.1
*        @date Apr 21, 2021
*/

#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


/** 
* @struck Ennemy 
* @brief structure pour l'ennemy
*
*/


typedef struct{
SDL_Surface *sprite;/*!< variable sdl_surface du spritesheet du l'ennemy >*/
SDL_Rect pos;/*!< variable pour la position d'ennemy >*/
int frame; /*!< le frame actuel d'ennemy >*/
SDL_Rect Right[4]; /*!< variable d'ennemy >*/
}Ennemy;


/** 
* @struck box 
* @brief structure pour la position d'obstacle
*
*/

typedef struct
{
int x;/*!< position sur l'axe des abscissedu box >*/
int y;/*!< position sur l'axe des ordonnée du box>*/
int w;/*!< position du le  width du box >*/
int h;/*!< position du le height du box >*/
}box;
void initialiser_ennemy(Ennemy *e,char *file_name);
void Sprit(Ennemy *e,int *y );
void afficher(Ennemy *e,SDL_Surface *screen);
void animation(Ennemy *e,SDL_Surface *screen);
void deplacement(Ennemy *e,int *sp,int *x,SDL_Surface *screen);


int collision(box *b,Ennemy *e);






#endif // FONCTION_H_INCLUDED
