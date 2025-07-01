#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define width 1200
#define height 900

extern moraba () ;
extern int ball ( int* , int* ) ;
void start ( int* , int ) ;
extern int xm ;
extern const int ym ;

int ww [9][15] = {0} ;
int n ;

int main()
{
    int l = width/15 , h = 40 , t , point = 0 ;
    int sw = 1 , x = width/2 , y = 670 ;
    char c , name [30] ;
    double ts = 0.002 ;
    printf ("n : tedad radif ajor haye bazi\nPlease enter n! \nn = ") ;
    scanf ("%d",&n) ;
    system("cls") ; // safhe consol ra pak mikonad ;
    printf ("Please enter your name\nname : ") ;
    getchar () ;
    gets (name) ;
    system("cls") ;
    al_init() ; // bayad braye kar ba allegro bashada ;
    al_init_primitives_addon() ; // baraye rasm shekl ;
    ALLEGRO_DISPLAY* display = al_create_display ( width , height ) ;
    start ( &x , y ) ;
    al_clear_to_color (al_map_rgb(0,0,0)) ;
    while( point != n*15 )
    {
        moraba() ;
        t = ball( &x , &y ) ;
        mile () ;
        al_flip_display () ;
        if ( t )
            break ;
        if ( point == n*15/3 && sw ) // sw : faghat baraye inke 1 bar sorat taghiyr konad
        {
            ts /= 1.5 ;
            sw = 0 ;
        }
        al_rest(ts) ;
        al_clear_to_color(al_map_rgb(0,0,0)) ;
        point = 0 ;
        for ( int i = 0 ; i < n ; i ++ ) // mohasebe emtiaz
            for ( int j = 0 ; j < 15 ; j ++ )
                if ( ww [i][j] )
                    point ++ ;
    }
    al_destroy_display(display) ;
    if ( point == n*15 )
        printf ("You win!\n") ;
    /*

    */
    printf ("your score is %d",point) ;
    FILE* file = fopen ("points/points.txt","r+") ;
    fseek (file,0,SEEK_END) ;
    fprintf (file,"%s  %d\n",name,point) ;
    fclose (file) ;
    al_rest (1.5) ;// //
    return 0;
}

void start ( int* x , int y ) // start bazi ;
{
    al_install_keyboard () ;
    ALLEGRO_KEYBOARD_STATE ks ;
    al_get_keyboard_state (&ks) ;
    while ( !al_key_down ( &ks , ALLEGRO_KEY_SPACE ) )
    {
        al_clear_to_color (al_map_rgb(0,0,0)) ; // kol safhe ro rang mikone ;
        if ( al_key_down( &ks , ALLEGRO_KEY_RIGHT ) && xm < width - 120 )
        {
            xm += 4 ; //avaz shodan mogheeeat mile
            (*x) += 4 ;  // avaz shodan mogheeeat toop
        }
        else if ( al_key_down( &ks , ALLEGRO_KEY_LEFT ) && xm > 0 )
        {
            xm -= 4 ;
            (*x) -= 4 ;
        }
        al_draw_rounded_rectangle (xm,ym,xm+120,ym+30,10,10,al_map_rgb(0,255,0),2) ; //chap dobare mostatil
        al_draw_filled_circle((*x),y,20,al_map_rgb(255,255,255)) ;//chap dobare toop
        moraba() ;
        al_flip_display() ;// baraye inke tasavir az hafeze roye safhe chap shavad ;
        al_get_keyboard_state (&ks) ;
    }
    return ;
}
