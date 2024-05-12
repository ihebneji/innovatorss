#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "bg.h"
#include "game.h"
#include <stdbool.h>
#include <math.h>

void initBack(background *b)
{
b->camera_pos.x=0;
b->camera_pos.y=0;
b->pos_img.x=0;
b->pos_img.y=120;
b->pos_img.w=1920;
b->pos_img.h=1080/2;
b->bg_counter=0;
b->value=1920;
}
int check_bg(background *b,int xc ,int posbg)
{
  uint8_t* keystate=SDL_GetKeyState(NULL);
  int chk=0;
  if(xc>950)
  {if(keystate[SDLK_RIGHT])
  {
   b->value+=5;
   }
   if(keystate[SDLK_RIGHT]&&keystate[SDLK_LSHIFT])
   {
    b->value+=10;}
   if(b->value>=5000)
   chk=1;
   }
   if(xc<=0 && posbg!=0)
  {if(keystate[SDLK_LEFT])
  {
  b->value-=5;}
  if(keystate[SDLK_LEFT]&&keystate[SDLK_LSHIFT])
{ 
b->value-=10;}
}
   return chk;
}
int check_bg2(background *b,int xc)
{
  uint8_t* keystate=SDL_GetKeyState(NULL);
  int chk=0;
  if(xc>950)
  {if(keystate[SDLK_d])
  {
   b->value2+=5;
   }
   if(keystate[SDLK_d]&&keystate[SDLK_LSHIFT])
   {
    b->value2+=10;}
   if(b->value2>=5000)
   chk=1;
   }
   if(xc<=0)
  {if(keystate[SDLK_LEFT])
  {
  b->pos_img.x-=5;}
  if(keystate[SDLK_LEFT]&&keystate[SDLK_LSHIFT])
 {
  b->pos_img.x-=10;}
  }
  
   return chk;
}
void init_bgimage(background *b,int level)
{
  char filename[65];


b->bg=(SDL_Surface*)malloc(sizeof(SDL_Surface));
sprintf(filename,"level1/0.jpg");        
b->bg=IMG_Load(filename);  
}
void aficherBack(background b,SDL_Surface *window)
{
SDL_BlitSurface(b.bg,NULL,window,&b.pos_img);
SDL_FreeSurface(b.bg);
}
void scrolling(background *b,int xc,int *dir,int directionmv)
{
  (*dir)=0;
  b->chck2=check_bg(b,xc,b->pos_img.x);
    uint8_t* keystate=SDL_GetKeyState(NULL);
    if(b->chck2==0)
{if(xc>950 ){
if(keystate[SDLK_RIGHT] |directionmv ==1)
{
(*dir)=1;
b->pos_img.x-=5;}
if((keystate[SDLK_RIGHT]&&keystate[SDLK_LSHIFT] )|directionmv==7)
{
  (*dir)=3;
b->pos_img.x-=10;}
}}
if(xc<=0 && (b->pos_img.x!=0))
{if((keystate[SDLK_LEFT])|directionmv==2)
{
  (*dir)=-1;
b->pos_img.x+=5;}
if((keystate[SDLK_LEFT]&&keystate[SDLK_LSHIFT])|directionmv==8)
{
  (*dir)=-3;
b->pos_img.x+=10;}
}

}

























colide collision2(SDL_Rect rect1, SDL_Rect rect2) {
    colide result = {false, false, false, false};

    // Check if the rectangles overlap
    if (rect1.x + rect1.w >= rect2.x &&
        rect1.x <= rect2.x + rect2.w &&
        rect1.y + rect1.h >= rect2.y &&
        rect1.y <= rect2.y + rect2.h) {
        // Determine which sides of the rectangles collided
        int dx = rect1.x - rect2.x;
        int dy = rect1.y - rect2.y;
        int dw = rect1.w + rect2.w;
        int dh = rect1.h + rect2.h;

        if (dy < dh / 2) {
            result.top = true;
        }
        else if (dy > dh / 2) {
            result.bottom = true;
        }

        if (dx < dw / 2) {
            result.left = true;
        }
        else if (dx > dw / 2) {
            result.right = true;
        }
    }

    return result;
}

////////////el animation mta3 el coin ki dour
void load_img_coin(background *b,int coins)
{
  char filename[50];
sprintf(filename,"coin/%d.png",coins);        
b->coin=IMG_Load(filename); 
b->coin_counter++;
if(b->coin_counter>30)
b->coin_counter=1;
}
void init_coin1(background *b,int offsetx,int offsety)
  {
    b->pos_coin.x=900;
    b->pos_coin.y=750;
     b->pos_coin.x+=offsetx;
  b->pos_coin.y+=offsety;
  b->coin_counter=1;
  b->c1=0;
  }

//////////////////////////hedhi el fonction ki tet7arek el background el coin tet7arek m3aha 
void move_coin1(background *b,int xc,int y,int dir,background p,Mix_Chunk  *mus_coin,int *score)
{
  uint8_t* keystate=SDL_GetKeyState(NULL);
  SDL_Rect rectp;
  rectp.x=xc;
  rectp.y=y;
  rectp.h=170;
  rectp.w=150;
 colide coll;
 
  if(xc>950 ){
if(dir==1)
{
b->pos_coin.x-=5;}
if(dir ==3)
{
b->pos_coin.x-=15;}
}
if(xc<=0 && (p.pos_img.x!=0))
{if(dir==-1)
{
b->pos_coin.x+=5;}
if(dir==-3)
{
b->pos_coin.x+=15;}
}
////////////////////////////w lina ki tsir collision mabin el perso wel coin el score izid wil coin tetna7a
coll= collision2 (b->pos_coin,rectp);
if(coll.bottom | coll.right |coll.left | coll.top)
b->c1=1;
if(b->c1==1)
{
(*score)+=100;}
}
void afficher_coin(SDL_Surface *coin,SDL_Surface *window,int x,int y)
{
 SDL_Rect rect;
 rect.x=x;
 rect.y=y;
 SDL_BlitSurface(coin,NULL,window,&rect);

}
///////////////////////////////////hedhi el fonction mta3 el collision trigonometrique eli detecti ken el perso mas el cercle circonscri mta3 el coin w traja3 valeur 1 keni verifier sinon 0
int check_rotation_collision(double x1, double y1, double w1, double h1, double angle1,double x2, double y2, double w2, double h2, double angle2) {
    // Calculate the center points of the rectangles
    double rect1_center_x = x1 + w1 / 2.0;
    double rect1_center_y = y1 + h1 / 2.0;
    double rect2_center_x = x2 + w2 / 2.0;
    double rect2_center_y = y2 + h2 / 2.0;

    // Calculate the distance between the centers of the rectangles
    double dx = rect2_center_x - rect1_center_x;
    double dy = rect2_center_y - rect1_center_y;
    double distance = sqrt(dx * dx + dy * dy);

    // Calculate the angles between the centers of the rectangles and the x-axis
    double angle_diff1 = atan2(rect2_center_y - rect1_center_y, rect2_center_x - rect1_center_x) - angle1;
    double angle_diff2 = atan2(rect1_center_y - rect2_center_y, rect1_center_x - rect2_center_x) - angle2;

    // Calculate the width and height of the bounding box containing both rectangles
    double max_width = (w1 + w2) / 2.0;
    double max_height = (h1 + h2) / 2.0;

    // Check for collision using trigonometry
    if (fabs(dx * cos(angle_diff1) + dy * sin(angle_diff1)) <= max_width &&
        fabs(dx * cos(angle_diff2) + dy * sin(angle_diff2)) <= max_width &&
        fabs(-dx * sin(angle_diff1) + dy * cos(angle_diff1)) <= max_height &&
        fabs(-dx * sin(angle_diff2) + dy * cos(angle_diff2)) <= max_height) {
        return 1; // Collision detected
    }

    return 0; // No collision
}
