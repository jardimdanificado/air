#include <stdio.h>
#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#include <unistd.h>

#include "turns.h"
#include "itoa.h"
#include "ship.h"
#include "cursor.h"
#include "pathfinder.h"
#include "teclado.h"
#include "ui.h"

int main()
{
    int tmax[2],tecla,turno;
    char display[3];
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,true);
    raw();
    
    
    getmaxyx(stdscr,tmax[0],tmax[1]);
    resizeterm(tmax[0],tmax[1]);
    pposicao_inicial(tmax[0],tmax[1]);
    cposicao_padrao(tmax[0],tmax[1]);
    
    while(tecla!='q')
    {
        placar_turno(tmax);
        placar_distancia(tmax);
        curs_set(1);
        catualiza();
        tecla = Teclado();
        refresh();
    }



    endwin();
}
