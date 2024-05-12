#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include<stdio.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
typedef struct
{
SDL_Surface *ui;
SDL_Rect pos_ui;
}chara;
typedef struct
{
SDL_Surface *bg_ui,*bord,*optimized;
SDL_Rect pos_ui;
SDL_Event even;
}ui_char;
typedef struct
{
float x;
float y;
}vector2d;
typedef struct 
{
  SDL_Rect pos,pos2;
  vector2d vel,vel2;
  vector2d acc,acc2;
  SDL_Rect rect,pos_minipers;
SDL_Surface *p1,*btn,*smoke,*op_smoke,*mini_pers,*enemy;
SDL_Surface *op_p;
SDL_Surface *p2,*op_p2,*mini_enemy;
SDL_Rect pos_pers,pos_enemy,pos_mini_enemy;
SDL_Rect aff_pers,pos_smoke;
SDL_Rect pos_pers2,aff_smoke;
SDL_Rect aff_pers2;
SDL_Event event;
int direction,collision,sprint,slide,i,jump,death,smoke_c;
int direction2,collision2,sprint2,slide2,i2,jump2,death2,smoke_c2;
int coll_portal;
int colli_pers,enemy_dir,enm_dir_mv;
int enemy_counter,value_enem_mini;
}person;



typedef struct
{
SDL_Surface *bg_g;
SDL_Rect pos_bg;
SDL_Surface *bg_g2;
SDL_Rect pos_bg2;
}bg_game;
typedef struct 
{
SDL_Surface *lost_ui,*heart,*op_h,*health_bar,*op_hbar,*inviz,*op_inviz;
SDL_Surface *health,*op_health,*op_score,*op_lostui;
SDL_Surface *optimize,*ball,*op_ball;
SDL_Rect score_pos,pos_ball;
SDL_Rect pos_h_bar;
SDL_Rect pos_h,pos_inviz;
SDL_Rect pos_aff_h,pos_aff_inv;
SDL_Rect pos_heart;
int lives,smoke_toggle;
SDL_Rect aff_heart;
}health;
typedef struct 
{
  int score;
  int m;
  int s;
  int ms;

}times;
typedef struct
{
SDL_Rect pos;
SDL_Surface *tsurf ,*ts_score,*t_timer;
TTF_Font *police,*p_score,*p_timer;
SDL_Color coul;
char tixt[20];
}text_pers;

void initPerso(person *p);	
void animPerso(person *p,int dir,int player);
void afficherPerso(person p, SDL_Surface * window);	

void initheart(health *p);
void afficherheart(health p, SDL_Surface * window);
void animheart(health *p,int num,int reset,person *b);
void libererheart(health p);

int collision_detection(person p);
void inithealth_bar(health *p);
void afficherhealth_bar(health p, SDL_Surface * window);
void libererhealth_bar(health p);
void inithealth(health *p);
void animer_health(health *p,person *per,int reset);
void inithealth_image(health *p);
void initheart_image(health *p);
void afficherhealth(health p, SDL_Surface * window);
void libererhealth(health p);


void init_enemy(person *p);
void init_enemy_img(person *p,int counter,int level);
void afficher_enemy(person p,SDL_Surface *window);
void move_enemy(person *p,int dir,int direction,int pos,int y,health *b,int *max,int *min,int check);








































void movePerso (person *p,int xc,int check,int collision,int *next,int directionmv);
void jump_perso(person *p,int check,int collision,int directionmv);

void initPersoui(ui_char *p,int i);
void afficherui(ui_char p, SDL_Surface * window);
void initialiser_imagebordermale(ui_char *imgbtn,int pos_p_ui);
void afficher_imagebordermale(SDL_Surface *window,ui_char imge);
void libererbord(ui_char p);


void init_inviz(health *p);
void init_invizimage(health *p);
void animer_invizbar(health *p,int *off);
void afficher_inviz(health p, SDL_Surface * window);
void init_inviz_ball(health *p,int x,int y);
void init_inviz_ballimage(health *p,int counter);
void afficher_invizball(health p, SDL_Surface * window);
void anim_invizball(health *p,SDL_Event event ,int pos,int y,int s,int directionmv);
void init_timer_display(text_pers *txt,times *t);
void afficher_timer_display(text_pers txt , SDL_Surface *window,times *t);
void liberertext(text_pers *txt);
void init_score_display(text_pers *txt,times *t);
void afficher_score_display(text_pers tx , SDL_Surface *window,times *t);
void initscore_ui(health *p);
void afficherscore_ui(health p, SDL_Surface * window);
void freescore_ui(health p);
void initlost_ui(health *p);
void afficherlost_ui(health p, SDL_Surface * window);
void initPerso2(person *p);
void animPerso2(person *p,int dir);
void movePerso2(person *p,int xc,int check);
void afficherPerso2(person p, SDL_Surface * window);
void jump_perso2(person *p);
void init_smoke(person *p);
void smoke_image(person *p,int x,int y);
void afficher_smoke(person p,SDL_Surface * window);
void colli_portal(person *p);
void libererimage(person p);
void gravity(person *p,int colli);
void libererimageanim(ui_char p);

void init_miniperson(person *p);
void init_miniperson_image(person *p);
void afficher_mini_pers(person p,SDL_Surface *window);
void move_minipers(person *p,int xc,int dir);

void init_enemy_mini(person *p);
void init_mini_enemy_img(person *p);
void afficher_mini_enemy(person p,SDL_Surface *window);
void move_enemy_mini(person *p,int x,int dir,int x_enm,int direction);

void initialiser_walking(Mix_Chunk *music,int lvl);



#endif
