#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>

/** 
* @struct enigme
* @brief struct for enigme
*/ 


typedef struct
{
    SDL_Surface *fenetre_enigme;
    SDL_Surface *image;
    SDL_Surface *texte;
    TTF_Font *police;
    SDL_Rect posim,post;
}enigme;

void init_enigme(enigme *enig,int ancienne[]);
void remplir_fichier(char questions[]);
void afficher_enigme(enigme *enig,int *ancienne,char questions[],int *ligne);
int solution(int q);
int resolution(int *affiche);
void afficher_resultat(enigme *enig,int solution,int resolution);
void ffree(enigme *enig);



#endif // ENIGME_H_INCLUDED
