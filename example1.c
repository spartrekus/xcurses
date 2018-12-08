
/* include the X library headers */
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <stdio.h>
#include <stdlib.h>

#include "xcurses.c"

int main()
{	
        int ch ; int gameover = 0;
        char text[255];
	initscr();

	while( gameover == 0 ) 
        {		
		XNextEvent(dis, &event);

		//if (event.type==Expose && event.xexpose.count==0) {
		//	redraw();
		//}
                mvlinew( 150, 150, 300, 300 ); 
                mvlinew( 20, 30, 100, 120 ); 
                
                mvpointw( 95, 90 );

                //XDrawArc( dis, win, gc, 100, 100, 150, 150, 0, 360);
                XFillArc( dis, win, gc, 300, 300, 10, 10, 0, 360*64);


                mvrectanglew( 10, 10, 200, 50); 

                ch = getch(); 

                if      ( ch =='L') {    mvprintw( 250, 250, "line" );   } 
                else if ( ch =='l') {    mvlinew( 20, 30, 100, 120 ); }
                else if ( ch =='r') {    mvrectanglew( 10, 20, 100, 200); }
                else if ( ch =='q') {  gameover = 1 ; }
                else if ( ch =='p') {  mvpointw( 75, 50 ); }

		if (event.type==ButtonPress) 
                {
			int x=event.xbutton.x, y=event.xbutton.y;
                        XSetForeground(dis, gc, 0 );
			mvprintw( y, x , "Mouse ");
			printf( "Y=%d X=%d\n", y, x );
		}

	}
   	endwin();
	return 0;
}



