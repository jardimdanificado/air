#!/bin/bash
apt install libncurses5-dev libxdo build-essential libx11 libxtst libc-bin linux-libc-dev

gcc main.c -o air.run -lncurses -lxdo
