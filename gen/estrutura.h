

void criar_aeroportos(int *tmax)
{
    unsigned long cusd = 6452;
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
		if(cronometro == roleta&&roleta <= (N_PISOS/2))
		{
		    mvaddch(y,x-1,'[');
			mvaddch(y,x,'%');
			mvaddch(y,x+1,'#');
			mvaddch(y,x+2,']');
			mvaddch(y,x+3,'=');
			mvaddch(y,x+4,'=');
			mvaddch(y+1,x-1,' ');
			mvaddch(y+1,x,'-');
			mvaddch(y+1,x+1,' ');
			mvaddch(y+1,x+2,'-');
			mvaddch(y+2,x-1,'=');
			mvaddch(y+2,x,'=');
			mvaddch(y+2,x+1,'=');
			mvaddch(y+2,x+2,'=');
			mvaddch(y+1,x+3,' ');
			mvaddch(y+1,x+4,'-');
			mvaddch(y+2,x+3,'=');
			mvaddch(y+2,x+4,'=');
			y = tmax[0]+1;
			x = tmax[1]+1;
		}
		else if(cronometro == roleta&&roleta > (N_PISOS/2))
		{
		    mvaddch(y,x-1,'[');
			mvaddch(y,x,'%');
			mvaddch(y,x+1,'#');
			mvaddch(y,x+2,']');
			mvaddch(y,x+3,'=');
			mvaddch(y,x+4,'=');
			mvaddch(y-1,x-1,' ');
			mvaddch(y-1,x,'-');
			mvaddch(y-1,x+1,' ');
			mvaddch(y-1,x+2,'-');
			mvaddch(y-2,x-1,'=');
			mvaddch(y-2,x,'=');
			mvaddch(y-2,x+1,'=');
			mvaddch(y-2,x+2,'=');
			mvaddch(y-1,x+3,' ');
			mvaddch(y-1,x+4,'-');
			mvaddch(y-2,x+3,'=');
			mvaddch(y-2,x+4,'=');
			y = tmax[0]+1;
			x = tmax[1]+1;
		}
            }
          }
        }
}


