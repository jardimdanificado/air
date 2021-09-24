void criar_nuvens(int *tmax)
{
    mvprintw(tmax[0]-1,1,"LOADING CLOUDS.  ");
    refresh();
    unsigned long cusd = 5645;
    unsigned long semente = mix(clock(), time(NULL), cusd);
    srand(semente);
    int N_PISOS= tmax[1]*(tmax[0]-3);
    int roleta = (rand() % (N_PISOS - 8+ 1)) + 8;
	int cronometro =0;

	for(int y = 1;y<(tmax[0]-2);y++)
        {
          for(int x = 0;x<tmax[1];x++)
       	  {
            mvinch(y,x);
            inch();
            int leitura = inch();
            if(leitura == ' ')
            {
		cronometro++;
		if(cronometro == roleta&&roleta<(N_PISOS/8))
		{
		    mvaddch(y,x,'#');
		    mvaddch(y,x-(rand()%2),'#');
		    srand(semente);
		    mvaddch(y,x+(rand()%2),'#');
		    srand(semente);
		    mvaddch(y-2,x,'#');
		    srand(semente);
		    mvaddch(y+2,x,'#');
		    srand(semente);
		    mvaddch(y,x-(rand()%3),'#');
		    srand(semente);
		    mvaddch(y,x+3,'#');
		    srand(semente);
		    mvaddch(y-(rand()%3),x,'#');
		    srand(semente);
		    mvaddch(y+3,x,'#');
		    srand(semente);
		    mvaddch(y,x-(rand()%4),'#');
		    srand(semente);
		    mvaddch(y,x+(rand()%4),'#');
		    srand(semente);
		    mvaddch(y-4,x,'#');
		    srand(semente);
		    mvaddch(y+4,x,'#');
		    srand(semente);
		    mvaddch(y,x-(rand()%5),'#');
		    srand(semente);
		    mvaddch(y,x+3,'#');
		    srand(semente);
		    mvaddch(y-(rand()%5),x,'#');
		    srand(semente);
		    mvaddch(y+5,x,'#');
        }
        if(cronometro == roleta&&roleta>(N_PISOS/8))
		{
		    mvaddch(y,x,'#');
		    mvaddch(y-(rand()%2),x-(rand()%2),'#');
		    srand(semente);
		    mvaddch(y+(rand()%2),x+(rand()%2),'#');
		    srand(semente);
		    mvaddch(y-2,x+(rand()%2),'#');
		    srand(semente);
		    mvaddch(y+(rand()%2),x-(rand()%2),'#');
		    srand(semente);
		    mvaddch(y-(rand()%2),x-3,'#');
		    srand(semente);
		    mvaddch(y+(rand()%2),x+(rand()%3),'#');
		    srand(semente);
		    mvaddch(y-3,x+(rand()%3),'#');
		    srand(semente);
		    mvaddch(y+(rand()%2),x-(rand()%3),'#');
		    
		    
        }

        for(int y = 0; y < tmax[0];y++)
        {
            for(int x = 0; x < tmax[1];x++)
            {
                mvinch(y,x);
                int var = inch();
                mvinch(y,x-1);
                int var1 = inch();
                mvinch(y,x+1);
                int var2 = inch();
                mvinch(y,x+2);
                int var3 = inch();
        
                if(var1 == '#'&&var == ' '&&var2== ' '&&var3=='#')
                {
                    mvaddch(y,x,'#');
                    mvaddch(y,x+1,'#');
                }
            }
        }
        mvprintw(tmax[0]-1,1,"LOADING CLOUDS.. ");
        refresh();
        
        
        for(int y = 0; y < tmax[0];y++)
        {
            for(int x = 0; x < tmax[1];x++)
            {
                mvinch(y,x);
                int var = inch();
                mvinch(y,x-1);
                int var1 = inch();
                mvinch(y,x+1);
                int var2 = inch();
                mvinch(y,x+2);
                int var3 = inch();
        
                if(var1 == '#'&&var == ' '&&var2== '#'&&var3=='#')
                {
                    mvaddch(y,x,'#');
                }
            }
        }
        mvprintw(tmax[0]-1,1,"LOADING CLOUDS...");
        refresh();
         for(int y = 0; y < tmax[0];y++)
        {
            for(int x = 0; x < tmax[1];x++)
            {
                mvinch(y,x);
                int var = inch();
                mvinch(y,x-1);
                int var1 = inch();
                mvinch(y,x+1);
                int var2 = inch();
                mvinch(y,x+2);
                int var3 = inch();
        
                if(var1 == ' '&&var == '#'&&var2== ' '&&var3== ' ')
                {
                    mvaddch(y,x+1,'#');
                    mvaddch(y,x-1,'#');
                }
            }
        }
       
}
}
}
}
