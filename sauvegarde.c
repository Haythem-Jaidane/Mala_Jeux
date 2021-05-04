#include "sauvegarde.h"

void sauvegarder (SDL_Rect posperso, SDL_Rect posenemi , int score , SDL_Rect camera , char * nomfichier) {
save s;
FILE *fichier;
s.camera=camera;
s.posennemi=posenemi;
s.score=score;
s.posperso=posperso;
fichier=fopen(nomfichier,"wb");
if (fichier != NULL)
{
    fwrite(&s,sizeof(save),1,fichier);
    printf("success");
}else printf("failed");
fclose(fichier);
}

int charger ( SDL_Rect *posperso, SDL_Rect *posenemi , int *score , SDL_Rect *camera , char * nomfichier){
    FILE *fichier;
    save s;
    fichier=fopen(nomfichier,"rb");
    fread(&s,sizeof(save),1,fichier);
    fclose(fichier);
    *posperso=s.posperso;
    *posenemi=s.posennemi;
    *score=s.score;
    *camera=s.camera;
    printf("position pesro: %d,%d\n",s.posperso.x,s.posperso.y);
    printf("position enemie: %d,%d\n",s.posennemi.x,s.posennemi.y);
    printf("position camera: %d,%d\n",s.camera.x,s.camera.y);
    printf("score: %d\n",s.score);


}




