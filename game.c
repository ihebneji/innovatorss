#include"game.h"
#include"bg.h"
#include<stdio.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#define JUMP_POWER 10
#define MAX_SPEED 10

void initPerso(person *p)
{
  p->btn=IMG_Load("perso/moveforward/1.png"); 

p->pos.y=800;
p->pos.h=50;
p->pos.h=100;
p->pos.x=0;

p->direction=0;

}

void afficherPerso(person p, SDL_Surface * window)
{  
SDL_BlitSurface(p.btn,NULL,window,&p.pos); 

}
void movePerso (person *p,int xc,int check,int collision,int *next,int directionmv)
{
   printf("directionmv:%d\n",p->pos.x);
if(check==0)
xc=960;    
if(check==1)
xc=1550;
uint8_t* keystate=SDL_GetKeyState(NULL);

if(keystate[SDLK_RIGHT] ){ 
  
  if(collision!=3)
{
  p->pos.x+=7;}
if(p->pos.x>=xc)
p->pos.x=xc;
p->direction=1;
}
 if((keystate[SDLK_RIGHT]&&keystate[SDLK_LSHIFT]) ){
 
    
  if(collision!=3)
{p->pos.x+=10;}
if(p->pos.x>=xc)
p->pos.x=xc;
  }
   if ((keystate[SDLK_RIGHT]&&keystate[SDLK_LCTRL])){
    p->direction=4; 
    if(collision!=3)
{p->pos.x+=10;}
if(p->pos.x>xc)
p->pos.x=xc;
  }
  
if (keystate[SDLK_LEFT]){
 p->pos.x-=6;
if(p->pos.x<0)
p->pos.x=0;
}

   if ((keystate[SDLK_LEFT]&&keystate[SDLK_LSHIFT])){  
   p->pos.x-=10;
if(p->pos.x<=0)
p->pos.x=0;
  }
 
  if (keystate[SDLK_LEFT]&&keystate[SDLK_LCTRL]){
    p->direction=5; 
p->pos.x-=10;
if(p->pos.x<0)
p->pos.x=0;
  }



}

int collision_detection(person p)
{
  int trv=0;
    if((p.pos.x+p.aff_pers.w< p.pos_smoke.x-200)|(p.pos.x>p.pos_smoke.x+p.aff_smoke.w+150)|(p.pos_pers.y+p.aff_pers.h < p.pos_smoke.y)|(p.pos.y>p.pos_smoke.y+p.aff_smoke.h)){
  trv=0;
    }
  else 
  trv=1;
  return trv;
  
}


void inithealth(health *p)
{
p->pos_h.x=221;
p->pos_h.y=88;
p->pos_aff_h.h=48;
p->pos_aff_h.w=396;
p->pos_aff_h.x=15;
p->pos_aff_h.y=0;
p->lives=0;
}
void inithealth_image(health *p)
{
p->health=IMG_Load("health.png");
}
void animer_health(health *p,person *per,int reset)
{
  uint8_t* keystate=SDL_GetKeyState(NULL);
if(p->pos_aff_h.x>385)
{p->pos_aff_h.x=15;
p->lives++;
if(p->lives>3)
p->lives=3;
}

if(p->lives==3)
{p->pos_aff_h.x=385;
per->direction=-5;}
if(reset>200)
p->pos_aff_h.x=15;
}
void afficherhealth(health p, SDL_Surface * window)
{
SDL_BlitSurface(p.health,&p.pos_aff_h,window,&p.pos_h); 
SDL_FreeSurface(p.health);
}














 







void init_enemy(person *p)
{
 p->pos_enemy.x=2950;
 p->pos_enemy.y=740;
 p->pos_enemy.h=309;
 p->pos_enemy.w=427;
 p->enemy_counter=1;
 p->enemy_dir=1;

}

////////////////////////////el animation mta3 el enemy 7asb el niveau ya3mel animation 
void init_enemy_img(person *p,int counter,int level)
{
char filename[65];
if(level==1)
{if(p->enemy_dir==1)
sprintf(filename,"enemy2/%d.png",counter);
if(p->enemy_dir==2)
sprintf(filename,"enemy2/Comp/%d.png",counter);         
p->enemy=IMG_Load(filename);
p->enemy_counter++;
if(p->enemy_counter>37)
p->enemy_counter=1;}

if(level==2)
{if(p->enemy_dir==1)
sprintf(filename,"enemy/%d.png",counter);
if(p->enemy_dir==2)
sprintf(filename,"enemy/mv_bk/%d.png",counter);         
p->enemy=IMG_Load(filename);
p->enemy_counter++;
if(p->enemy_counter>24)
p->enemy_counter=1;}
}
void afficher_enemy(person p,SDL_Surface *window)
{
  SDL_BlitSurface(p.enemy,NULL,window,&p.pos_enemy);
  SDL_FreeSurface(p.enemy);
}
///////////////////////////////el enemy 3andou intervale mou3ayen yemchi fih fil main el interval fi zouz variablouwet min w max wel enemy theni fi min2 w max2
/////////////////////////ki el perso yod5el lel intervale hedheka el enemy  chouf el position mta3 el perso mba3ed yemchilo  

void move_enemy(person *p,int dir,int direction,int pos,int y,health *b,int *max,int *min,int check)
{

colide coll;
SDL_Rect rect;
rect.x=pos;
rect.y=y;
rect.h=170;
rect.w=150;
coll= collision2 (p->pos_enemy,rect);
if(check==0 | check==3)
{if(coll.bottom | coll.right |coll.left | coll.top)
b->pos_aff_h.x+=7;
}

  if(dir==1)
  {p->pos_enemy.x+=5;
  if(p->pos_enemy.x>=(*max))
  p->enemy_dir=2;}
  

  if(pos>=(*min) && pos<=(*max))
{
   if(pos<p->pos_enemy.x)
   {
    p->enemy_dir=2;
    p->pos_enemy.x-=10;
   }
   if(pos>p->pos_enemy.x)
   {
    p->enemy_dir=1;
    p->pos_enemy.x+=10;
   }
   
}
  if(dir==2)
{
  p->pos_enemy.x-=5;
  }
  if(p->pos_enemy.x<=(*min))
  p->enemy_dir=1;
 if(direction==1)
 {(*max)-=7;
  (*min)-=7;
 p->pos_enemy.x-=7;}
 if(direction==-1)
 {(*max)+=7;
  (*min)+=7;
 p->pos_enemy.x+=7;}
 if(direction==3)
 {(*max)-=15;
  (*min)-=15;
 p->pos_enemy.x-=15;}
 if(direction==-3)
 {(*max)+=15;
 (*min)+=15;
 p->pos_enemy.x+=15;}

}


