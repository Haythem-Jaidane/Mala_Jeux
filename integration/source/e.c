
        /** 
* @file e.c 
*/ 


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include "e.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
/** 
* @brief To initialize the enigme. 
* @param enig enigme 
* @param ancienne
* @return Nothing 
*/ 

void init_enigme(enigme *enig,int ancienne[])
{
    int i;
    enig->fenetre_enigme=NULL;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    enig->image=NULL;
    enig->posim.x=0;
    enig->posim.y=0;
    enig->post.x=120;
    enig->post.y=50;
    for(i=0;i<6;i++)
    {
       ancienne[i]=0;
    }
}
/** 
* @brief To fill le fichiers questions. 
* @param questions
*
* @return Nothing 
*/ 

void remplir_fichier(char questions[])
{
    FILE *fq=NULL;
    fq=fopen(questions,"w");
    if(fq==NULL) printf("erreur de l'ouverture");
    else
    {
	fprintf(fq,"Le femur est l os le plus long de notre corp?  \nLe dioxygene occupe 21%  l air? \nEst-ce que la peau est l organe le plus lourd du corps humain? \nLe Co² est du chlorure de carbone? \n les globules blanc servent a transporter les gazs? \n  le Mg represente le magnesium? \n");
	fclose(fq);
    }
}
/** 
* @brief pour afficher enigme. 
* @param enig enigme
* @param ancienne 
* @param question
* @param ligne
* @return Nothing 
*/ 

void afficher_enigme(enigme *enig,int ancienne[],char questions[],int *ligne)
{
   FILE *fq=NULL;
   int i,ici=0,taille=200,l;
   char ch[200];
   SDL_Color couleur={255,0,0};
   do
   {  ici=0;
      l=1+random()%6;
  printf("\nvoici notre premier l :%d\n",l);
      for(i=0;i<6;i++)
      {
         if(ancienne[i]==l)
                 {
                    ici=1;
                    break;
                 }
      }
   }while(ici==1);
   for(i=0;i<6;i++)
   {
         if(ancienne[i]==0)
                 {
                    ancienne[i]=l;
                    break;
                 }
   }
   if(ancienne[5]!=0) { 
              	         for(i=0;i<6;i++)
              	         {
                            ancienne[i]=0;
              	         }
                      }
   enig->fenetre_enigme=SDL_SetVideoMode(1300,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
   enig->image=IMG_Load("espace.png");
   enig->police=TTF_OpenFont("espace.ttf",60);
   fq=fopen(questions,"r");
   if(fq==NULL) printf("erreur de l'ouverture");
    else{ 
           (*ligne)=1;
	   while((fgets(ch,taille,fq)!=NULL)&&(*ligne<l))
	        {
	    	    (*ligne)++;
	        }
           enig->texte=TTF_RenderText_Blended(enig->police,ch,couleur);
	   SDL_BlitSurface(enig->image,NULL,enig->fenetre_enigme,&(enig->posim));
	   SDL_BlitSurface(enig->texte,NULL,enig->fenetre_enigme,&(enig->post));
	   SDL_Flip(enig->fenetre_enigme);
	   fclose(fq);
        }
   
}
/** 
* @brief donner la solution.
* @param q
* @return s
*/ 

int solution(int q)
{
int s=0;
    switch(q)
    {
    case 1:
        s=2;
        break;
    case 2:
        s=1;
        break;
    case 3:
        s=1;
        break;
    case 4:
        s=2;
        break;
    case 5:
        s=2;
        break;
    case 6:
        s=1;
        break;
    }
    return s;
}
/** 
* @brief resoudre. 
* @param affiche
*
* @return r
*/ 

int resolution(int *affiche)
{
    SDL_Event event;
    int r=0;
    SDL_PollEvent(&event);
    switch(event.type)
    {

    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
        case SDLK_a:
            r=1;
	    *affiche=1;
            break;
        case SDLK_z:
            r=2;
	    *affiche=1;
            break;
   
        }
        break;
    }
    return r;
}
/** 
* @brief afficher resultat. 
* @param enig enigme 
* @param solution
* @param resolution
* @return Nothing 
*/ 

void afficher_resultat(enigme *enig,int solution,int resolution)
{
   
    if(solution==resolution)
    {
        enig->image=IMG_Load("0.png");
        SDL_BlitSurface(enig->image,NULL,enig->fenetre_enigme,&(enig->posim));
        SDL_Flip(enig->fenetre_enigme);
       
    }
    else
    {
        enig->image=IMG_Load("1.png");
        SDL_BlitSurface(enig->image,NULL,enig->fenetre_enigme,&(enig->posim));
        SDL_Flip(enig->fenetre_enigme);
        
    }
}
/** 
* @brief free memory. 
* @param enig enigme 
* @return Nothing 
*/ 

void ffree(enigme *enig)
{
    TTF_CloseFont(enig->police);
    TTF_Quit();
    SDL_FreeSurface(enig->image);
    SDL_FreeSurface(enig->texte);
    SDL_Quit();
}
