

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL/SDL_ttf.h"
#include <time.h>
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_image.h"
#include "enigme1.h"
/** 
* @file projet_jeux/main.c 
* @brief Testing Program. 
* @author ihebddin ferjani
* @version 0.1 
* @date Apr 27, 2021 
* 
* Testing program for b * 
*/
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO); // Démarrage de la SDL (ici : chargement du système vidéo)
 
    /*
    La SDL est chargée.
    Vous pouvez mettre ici le contenu de votre programme
    */
TTF_Init();
TTF_Font *police1;






police1=TTF_OpenFont("Bebas-Regular.ttf", 50);
if (police1 == NULL)
 {
  printf("error dans open font enigme\n");
}
else{

char affich_ch[20];
char affich_ch1[20];
char affich_ch2[20];

SDL_Surface *affich;
SDL_Surface *affich1;
SDL_Surface *affich2;
SDL_Rect affich_pos;
SDL_Rect affich1_pos;
SDL_Rect affich2_pos;

affich_pos.x=74;
affich_pos.y=100;

affich1_pos.x=100;
affich1_pos.y=200;

affich2_pos.x=100;
affich2_pos.y=300;

SDL_Color yellow = {225,225,0};



SDL_Surface *screen;
SDL_Surface *image;
image=IMG_Load("menuspace1.jpg");
SDL_Rect image_pos;
image_pos.x=0;
image_pos.y=0;   
screen= SDL_SetVideoMode( 900,568, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_BlitSurface(image, NULL, screen,&image_pos);
 SDL_Color black= {84,14,70};

sprintf(affich_ch,"Chose Input mode :");
sprintf(affich_ch1,"Mouse");
sprintf(affich_ch2,"A,B,C");

affich=TTF_RenderText_Solid(police1,affich_ch,black);
affich1=TTF_RenderText_Solid(police1,affich_ch1,yellow);
affich2=TTF_RenderText_Solid(police1,affich_ch2,yellow);

SDL_BlitSurface(affich, NULL, screen,&affich_pos);
SDL_BlitSurface(affich1, NULL, screen,&affich1_pos);
SDL_BlitSurface(affich2, NULL, screen,&affich2_pos);

SDL_Flip(screen);



int continuer=1;
SDL_Event event;
while(continuer!=0)
{
   while(SDL_PollEvent(&event))	
   { 
      
    if(event.type==SDL_QUIT)
    {
    continuer=0;

    }
    if(event.type==SDL_MOUSEBUTTONDOWN)   
    { int x,y;
      Uint32 buttouns=SDL_GetMouseState(&x,&y);
      if((event.button.button==SDL_BUTTON_LEFT)&&(x >99)&&(x <250)&&(y >199)&&(y <250))
      {
 
  
    
            SDL_FreeSurface(screen);
              show_enigme1();
              
               
               continuer=0;
            }else if((event.button.button==SDL_BUTTON_LEFT)&&(x >99)&&(x<250)&&(y >299)&&(y <350))
            { //input a b c 
            SDL_FreeSurface(screen);
          show_enigme();
        

               
                continuer=0;
            }
  

         



      

     }



    }


}




TTF_CloseFont(police1);



 }
              
TTF_Quit();

SDL_Quit(); // Arrêt de la SDL (libération de la mémoire).
 
    
 return EXIT_SUCCESS;
}



