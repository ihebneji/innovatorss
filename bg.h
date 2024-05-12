#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_W_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdbool.h>

typedef struct 
{ SDL_Surface *paysage,*loading,*bg,*shared,*min_border,*minimap,*masque;
  SDL_Rect pos_img,pos_img2,pos_min_bord,pos_affminimap;
  SDL_Rect camera_pos,camera_pos2;

  SDL_Surface *coin;
  SDL_Rect pos_coin;
int c1;


int coin_dir;
  int coin_counter;
  int level,lo,bg_counter;
  int value,value2;
  int chck,chck2;

}background;
typedef struct
{char scorename[20];
int score;
}score;
typedef struct {
    bool top;
    bool bottom;
    bool left;
    bool right;
} colide;
void intit_Loadingscreen(background *b,int loading);
void afficher_LoadingScreen(background b,SDL_Surface *screen);
void initBack(background *b);
void init_bgimage(background *b,int level);
void aficherBack(background b,SDL_Surface *screen);
colide collision2(SDL_Rect rect1, SDL_Rect rect2) ;
SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y);
int collisionmap(SDL_Surface *masque, SDL_Rect posPerso);




void load_img_coin(background *b,int coins);
void init_coin1(background *b,int offsetx,int offsety);
void afficher_coin(SDL_Surface *coin,SDL_Surface *window,int x,int y);
void move_coin1(background *b,int xc,int y,int dir,background p,Mix_Chunk  *mus_coin,int *score);
int check_rotation_collision(double x1, double y1, double w1, double h1, double angle1,double x2, double y2, double w2, double h2, double angle2);
void free_coins(background b);





























void initialiser_audio(Mix_Music *music);
void scrolling(background *b,int xc,int *dir,int directionmv);
void animerBack(background *b);
void initimage(background *b);
void aficherimage(background b,SDL_Surface *screen);
void libererbg(background b);
void libererloading(background b);
void recloading(int loading,background *b);
void initBack2(background *b);
void aficherBack2(background b,SDL_Surface *window,SDL_Rect pos_img2,SDL_Rect camera_pos2);
void scrolling2(background *b,int xc);
void load_bord_sharedscreen(background *b);
void displaybord_shared(background b,SDL_Surface *window);
void free_sharedbord(background b);
int check_bg(background *b,int xc,int posbg);
int check_bg2(background *b,int xc);
void loid_music_bg(Mix_Music *music);
void initialiser_audio_bg(Mix_Music *music);

#endif
