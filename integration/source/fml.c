/** 
*        @file fml.c
*        @brief fonction de l'entite secondaire(enemy)
*        @author mohamed khaled baoueb
*        @version 0.1
*        @date Apr 21, 2021
*/

#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "../header/fml.h"

///////////////////////////////////////////

/** 
* @brief initialiser la position d'ennemy
* @param e variable d'ennemy
* @param file_name variable du sprite
* @return Nothing
*/



void initialiser_ennemy(Ennemy *e,char *file_name)
{
e->pos.x=780;
e->pos.y=440;
e->frame=0;
e->sprite=IMG_Load(file_name);
}

/////////////////////////////
/** 
* @brief pour la movment du spritsheet
* @param e variable d'ennemy
* @param y 
* @return Nothing
*/


void Sprit(Ennemy *e,int *y )
{
int i;

for(i=0;i<4;i++){
e->Right[i].x=100*i; //100
e->Right[i].y=*y; //100
e->Right[i].w=100; //100
e->Right[i].h=100; //100
}
}

///////////////////////////////////////////////////////////////
/** 
* @brief pour afficher l'ennemy
* @param e variable d'ennemy
* @param screen variable de l'ecran 
* @param image variable du l'image du background
* @return Nothing
*/



void afficher(Ennemy *e,SDL_Surface *screen)
{
SDL_Rect positionEcran;
positionEcran.x=0;
positionEcran.y=0;
SDL_BlitSurface(e->sprite,&(e->Right[e->frame]),screen,&e->pos);

}

/////////////////////////////////////////////
/** 
* @brief pour annimer l'ennemy
* @param e variable d'ennemy
* @param screen variable de l'ecran 
* @return Nothing
*/

void animation(Ennemy *e,SDL_Surface *screen)
{
	//Sprit(e,&(*sp));
(e->frame)++;
if(e->frame>=4){
    e->frame=0;
}
//SDL_Delay(500);	
}

/*srand(time(0));
a=rand()%1000;*/

//////////////////////////////////////////////////////////////
/** 
* @brief pour la deplacement alliatoir du l'ennemy
* @param e variable d'ennemy
* @param sp variable du spritesheet
* @param x position sur l'axe des abscisse
* @param screen variable de l'ecran 
* @return Nothing
*/


void deplacement(Ennemy *e,int *sp,int *x,SDL_Surface *screen)
{
	//Sprit(e,&(*sp));
if(*x==1)
	{
		if(e->pos.x<900)
		{
			e->pos.x+=10;
			*sp=200; //200
		}
		else
		{
			*x=-1;

		}
		
    }

else
if(*x==-1)
if(e->pos.x>0)
		{
			e->pos.x-=10;
			*sp=100; //100
		}
		else
		{
			*x=1;
		}

}

///////////////////////////////

/** 
* @brief pour la collision
* @param b variable du box
* @param e variable d'ennemy
* @return int
*/
int collision(box *b,Ennemy *e)
{
	b->x=698;
	b->y=600;
	b->w=60;
	b->h=75;


	if(e->pos.x>b->x+b->w || b->x > e->pos.x+e->pos.w || b->y + b->h < e->pos.y || b->y > e->pos.y + e->pos.h)
	{
		return 0;
	}
	else
		return 1;

}
