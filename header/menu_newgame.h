#ifndef MENU_NEWGAME
#define MENU_NEWGAME

void affichage();

void affichage_button();

void single_player();

void multiplayer();

void menu_newgame(SDL_Surface *ecran,int *continuer,Mix_Chunk *son);

#endif
