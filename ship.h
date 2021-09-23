
int pposi[2] = {2,2};

int pretorna_y()
{
    return(pposi[0]);
}

int pretorna_x()
{

    return(pposi[1]);
}

void pposicao_inicial(int y, int x)
{
    pposi[0] = y/2;
    pposi[1] = x/2;
    mvaddch(pposi[0],pposi[1],'@');
    refresh();
}



void pmoveup(int y, int x)
{
    mvaddch(pposi[0],pposi[1],' ');
    pposi[0]--;
    mvaddch(pposi[0],pposi[1],'@');
    move(y,x);
    refresh();

}
void pmoveupr(int y, int x)
{
    mvaddch(pposi[0],pposi[1],' ');
    pposi[0]--;
    pposi[1]++;
    mvaddch(pposi[0],pposi[1],'@');
    move(y,x);
    refresh();

}
void pmoveupl(int y, int x)
{
    mvaddch(pposi[0],pposi[1],' ');
    pposi[0]--;
    pposi[1]--;
    mvaddch(pposi[0],pposi[1],'@');
    move(y,x);
    refresh();

}
void pmovedown(int y, int x)
{
    mvaddch(pposi[0],pposi[1],' ');
    pposi[0]++;
    mvaddch(pposi[0],pposi[1],'@');
    move(y,x);
    refresh();

}
void pmovedownr(int y, int x)
{
    mvaddch(pposi[0],pposi[1],' ');
    pposi[0]++;
    pposi[1]++;
    mvaddch(pposi[0],pposi[1],'@');
    move(y,x);
    refresh();

}
void pmovedownl(int y, int x)
{
    mvaddch(pposi[0],pposi[1],' ');
    pposi[0]++;
    pposi[1]--;
    mvaddch(pposi[0],pposi[1],'@');
    move(y,x);
    refresh();

}
void pmoveleft(int y, int x)
{
    mvaddch(pposi[0],pposi[1],' ');
    pposi[1]--;
    mvaddch(pposi[0],pposi[1],'@');
    move(y,x);
    refresh();

}
void pmoveright(int y, int x)
{
    mvaddch(pposi[0],pposi[1],' ');
    pposi[1]++;
    mvaddch(pposi[0],pposi[1],'@');
    move(y,x);
    refresh();

}

void printa_principal()
{

}
