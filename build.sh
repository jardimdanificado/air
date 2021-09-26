#!/bin/bash
sudo apt install libncurses5-dev libxdo-dev libxdo3 build-essential libx11-dev libxtst-dev libc-bin linux-libc-dev

gcc main.c -o air.run -lncurses -lxdo
