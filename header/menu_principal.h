#ifndef MENU_PRINCIPAL
#define MENU_PRINCIPAL

void initialisation();

void bouton(SDL_Surface* new_game,SDL_Surface* option,
             SDL_Surface* scoreboard,SDL_Surface* exit,SDL_Surface* ecran,
             SDL_Rect *pos, SDL_Rect *pos1, 
             SDL_Rect *pos2, SDL_Rect *pos3);
             
void animation_background(int *frame, SDL_Surface* back,SDL_Surface* ecran,SDL_Rect *positionFond);

#endif
