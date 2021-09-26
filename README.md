# AIR

Aircraft Instruments, Roguelike!

numpad(8way)/keypad moves cursor;

'+' increase the speed by 1;

'-' decrase the speed by 1;

SPACE set a destination

'q' quits 

to compile on debian(if you prefer theres a build.sh file included in source):

sudo apt install libncurses5-dev libxdo-dev libxdo3 build-essential libx11-dev libxtst-dev libc-bin linux-libc-dev

gcc main.c -o air.run -lncurses -lxdo
