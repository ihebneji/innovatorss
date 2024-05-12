#include "minimap.h"
void init_map(minimap *m,personne p,background back,SDL_Surface*ecran,double redimentionement)
{

    //m->map = IMG_Load("src/fond1.jpg");
    m->map=rotozoomSurface(back.map,0,redimentionement,0);
    if(m->map==NULL)
        printf("no map");
    //m->minijoueur = IMG_Load("src/robot.ico");
    m->minijoueur=rotozoomSurface(p.perso,0,redimentionement,0);
    if(m->minijoueur)
        printf("no minijoueur");
    m->evenement = IMG_Load("./src/signe_1.png");
    if(m->evenement==NULL)
        printf("no evenement");
    m->positionmap.x = (ecran->w - m->map->w)/2;
    m->positionmap.y = 19;
    m->positionevenement.x = 1200;
    m->positionevenement.y = 400;
    m->imageevenement=1;
    m->animationevenement=SDL_GetTicks();
}
void MAJMinimap(SDL_Rect posJoueur, minimap *m,SDL_Rect camera,double redimensionnement)
{
    SDL_Rect posJoueurABS;
    posJoueurABS.x = 0;
    posJoueurABS.y = 0;
    posJoueurABS.x = posJoueur.x+camera.x *-1;
    posJoueurABS.y = posJoueur.y+camera.y ;
    m->positionminijoueur.x = (posJoueurABS.x * redimensionnement ) + m->positionmap.x;
    m->positionminijoueur.y = (posJoueurABS.y * redimensionnement )+ m->positionmap.y;
}
void afficherminimap(minimap m,background back, SDL_Surface *screen,double redimensionnement)
{
    SDL_BlitSurface(m.map, NULL, screen, &m.positionmap);
    SDL_BlitSurface(m.minijoueur, NULL, screen, &m.positionminijoueur);
    SDL_Rect evenement={
      m.positionmap.x + (m.positionevenement.x+back.camera.x ) * redimensionnement,
      m.positionmap.y + (m.positionevenement.y+back.camera.y  ) * redimensionnement
    };
    SDL_BlitSurface(m.evenement, NULL, screen, &evenement);
}
void animerminimap(minimap * m)
{
    if(SDL_GetTicks()-m->animationevenement>200){
 char ch[40];
    sprintf(ch, "src/signe_%d.png",m->imageevenement);
    
    m->imageevenement++;
        if (m->imageevenement==3)
            m->imageevenement=0;
    if(m->evenement)
        SDL_FreeSurface(m->evenement);
    m->evenement=IMG_Load(ch);
    if(m->evenement==NULL)
        printf("error evenement\n");
    m->animationevenement=SDL_GetTicks();
    }
}
void initialiser_temps(temps *t)
{
    t->s = 0;
    t->position.x = 10;
    t->position.y = 50;
    t->police = TTF_OpenFont("src/police.ttf", 40);
    if (t->police == NULL)
    {
        printf("error font \n ");
    }
    t->color.r = 0 ; 
    t->color.g = 0 ; 
    t->color.b = 0 ; 

    strcpy(t->contenu, "");
    t->texte = NULL;
  t->tempsEcoulees = 0;
  t->t1=SDL_GetTicks()/1000; 
}

void afficher_temps(temps *t, SDL_Surface *ecran)
{ 
  t->t2=SDL_GetTicks()/1000; 
  t->tempsEcoulees = t->t2 - t->t1;
  t->min = ((t->tempsEcoulees / 60) % 60);
  t->sec = ((t->tempsEcoulees) % 60);
  sprintf(t->contenu, "%02d:%02d", t->min, t->sec); 
  t->texte = TTF_RenderText_Blended(t->police, t->contenu, t->color);
  SDL_BlitSurface(t->texte, NULL, ecran, &(t->position)); 
  t->s = (t->sec * 10 + t->min * 600);
}

void free_temps(temps *t)
{
  SDL_FreeSurface(t->texte);
  TTF_CloseFont(t->police);
}

SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{
SDL_Color color;
Uint32 col=0;
char* pPosition=(char* )pSurface->pixels;
pPosition+=(pSurface->pitch *y);
pPosition+=(pSurface->format->BytesPerPixel *x);
memcpy (&col,pPosition,pSurface->format->BytesPerPixel);

SDL_GetRGB(col,pSurface->format,&color.r,&color.g,&color.b);
return(color);
}

 int collisionPP( personne p, background back)
{
    SDL_Color Couleur_Obstacle = {0, 0, 0};
    SDL_Color cal ;
 int X,Y,H,W;
 
     X = p.pos.x + back.camera.x *-1;
     Y = p.pos.y +back.camera.y;
  W = p.pos.w;
  H = p.pos.h;
printf("X: %d\tY=%d",X,Y);
    int pos[8][2];
    pos[0][0]=X;
    pos[0][1]=Y;
    pos[1][0]=X+W/2;
    pos[1][1]=Y;
    pos[2][0]=X+W;
    pos[2][1]=Y;
    pos[3][0]=X;
    pos[3][1]=Y+H/2;
    pos[4][0]=X;
    pos[4][1]=Y+H;
    pos[5][0]=X+W/2;
    pos[5][1]=Y+H;
    pos[6][0]=X+W;
    pos[6][1]=Y+H;
    pos[7][0]=X+W;
    pos[7][1]=Y+H/2;
    int collision=0,i=0;
    while ((i<8)&&(collision==0))
    {
        cal = GetPixel(back.masque, pos[i][0], pos[i][1]);
        //cal1=
        if((cal.r == Couleur_Obstacle.r) && (cal.g == Couleur_Obstacle.g) && (cal.b == Couleur_Obstacle.b))
        {
            collision = i;
        }
          i++;
    }
    return collision;
}
void liberermini(minimap*mini){
    SDL_FreeSurface(mini->minijoueur);
    SDL_FreeSurface(mini->map);
    SDL_FreeSurface(mini->evenement);
}

void sauvegarder (personne p,  background b, char * nomfichier){
    FILE*F=fopen(nomfichier,"wb");
    if(!F){("cannot save");return;}
    fwrite(&p, sizeof(personne), 1, F);
    fwrite(&b,sizeof(background),1,F);
    fclose(F);
}
 void charger ( personne * p, background *b , char * nomfichier){
    FILE*F=fopen(nomfichier,"rb");
    if(!F)("cannot save");
    int i=0;
    fread(p, sizeof(personne), 1, F);
    fread(b, sizeof(background), 1, F);
    fclose(F);
}