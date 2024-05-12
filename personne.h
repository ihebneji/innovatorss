#ifndef PERSONNE_H
#define PERSONNE_H
#include <stdlib.h>
#include <stdio.h>

#include <SDL/SDL.h>

typedef struct
{
    SDL_Surface *perso;         /*!< image du personnage */
    SDL_Rect pos;                /*!< position personnage */
    int dir;                    /*!< kol mayostaa yaaraf rohou mnin */
} personne;
#endif