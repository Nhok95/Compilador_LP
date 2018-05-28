#! /bin/bash
clear
antlr -gt example1.g
dlg -ci parser.dlg scan.c
g++ -std=c++11 -o example1 example1.c scan.c err.c -I/usr/include/pccts -Wno-write-strings
echo "FIN COMPILADO"