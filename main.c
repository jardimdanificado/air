#include <stdio.h>
#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>


// sudo apt-get install libxdo-dev libxdo2 
#include <xdo.h>


//   utilidades
#include "libs/mix.h"
#include "libs/nscan.h"
#include "libs/itoa.h"

//    geradores
#include "gen/estrutura.h"
#include "gen/nuvens.h"

// data
#include "data/grana.h"
#include "data/tela.h"
#include "data/turns.h"
#include "data/nave.h"
#include "data/cursor.h"
#include "data/clima.h"

#include "data/carga.h"

// sistema
#include "core/pathfinder.h"
#include "core/teclado.h"
#include "core/ui.h"




xdo_t * xfake;

int contanuvem=0;
char mapa[2000][2000];
int abas_cont = 0;

void alarme(int signo){
    signo = 0;
    curs_set(0);
    int telam[2] = {telamy(),telamx()};
    if(temrota()==1)
    {
    traduzir_path(telam);
    }
    xdo_send_keysequence_window(xfake, CURRENTWINDOW, "d", 0);
    contanuvem++;
  if(temrota()==1){
    if(contanuvem==5*((get_velo()/2)+1))
    {
        clima_atualiza();
        
        
        for(int y = 1;y<(telamy()-2);y++)
        {
          for(int x = 0;x<telamx();x++)
          {
            mvinch(y,x);
            char vodca = inch();
             if(vodca=='+')
             {
                    mvaddch(y,x,'+');
       	            refresh();
       	     }
     	     else if(mapa[y][x]=='@')
             {
                    
       	            mvaddch(y,x,' ');
       	           
       	            refresh();
       	     }
       	     else
             {
                    mvaddch(y,x,mapa[y][x]);
                    refresh();
             }
              
          }
        }
        for(int i = 0; i<getclima();i++)
        {
            update_nave();
            mvprintw(telamy()-1,1,"LOADING CLOUDS...");
            attron(COLOR_PAIR(3));
            criar_nuvens(telam);
            attroff(COLOR_PAIR(3));
            contanuvem=0;
            titulo_(telam);
        }
        divisor(telam);
        titulo(telam);
        placar_turno(telam);
    }
  }
    if(temrota()==0){
    if(contanuvem==5)
    {
        clima_atualiza();
        
        
        for(int y = 1;y<(telamy()-2);y++)
        {
          for(int x = 0;x<telamx();x++)
          {
            mvinch(y,x);
            char vodca = inch();
             if(vodca=='+')
             {
                    mvaddch(y,x,'+');
       	            refresh();
       	     }
     	     else if(mapa[y][x]=='@')
             {
                    
       	            mvaddch(y,x,' ');
       	           
       	            refresh();
       	     }
       	     else
             {
                    mvaddch(y,x,mapa[y][x]);
                    refresh();
             }
              
          }
        }
        for(int i = 0; i<getclima();i++)
        {
            update_nave();
            mvprintw(telamy()-1,1,"LOADING CLOUDS...");
            attron(COLOR_PAIR(3));
            criar_nuvens(telam);
            attroff(COLOR_PAIR(3));
            contanuvem=0;
            titulo_(telam);
        }
        divisor(telam);
        titulo(telam);
        placar_turno(telam);
    }
  }
    
    
    turnomais();
    refresh();
    
    
}

int main()
{

    int *tmax;
    int tecla;
    int turno;
    char display[3];
    initscr();
    start_color();
    xfake = xdo_new(NULL);
    init_color(COLOR_BLUE, 700, 700, 710);
    
    init_pair(1, COLOR_GREEN, COLOR_RED);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    cbreak();
    noecho();
    keypad(stdscr,true);
    raw();
    curs_set(0);
    
    tmax = (int *)malloc(sizeof(int)*2);
    
    attron(COLOR_PAIR(2));
    mvaddch(1,1,' ');
    attroff(COLOR_PAIR(2));
    
    getmaxyx(stdscr,tmax[0],tmax[1]);
    resizeterm(tmax[0],tmax[1]);
    cposicao_padrao(tmax[0],tmax[1]);
    setytela(tmax[0]);
    setxtela(tmax[1]);
    
    //char mapa[tmax[0]][tmax[1]];
    
    
    divisor(tmax);
    titulo(tmax);
    
    
    
    
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
    
    
    
    pposicao_inicial(tmax);
    setdestino();
    
    
    for(int i = 0; i<getclima();i++)
            {
             if(i%2==0){mvprintw(tmax[0]-1,1,"LOADING CLOUDS.  ");attron(COLOR_PAIR(3));criar_nuvens(tmax);attroff(COLOR_PAIR(3));}
             else{mvprintw(tmax[0]-1,1,"LOADING CLOUDS...");attron(COLOR_PAIR(3));criar_nuvens(tmax);attroff(COLOR_PAIR(3));}
            }
        divisor(tmax);
        titulo(tmax);
        titulo_(tmax);
    
    
    
    while(tecla!='q')
    {
        if(abastecendo == 1)
        {
            int random = rand()%15;
            for(int i = 0; i < random; i++)
            {
                if(getgrana()<0)
                {
                    abastecendo = 0;
                    i = random +20;
                    
                }
                abastecer();
                placar_gasosa(tmax);
            }
        }
        
        signal(SIGALRM, alarme);
        if(temrota() == 1&&gasosaq >0)
        {
            ualarm(600000/get_velo(),0);
        }
        else
        {
            ualarm(900000,0);
        }
        refresh();
        divisor(tmax);
        limpa_bot(tmax);
        printClima(tmax);
        placardinheiro(tmax);
        placar_gasosa(tmax);
        placar_turno(tmax);
        placar_velocidade(tmax);
        escondererro(tmax);
        escondererro2(tmax);
        
        curs_set(1);
        
        catualiza();
        refresh();
        //tecla = ' ';
        

        tecla = Teclado(tmax);

        
        update_nave();
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



