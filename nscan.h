int scan[4];

int scan0()
{
    return(scan[0]);
}

int scan1()
{
    return(scan[1]);
}

int scan2()
{
    return(scan[2]);
}

int scan3()
{
    return(scan[3]);
}

int scanear(int y,int x)
{
    //esquerda
    mvinch(y,x-1);
    scan[0] = inch();
    
    //cima
    mvinch(y+1,x);
    scan[1] = inch();
    
    //direita
    mvinch(y,x+1);
    scan[2] = inch();
    
    //baixo
    mvinch(y+1,x);
    scan[3] = inch();
}
