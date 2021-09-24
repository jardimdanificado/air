char displayd[3] = {'0','0','0'};
char turnosy[4] = {'0','0','0','0'};
char gasosi[3] = {'0','0','0'};


int placar_distancia(int *tmax)
{    
    int quant = retornarqturnos();
    itoa(quant,displayd,6);
    mvaddch(tmax[0]-1,tmax[1]-3,displayd[0]);
    mvaddch(tmax[0]-1,tmax[1]-2,displayd[1]);
    mvaddch(tmax[0]-1,tmax[1]-1,displayd[2]);
    move(cretorna_y(),cretorna_x());
}

int placar_turno(int *tmax)
{    
    int turnost = retornarturno();
    itoa(turnost,turnosy,8);
    mvaddch(tmax[0]-1,tmax[1]-10,turnosy[0]);
    mvaddch(tmax[0]-1,tmax[1]-9,turnosy[1]);
    //mvaddch(tmax[0]-1,tmax[1]-8,':');
    mvaddch(tmax[0]-1,tmax[1]-8,turnosy[2]);
    mvaddch(tmax[0]-1,tmax[1]-7,turnosy[3]);
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
