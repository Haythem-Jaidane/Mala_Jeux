

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include "menu.h"

void play(SDL_Surface *screen)
{

Mix_Chunk *stone ;

 stone = Mix_LoadWAV( "SOUND/bref.wav" );


SDL_Surface *background=NULL,*single[3],*multi[3],*back[3];
    int sin=0,na=0,re=0,r=0;
SDL_Rect background_pos;
SDL_Rect possin,posno,posrys,posre;
int screenx=640;
int screeny=740;
TTF_Font *police = NULL;
background_pos.x=0;
background_pos.y=0;
SDL_Event event;
posrys.x=screenx/6.4;
posrys.y=screeny/5.69;
possin.x=screenx/1.73;
possin.y=screeny/2;
posno.x=640/12.8;
posno.y=screeny/2;

posre.x=640/1.42;
posre.y=740/1.4;
SDL_Color couleurNoire ={139,0,0};
back[0]=IMG_Load("playbuttons/options/return1.png");
    back[1]=IMG_Load("playbuttons/options/return2.png");
    back[2]=IMG_Load("playbuttons/options/return3.png");
single[0] = IMG_Load("playbuttons/play/single1.png");
single[1] = IMG_Load("playbuttons/play/single2.png");
single[2] = IMG_Load("playbuttons/play/single3.png");
multi[0] = IMG_Load("playbuttons/play/multi1.png");
multi[1] = IMG_Load("playbuttons/play/multi2.png");
multi[2] = IMG_Load("playbuttons/play/multi3.png");
background =IMG_Load("tabumba 2.1.png");

int done=1;
    while (done)
    {

    //affichage des images
SDL_BlitSurface(background,NULL,screen,&background_pos);
SDL_BlitSurface(single[sin],NULL,screen,&possin);
SDL_BlitSurface(multi[na],NULL,screen,&posno);
SDL_BlitSurface(back[re],NULL,screen,&posre);
    SDL_Flip(screen);
      
     int t;
   

while (SDL_PollEvent(&event)){
    if (t==1)
 Mix_PlayChannel( -1,stone, 0 );
t=0;

     switch(event.type)
     {case SDL_QUIT:
     done = 0;break;
  case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
{case SDLK_ESCAPE:
             done = 0;
     break;
     case SDLK_LEFT:
     if (sin==0 && na==0 && re==0)
                    {na=1;
                        }
                        else if (na==1 && t==0){
                            sin=0;
                            na=0;
                           
                            t=1;
                            re=1;
                        }
                        else if(re==1 && t==0)
                        {
                                sin=1;
                                na=0;
                               
                                t=1;
                                re=0;
                            }
                            else if(sin==1 && t==0)
                            {
                            sin=0;
                            na=1;
                            
                            t=1;
                            re=0;
                            }
              

                              
     break;
     case SDLK_RIGHT:
   if (sin==0 && na==0 && re==0)
                    {sin=1;
                    }
                        else if (sin==1 && t==0){
                            sin=0;
                            na=0;
                           
                            t=1;
                            re=1;
                        }
                        else if(re==1 && t==0)
                        {
                                sin=0;
                                na=1;
                               
                                t=1;
                                re=0;
                            }
                            else if(na==1 && t==0)
                            {
                            sin=1;
                            na=0;
                            
                            t=1;
                            re=0;
                            }
              
     break;
     case SDLK_RETURN:
     if (sin==1)
      {sin=2;
game();     
        SDL_Delay (100);
                }

                if (na==1)
    { na=2;
game2();
        SDL_Delay (100);
                   
}

if(re==1)
{re=2;
SDL_Delay(100);
done=0;}

break;



}break;
case SDL_MOUSEMOTION:{
               sin=0;
                na=0;

 Mix_PlayChannel( -1,stone, 0 );           
re=0;
                    
if(event.motion.x >= possin.x && event.motion.x <= (possin.x + 150) && event.motion.y >= possin.y && event.motion.y <= (possin.y + 100))
                {
               sin=1;
                }
 else if            
(event.motion.x >= posno.x && event.motion.x <= (posno.x + 150) && event.motion.y >= posno.y && event.motion.y <= (posno.y + 100))
                {
                    na=1;
                    

                }
                 else if            
(event.motion.x >= posre.x && event.motion.x <= (posre.x + 150) && event.motion.y >= posre.y && event.motion.y <= (posre.y + 100))
                {
                    re=1;
                    

                }
}break;

            case SDL_MOUSEBUTTONDOWN:
                  if (sin==1)
      {sin=2;
game();
                        SDL_Delay (100);
                }

                if (na==1)
    { na=2;
game2();
        SDL_Delay (100);
                   
}

if(re==1)
{re=2;
SDL_Delay(100);
done=0;}

                    
break;
}}}
if (done==0)
{menu(screen);
   SDL_FreeSurface(single[0]);
        SDL_FreeSurface(single[1]);
        SDL_FreeSurface(single[2]);
         SDL_FreeSurface(multi[0]);
        SDL_FreeSurface(multi[1]);
        SDL_FreeSurface(multi[2]);
        SDL_FreeSurface(back[2]);
        SDL_FreeSurface(back[0]);
        SDL_FreeSurface(back[1]);

}
}
void commandes(SDL_Surface *screen)
{


    SDL_Surface *background=NULL,*texte1,*texte2,*texte3,*texte4,*texte5,*texte6;
  SDL_Surface *leftclick,*rightclick,*skey,*wkey,*akey,*dkey,*xkey,*ckey,*movement,*action;   
SDL_Rect posrc,poslc,posleft,posright,posdown,posup,pospunch,posweapons,positiona,positionm ;
int r=0;
TTF_Init();
TTF_Font *police = NULL;
SDL_Rect positiont2,positiont1,positiont3,positiont4,positiont5,positiont6,poslogo,background_pos;
int done=0,i=0;
background_pos.x=0;
background_pos.y=0;
positiont1.x=110;
positiont1.y=200;
posup.y=200;
posup.x=10; 
positiont2.x=110;
positiont2.y=280;
posleft.y=280;
posleft.x=10;
positiont3.x=110;
positiont3.y=360;
posright.y=360;
posright.x=10;
positiont4.x=110;
positiont4.y=420;
posdown.y=420;
posdown.x=10;
positiont5.x=450;
positiont5.y=200;
pospunch.y=200;
pospunch.x=310;
posrc.y=260;
posrc.x=310;
positiont6.x=400;
positiont6.y=390;
posweapons.y=380;
posweapons.x=310;
poslc.y=450;
poslc.x=310;
positiona.y=70;
positiona.x=310;
positionm.y=70;
positionm.x=10;



 SDL_Color couleurNoire ={153,0,153};
 
 police = TTF_OpenFont("playbuttons/credits/Headlight.otf",40);
texte1 = TTF_RenderText_Blended(police,"Jump",couleurNoire);
texte2 = TTF_RenderText_Blended(police,"Left ",couleurNoire);
texte3 = TTF_RenderText_Blended(police,"Right",couleurNoire);
texte4 = TTF_RenderText_Blended(police,"Crouch",couleurNoire);
texte5 = TTF_RenderText_Blended(police,"Attack",couleurNoire);
texte6 =TTF_RenderText_Blended(police,"Swap Weapons",couleurNoire);
movement = IMG_Load("playbuttons/commands/movement.png");
action = IMG_Load("playbuttons/commands/action.png");
wkey = IMG_Load("playbuttons/commands/W.png");
skey = IMG_Load("playbuttons/commands/S.png");
akey = IMG_Load("playbuttons/commands/A.png");
dkey = IMG_Load("playbuttons/commands/D.png");
xkey = IMG_Load("playbuttons/commands/X.png");
ckey = IMG_Load("playbuttons/commands/C.png");
rightclick = IMG_Load("playbuttons/commands/RC.png");
leftclick = IMG_Load("playbuttons/commands/LC.png");
background =IMG_Load("tabumba 2.1.png");



while(done==0)
{


SDL_BlitSurface(background,NULL,screen,&background_pos);
 

SDL_BlitSurface(texte1,NULL,screen,&positiont1);
SDL_BlitSurface(texte2,NULL,screen,&positiont2);
SDL_BlitSurface(texte3,NULL,screen,&positiont3);
SDL_BlitSurface(texte4,NULL,screen,&positiont4);
SDL_BlitSurface(texte5,NULL,screen,&positiont5);
SDL_BlitSurface(texte6,NULL,screen,&positiont6);
SDL_BlitSurface(action,NULL,screen,&positiona);
SDL_BlitSurface(movement,NULL,screen,&positionm);

SDL_BlitSurface(leftclick,NULL,screen,&poslc);

SDL_BlitSurface(rightclick,NULL,screen,&posrc);

SDL_BlitSurface(skey,NULL,screen,&posdown);

SDL_BlitSurface(wkey,NULL,screen,&posup);

SDL_BlitSurface(akey,NULL,screen,&posleft);

SDL_BlitSurface(dkey,NULL,screen,&posright);

SDL_BlitSurface(xkey,NULL,screen,&pospunch);

SDL_BlitSurface(ckey,NULL,screen,&posweapons);

done=back(screen,2);
SDL_Flip(screen);}
}

