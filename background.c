#include "background.h"
void init_bg(background*back){
    back->map=IMG_Load("src/Level.jpg");
    SDL_Surface*image=rotozoomSurface(back->map,0,0.4,0);
    SDL_FreeSurface(back->map);
    back->map=image;
    if (back->map==NULL)
    {
        printf("error map");
    }
    
    back->masque= IMG_Load("src/Level.jpg");
    image=rotozoomSurface(back->masque,0,0.4,0);
    back->masque=image;
    back->camera.x=0;
    back->camera.y=0;
}
void afficher_bg(background back,SDL_Surface*ecran){
    SDL_BlitSurface(back.map,NULL,ecran,&back.camera);
}
void liberer_bg(background*back){
    SDL_FreeSurface(back->masque);
}
void scrolling (background*back,int direction,SDL_Rect perso,SDL_Surface *screen)
{
const int speed=10;
printf("camera :%d\tperso:%d\t",back->camera.x,perso.x);
if (direction ==0)
	{
	    back->camera.x+= speed;	
	}
else if (direction ==1 )
{
	back->camera.x-=speed; 
}
else if (direction ==2 && back->camera.y-10>0){
    back->camera.y-= speed;
}
    else if (direction ==3 && back->camera.y+15+screen->h<back->masque->h)
        back->camera.y+= speed;
	printf("%d\n",back->camera.y);
}
void afficher_background(background back,SDL_Surface*screen){
    SDL_BlitSurface(back.masque,NULL,screen,&back.camera);
}