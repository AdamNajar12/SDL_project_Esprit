
#define background_H_INCLUDED
#define CAMERA_W 1386  ///// la largeur/hauteur du screen dans setvideomod
#define CAMERA_H 490


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct
{
SDL_Surface *background;
SDL_Rect backg;
Mix_Music *music;
SDL_Rect pos_camera;

}background;


void initialiser_back(background *b);
void afficher_background (SDL_Surface *screen,background *b);
void scrolling (background *b, int direction );






