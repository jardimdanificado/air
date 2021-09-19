#include <stdio.h>
#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>

int main() 
{
    int yxmax[2];
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,true);
    raw();
    curs_set(0);
    getmaxyx(stdscr,yxmax[0],yxmax[1]);
    resizeterm(yxmax[0],yxmax[1]);
    
    
    while(tecla!='q')
    {
        
    }
    endwin();
}
