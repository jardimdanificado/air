int clima =0;

void gerar_clima()
{
    unsigned long cusd = 8979842875;
    unsigned long semente = mix(clock(), time(NULL), cusd);
    srand(semente);
    
    clima = rand()%30;
}

int getclima()
{
   return(clima); 
}

void climasobe()
{
if(clima<50)
    clima++;
}

void climadesce()
{
if(clima>0)
    clima--;
}

void printClima(int *tmax)
{
    mvprintw(tmax[0]-1,1,"weather: ");
    if(clima<5)
    {
        mvprintw(tmax[0]-1,10,"clear sky");
    }
    if(clima>=5&&clima<10)
    {
        mvprintw(tmax[0]-1,10,"not so clear");
    }
    if(clima>=10&&clima<15)
    {
        mvprintw(tmax[0]-1,10,"cloudy");
    }
    if(clima>=15&&clima<20)
    {
        mvprintw(tmax[0]-1,10,"its raining!");
    }
    if(clima>=20&&clima<25)
    {
        mvprintw(tmax[0]-1,10,"raining a lot!");
    }
    if(clima>=25&&clima<30)
    {
        mvprintw(tmax[0]-1,10,"thunders!");
    }
    if(clima>=30&&clima<35)
    {
        mvprintw(tmax[0]-1,10,"sky gates have opened");
    }
    if(clima>=35&&clima<40)
    {
        mvprintw(tmax[0]-1,10,"god did it again");
    }
    if(clima>=40&&clima<45)
    {
        mvprintw(tmax[0]-1,10,"the world has not that much of water");
    }
    if(clima>=45&&clima<50)
    {
        mvprintw(tmax[0]-1,10,"YOUR GAME WILL CRASH");
    }
}

void clima_atualiza()
{
    unsigned long cusd = 8979842875;
    unsigned long semente = mix(clock(), time(NULL), cusd);
    srand(semente);
    int ranom = 0;
    int alea = rand()%5;
    ranom = rand()%20;
    
    for(int i = 0;i < alea;i++)
    {
        if(ranom>=10)
        {
            climadesce();
        }
        if(ranom<10)
        {
            climasobe();
        }
    }
}



