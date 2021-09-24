int scan[8];

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

int scan4()
{
    return(scan[4]);
}

int scan5()
{
    return(scan[5]);
}

int scan6()
{
    return(scan[6]);
}

int scan7()
{
    return(scan[7]);
}

int scanear(int y,int x)
{
    //esquerda
    mvinch(y,x-1);
    scan[0] = inch();
    
    //cima
    mvinch(y-1,x);
    scan[1] = inch();
    
    //direita
    mvinch(y,x+1);
    scan[2] = inch();
    
    //baixo
    mvinch(y+1,x);
    scan[3] = inch();
    
    //esquerda cima
    mvinch(y-1,x-1);
    scan[4] = inch();
    
    //cima direita
    mvinch(y-1,x+1);
    scan[5] = inch();
    
    //direita baixo
    mvinch(y+1,x+1);
    scan[6] = inch();
    
    //baixo esquerda
    mvinch(y+1,x-1);
    scan[7] = inch();
}
