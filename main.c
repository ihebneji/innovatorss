#include "minimap.h"
int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_Surface *screen;
    screen = SDL_SetVideoMode(1280, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); 

    SDL_Event event;
    minimap m;
    temps t;
    personne p;
    p.perso = IMG_Load("./src/hero.png");
    p.pos.x = 50;
    p.pos.y = 400;
    p.pos.w = p.perso->w;
    p.pos.h = p.perso->h;
    double redimention=0.2;
    background back;
    init_bg(&back);

    SDL_EnableKeyRepeat(100, 10);


    int continuer = 1;
    init_map(&m,p,back,screen,redimention);
    initialiser_temps(&t); 


    while (continuer)
    {
        afficher_background(back,screen);

//printf("perso: x:%d \tcamera x:%d\tmini:x%d miniback:x%d\n",p.pos.x,back.camera.x,m.positionminijoueur.x,m.positionmap.x);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer=0;
                    break;
                case SDLK_LEFT:
                if ( back.camera.x!=0)
                    scrolling(&back,0,p.pos,screen);
                else if(p.pos.x-10>=0){
                        p.pos.x -= 10;  
                }
                p.dir=3;
                    break;
                case SDLK_RIGHT:
                    if(p.pos.x>=screen->w/4 && back.camera.x *-1+screen->w <back.masque->w){
                        scrolling(&back,1,p.pos,screen);
                    }else{
                        p.pos.x +=10;
                    } p.dir=4;
                    break;
                case SDLK_UP:
                        p.pos.y -= 10;
                        p.dir=1;
                    break;
                case SDLK_DOWN:
                        p.pos.y += 10;
                        p.dir=2;
                    break;
                case SDLK_l:
                    charger(&p,&back ,"save.bin");
                    break;
                case SDLK_o:
                    sauvegarder(p,back,"save.bin");
                    break;          
                }
                break;
            }
        }
        SDL_BlitSurface(p.perso, NULL, screen, &p.pos);        
 
        animerminimap(&m);
        MAJMinimap(p.pos, &m, back.camera,redimention); 
        afficherminimap(m,back,screen,redimention); 
        afficher_temps(&t, screen); 
        printf("collision:%d?\n",collisionPP(p,back));
      // printf("%d\n",c);
       
////////////////////////////////////////////////
        SDL_Flip(screen);  
        SDL_Delay(20);       
    }     
    SDL_FreeSurface(p.perso);
    liberer_bg(&back);
    liberermini(&m);
    free_temps(&t);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
