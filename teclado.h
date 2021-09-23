

int qturnos = 3;

int retornarqturnos()
{
    return(qturnos);
}

int Teclado()
{
        int tecla = getchar();
        
        
        switch(tecla)
        {
        		case 'q':
        		{
        			return(tecla);
        		}
        		break;
        		
        		case '5':
        		{
        		  curs_set(0);
        		  for(int i = 0; i <5;i++)
        		  {
        		    
        		    qturnos = gerar_rota(qturnos);
        		    //mvaddch(cretorna_y(),cretorna_x(),'0');
        		    //move(cretorna_y(),cretorna_x());
        		    //tecla = getchar();
        		    traduzir_path(qturnos);
        		    //mvaddch(cretorna_y(),cretorna_x(),' ');
        		    //move(cretorna_y(),cretorna_x());
        		  }
        		}
        		break;

                case '8':
                {
                    cmoveup();
                }
                break;
                
                case '7':
                {
                    cmoveupl();
                }
                break;
                
                case '9':
                {
                    cmoveupr();
                }
                break;
                
                case '2':
                {
                    cmovedown();
                }
                break;
                
                case '1':
                {
                    cmovedownl();
                }
                break;
                
                case '3':
                {
                    cmovedownr();
                }
                break;

                case '6':
                {
                    cmoveright();
                }
                break;

                case '4':
                {
                    cmoveleft();
                }
                break;
                
                case '+':
                {
                    if(qturnos >= 0)
                        qturnos= qturnos + 3;
                }
                break;
                
                case '-':
                {
                    if(qturnos >=3)
                        qturnos = qturnos - 3;
                
                }
                break;



         }

}
