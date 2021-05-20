#include "background.h"


void initialiser_back(background *b)
{

b->background=IMG_Load("background.png");

b->backg.x = 0;
b->backg.y = 0;
b->backg.w = b->background->w;
b->backg.h = b->background->h;

if(Mix_OpenAudio(4410,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}


b->music= Mix_LoadMUS("music1.mp3");

Mix_PlayMusic(b->music,-1);
b->pos_camera.x=0;
b->pos_camera.y=0;
b->pos_camera.w=CAMERA_W;
b->pos_camera.h=CAMERA_H;



}



void afficher_background (SDL_Surface *screen,background *b)
{
   SDL_BlitSurface(b->background,&b->pos_camera,screen,&b->backg);
}



void scrolling (background *b, int direction )
{
 if (direction==0)
  b->pos_camera.x++;
 else 
if 
  (direction==1)
  b->pos_camera.x--;
else 
if 
  (direction==2)
  b->pos_camera.y++;
else 
if 
 (direction==3)
 b->pos_camera.y--;
}
