char displayd[3] = {'0','0','0'};
char turnosy[4] = {'0','0','0','0'};
char gasosi[3] = {'0','0','0'};
char velo_d[2] = {'0','0'};

int titulo(int *tmax)
{
    mvprintw(0,((tmax[1]/2)-(sizeof("__AirCraft Instruments__")/2)) ,"__AirCraft Instruments__" );
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
        if(var == ' '||var == '#')
        {
            mvaddch(0,i,'_');
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

int placar_distancia(int *tmax)
{    
    int quant = retornarqturnos();
    itoa(quant,displayd,6);
    mvaddch(tmax[0]-1,tmax[1]-14,'T');
    mvaddch(tmax[0]-1,tmax[1]-13,'U');
    mvaddch(tmax[0]-1,tmax[1]-12,'R');
    mvaddch(tmax[0]-1,tmax[1]-11,'N');
    mvaddch(tmax[0]-1,tmax[1]-10,'_');
    mvaddch(tmax[0]-1,tmax[1]-9,'R');
    mvaddch(tmax[0]-1,tmax[1]-8,'A');
    mvaddch(tmax[0]-1,tmax[1]-7,'N');
    mvaddch(tmax[0]-1,tmax[1]-6,'G');
    mvaddch(tmax[0]-1,tmax[1]-5,'E');
    mvaddch(tmax[0]-1,tmax[1]-4,':');
    mvaddch(tmax[0]-1,tmax[1]-3,displayd[0]);
    mvaddch(tmax[0]-1,tmax[1]-2,displayd[1]);
    mvaddch(tmax[0]-1,tmax[1]-1,displayd[2]);
    move(cretorna_y(),cretorna_x());
}

int placar_turno(int *tmax)
{    
    int turnost = retornarturno();
    itoa(turnost,turnosy,8);
    mvaddch(tmax[0]-1,tmax[1]-24,'T');
    mvaddch(tmax[0]-1,tmax[1]-23,'U');
    mvaddch(tmax[0]-1,tmax[1]-22,'R');
    mvaddch(tmax[0]-1,tmax[1]-21,'N');
    mvaddch(tmax[0]-1,tmax[1]-20,':');
    mvaddch(tmax[0]-1,tmax[1]-19,turnosy[0]);
    mvaddch(tmax[0]-1,tmax[1]-18,turnosy[1]);
    //mvaddch(tmax[0]-1,tmax[1]-8,':');
    mvaddch(tmax[0]-1,tmax[1]-17,turnosy[2]);
    mvaddch(tmax[0]-1,tmax[1]-16,turnosy[3]);
    move(cretorna_y(),cretorna_x());
}

int placar_gasosa(int *tmax)
{    
    int gasosinha = retornargasosa();
    itoa(gasosinha,gasosi,6);
    mvaddch(tmax[0]-1,tmax[1]-28,gasosi[0]);
    mvaddch(tmax[0]-1,tmax[1]-27,gasosi[1]);
    mvaddch(tmax[0]-1,tmax[1]-26,gasosi[2]);
    
    mvaddch(tmax[0]-1,tmax[1]-33,'F');
    mvaddch(tmax[0]-1,tmax[1]-32,'U');
    mvaddch(tmax[0]-1,tmax[1]-31,'E');
    mvaddch(tmax[0]-1,tmax[1]-30,'L');
    mvaddch(tmax[0]-1,tmax[1]-29,':');
    
    
    move(cretorna_y(),cretorna_x());
}

int placar_velocidade(int *tmax)
{    
    int gasosinha = get_velo();
    itoa(gasosinha,velo_d,6);
    mvaddch(tmax[0]-1,tmax[1]-36,velo_d[0]);
    mvaddch(tmax[0]-1,tmax[1]-35,velo_d[1]);
    
    mvaddch(tmax[0]-1,tmax[1]-42,'S');
    mvaddch(tmax[0]-1,tmax[1]-41,'P');
    mvaddch(tmax[0]-1,tmax[1]-40,'E');
    mvaddch(tmax[0]-1,tmax[1]-39,'E');
    mvaddch(tmax[0]-1,tmax[1]-38,'D');
    mvaddch(tmax[0]-1,tmax[1]-37,':');
    
    
    move(cretorna_y(),cretorna_x());
}
