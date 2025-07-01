#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define width 1200
#define height 900

extern int n ;
extern int ww [9][15] ;

void moraba ()// braye chap ajor ha ;
{
    int l = width/15 , h = 40 ;
    ALLEGRO_COLOR color[9] = // baraye rang ha be tartib ;
    {
        al_map_rgb(255,0,0) ,
        al_map_rgb(255,215,0) ,
        al_map_rgb(0,255,0) ,
        al_map_rgb(255,69,0) ,
        al_map_rgb(0,255,255) ,
        al_map_rgb(0,0,255) ,
        al_map_rgb(255,0,255) ,
        al_map_rgb(210,105,30) ,
        al_map_rgb(255,20,147)
    } ;
    for ( int j = 0 ; j < n ; j ++ ) // n extern az main ;
    {
        for ( int i = 0 ; i < 15 ; i ++ )
        {
            if ( !ww[j][i] )
                al_draw_filled_rectangle(i*l,j*h,(i+1)*l,(j+1)*h,color[j]) ;
        }
    }
    for ( int i = 0 ; i <= width ; i += l ) // baraye khat haye meshki beyn mostatil ha ;
        al_draw_line(i,0,i,n*h,al_map_rgb(0,0,0),4) ;
    for ( int i = 0 ; i < n*h ; i += h )
        al_draw_line(0,i,width,i,al_map_rgb(0,0,0),4) ;
    return ;
}
