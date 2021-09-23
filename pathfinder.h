

char path[5];

char scan[4];

int linha_atual=1;

void limpar_rota()
{
    for(int i = 5;i<5;i++)
    {
        path[i] = '0';
    }
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


int traduzir_path(int qturnos)
{
    for(int i = 0; i <qturnos;i++)
    {
        usleep(qturnos*1500);
        
        if(path[i]=='8')
        {
            pmoveup(pretorna_y(),pretorna_x());
        }
        
        if(path[i]=='9')
        {
            pmoveupr(pretorna_y(),pretorna_x());
        }
        
        if(path[i]=='7')
        {
            pmoveupl(pretorna_y(),pretorna_x());
        }
        
        if(path[i]=='6')
        {
            pmoveright(pretorna_y(),pretorna_x());
        }
        if(path[i]=='4')
        {
            pmoveleft(pretorna_y(),pretorna_x());
        }
        if(path[i]=='1')
        {
            pmovedownl(pretorna_y(),pretorna_x());
        }
        if(path[i]=='2')
        {
            pmovedown(pretorna_y(),pretorna_x());
        }
        if(path[i]=='3')
        {
            pmovedownr(pretorna_y(),pretorna_x());
        }
        turnomais();
        
    }
    
    
}


int gerar_rota(int qturnos)
{
    limpar_rota();
    linha_atual = 0;
    
    for(int i=0; i < qturnos;i++)
    {
        
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
       scanear(pretorna_y(),pretorna_x());
       return(qturnos);
   }
}
