

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "perso.h" 
	 
	


void init_perso(personnage *pers,TTF_Font *fontTest){
	pers->mat[0][0]=IMG_Load("p.png"); 
        pers->mat[0][1]=IMG_Load("p1.png");
        pers->mat[0][2]=IMG_Load("p2.png");
        pers->mat[0][3]=IMG_Load("p3.png");	
        pers->mat[1][0]=IMG_Load("p4.png");
        pers->mat[1][1]=IMG_Load("p5.png");
        pers->mat[1][2]=IMG_Load("p6.png");
        pers->mat[1][3]=IMG_Load("p7.png");
        pers->mat[2][0]=IMG_Load("p16.png");  
        pers->mat[2][1]=IMG_Load("p15.png");
        pers->mat[2][2]=IMG_Load("pee.png");
        pers->mat[2][3]=IMG_Load("p122.png");

pers->d=0;
pers->num=0;
pers->Positionmat.x=0;
pers->Positionmat.y=250;
pers->positionmatRel.x=-50;
pers->positionmatRel.y=0;





pers->nvie=3; 
pers->nscore=0; 

pers->vitesse=5;
pers->acceleration=0;
pers->up=0;


pers->vie=IMG_Load("v1.png");



// charger police
	

fontTest=TTF_OpenFont("arial.ttf",22);
SDL_Color fontColor={0,0,255};
pers->score=TTF_RenderText_Solid(fontTest,"Score :",fontColor);






}

 


void animateEntity(personnage *pers)
{

if(pers->num==3)
pers->num=0;
else pers->num++;

}


void deplacer_perso(int direction,personnage *pers){
	
	if(direction==0){
	          
	          pers->Positionmat.x+=25; 
                   
} 
	 else 
	     if(direction==1){ 
	           
	          pers->Positionmat.x-=25; }
	          
else if(direction==2)
{

pers->Positionmat.x+=2;

}
	



}



void movePerso(personnage *pers,Uint32 dt)
{
double dx;
dx=pers->vitesse*dt+0.5*pers->acceleration*dt*dt;

}




void blitEntity(personnage *pers,SDL_Surface *ecran)
{

SDL_BlitSurface(pers->mat[pers->d][pers->num],NULL,ecran,&pers->Positionmat);
SDL_Flip(ecran);

}

void afficherperso(personnage *pers,SDL_Surface *ecran)
{

SDL_Rect vieposition;
vieposition.x=0;
vieposition.y=20;
SDL_BlitSurface(pers->vie,NULL,ecran,&vieposition);
SDL_Flip(ecran);


//police1

SDL_Rect texte1Pos;
texte1Pos.x=0;
texte1Pos.y=70;
SDL_BlitSurface(pers->score,NULL,ecran,&texte1Pos);
SDL_Flip(ecran);



}
void saut(personnage * pers)
{


 pers->positionmatRel.x++;

            if(pers->positionmatRel.x>=50)
            {
                pers->positionmatRel.x=-50;
            }

            //On met à "0" les pos abs:
            pers->Positionmat.x = 0;
            pers->Positionmat.y = 250;

            //On calcule la valeur relative de y:
            pers->positionmatRel.y=(-0.04*(pers->positionmatRel.x*pers->positionmatRel.x)+100);

            //On calcule maintenant les valeurs abs
            pers->Positionmat.x = pers->Positionmat.x + pers->positionmatRel.x+50;
            pers->Positionmat.y = pers->Positionmat.y - pers->positionmatRel.y;



}



