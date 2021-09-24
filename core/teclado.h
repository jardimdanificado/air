

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
                default:
        		{
        			return(tecla);
        		}
        		break;
        		
        		case '5':
        		{
        		if(retornargasosa()>0)
        		  {
        		  int var;
        		  curs_set(0);
        		 // limpar_rota();
        		   for(int i = 0; i <5;i++)
        		   {
        		    //mvaddch(cretorna_y(),cretorna_x(),'+');
        		    for(int i=0; i < qturnos;i++)
                    {
        		        var = gerar_rota(qturnos,tmax);
        		        if(var == 0)
        		        {
        		            move(cretorna_y(),cretorna_x());
        		            mvaddch(cretorna_y(),cretorna_x(),' ');
        		            return(tecla);
        		        }
        		    }
        		    
        		    move(cretorna_y(),cretorna_x());
        		    mvaddch(cretorna_y(),cretorna_x(),' ');
        		    return(tecla);
                   }
        		  }
        		}
        		
        		case ' ':
        		{
        		  if(retornargasosa()>0)
        		  {
        		    int var;
        		    curs_set(0);
        		    //mvaddch(cretorna_y(),cretorna_x(),'+');
        		    for(int i=0; i < qturnos;i++)
                    {
        		        var = gerar_rota(qturnos,tmax);
        		        if(var == 0)
        		        {
        		            move(cretorna_y(),cretorna_x());
        		            mvaddch(cretorna_y(),cretorna_x(),' ');
        		            return(tecla);
        		        }
        		        
        		    }
        		    mvaddch(cretorna_y(),cretorna_x(),' ');
        		    move(cretorna_y(),cretorna_x());
        		    return(tecla);
        		    //tecla = getchar();
        		    //traduzir_path(qturnos);
        		  } 

        		}
        		
        		break;

                case '8':
                {
                    if(cretorna_y()>1)
                    cmoveup();
                }
                break;
                
                case '7':
                {
                    if(cretorna_y()>1&&cretorna_x()>0)
                    cmoveupl();
                }
                break;
                
                case '9':
                {
                    if(cretorna_y()>1&&cretorna_x()<tmax[1]-1)
                    cmoveupr();
                }
                break;
                
                case '2':
                {
                    if(cretorna_y()<tmax[0]-3)
                    cmovedown();
                }
                break;
                
                case '1':
                {
                    if(cretorna_y()<tmax[0]-3&&cretorna_x()>0)
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
                    if(cretorna_y()<tmax[0]-3)
                    cmovedown();
                }
                break;
                
                case KEY_UP:
                {
                    if(cretorna_y()>1)
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
                
                case '<':
                {
                    
                        velodesce();
                }
                break;
                
                case '>':
                {
                        velosobe();
                
                }
                break;
                
                



         }

}
