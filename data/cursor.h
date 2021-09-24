

int cposi[2];

int cretorna_y()
{
    return(cposi[0]);
}

void catualiza()
{
    move(cposi[0],cposi[1]);
    refresh();
}

int cretorna_x()
{

    return(cposi[1]);
}

void cposicao_padrao(int y, int x)
{
    cposi[0] = y/2;
    cposi[1] = x/2;
    move(cposi[0],cposi[1]);
    refresh();
}

void cmoveup()
{

    cposi[0]--;
    move(cposi[0],cposi[1]);
    refresh();

}
void cmoveupl()
{

    cposi[0]--;
    cposi[1]--;
    move(cposi[0],cposi[1]);
    refresh();

}
void cmoveupr()
{

    cposi[0]--;
    cposi[1]++;
    move(cposi[0],cposi[1]);
    refresh();

}
void cmovedown()
{

    cposi[0]++;
    move(cposi[0],cposi[1]);
    refresh();

}
void cmovedownl()
{

    cposi[0]++;
    cposi[1]--;
    move(cposi[0],cposi[1]);
    refresh();

}
void cmovedownr()
{

    cposi[0]++;
    cposi[1]++;
    move(cposi[0],cposi[1]);
    refresh();

}
void cmoveleft()
{

    cposi[1]--;
    move(cposi[0],cposi[1]);
    refresh();

}
void cmoveright()
{

    cposi[1]++;
    move(cposi[0],cposi[1]);
    refresh();

}
