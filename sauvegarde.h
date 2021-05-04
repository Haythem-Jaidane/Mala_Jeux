#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct save
{
	SDL_Rect posperso; 
	SDL_Rect posennemi;
	SDL_Rect camera; 	 
	int score; 
	
}save;


void sauvegarder (SDL_Rect posperso, SDL_Rect posenemi , int score , SDL_Rect camera , char * nomfichier) ; 
int charger ( SDL_Rect *posperso, SDL_Rect *posenemi , int *score , SDL_Rect *camera , char * nomfichier);


#endif
