#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define width 1200
#define height 900

extern int ww [9][15] ;
extern int n ;
extern int xm ;
extern const int ym ;

int ball ( int* x , int* y )
{
    static int q = 2 , t = -2 ; // sorat toop ,, y : t ,, x : q ;   y be samt payin + ;
    int a , b ;
    int sw = 1 ;
    *x += q ;
    *y += t ;
    if ( (*x)+20 > width || (*x)-20 < 0 ) // jologiri az kharej shodan toop az safhe (x) ;
        q *= -1 ;
    if ( (*y)-20 < 0 ) // jologiri az kharej shodan toop az safhe (y) ;
        t *= -1 ;
    if ( (*y) - 20 <= n * 40 )
    {
        a = (*x)/80 ; // mokhtasat mostatil toop baraye araye (x) ;
        b = (*y)/40 ; // mokhtasat mostatil toop baraye araye (y) ;
        if ( t < 0 && b > 0 && ww [b-1][a] == 0 ) // bala
        {
            if ( b*40 + 20 >= (*y) )
            {
                ww [b-1][a] = 1 ;
                t *= -1 ;
                sw = 0 ;
            }
        }
        if ( sw && t > 0 && b < n-1 && ww [b+1][a] == 0 ) // payin
        {
            if ( b*40 + 20 <= (*y) )
            {
                ww [b+1][a] = 1 ;
                t *= -1 ;
                sw = 0 ;
            }
        }
        if ( sw && q > 0 && b < n-1 && a < 14 && ww [b][a+1] == 0 ) // rast
        {
            if ( a*80 + 60 <= (*x) )
            {
                ww [b][a+1] = 1 ;
                q *= -1 ;
                sw = 0 ;
            }
        }
        if ( sw && q < 0 && a > 0 && b < n-1 && ww [b][a-1] == 0 ) // chap
        {
            if ( a*80 + 20 >= (*x) )
            {
                ww [b][a-1] = 1 ;
                q *= -1 ;
                sw = 0 ;
            }
        }
        if ( sw && q > 0 && t < 0 && a < 14 && b > 0 && ww [b-1][a+1] == 0 && ww [b-1][a] != 0 ) // bala rast
        {
            /*
                aval chek mikonad ke bala va rast khali bashad ;
            */
            if ( b < n )
            {
                if ( ww [b][a+1] == 0 )
                    sw = 0 ;
            }
            if ( sw && a*80 + 70 <= (*x) && b*40 + 10 >= (*y) )
            {
                ww [b-1][a+1] = 1 ;
                q *= -1 ;
                t *= -1 ;
                sw = 0 ;
            }
        }
        if ( sw && q < 0 && t < 0 && a > 0 && b > 0 && ww [b-1][a-1] == 0 && ww [b-1][a] ) // bala chap
        {
            if ( b < n )
            {
                if ( ww [b][a-1] == 0 )
                    sw = 0 ;
            }
            if ( b*40 + 10 >= (*y) && a*80 + 10 >= (*x) )
            {
                ww [b-1][a-1] = 1 ;
                q *= -1 ;
                t *= -1 ;
                sw = 0 ;
            }
        }
        if ( sw && q < 0 && t > 0 && a > 0 && b < n-1 && ww [b+1][a-1] == 0 && ww [b][a-1] != 0 && ww [b+1][a] ) // payin chap
        {
            if ( a*80 + 10 >= (*x) && b*40 + 10 <= (*y) )
            {
                ww [b+1][a-1] = 1 ;
                q *= -1 ;
                t *= -1 ;
                sw = 0 ;
            }
        }
        if ( sw && q > 0 && t > 0 && a < 14 && b < n-1 && ww [b+1][a+1] == 0 && ww [b+1][a] != 0 && ww [b][a+1] != 0 ) // payin rast
        {
            if ( b*40 + 10 <= (*y) && a*80 + 70 <= (*x) )
            {
                ww [b+1][a+1] = 1 ;
                q *= -1 ;
                t *= -1 ;
                sw = 0 ;
            }
        }
    }
    else
    {
        a = *x ;
        b = *y ;
        if ( b >= ym )
            return 1 ;
        if ( b >= ym - 20 && a >= xm && a <= xm + 120 )
            t *= -1 ;
    }
    al_draw_filled_circle((*x),(*y),20,al_map_rgb(255,255,255)) ;
    return 0 ;
}
