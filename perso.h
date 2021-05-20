#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
typedef struct
{
int nvie;
int nscore;
SDL_Surface *mat[3][4];
SDL_Rect Positionmat;
SDL_Rect positionmatRel;
int d;
int num;
double vitesse;
double acceleration;
SDL_Surface *vie;
SDL_Surface *score;
int up;

}personnage;
personnage pers;




void init_perso(personnage *pers,TTF_Font *fontTest);
void afficherperso(personnage *pers,SDL_Surface *ecran);
void deplacer_perso(int  direction,personnage *pers);
void  movePerso(personnage *pers,Uint32 dt);
void animateEntity(personnage *pers);
void blitEntity(personnage *pers,SDL_Surface *ecran);
void afficherperso(personnage *pers,SDL_Surface *ecran);
void saut(personnage * pers);
