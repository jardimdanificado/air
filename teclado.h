

int qturnos = 3;

int retornarqturnos()
{
    return(qturnos);
}

int Teclado(int *tmax)
{
        int tecla = getch();
        
        
        switch(tecla)
        {
        		case 'q':
        		{
        			return(tecla);
        		}
        		break;
        		
        		case '5':
        		{
        		if(retornargasosa()>0)
        		  {
        		  curs_set(0);
        		 // limpar_rota();
        		   for(int i = 0; i <5;i++)
        		   {
        		    mvaddch(cretorna_y(),cretorna_x(),'0');
        		    for(int i=0; i < qturnos;i++)
                    {
        		        gerar_rota(qturnos);
        		    }
        		    
        		    move(cretorna_y(),cretorna_x());
        		    //tecla = getchar();
        		    //traduzir_path(qturnos);
        		    mvaddch(cretorna_y(),cretorna_x(),' ');
                   }
        		  }
        		}
        		
        		case ' ':
        		{
        		  if(retornargasosa()>0)
        		  {
        		    int var;
        		    curs_set(0);
        		    mvaddch(cretorna_y(),cretorna_x(),'0');
        		    for(int i=0; i < qturnos;i++)
                    {
        		        var = gerar_rota(qturnos);
        		        if(var == 0)
        		        {
        		            return(0);
        		        }
        		    }
        		    mvaddch(cretorna_y(),cretorna_x(),' ');
        		    move(cretorna_y(),cretorna_x());
        		    //tecla = getchar();
        		    //traduzir_path(qturnos);
        		  } 

        		}
        		
        		break;

                case '8':
                {
                    if(cretorna_y()>0)
                    cmoveup();
                }
                break;
                
                case '7':
                {
                    if(cretorna_y()>0&&cretorna_x()>0)
                    cmoveupl();
                }
                break;
                
                case '9':
                {
                    if(cretorna_y()>0&&cretorna_x()<tmax[1]-1)
                    cmoveupr();
                }
                break;
                
                case '2':
                {
                    if(cretorna_y()<tmax[0]-2)
                    cmovedown();
                }
                break;
                
                case '1':
                {
                    if(cretorna_y()<tmax[0]-2&&cretorna_x()>0)
                    cmovedownl();
                }
                break;
                
                case '3':
                {
                    if(cretorna_y()<tmax[1]-1&&cretorna_x()<tmax[1]-1)
                    cmovedownr();
                }
                break;

                case '6':
                {
                    if(cretorna_x()<tmax[1]-1)
                    cmoveright();
                }
                break;

                case '4':
                {
                    if(cretorna_x()>0)
                    cmoveleft();
                }
                break;
                
                case KEY_RIGHT:
                {
                    if(cretorna_x()<tmax[1]-1)
                    cmoveright();
                }
                break;

                case KEY_LEFT:
                {
                    if(cretorna_x()>0)
                    cmoveleft();
                }
                break;
                
                case KEY_DOWN:
                {
                    if(cretorna_y()<tmax[0]-2)
                    cmovedown();
                }
                break;
                
                case KEY_UP:
                {
                    if(cretorna_y()>0)
                    cmoveup();
                }
                break;
                
                case '+':
                {
                    
                        qturnos= qturnos + 1;
                }
                break;
                
                case '-':
                {
                    if(qturnos > 0)
                        qturnos = qturnos - 1;
                
                }
                break;



         }

}
