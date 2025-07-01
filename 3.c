#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define width 1200
#define height 900

int xm = 540 ;
const int ym = 700 ;

int mile ()
{
    al_install_keyboard () ; // tarif estefade az keyboard ;
    ALLEGRO_KEYBOARD_STATE ks ;
    al_get_keyboard_state (&ks) ;
    if ( al_key_down( &ks , ALLEGRO_KEY_RIGHT ) && xm < width - 120 )
        xm += 4 ;
    else if ( al_key_down( &ks , ALLEGRO_KEY_LEFT ) && xm > 0 )
        xm -= 4 ;
    al_draw_rounded_rectangle (xm,ym,xm+120,ym+30,10,10,al_map_rgb(0,255,0),2) ;
    return 0 ;
}
