#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "perso.h" 
 
	 
	int main ( int argc, char *argv[] ){
	SDL_Surface *ecran=NULL; 
	 int  d; 
	personnage pers; 
	Uint32 dt,t_prev;



SDL_Init(SDL_INIT_VIDEO);
TTF_Init();	
int continuer=1;
	SDL_Event evenement; 
	
	ecran=SDL_SetVideoMode(600,600,32,SDL_HWSURFACE); 
	
//creer et stocker des couleurs
Uint32 red,green,blue, couleurCapeDuPersonnage;
couleurCapeDuPersonnage=SDL_MapRGB(ecran->format,0,0,128);
red=SDL_MapRGB(ecran->format,255,0,0);

green=SDL_MapRGB(ecran->format,0,255,0);
blue=SDL_MapRGB(ecran->format,0,0,255);
SDL_FillRect(ecran,NULL,couleurCapeDuPersonnage);
SDL_Flip(ecran);


//le personnage
init_perso(&pers);

	


	
while(continuer){


SDL_FillRect(ecran,NULL,couleurCapeDuPersonnage);
afficherperso(&pers,ecran);




blitEntity(&pers,ecran);
	
SDL_WaitEvent(&evenement);
t_prev=SDL_GetTicks();


if(evenement.type==SDL_QUIT)
{break;}	

if(evenement.type==SDL_KEYDOWN){
	    if(evenement.key.keysym.sym==SDLK_LEFT){
	         d=1;
               	  pers.d=1;          
} 
	  else 
	    if (evenement.key.keysym.sym==SDLK_RIGHT){
	          d=0; 
	           
                 pers.d=0;
} 
    else 
	    if (evenement.key.keysym.sym==SDLK_a){

              d=2;
              pers.d=2;	   
}
 else 
	    if (evenement.key.keysym.sym==SDLK_SPACE)
{

pers.acceleration+=0.005;

}
else if (evenement.key.keysym.sym==SDLK_d)
{    

pers.acceleration-=0.01;

}

else if (evenement.key.keysym.sym==SDLK_UP)
{
pers.mat[0][0]=pers.mat[0][1];
pers.up=1;
saut(&pers,dt,200);

 
}
if(d>=0 && d<=1)
	 {deplacer_perso(d,&pers);}
movePerso(&pers,dt);         
animateEntity(&pers);

      
}
dt=SDL_GetTicks()-t_prev;



}
	

SDL_Surface *vie;
        SDL_Surface *score;
//Liberer la memoire

SDL_FreeSurface(pers.vie);
SDL_FreeSurface(pers.score);
SDL_FreeSurface(pers.mat[d][pers.num]);
SDL_FreeSurface(ecran); 
	TTF_Quit();
	SDL_Quit();  
	return 0; 
	}

