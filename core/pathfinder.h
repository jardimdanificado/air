

char path[150];


int linha_atual=0;


void limpar_rota()
{
    for(int i = 0;i<150;i++)
    {
        path[i] = '0';
    }
    linha_atual = 0;
}

int update_turno(int *tmax)
{    
    char turnosy[4];
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


int update_gasosa(int *tmax)
{    
    char gasi[3];
    int gasosinha = retornargasosa();
    itoa(gasosinha,gasi,6);
    mvaddch(tmax[0]-1,tmax[1]-28,gasi[0]);
    mvaddch(tmax[0]-1,tmax[1]-27,gasi[1]);
    mvaddch(tmax[0]-1,tmax[1]-26,gasi[2]);
    
    mvaddch(tmax[0]-1,tmax[1]-33,'F');
    mvaddch(tmax[0]-1,tmax[1]-32,'U');
    mvaddch(tmax[0]-1,tmax[1]-31,'E');
    mvaddch(tmax[0]-1,tmax[1]-30,'L');
    mvaddch(tmax[0]-1,tmax[1]-29,':');
    
    
    move(cretorna_y(),cretorna_x());
}


int traduzir_path(int qturnos,int *tmax)
{
    int var;
    for(int i = 0; i <qturnos;i++)
    {
        usleep(300000/get_velo());
        if(scan0()=='+'||scan1()=='+'||scan2()=='+'||scan3()=='+'||scan4()=='+'||scan5()=='+'||scan6()=='+'||scan7()=='+')
        {
            return(0);
        }
        if(path[i]=='8')
        {
            var = pmoveup(pretorna_y(),pretorna_x());
            turnomais();
        }
        
        if(path[i]=='9')
        {
            var = pmoveupr(pretorna_y(),pretorna_x());
            turnomais();
        }
        
        if(path[i]=='7')
        {
            var = pmoveupl(pretorna_y(),pretorna_x());
            turnomais();
        }
        
        if(path[i]=='6')
        {
            var = pmoveright(pretorna_y(),pretorna_x());
            turnomais();
        }
        if(path[i]=='4')
        {
            var = pmoveleft(pretorna_y(),pretorna_x());
            turnomais();
        }
        if(path[i]=='1')
        {
            var = pmovedownl(pretorna_y(),pretorna_x());
            turnomais();
        }
        if(path[i]=='2')
        {
            var = pmovedown(pretorna_y(),pretorna_x());
            turnomais();
        }
        if(path[i]=='3')
        {
            var = pmovedownr(pretorna_y(),pretorna_x());
            turnomais();
        }
        update_gasosa(tmax);
        update_turno(tmax);
        if(var == 0)
        {
            return(0);
        }
        
    }
    
    
}


int gerar_rota(int qturnos,int *tmax)
{
    
    mvaddch(cretorna_y(),cretorna_x(),'+');
    limpar_rota();
    scanear(pretorna_y(),pretorna_x());
        
        if(pretorna_y()>cretorna_y()&&pretorna_x()>cretorna_x())
        {
            path[linha_atual] = '7';
            linha_atual++;
            mvaddch(pretorna_y()-1,pretorna_x()-1,'\\');
            refresh();
        }
        else if(pretorna_y()>cretorna_y()&&pretorna_x()<cretorna_x())
        {
            path[linha_atual] = '9';
            linha_atual++;
            mvaddch(pretorna_y()-1,pretorna_x()+1,'/');
            refresh();
        }
    
        else if(pretorna_y()<cretorna_y()&&pretorna_x()>cretorna_x())
        {
            path[linha_atual] = '1';
            linha_atual++;
            mvaddch(pretorna_y()+1,pretorna_x()-1,'/');
            refresh();
            
        }
    
        else if(pretorna_y()<cretorna_y()&&pretorna_x()<cretorna_x())
        {
            path[linha_atual] = '3';
            linha_atual++;
            mvaddch(pretorna_y()+1,pretorna_x()+1,'\\');
            refresh();
            
        }
    
        else if(pretorna_x()==cretorna_x())
        {
            if(pretorna_y()>cretorna_y())
            {
                path[linha_atual] = '8';
                linha_atual++;
                mvaddch(pretorna_y()-1,pretorna_x(),'|'); 
                refresh();

            }
            if(pretorna_y()<cretorna_y())
            {
                path[linha_atual] = '2';
                linha_atual++;
                mvaddch(pretorna_y()+1,pretorna_x(),'|');
                refresh();
                
            }
       }   
       else if(pretorna_y()==cretorna_y())
       {
         if(pretorna_x()>cretorna_x())
         {
            path[linha_atual] = '4';
            linha_atual++;
            mvaddch(pretorna_y(),pretorna_x()-1,'-');
            refresh();
         }
    
         if(pretorna_x()<cretorna_x())
         {
            path[linha_atual] = '6';
            linha_atual++;
            mvaddch(pretorna_y(),pretorna_x()+1,'-');
            refresh();
         }
       }
       
    mvaddch(cretorna_y(),cretorna_x(),'+');
    
    if(scan0()!='+'&&scan1()!='+'&&scan2()!='+'&&scan3()!='+'&&scan4()!='+'&&scan5()!='+'&&scan6()!='+'&&scan7()!='+')
    {
       int var = traduzir_path(1,tmax);
       if(var == 0)
       {
            return(0);
       }
    }
   
}
