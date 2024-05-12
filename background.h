#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <stdlib.h>
#include <stdio.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
typedef struct background
{
	SDL_Surface *map,
				*masque;
	SDL_Rect camera;
}background;



void init_bg(background*back);
void afficher_bg(background back,SDL_Surface*ecran);
void liberer_bg(background*);
void scrolling (background*back,int direction,SDL_Rect perso,SDL_Surface *screen);

void afficher_background(background back,SDL_Surface*screen);

#endif