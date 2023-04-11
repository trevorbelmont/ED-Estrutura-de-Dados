#!/bin/bash

#CONDIÇÃO:  as pastas "bin" e "logs" tem que existirem na pasta msm pasta do script

#EXEMPLO DE USO: "bash test.sh renew history half/end 6"
  # o número do arquivo é sempre o ÚLTIMO ARGUMENTO
  # se a tag "renew" for usada o script faz um back up do relatório gerado anteriormente e o sobrescreve com um novo
  # se a tag "history" for usada o script copia os comandos usados no relatório antes de usá-lo
  # se "half" for usada o script só faz o relatório até o teste dos arquivos errados e cria uma cópia (para ser corrigida) e a abre
  # se "end" termina o relatório (adiciona ao arquivo o relatório do teste do arquivo correto)



# mais importante que tudo: DURANTE O REDIRECIONAMENTO DE ARQUIVOS
#                             " >> ", dois maior que, igual append
#                             " >  ", maior que simples, RESCREVE O ARQUIVO - OVERWRITE

#declaração de varíaveis deve ser feit e sem espaços entre o  igual,"=".

ERRADO="bin/c${@: -1}errado.exe"
CORRETO="bin/c${@: -1}correto.exe"
RELATORIO="c${@: -1}relatorio.txt"
log_ruim="logs/${@: -1}_log_ruim"
log_bom="logs/${@: -1}_log_bom"


# "$n" == "${n} ==  string do n-ésimo argumento 
# a versão com chaves é mais e segura útil quando a variável tá no meio do nome de um arquivo, por exemplo

# Se o último argumento não for um inteiro exita o script.
if [ ${@: -1} -eq ${@: -1} ]; 
  then
    echo "${@: -1} é um int e será analisado os arquivos c${@: -1}.c"

  else       #checa usando -eq que só compara valores inteiros (não strings)
    echo " too bad, o último argumento (${@: -1}) não era um inteiro. cancelando operação."
    exit 1
  fi

# testa se o segundo ou tercerio argumento manda sobescrever:
if [ "$1" == 'renew' -o "$2" == 'renew' -o "$3" == 'renew' ]; 
  then 
    #cria cópia de segurança do último relatório
    touch ${RELATORIO}.backup && cat $RELATORIO >> $RELATORIO.backup

    # impede que o script sobescreva o relatório com apenas a finalização, caso os argumentos RENEW e END sejam ambos passados, apaga o backup e fecha o script.
    [ "${1}" == 'end' -o "${2}" == 'end' -o "$3" == 'end' ] && echo "END e RENEW habilitados. Cancelando operação." && rm -i ${RELATORIO}.backup &&exit 1
    
    # se o if anterior for falso (não tiver END && RENEW ao msm tempo), apaga o relatório anterior - foi feito backup
    rm -i $RELATORIO    
fi
# termina o if com fi (if ao contrário, e é o msm com "case" que fecha com"esac". aff!) 

# usar if é meio complicado: 'strings' tem que ser entre aspas simples e o espaço antes e depois do igual é obrigatório
# -o é o "ou lógico", "||", disjunção
# -e é o "e lógico", "&&", conjunção
# comparações entre ints também podem ser feitas com feitas com -lt (less than) -gt (greater than)  -eq/-ne (equals / not equal) -le e -ge (greater/less or equal)
# pode ser simplificado usando apenas os colchetes e a comparação booleana antes de comandos:
# Mais informações: https://ryanstutorials.net/bash-scripting-tutorial/bash-if-statements.php

# test se nenhum argumento é "end" (apenas finalizar). Caso qualquer um for, pula os 2 primeiros tópicos
# leia-se: se não end em 1 && naõ end em 2 && não end em 3
if [ "${1}" != 'end' -a "${2}" != 'end' -a "$3" != 'end' ]; 
  then      #  o script faz os comandos dos 2 primeiros tópicos do relatório


#1 
#as predefinições da printf já fazem o -a (append at the end) e criam o arquivo, caso ele não exista
printf "1. \n\n\n2.\n" >> c${@: -1}relatorio.txt

#2

gcc c${@: -1}.c -o ${ERRADO} -g

[ "${1}" == "history" -o "${2}" == "history" -o "$3" == 'history' ] && printf "valgrind -q --log-file=\"${log_ruim}\" --leak-check=full ./$ERRADO\n" >> c${@: -1}relatorio.txt
valgrind  --log-file="$log_ruim" --leak-check=full ./${ERRADO}

[ "${1}" == "history" -o "${2}" == "history" -o "$3" == 'history' ] && printf "cat $log_ruim >> c${@: -1}relatorio.txt\n\n" >> c${@: -1}relatorio.txt
cat $log_ruim >> c${@: -1}relatorio.txt

[ "${1}" == "history" -o "${2}" == "history" -o "$3" == 'history' ] && printf "\ntouch c${@: -1}correto.c && cat c${@: -1}.c c${@: -1}correto.c \n" >> c${@: -1}relatorio.txt

## cria arquivo cxcorreto.c apenas se ele já não existir e interrompe a aplicação
# checa se o arquivo existe com a mesma extensaão (se não é uma pasta ou um homônimo)
if [ ! -f "c${@: -1}correto.c" ];
    then            # -f checa se o arquivo existe e é de msm extensão
                                              # -e checa se algum arquivou ou pasta com o nome existe
touch c${@: -1}correto.c && cat c${@: -1}.c >> c${@: -1}correto.c
code c${@: -1}correto.c 

echo "c${@: -1}correto.c foi criado. porém é necessário resolver o problema"
echo "run     bash test.sh end ${@: -1}     depois de completar para terminar o relatório"
    
exit 1

    else
    echo "c${@: -1}correto.c já existe e não será alterado (espero). Continuando..."
    fi            # Finaliza if do "não tinha cxcorreto.c"

#finaliza if do "não end"
fi 



## Exita se um dos primeiros argumentos for um "half"
[ "${1}" = 'half' -o "${2}" = 'half' -o "$3" == 'half' ] && exit 1


#4

printf "\n\n4.\n" >> c${@: -1}relatorio.txt

[ "${1}" == "history" -o "${2}" == "history" -o "$3" == 'history' ] && printf "gcc c${@: -1}.c -o ${CORRETO} -g \n valgrind --log-file=\"logs/log_bom_${@: -1}\" --leak-check=full ./$CORRETO\n" >> c${@: -1}relatorio.txt
gcc c${@: -1}correto.c -o $CORRETO -g
valgrind  --log-file="${log_bom}" --leak-check=full ./${CORRETO}


[ "${1}" == "history" -o "${2}" == "history" -o "$3" == 'history' ] && printf "cat $log_bom >> c${@: -1}relatorio.txt\n" >> c${@: -1}relatorio.txt
cat $log_bom >> c${@: -1}relatorio.txt

# abri o relatório
code c${@: -1}relatorio.txt