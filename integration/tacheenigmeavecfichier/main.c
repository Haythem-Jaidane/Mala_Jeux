#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include"e.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include<time.h>


/** 
* @file main.c 
* @brief Testing Programm. 
* @author Aloui
* @version 0.1 
* @date Apr 23, 2021
* 
* Testing program for enigme avec fichier * 
*/


int main(int argc, char *argv[])
{
    enigme enig;
    int ancienne[6],s,r,continuer=1,affiche=0,nouvelleenig=1,temps_actuel=0,temps_pred=0,ligne=0;
    SDL_Event event;
    srand(time(NULL));

    init_enigme(&enig,ancienne);
    remplir_fichier("questions");

    while(nouvelleenig)
   {
    afficher_enigme(&enig,ancienne,"questions",&ligne);
    s=solution(ligne);
    continuer=1;
    while(continuer)
    {   
   
   
          { 
          r=resolution(&affiche);
          if(affiche==1) 
          {
             afficher_resultat(&enig,s,r);
             while(continuer)
             {
	        SDL_PollEvent(&event);
                if(event.type==SDL_QUIT) {
                                            continuer=0;
                                            nouvelleenig=0;
					 }
             }
          }
          }
    }
   }    
    ffree(&enig);
    return EXIT_SUCCESS;
}

