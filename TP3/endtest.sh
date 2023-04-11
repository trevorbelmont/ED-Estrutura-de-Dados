#!/bin/bash

ERRADO="bin/c${1}errado.exe"
CORRETO="bin/c${1}correto.exe"
RELATORIO="c${1}relatorio.txt"
log_ruim="logs/${1}_log_ruim"
log_bom="logs/${1}_log_bom"


printf "\n4.\n" >> c${1}relatorio.txt

printf "gcc c$1.c -o ${CORRETO} -g \n valgrind --log-file=\"logs/log_bom_${1}\" --leak-check=full ./$CORRETO\n" >> c${1}relatorio.txt
gcc c${1}correto.c -o $CORRETO -g
valgrind  --log-file="${log_bom}" --leak-check=full ./${CORRETO}


printf "cat $log_bom >> c${1}relatorio.txt\n" >> c${1}relatorio.txt
cat $log_bom >> c${1}relatorio.txt

# abri o relatório
code c${1}relatorio.txt
