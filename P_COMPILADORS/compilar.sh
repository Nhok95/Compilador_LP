#! /bin/bash
clear
antlr -gt plumber.g
dlg -ci parser.dlg scan.c
g++ -std=c++11 -o plumber plumber.c scan.c err.c -I/usr/include/pccts -Wno-write-strings
echo "FIN COMPILADO"