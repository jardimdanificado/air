

char path[150];


int linha_atual=0;

int exec_atual = 0;

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


int traduzir_path(int *tmax)
{
    int var;

        usleep(300000/get_velo());
    if(gasosaq>0)
    {
        if(path[exec_atual]=='8')
        {
            var = pmoveup(pretorna_y(),pretorna_x());
            turnomais();
        }
        
        if(path[exec_atual]=='9')
        {
            var = pmoveupr(pretorna_y(),pretorna_x());
            turnomais();
        }
        
        if(path[exec_atual]=='7')
        {
            var = pmoveupl(pretorna_y(),pretorna_x());
            turnomais();
        }
        
        if(path[exec_atual]=='6')
        {
            var = pmoveright(pretorna_y(),pretorna_x());
            turnomais();
        }
        if(path[exec_atual]=='4')
        {
            var = pmoveleft(pretorna_y(),pretorna_x());
            turnomais();
        }
        if(path[exec_atual]=='1')
        {
            var = pmovedownl(pretorna_y(),pretorna_x());
            turnomais();
        }
        if(path[exec_atual]=='2')
        {
            var = pmovedown(pretorna_y(),pretorna_x());
            turnomais();
        }
        if(path[exec_atual]=='3')
        {
            var = pmovedownr(pretorna_y(),pretorna_x());
            turnomais();
        }
    }
        update_gasosa(tmax);
        update_turno(tmax);
        
        if(var == 0)
        {
            return(0);
        }
        
    //}
    
    exec_atual++;
}

int ultimo_destino[2];

void setdestino()
{
    ultimo_destino[0]=pretorna_y();
    ultimo_destino[1]=pretorna_x();
}

int get_udy()
{
    return(ultimo_destino[0]);
}

int get_udx()
{
    return(ultimo_destino[1]);
}

int temrota()
{
    int seboseira = 0;
    for(int x =0;x <telamx();x++)
    {
        for(int y =0;y <telamy()-2;y++)
        {
            mvinch(y,x);
            char var2 = inch();
            if(var2=='+')
            {
                seboseira = 1;
                return(1);
            }
        }
    }
    if(seboseira == 0)
    {
    return(0);
    }
    
}

int gerar_rota(int *tmax)
{
    int imagi[2];
    int o_destino[2];
    exec_atual = 0;
    mvaddch(cretorna_y(),cretorna_x(),'+');
    o_destino[0] = cretorna_y();
    o_destino[1] = cretorna_x();
    ultimo_destino[0] = cretorna_y();
    ultimo_destino[1] = cretorna_x();
    limpar_rota();
    scanear(pretorna_y(),pretorna_x());
    imagi[0] = pretorna_y();
    imagi[1] = pretorna_x();
    //scanear(imagi[0],imagi[1]);
    
      while(imagi[0]!=o_destino[0]||imagi[1]!=o_destino[1]) 
      {
        scanear(imagi[0],imagi[1]);
        if(imagi[0]>o_destino[0]&&imagi[1]>o_destino[1])
        {
            path[linha_atual] = '7';
            linha_atual++;
            imagi[0]--;
            imagi[1]--;

            refresh();
        }
        else if(imagi[0]>o_destino[0]&&imagi[1]<o_destino[1])
        {
            path[linha_atual] = '9';
            linha_atual++;
            imagi[0]--;
            imagi[1]++;
            refresh();
        }
    
        else if(imagi[0]<o_destino[0]&&imagi[1]>o_destino[1])
        {
            path[linha_atual] = '1';
            imagi[0]++;
            imagi[1]--;
            linha_atual++;
            refresh();
            
        }
    
        else if(imagi[0]<o_destino[0]&&imagi[1]<o_destino[1])
        {
            path[linha_atual] = '3';
            linha_atual++;
            imagi[0]++;
            imagi[1]++;
            refresh();
            
        }
    
        else if(imagi[1]==o_destino[1])
        {
            if(imagi[0]>o_destino[0])
            {
                path[linha_atual] = '8';
                imagi[0]--;
                linha_atual++;
                refresh();

            }
            if(imagi[0]<o_destino[0])
            {
                path[linha_atual] = '2';
                linha_atual++;
                imagi[0]++;
                refresh();
                
            }
       }   
       else if(imagi[0]==o_destino[0])
       {
         if(imagi[1]>o_destino[1])
         {
            path[linha_atual] = '4';
            linha_atual++;
            imagi[1]--;
            refresh();
         }
    
         if(imagi[1]<o_destino[1])
         {
            path[linha_atual] = '6';
            linha_atual++;
            imagi[1]++;
            refresh();
         }
       }
     }
    
   if(imagi[0]==o_destino[0]&&imagi[1]==o_destino[1])
    {
        return(0);
    }
   
}
