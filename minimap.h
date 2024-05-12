#ifndef minimap_H
#define minimap_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>

typedef struct
{
    SDL_Surface *map;
    SDL_Surface *minijoueur;
    SDL_Surface *evenement;
    SDL_Rect positionmap;
    SDL_Rect positionminijoueur;
    SDL_Rect positionevenement;
    Uint32 animationevenement;
    double redimensionnement;
    int imageevenement;
} minimap;

typedef struct 
{
   SDL_Surface *texte;                
   int s;                        
   SDL_Rect position;            
   TTF_Font *police;             
   char contenu[100];             
   int tempsEcoulees;         
   SDL_Color color;             
   time_t t1, t2;                
   int min, sec;                
} temps;

#include "personne.h"
#include "background.h"
void sauvegarder (personne p,  background b, char * nomfichier);
void charger ( personne * p, background *b , char * nomfichier);
void init_map(minimap *m,personne p,background back,SDL_Surface*ecran,double redimentionement);

void MAJMinimap(SDL_Rect posJoueur, minimap *m,SDL_Rect camera, double redimensionnement);

void afficherminimap(minimap m,background back ,SDL_Surface *screen,double redimensionnement);

void animerminimap( minimap  *m);

void initialiser_temps(temps *t);

void afficher_temps(temps *t, SDL_Surface *ecran);

void free_temps(temps *t);

SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);

int collisionPP( personne p, background back);

void liberermini(minimap*mini);

void charger ( personne * p, background *b , char * nomfichier);
void sauvegarder (personne p,  background b, char * nomfichier);
#endif

