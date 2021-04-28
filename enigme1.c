#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "enigme1.h"
#include <time.h>



void input_show(int pos,SDL_Surface * quest,SDL_Surface * quest1,SDL_Surface * quest2,SDL_Surface * quest3,char * quest_ch,char * quest_ch1,char * quest_ch2,char * quest_ch3,TTF_Font *police,SDL_Rect quest_pos,SDL_Rect quest1_pos,SDL_Rect quest2_pos,SDL_Rect quest3_pos,SDL_Surface *screen)
{

int continuer=1;
/*
int score=50;
int life=3;
int win=0;
*/

while(continuer!=0)
{SDL_Event event;
   while(SDL_PollEvent(&event))	
   { 
     switch(event.type)
   {case SDL_QUIT: 

     continuer=0;
       break;
    case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
      case  SDLK_a:
if(pos==0)
{

SDL_FreeSurface(quest);
SDL_FreeSurface(quest1);
SDL_FreeSurface(quest2);
SDL_FreeSurface(quest3);
SDL_FreeSurface(screen);
SDL_Flip(screen);
SDL_Surface *quest;
SDL_Surface *quest1;
SDL_Surface *quest2;
SDL_Surface *quest3;
SDL_Surface *screen= SDL_SetVideoMode( 900,568, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_Surface *image=IMG_Load("galaxywonder.jpg");
SDL_Rect image_pos;
image_pos.x=0;
image_pos.y=0;
SDL_BlitSurface(image, NULL, screen,&image_pos);
SDL_Flip(screen);
sprintf(quest_ch,"Congratulation !");
sprintf(quest_ch1," ");
sprintf(quest_ch2," ");
sprintf(quest_ch3," ");

quest_pos.x=320;
quest_pos.y=240;
SDL_Color blue = {45,58,223};

quest=TTF_RenderText_Solid(police,quest_ch,blue);
quest1=TTF_RenderText_Solid(police,quest_ch1,blue);
quest2=TTF_RenderText_Solid(police,quest_ch2,blue);
quest3=TTF_RenderText_Solid(police,quest_ch3,blue);
SDL_BlitSurface(quest, NULL, screen,&quest_pos);
SDL_BlitSurface(quest1, NULL, screen,&quest1_pos);
SDL_BlitSurface(quest2, NULL, screen,&quest2_pos);
SDL_BlitSurface(quest3, NULL, screen,&quest3_pos);
SDL_Flip(screen);
 




}else
{

SDL_FreeSurface(quest);
SDL_FreeSurface(quest1);
SDL_FreeSurface(quest2);
SDL_FreeSurface(quest3);
SDL_FreeSurface(screen);
SDL_Flip(screen);
SDL_Surface *quest;
SDL_Surface *quest1;
SDL_Surface *quest2;
SDL_Surface *quest3;
SDL_Surface *screen= SDL_SetVideoMode( 900,568, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

SDL_Surface *image=IMG_Load("galaxywonder.jpg");
SDL_Rect image_pos;
image_pos.x=0;
image_pos.y=0;
SDL_BlitSurface(image, NULL, screen,&image_pos);
SDL_Flip(screen);
sprintf(quest_ch,"you lost ");
sprintf(quest_ch1," ");
sprintf(quest_ch2," ");
sprintf(quest_ch3," ");
SDL_Color blue = {45,58,223};

quest_pos.x=320;
quest_pos.y=240;

quest=TTF_RenderText_Solid(police,quest_ch,blue);
quest1=TTF_RenderText_Solid(police,quest_ch1,blue);
quest2=TTF_RenderText_Solid(police,quest_ch2,blue);
quest3=TTF_RenderText_Solid(police,quest_ch3,blue);
SDL_BlitSurface(quest, NULL, screen,&quest_pos);
SDL_BlitSurface(quest1, NULL, screen,&quest1_pos);
SDL_BlitSurface(quest2, NULL, screen,&quest2_pos);
SDL_BlitSurface(quest3, NULL, screen,&quest3_pos);
SDL_Flip(screen);







}

      break;

     case SDLK_b:
if(pos==1)
{
SDL_FreeSurface(quest);
SDL_FreeSurface(quest1);
SDL_FreeSurface(quest2);
SDL_FreeSurface(quest3);

SDL_Flip(screen);
SDL_Surface *image=IMG_Load("galaxywonder.jpg");
SDL_Rect image_pos;
image_pos.x=0;
image_pos.y=0;
SDL_BlitSurface(image, NULL, screen,&image_pos);
SDL_Surface *quest;
SDL_Surface *quest1;
SDL_Surface *quest2;
SDL_Surface *quest3;
quest_pos.x=320;
quest_pos.y=240;
sprintf(quest_ch,"Congratulation !");
sprintf(quest_ch1," ");
sprintf(quest_ch2," ");
sprintf(quest_ch3," ");
SDL_Color blue = {45,58,223};

quest=TTF_RenderText_Solid(police,quest_ch,blue);
quest1=TTF_RenderText_Solid(police,quest_ch1,blue);
quest2=TTF_RenderText_Solid(police,quest_ch2,blue);
quest3=TTF_RenderText_Solid(police,quest_ch3,blue);
SDL_BlitSurface(quest, NULL, screen,&quest_pos);
SDL_BlitSurface(quest1, NULL, screen,&quest1_pos);
SDL_BlitSurface(quest2, NULL, screen,&quest2_pos);
SDL_BlitSurface(quest3, NULL, screen,&quest3_pos);
SDL_Flip(screen);


}else
{SDL_FreeSurface(quest);
SDL_FreeSurface(quest1);
SDL_FreeSurface(quest2);
SDL_FreeSurface(quest3);

SDL_Flip(screen);

SDL_Surface *image=IMG_Load("galaxywonder.jpg");
SDL_Rect image_pos;
image_pos.x=0;
image_pos.y=0;
SDL_BlitSurface(image, NULL, screen,&image_pos);

SDL_Surface *quest;
SDL_Surface *quest1;
SDL_Surface *quest2;
SDL_Surface * quest3;


sprintf(quest_ch,"you lost ");
sprintf(quest_ch1," ");
sprintf(quest_ch2," ");
sprintf(quest_ch3," ");
SDL_Color blue = {45,58,223};
quest_pos.x=320;
quest_pos.y=240;
quest=TTF_RenderText_Solid(police,quest_ch,blue);
quest1=TTF_RenderText_Solid(police,quest_ch1,blue);
quest2=TTF_RenderText_Solid(police,quest_ch2,blue);
quest3=TTF_RenderText_Solid(police,quest_ch3,blue);
SDL_BlitSurface(quest, NULL, screen,&quest_pos);
SDL_BlitSurface(quest1, NULL, screen,&quest1_pos);
SDL_BlitSurface(quest2, NULL, screen,&quest2_pos);
SDL_BlitSurface(quest3, NULL, screen,&quest3_pos);
SDL_Flip(screen);
 

}


        break;

       case SDLK_c:

if(pos==2)
{SDL_FreeSurface(quest);
SDL_FreeSurface(quest1);
SDL_FreeSurface(quest2);
SDL_FreeSurface(quest3);
SDL_FreeSurface(screen);
SDL_Flip(screen);
/*updating and showing after win*/ 
SDL_Surface *screen= SDL_SetVideoMode( 900,568, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_Surface *image=IMG_Load("galaxywonder.jpg");
SDL_Rect image_pos;
image_pos.x=0;
image_pos.y=0;
SDL_BlitSurface(image, NULL, screen,&image_pos);
SDL_Flip(screen);
SDL_Surface *quest;
SDL_Surface *quest1;
SDL_Surface *quest2;
SDL_Surface * quest3;

sprintf(quest_ch,"Congratulation !");
sprintf(quest_ch1," ");
sprintf(quest_ch2," ");
sprintf(quest_ch3," ");
SDL_Color blue = {45,58,223};
quest=TTF_RenderText_Solid(police,quest_ch,blue);
quest1=TTF_RenderText_Solid(police,quest_ch1,blue);
quest2=TTF_RenderText_Solid(police,quest_ch2,blue);
quest3=TTF_RenderText_Solid(police,quest_ch3,blue);
quest_pos.x=320;
quest_pos.y=240;

SDL_BlitSurface(quest, NULL, screen,&quest_pos);
SDL_BlitSurface(quest1, NULL, screen,&quest1_pos);
SDL_BlitSurface(quest2, NULL, screen,&quest2_pos);
SDL_BlitSurface(quest3, NULL, screen,&quest3_pos);
SDL_Flip(screen);
 

}else
{SDL_FreeSurface(quest);
SDL_FreeSurface(quest1);
SDL_FreeSurface(quest2);
SDL_FreeSurface(quest3);
SDL_FreeSurface(screen);
SDL_Flip(screen);
SDL_Surface *screen= SDL_SetVideoMode( 900,568, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_Flip(screen);
SDL_Surface *image=IMG_Load("galaxywonder.jpg");
SDL_Rect image_pos;
image_pos.x=0;
image_pos.y=0;
SDL_BlitSurface(image, NULL, screen,&image_pos);
SDL_Surface *quest;
SDL_Surface *quest1;
SDL_Surface *quest2;
SDL_Surface * quest3;
/*updating and showing after lose*/
sprintf(quest_ch,"you lost ");
sprintf(quest_ch1," ");
sprintf(quest_ch2," ");
sprintf(quest_ch3," ");
SDL_Color blue = {45,58,223};
quest=TTF_RenderText_Solid(police,quest_ch,blue);
quest1=TTF_RenderText_Solid(police,quest_ch1,blue);
quest2=TTF_RenderText_Solid(police,quest_ch2,blue);
quest3=TTF_RenderText_Solid(police,quest_ch3,blue);
quest_pos.x=320;
quest_pos.y=240;
SDL_BlitSurface(quest, NULL, screen,&quest1_pos);
SDL_BlitSurface(quest1, NULL, screen,&quest1_pos);
SDL_BlitSurface(quest2, NULL, screen,&quest2_pos);
SDL_BlitSurface(quest3, NULL, screen,&quest3_pos);
SDL_Flip(screen);

}



        break;

    
    }
    break;


   }



}

}
}


//mouse part




void input_show1(int pos,SDL_Surface * quest,SDL_Surface * quest1,SDL_Surface * quest2,SDL_Surface * quest3,char * quest_ch,char * quest_ch1,char * quest_ch2,char * quest_ch3,TTF_Font *police,SDL_Rect quest_pos,SDL_Rect quest1_pos,SDL_Rect quest2_pos,SDL_Rect quest3_pos,SDL_Surface *screen)
{

int continuer=1;
/*
int score=50;
int life=3;
int win=0;
*/

while(continuer!=0)
{SDL_Event event;
  while(SDL_PollEvent(&event))	
   { 
      
    if(event.type==SDL_QUIT)
    {
    continuer=0;

    }
    if(event.type==SDL_MOUSEBUTTONDOWN)   
    { int x,y;
      Uint32 buttouns=SDL_GetMouseState(&x,&y);
      if((event.button.button==SDL_BUTTON_LEFT)&&(x >99)&&(x <450)&&(y >199)&&(y <250))
      {if(pos==0)
{

SDL_FreeSurface(quest);
SDL_FreeSurface(quest1);
SDL_FreeSurface(quest2);
SDL_FreeSurface(quest3);
SDL_FreeSurface(screen);
SDL_Flip(screen);
SDL_Surface *quest;
SDL_Surface *quest1;
SDL_Surface *quest2;
SDL_Surface *quest3;
SDL_Surface *screen= SDL_SetVideoMode( 900,568, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_Surface *image=IMG_Load("galaxywonder.jpg");
SDL_Rect image_pos;
image_pos.x=0;
image_pos.y=0;
SDL_BlitSurface(image, NULL, screen,&image_pos);
SDL_Flip(screen);
sprintf(quest_ch,"Congratulation !");
sprintf(quest_ch1," ");
sprintf(quest_ch2," ");
sprintf(quest_ch3," ");

quest_pos.x=320;
quest_pos.y=240;
SDL_Color blue = {45,58,223};

quest=TTF_RenderText_Solid(police,quest_ch,blue);
quest1=TTF_RenderText_Solid(police,quest_ch1,blue);
quest2=TTF_RenderText_Solid(police,quest_ch2,blue);
quest3=TTF_RenderText_Solid(police,quest_ch3,blue);
SDL_BlitSurface(quest, NULL, screen,&quest_pos);
SDL_BlitSurface(quest1, NULL, screen,&quest1_pos);
SDL_BlitSurface(quest2, NULL, screen,&quest2_pos);
SDL_BlitSurface(quest3, NULL, screen,&quest3_pos);
SDL_Flip(screen);
 




}else
{

SDL_FreeSurface(quest);
SDL_FreeSurface(quest1);
SDL_FreeSurface(quest2);
SDL_FreeSurface(quest3);
SDL_FreeSurface(screen);
SDL_Flip(screen);
SDL_Surface *quest;
SDL_Surface *quest1;
SDL_Surface *quest2;
SDL_Surface *quest3;
SDL_Surface *screen= SDL_SetVideoMode( 900,568, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

SDL_Surface *image=IMG_Load("galaxywonder.jpg");
SDL_Rect image_pos;
image_pos.x=0;
image_pos.y=0;
SDL_BlitSurface(image, NULL, screen,&image_pos);
SDL_Flip(screen);
sprintf(quest_ch,"you lost ");
sprintf(quest_ch1," ");
sprintf(quest_ch2," ");
sprintf(quest_ch3," ");
SDL_Color blue = {45,58,223};

quest_pos.x=320;
quest_pos.y=240;

quest=TTF_RenderText_Solid(police,quest_ch,blue);
quest1=TTF_RenderText_Solid(police,quest_ch1,blue);
quest2=TTF_RenderText_Solid(police,quest_ch2,blue);
quest3=TTF_RenderText_Solid(police,quest_ch3,blue);
SDL_BlitSurface(quest, NULL, screen,&quest_pos);
SDL_BlitSurface(quest1, NULL, screen,&quest1_pos);
SDL_BlitSurface(quest2, NULL, screen,&quest2_pos);
SDL_BlitSurface(quest3, NULL, screen,&quest3_pos);
SDL_Flip(screen);







}
 
  
    
            
              
            }else if((event.button.button==SDL_BUTTON_LEFT)&&(x >99)&&(x<450)&&(y >299)&&(y <350))
            { if(pos==1)
{
SDL_FreeSurface(quest);
SDL_FreeSurface(quest1);
SDL_FreeSurface(quest2);
SDL_FreeSurface(quest3);

SDL_Flip(screen);
SDL_Surface *image=IMG_Load("galaxywonder.jpg");
SDL_Rect image_pos;
image_pos.x=0;
image_pos.y=0;
SDL_BlitSurface(image, NULL, screen,&image_pos);
SDL_Surface *quest;
SDL_Surface *quest1;
SDL_Surface *quest2;
SDL_Surface *quest3;
quest_pos.x=320;
quest_pos.y=240;

sprintf(quest_ch,"Congratulation !");
sprintf(quest_ch1," ");
sprintf(quest_ch2," ");
sprintf(quest_ch3," ");
SDL_Color blue = {45,58,223};

quest=TTF_RenderText_Solid(police,quest_ch,blue);
quest1=TTF_RenderText_Solid(police,quest_ch1,blue);
quest2=TTF_RenderText_Solid(police,quest_ch2,blue);
quest3=TTF_RenderText_Solid(police,quest_ch3,blue);
SDL_BlitSurface(quest, NULL, screen,&quest_pos);
SDL_BlitSurface(quest1, NULL, screen,&quest1_pos);
SDL_BlitSurface(quest2, NULL, screen,&quest2_pos);
SDL_BlitSurface(quest3, NULL, screen,&quest3_pos);
SDL_Flip(screen);


}else
{SDL_FreeSurface(quest);
SDL_FreeSurface(quest1);
SDL_FreeSurface(quest2);
SDL_FreeSurface(quest3);

SDL_Flip(screen);

SDL_Surface *image=IMG_Load("galaxywonder.jpg");
SDL_Rect image_pos;
image_pos.x=0;
image_pos.y=0;
SDL_BlitSurface(image, NULL, screen,&image_pos);

SDL_Surface *quest;
SDL_Surface *quest1;
SDL_Surface *quest2;
SDL_Surface * quest3;


sprintf(quest_ch,"you lost ");
sprintf(quest_ch1," ");
sprintf(quest_ch2," ");
sprintf(quest_ch3," ");
SDL_Color blue = {45,58,223};
quest_pos.x=320;
quest_pos.y=240;
quest=TTF_RenderText_Solid(police,quest_ch,blue);
quest1=TTF_RenderText_Solid(police,quest_ch1,blue);
quest2=TTF_RenderText_Solid(police,quest_ch2,blue);
quest3=TTF_RenderText_Solid(police,quest_ch3,blue);
SDL_BlitSurface(quest, NULL, screen,&quest_pos);
SDL_BlitSurface(quest1, NULL, screen,&quest1_pos);
SDL_BlitSurface(quest2, NULL, screen,&quest2_pos);
SDL_BlitSurface(quest3, NULL, screen,&quest3_pos);
SDL_Flip(screen);
 

}









            }else if((event.button.button==SDL_BUTTON_LEFT)&&(x >99)&&(x<450)&&(y >399)&&(y <450))
             {if(pos==2)
{SDL_FreeSurface(quest);
SDL_FreeSurface(quest1);
SDL_FreeSurface(quest2);
SDL_FreeSurface(quest3);
SDL_FreeSurface(screen);
SDL_Flip(screen);
/*updating and showing after win*/ 
SDL_Surface *screen= SDL_SetVideoMode( 900,568, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_Surface *image=IMG_Load("galaxywonder.jpg");
SDL_Rect image_pos;
image_pos.x=0;
image_pos.y=0;
SDL_BlitSurface(image, NULL, screen,&image_pos);
SDL_Flip(screen);
SDL_Surface *quest;
SDL_Surface *quest1;
SDL_Surface *quest2;
SDL_Surface * quest3;

sprintf(quest_ch,"Congratulation !");
sprintf(quest_ch1," ");
sprintf(quest_ch2," ");
sprintf(quest_ch3," ");
SDL_Color blue = {45,58,223};
quest=TTF_RenderText_Solid(police,quest_ch,blue);
quest1=TTF_RenderText_Solid(police,quest_ch1,blue);
quest2=TTF_RenderText_Solid(police,quest_ch2,blue);
quest3=TTF_RenderText_Solid(police,quest_ch3,blue);
quest_pos.x=320;
quest_pos.y=240;

SDL_BlitSurface(quest, NULL, screen,&quest_pos);
SDL_BlitSurface(quest1, NULL, screen,&quest1_pos);
SDL_BlitSurface(quest2, NULL, screen,&quest2_pos);
SDL_BlitSurface(quest3, NULL, screen,&quest3_pos);
SDL_Flip(screen);
 

}else
{SDL_FreeSurface(quest);
SDL_FreeSurface(quest1);
SDL_FreeSurface(quest2);
SDL_FreeSurface(quest3);
SDL_FreeSurface(screen);
SDL_Flip(screen);
SDL_Surface *screen= SDL_SetVideoMode( 900,568, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_Flip(screen);
SDL_Surface *image=IMG_Load("galaxywonder.jpg");
SDL_Rect image_pos;
image_pos.x=0;
image_pos.y=0;
SDL_BlitSurface(image, NULL, screen,&image_pos);
SDL_Surface *quest;
SDL_Surface *quest1;
SDL_Surface *quest2;
SDL_Surface * quest3;
/*updating and showing after lose*/
sprintf(quest_ch,"you lost ");
sprintf(quest_ch1," ");
sprintf(quest_ch2," ");
sprintf(quest_ch3," ");
SDL_Color blue = {45,58,223};
quest=TTF_RenderText_Solid(police,quest_ch,blue);
quest1=TTF_RenderText_Solid(police,quest_ch1,blue);
quest2=TTF_RenderText_Solid(police,quest_ch2,blue);
quest3=TTF_RenderText_Solid(police,quest_ch3,blue);
quest_pos.x=320;
quest_pos.y=240;
SDL_BlitSurface(quest, NULL, screen,&quest1_pos);
SDL_BlitSurface(quest1, NULL, screen,&quest1_pos);
SDL_BlitSurface(quest2, NULL, screen,&quest2_pos);
SDL_BlitSurface(quest3, NULL, screen,&quest3_pos);
SDL_Flip(screen);

}
   
              }

}

}
}

}


void randomize(int * a,int * b, int * c,int * d)
{

 srand(time(NULL));
(*a)=rand()%(9-0+1)+0;
(*b)=rand()%(9-0+1)+0;
(*c)=rand()%(9-0+1)+0;
(*d)=rand()%(9-0+1)+0;


}




void show_enigme()
{int a,b,c,d;
char quest_ch[50];
randomize(&a,&b,&c,&d);

float a_f=(float)a;
float b_f=(float)b;
float c_f=(float)c;
float d_f=(float)d;

float x_true,y_true,x_false1,y_false1,x_false,y_false;
y_true=d_f;
x_true=((c_f)-(b_f)*(d_f))/(a_f);


x_false=x_true+3;
y_false=y_true-2;

x_false1=x_true+4;
y_false1=y_true-3;


TTF_Font *police;

SDL_Rect quest_pos;
SDL_Rect quest1_pos;
SDL_Rect quest2_pos;
SDL_Rect quest3_pos;
SDL_Surface *quest;
SDL_Surface *quest1;
SDL_Surface *quest2;
SDL_Surface *quest3;
SDL_Color white = {0,0,0};
SDL_Color yellow = {225,225,0};
SDL_Color orange= {220,116,31};
SDL_Surface *screen;
SDL_Surface *image;
image=IMG_Load("galaxywonder.jpg");
SDL_Rect image_pos;
image_pos.x=0;
image_pos.y=0;
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
if (TTF_Init() < 0)
 {
  printf("error\n");
}
else{
police = TTF_OpenFont("Bebas-Regular.ttf", 50);
if (police == NULL)
 {
  printf("error dans open font enigme\n");
}

else
{
int pos;
char quest_ch1[20];
char quest_ch2[20];
char quest_ch3[20];
 screen= SDL_SetVideoMode( 900,568, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_BlitSurface(image, NULL, screen,&image_pos);
srand(time(NULL));
pos=rand()%(2-0+1)+0;
switch(pos)
{case 0:
sprintf(quest_ch1,"a. x=%f, y=%f ",x_true,y_true);
sprintf(quest_ch2,"b. x=%f, y=%f",x_false,y_false);
sprintf(quest_ch3,"c. x=%f, y=%f ",x_false1,y_false1);
break;
case 1:
sprintf(quest_ch1,"a. x=%f, y=%f ",x_false,y_false);
sprintf(quest_ch2,"b. x=%f, y=%f",x_true,y_true);
sprintf(quest_ch3,"c. x=%f, y=%f ",x_false1,y_false1);
break;


case 2:

sprintf(quest_ch1,"a. x=%f, y=%f ",x_false1,y_false1);
sprintf(quest_ch2,"b. x=%f, y=%f",x_false,y_false);
sprintf(quest_ch3,"c. x=%f, y=%f ",x_true,y_true);
break;






}



quest_pos.x=74;
quest_pos.y=100;

quest1_pos.x=100;
quest1_pos.y=200;

quest2_pos.x=100;
quest2_pos.y=300;


quest3_pos.x=100;
quest3_pos.y=400;

char op_plus[]="+";
char op_egal[]="=";

sprintf(quest_ch,"%2fx + %2fy = %2f ?",a_f,b_f,c_f);

quest=TTF_RenderText_Solid(police,quest_ch,orange);
SDL_BlitSurface(quest, NULL, screen,&quest_pos);

quest1=TTF_RenderText_Solid(police,quest_ch1,yellow);
quest2=TTF_RenderText_Solid(police,quest_ch2,yellow);
quest3=TTF_RenderText_Solid(police,quest_ch3,yellow);

SDL_BlitSurface(quest1, NULL, screen,&quest1_pos);
SDL_BlitSurface(quest2, NULL, screen,&quest2_pos);
SDL_BlitSurface(quest3, NULL, screen,&quest3_pos);


SDL_Flip(screen);

input_show(pos,quest,quest1,quest2,quest3,&quest_ch[50],&quest_ch1[20],&quest_ch2[20],&quest_ch3[20],police,quest_pos,quest1_pos,quest2_pos,quest3_pos,screen);

TTF_CloseFont(police);
TTF_Quit();

}

}
}
 //mouse part 

void show_enigme1()
{int a,b,c,d;
char quest_ch[50];
randomize(&a,&b,&c,&d);

float a_f=(float)a;
float b_f=(float)b;
float c_f=(float)c;
float d_f=(float)d;

float x_true,y_true,x_false1,y_false1,x_false,y_false;
y_true=d_f;
x_true=((c_f)-(b_f)*(d_f))/(a_f);


x_false=x_true+3;
y_false=y_true-2;

x_false1=x_true+4;
y_false1=y_true-3;


TTF_Font *police;

SDL_Rect quest_pos;
SDL_Rect quest1_pos;
SDL_Rect quest2_pos;
SDL_Rect quest3_pos;
SDL_Surface *quest;
SDL_Surface *quest1;
SDL_Surface *quest2;
SDL_Surface *quest3;
SDL_Color white = {0,0,0};
SDL_Color yellow = {225,225,0};
SDL_Color orange= {220,116,31};
SDL_Surface *screen;
SDL_Surface *image;
image=IMG_Load("galaxywonder.jpg");
SDL_Rect image_pos;
image_pos.x=0;
image_pos.y=0;
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
if (TTF_Init() < 0)
 {
  printf("error\n");
}
else{
police = TTF_OpenFont("Bebas-Regular.ttf", 50);
if (police == NULL)
 {
  printf("error dans open font enigme\n");
}

else
{
int pos;
char quest_ch1[20];
char quest_ch2[20];
char quest_ch3[20];
 screen= SDL_SetVideoMode( 900,568, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_BlitSurface(image, NULL, screen,&image_pos);
srand(time(NULL));
pos=rand()%(2-0+1)+0;
switch(pos)
{case 0:
sprintf(quest_ch1,"° x=%f, y=%f ",x_true,y_true);
sprintf(quest_ch2,"° x=%f, y=%f",x_false,y_false);
sprintf(quest_ch3,"° x=%f, y=%f ",x_false1,y_false1);
break;
case 1:
sprintf(quest_ch1,"° x=%f, y=%f ",x_false,y_false);
sprintf(quest_ch2,"° x=%f, y=%f",x_true,y_true);
sprintf(quest_ch3,"° x=%f, y=%f ",x_false1,y_false1);
break;


case 2:

sprintf(quest_ch1,"° x=%f, y=%f ",x_false1,y_false1);
sprintf(quest_ch2,"° x=%f, y=%f",x_false,y_false);
sprintf(quest_ch3,"° x=%f, y=%f ",x_true,y_true);
break;






}



quest_pos.x=74;
quest_pos.y=100;

quest1_pos.x=100;
quest1_pos.y=200;

quest2_pos.x=100;
quest2_pos.y=300;


quest3_pos.x=100;
quest3_pos.y=400;

char op_plus[]="+";
char op_egal[]="=";

sprintf(quest_ch,"%2fx + %2fy = %2f ?",a_f,b_f,c_f);

quest=TTF_RenderText_Solid(police,quest_ch,orange);
SDL_BlitSurface(quest, NULL, screen,&quest_pos);

quest1=TTF_RenderText_Solid(police,quest_ch1,yellow);
quest2=TTF_RenderText_Solid(police,quest_ch2,yellow);
quest3=TTF_RenderText_Solid(police,quest_ch3,yellow);

SDL_BlitSurface(quest1, NULL, screen,&quest1_pos);
SDL_BlitSurface(quest2, NULL, screen,&quest2_pos);
SDL_BlitSurface(quest3, NULL, screen,&quest3_pos);


SDL_Flip(screen);

input_show1(pos,quest,quest1,quest2,quest3,&quest_ch[50],&quest_ch1[20],&quest_ch2[20],&quest_ch3[20],police,quest_pos,quest1_pos,quest2_pos,quest3_pos,screen);

TTF_CloseFont(police);
TTF_Quit();


}

}
}

#endif






















