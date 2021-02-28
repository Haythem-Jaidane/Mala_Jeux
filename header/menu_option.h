#ifndef MENU_OPTION
#define MENU_OPTION

void affiche();

void modifier_son();

void full_screen(SDL_Surface *ecran);

void simple_screen(SDL_Surface *ecran);

void menu_option(SDL_Surface *ecran,int *continuer,int *screen,Mix_Chunk *son,TTF_Font *police,SDL_Color color);

#endif
