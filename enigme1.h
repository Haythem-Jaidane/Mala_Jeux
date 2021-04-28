#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include "SDL/SDL_ttf.h"
#include <time.h>



void show_enigme();
void randomize(int * a,int * b, int * c,int * d);

void input_show(int pos,SDL_Surface * quest,SDL_Surface * quest1,SDL_Surface * quest2,SDL_Surface * quest3,char * quest_ch,char * quest_ch1,char * quest_ch2,char * quest_ch3,TTF_Font *police,SDL_Rect quest_pos,SDL_Rect quest1_pos,SDL_Rect quest2_pos,SDL_Rect quest3_pos,SDL_Surface *screen);

void show_enigme1();

void input_show1(int pos,SDL_Surface * quest,SDL_Surface * quest1,SDL_Surface * quest2,SDL_Surface * quest3,char * quest_ch,char * quest_ch1,char * quest_ch2,char * quest_ch3,TTF_Font *police,SDL_Rect quest_pos,SDL_Rect quest1_pos,SDL_Rect quest2_pos,SDL_Rect quest3_pos,SDL_Surface *screen);






#endif

