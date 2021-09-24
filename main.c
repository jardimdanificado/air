#include <stdio.h>
#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#include <unistd.h>

//   utilidades
#include "libs/mix.h"
#include "libs/nscan.h"
#include "libs/itoa.h"

//    geradores
#include "gen/estrutura.h"
#include "gen/nuvens.h"

// data
#include "data/turns.h"
#include "data/nave.h"
#include "data/cursor.h"
#include "data/clima.h"

// sistema
#include "core/pathfinder.h"
#include "core/teclado.h"
#include "core/ui.h"

int main()
{
    int *tmax;
    int tecla;
    int turno;
    char display[3];
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,true);
    raw();
    
    tmax = (int *)malloc(sizeof(int)*2);
    
    
    
    getmaxyx(stdscr,tmax[0],tmax[1]);
    resizeterm(tmax[0],tmax[1]);
    pposicao_inicial(tmax[0],tmax[1]);
    cposicao_padrao(tmax[0],tmax[1]);
    
    char mapa[tmax[0]][tmax[1]];
    
    
    
    
    for(int i = 0;i <((tmax[0]*tmax[1])/500);i++)
    {
      criar_aeroportos(tmax);
    }
    
    for(int y = 1;y<(tmax[0]-2);y++)
        {
                for(int x = 0;x<tmax[1];x++)
       	        {
                    mvinch(y,x);
                    inch();
                    mapa[y][x] = inch();
                }
        }
        
    gerar_clima();
    update_nave();
    for(int i = 0; i<getclima();i++)
            {criar_nuvens(tmax);};
    
    while(tecla!='q')
    {
        
        limpa_bot(tmax);
        printClima(tmax);
        placar_gasosa(tmax);
        placar_turno(tmax);
        placar_distancia(tmax);
        placar_velocidade(tmax);
        escondererro(tmax);
        escondererro2(tmax);
        curs_set(1);
        catualiza();
        refresh();
        tecla = Teclado(tmax);
       if(tecla==' '||tecla == '5')
       {
        clima_atualiza();
        for(int y = 1;y<(tmax[0]-2);y++)
        {
          for(int x = 0;x<tmax[1];x++)
          {
     	     if(mapa[y][x]=='@')
             {
       	            mvaddch(y,x,' ');
       	     }
       	     else
             {
                    mvaddch(y,x,mapa[y][x]);
             }
          }
        }
        for(int i = 0; i<getclima();i++)
            {criar_nuvens(tmax);}
       }
        divisor(tmax);
        titulo(tmax);
        titulo_(tmax);
        update_nave();
        refresh();
        
    }
    refresh();
    free(tmax);
    endwin();
}
