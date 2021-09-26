
int abastecendo =0;


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
        		
        		case 'f':
        		{
        		    scanear(pretorna_y(),pretorna_x());
        		    if(getgrana()>0)
        		    {
        		        if(scan1()=='%'||scan3()=='%')
        		        {
        		            if(abastecendo==0)
        		            {
        		                abastecendo = 1;
        		            }
        		            else if(abastecendo==1)
        		            {
        		                abastecendo = 0;
        		            }
        		        }
        		    }
        		    else if(scan1()=='&'||scan3()=='&')
        		    {
        		      //abastecer();  
        		    }
        		}
        		break;
        		
        		
        		case ' ':
        		{
        		  if(get_udy()!=pretorna_y()||get_udx()!=pretorna_x())
        		  {
        		    mvaddch(get_udy(),get_udx(),' ');
        		  }
        		  if(retornargasosa()>0)
        		  {
        		    int var;
        		    curs_set(0);
        		    //mvaddch(cretorna_y(),cretorna_x(),'+');
        		        var = gerar_rota(tmax);
        		    if(var == 0)
        		    {
        		        move(cretorna_y(),cretorna_x());
        		        return(tecla);
        		    }
        		    move(cretorna_y(),cretorna_x());
        		    return(tecla);
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
                    
                        velosobe();
                }
                break;
                
                case '-':
                {
                        velodesce();
                }
                break;
                
                
                



         }

}
