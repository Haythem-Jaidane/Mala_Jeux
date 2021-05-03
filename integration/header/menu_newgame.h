#ifndef MENU_NEWGAME
#define MENU_NEWGAME

//void affichage();

void affichage_button();

void single_player(SDL_Surface *ecran,Mix_Chunk *son,TTF_Font *police,SDL_Color color,int *continuer);

void multiplayer();

void menu_newgame(SDL_Surface *ecran,int *continuer,Mix_Chunk *son,TTF_Font *police,SDL_Color color);

#endif
