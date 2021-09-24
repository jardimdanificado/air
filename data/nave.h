
int pposi[2] = {2,2};

int gasosaq = 52;

int gasosacont = 0;

int velocidade = 1;

int get_velo()
{
    return(velocidade);
}

void velosobe()
{
    velocidade++;
}

void velodesce()
{
    if(velocidade>1)
    {
        velocidade--;
    }
}

int retornargasosa()
{
    return(gasosaq);
}

int gasosa()
{
    if(gasosaq == 0)
    {
        return(0);
    }
    else if(get_velo()<3) {
    if(gasosacont ==(4/get_velo()))
    {
        gasosaq--;
        gasosacont=0;
    }
    
    }else if(get_velo()>2){
    
    if(gasosacont >0)
    {
        gasosaq= gasosaq- get_velo();
        gasosacont=0;
    }
        
    
    }
}

int gasosa_gastou()
{
    gasosacont++;
    int var = gasosa();
    if(var == 0)
    {
        return(0);
    }
}


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



int pmoveup(int y, int x)
{

    mvaddch(pposi[0],pposi[1],' ');
    pposi[0]--;
    mvaddch(pposi[0],pposi[1],'@');
    move(y,x);
    refresh();
    int var = gasosa_gastou();

if(var == 0)
{
    return(0);
}
 }
 
int pmoveupr(int y, int x)
{
    mvaddch(pposi[0],pposi[1],' ');
    pposi[0]--;
    pposi[1]++;
    mvaddch(pposi[0],pposi[1],'@');
    move(y,x);
    refresh();
 int var = gasosa_gastou();

if(var == 0)
{
    return(0);
}
 }
int pmoveupl(int y, int x)
{
    mvaddch(pposi[0],pposi[1],' ');
    pposi[0]--;
    pposi[1]--;
    mvaddch(pposi[0],pposi[1],'@');
    move(y,x);
    refresh();
 int var = gasosa_gastou();

if(var == 0)
{
    return(0);
}
 }
int pmovedown(int y, int x)
{
    mvaddch(pposi[0],pposi[1],' ');
    pposi[0]++;
    mvaddch(pposi[0],pposi[1],'@');
    move(y,x);
    refresh();
 int var = gasosa_gastou();

if(var == 0)
{
    return(0);
}
 }
int pmovedownr(int y, int x)
{
    mvaddch(pposi[0],pposi[1],' ');
    pposi[0]++;
    pposi[1]++;
    mvaddch(pposi[0],pposi[1],'@');
    move(y,x);
    refresh();
 int var = gasosa_gastou();

if(var == 0)
{
    return(0);
}
 }
int pmovedownl(int y, int x)
{
    mvaddch(pposi[0],pposi[1],' ');
    pposi[0]++;
    pposi[1]--;
    mvaddch(pposi[0],pposi[1],'@');
    move(y,x);
    refresh();
 int var = gasosa_gastou();

if(var == 0)
{
    return(0);
}
 }
int pmoveleft(int y, int x)
{
    mvaddch(pposi[0],pposi[1],' ');
    pposi[1]--;
    mvaddch(pposi[0],pposi[1],'@');
    move(y,x);
    refresh();
 int var = gasosa_gastou();

if(var == 0)
{
    return(0);
}
 }
int pmoveright(int y, int x)
{
    mvaddch(pposi[0],pposi[1],' ');
    pposi[1]++;
    mvaddch(pposi[0],pposi[1],'@');
    move(y,x);
    refresh();
 int var = gasosa_gastou();

if(var == 0)
{
    return(0);
}
}
 
void printa_principal()
{

}
