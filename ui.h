char displayd[3];
char turnosy[3];

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
    itoa(turnost,turnosy,6);
    mvaddch(tmax[0]-1,tmax[1]-7,turnosy[0]);
    mvaddch(tmax[0]-1,tmax[1]-6,turnosy[1]);
    mvaddch(tmax[0]-1,tmax[1]-5,turnosy[2]);
    move(cretorna_y(),cretorna_x());
}
