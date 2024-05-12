#include<stdio.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include"bg.h"
#include"game.h"
int main() {

  int afficher_pers=0;
int min=1900;
int max=3000;
int min2=1000;
int max2=1900;
int collision=0;
int valueeee=0;
  SDL_Surface * window=NULL ;
  SDL_Event event;
   int y = 0,x=0,check=0,next=7,pos_av=0,animui=1,death_timer=0,but=5,fpsof=1,bgg=1,xc=960;
int coin_dir=0;
  person pers,enemy,enemy2;
   background bg,coin;
   health h_bar,h;
  Mix_Music * music=NULL;
  Mix_Chunk * mus,*mus_coins,*walking;
  int boucle = 1;
  char gamename;
  char chaine_nom[15]={'\0'};
  text_pers txt_score,txt_time;
  times t,t2;
  SDL_Init(SDL_INIT_VIDEO);
  window = (SDL_Surface*)malloc(sizeof(SDL_Surface));
  window = SDL_SetVideoMode(0,0,32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_SWSURFACE |SDL_FULLSCREEN );
  initPerso(&pers);
  inithealth(&h);
  initBack(&bg);
 init_enemy(&enemy);
 init_enemy(&enemy2);
 init_coin1(&coin,0,100);

 while (boucle) {   
     bg.pos_img.y=0;
    SDL_FillRect(window,NULL,0);
    bg.pos_img.y=0;
    init_bgimage(&bg,2);
      inithealth_image(&h);   
      
     if(h.lives!=4)
    { 
    aficherBack(bg,window);
    scrolling(&bg,pers.pos.x,&coin_dir,valueeee); 

    movePerso (&pers,xc,bg.chck2,collision,&next,valueeee); 
    animer_health(&h,&pers,pers.death);
    afficherhealth(h,window);
   
  load_img_coin(&coin,coin.coin_counter);
    if(coin.c1==0)
    {afficher_coin(coin.coin,window,coin.pos_coin.x,coin.pos_coin.y);
    move_coin1(&coin,pers.pos.x,pers.pos.y,coin_dir,bg,mus_coins,&t2.score);
     } 
    afficherPerso(pers,window);
   if(pers.death>=90)
   {h.lives=4;
   next=8;
   }
    }
 init_enemy_img(&enemy,enemy.enemy_counter,1);
 afficher_enemy(enemy,window);
 move_enemy(&enemy,enemy.enemy_dir,coin_dir,pers.pos.x,pers.pos.y,&h,&max,&min,0);
 init_enemy_img(&enemy2,enemy2.enemy_counter,2);
 afficher_enemy(enemy2,window);
 move_enemy(&enemy2,enemy2.enemy_dir,coin_dir,pers.pos.x,pers.pos.y,&h,&max2,&min2,0);
 
    while (SDL_PollEvent( &event)) {
      switch (event.type) {
        case SDL_QUIT:
          boucle = 0;
          break;
  
          case SDL_KEYDOWN:
          if (event.key.keysym.sym == SDLK_ESCAPE)
          boucle=0;
       
      break;
      }
    }
    SDL_Flip(window);
    }
    SDL_Quit();
  return 0;
}
