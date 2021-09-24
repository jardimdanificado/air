

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



int traduzir_path(int qturnos)
{
    int var;
    for(int i = 0; i <qturnos;i++)
    {
        usleep(90000/(i+1));
        
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
        if(var == 0)
        {
            return(0);
        }
        
    }
    
    
}


int gerar_rota(int qturnos)
{
    
    
    limpar_rota();
    scanear(pretorna_y(),pretorna_x());
        
        if(pretorna_y()>cretorna_y()&&pretorna_x()>cretorna_x())
        {
            path[linha_atual] = '7';
            linha_atual++;
        }
        else if(pretorna_y()>cretorna_y()&&pretorna_x()<cretorna_x())
        {
            path[linha_atual] = '9';
            linha_atual++;
        }
    
        else if(pretorna_y()<cretorna_y()&&pretorna_x()>cretorna_x())
        {
            path[linha_atual] = '1';
            linha_atual++;
            
        }
    
        else if(pretorna_y()<cretorna_y()&&pretorna_x()<cretorna_x())
        {
            path[linha_atual] = '3';
            linha_atual++;
            
        }
    
        else if(pretorna_x()==cretorna_x())
        {
            if(pretorna_y()>cretorna_y())
            {
                path[linha_atual] = '8';
                linha_atual++;

            }
            if(pretorna_y()<cretorna_y())
            {
                path[linha_atual] = '2';
                linha_atual++;
                
            }
       }   
       else if(pretorna_y()==cretorna_y())
       {
         if(pretorna_x()>cretorna_x())
         {
            path[linha_atual] = '4';
            linha_atual++;
         }
    
         if(pretorna_x()<cretorna_x())
         {
            path[linha_atual] = '6';
            linha_atual++;
         }
       }
    if(scan0()!='0'&&scan1()!='0'&&scan2()!='0'&&scan3()!='0')
    {
       int var = traduzir_path(1);
       if(var == 0)
       {
            return(0);
       }
    }
   
}
