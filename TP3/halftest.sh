#!/bin/bash

ERRADO="bin/c${1}errado.exe"
CORRETO="bin/c${1}correto.exe"
RELATORIO="c${1}relatorio.txt"
log_ruim="logs/${1}_log_ruim"
log_bom="logs/${1}_log_bom"

#1

printf "1. \n\n\n2.\n" >> c${1}relatorio.txt

#2

printf "gcc c$1.c -o ${ERRADO} -g &&" >> $RELATORIO
gcc c$1.c -o ${ERRADO} -g

printf "valgrind -q --log-file=\"${log_ruim}\" --leak-check=full ./$ERRADO\n" >> c${1}relatorio.txt
valgrind  --log-file="$log_ruim" --leak-check=full ./${ERRADO}

printf "cat $log_ruim >> c${1}relatorio.txt\n" >> c${1}relatorio.txt
cat $log_ruim >> c${1}relatorio.txt

#4

printf "\n\n" >> c${1}relatorio.txt
