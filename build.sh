#!/bin/bash
sudo apt install libncurses5-dev libxdo build-essential libx11 libxtst

gcc main.c -o air.run -lncurses -lxdo
