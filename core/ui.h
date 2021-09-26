char displayd[3] = {'0','0','0'};
char turnosy[4] = {'0','0','0','0'};
char gasosi[3] = {'0','0','0'};
char velo_d[2] = {'0','0'};
char dindin[6] = {'0','0','0','0','0','0'};

int titulo(int *tmax)
{
    attron(COLOR_PAIR(4));
    mvprintw(0,((tmax[1]/2)-(sizeof("  AirCraft Instruments  ")/2)) ,"  AirCraft Instruments  " );
    attroff(COLOR_PAIR(4));
}

int escondererro(int *tmax)
{
    for(int i = 0; i < tmax[1];i++)
    {
        mvinch(tmax[0]-1,i);
        int var = inch();
        mvinch(tmax[0]-1,i-1);
        int var1 = inch();
        
        if(var == '^')
        {
            mvaddch(tmax[0]-1,i,' ');
        }
        if(var1 == ' '&&var == '0')
        {
            mvaddch(tmax[0]-1,i,' ');
        }
    }
}

int escondererro2(int *tmax)
{
    for(int i = 0; i < tmax[1];i++)
    {
        mvinch(tmax[0]-1,i);
        int var = inch();
        mvinch(tmax[0]-1,i-1);
        int var1 = inch();
        
        if(var == '^')
        {
            mvaddch(tmax[0]-1,i,' ');
        }
        if(var1 == ' '&&var == '@')
        {
            mvaddch(tmax[0]-1,i,' ');
        }
    }
}

int limpa_bot(int *tmax)
{
    for(int i = 0; i < tmax[1];i++)
    {
        mvaddch(tmax[0]-1,i,' ');
    }
}

int titulo_(int *tmax)
{

    for(int i = 0; i < tmax[1];i++)
    {
        mvinch(0,i);
        int var = inch();
        if(var == '#')
        {
            mvaddch(0,i,' ');
        }
    }

}

int divisor(int *tmax)
{
    for(int i = 0; i < tmax[1];i++)
    {
        mvinch(0,i);
        int var = inch();
        if(var == ' '||var == '#')
        {
            mvaddch(tmax[0]-2,i,'_');
        }
    }
}

int placar_turno(int *tmax)
{    
    int turnost = retornarturno();
    itoa(turnost,turnosy,8);
    mvaddch(tmax[0]-1,tmax[1]-10,'T');
    mvaddch(tmax[0]-1,tmax[1]-9,'U');
    mvaddch(tmax[0]-1,tmax[1]-8,'R');
    mvaddch(tmax[0]-1,tmax[1]-7,'N');
    mvaddch(tmax[0]-1,tmax[1]-6,':');
    mvaddch(tmax[0]-1,tmax[1]-5,turnosy[0]);
    mvaddch(tmax[0]-1,tmax[1]-4,turnosy[1]);
    //mvaddch(tmax[0]-1,tmax[1]-8,':');
    mvaddch(tmax[0]-1,tmax[1]-3,turnosy[2]);
    mvaddch(tmax[0]-1,tmax[1]-2,turnosy[3]);
    move(cretorna_y(),cretorna_x());
}

int placar_gasosa(int *tmax)
{    
    int gasosinha = retornargasosa();
    itoa(gasosinha,gasosi,6);
    mvaddch(tmax[0]-1,tmax[1]-14,gasosi[0]);
    mvaddch(tmax[0]-1,tmax[1]-13,gasosi[1]);
    mvaddch(tmax[0]-1,tmax[1]-12,gasosi[2]);
    
    mvaddch(tmax[0]-1,tmax[1]-19,'F');
    mvaddch(tmax[0]-1,tmax[1]-18,'U');
    mvaddch(tmax[0]-1,tmax[1]-17,'E');
    mvaddch(tmax[0]-1,tmax[1]-16,'L');
    mvaddch(tmax[0]-1,tmax[1]-15,':');
    
    
    move(cretorna_y(),cretorna_x());
}

int placar_velocidade(int *tmax)
{    
    int gasosinha = get_velo();
    itoa(gasosinha,velo_d,6);
    mvaddch(tmax[0]-1,tmax[1]-22,velo_d[0]);
    mvaddch(tmax[0]-1,tmax[1]-21,velo_d[1]);
    
    mvaddch(tmax[0]-1,tmax[1]-28,'S');
    mvaddch(tmax[0]-1,tmax[1]-27,'P');
    mvaddch(tmax[0]-1,tmax[1]-26,'E');
    mvaddch(tmax[0]-1,tmax[1]-25,'E');
    mvaddch(tmax[0]-1,tmax[1]-24,'D');
    mvaddch(tmax[0]-1,tmax[1]-23,':');
    
    
    move(cretorna_y(),cretorna_x());
}

int placardinheiro(int *tmax)
{
    int grann = getgrana();
    itoa(grann,dindin,12);
    mvaddch(tmax[0]-1,tmax[1]-36,'$');
    mvaddch(tmax[0]-1,tmax[1]-35,dindin[0]);
    mvaddch(tmax[0]-1,tmax[1]-34,dindin[1]);
    mvaddch(tmax[0]-1,tmax[1]-33,dindin[2]);
    mvaddch(tmax[0]-1,tmax[1]-32,dindin[3]);
    mvaddch(tmax[0]-1,tmax[1]-31,dindin[4]);
    mvaddch(tmax[0]-1,tmax[1]-30,dindin[5]);
    
    move(cretorna_y(),cretorna_x());
}
