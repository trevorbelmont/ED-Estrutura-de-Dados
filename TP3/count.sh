#!/bin/bash

#bash --version
count=${@: -1}
[ "${@: -1}" -eq ${@: -1} ] && echo " ${@: -1} é int do bom" # falha se não for int
[ "${@: -1}" != '5' ] && echo "é cinco ms $count // continuou" # mas continua o script msm se falhar
[ "${@: -1}" -eq ${@: -1} ] && echo " ${@: -1} é DE FATO um int dos bons"

touch test
yes "run" #| gdb bin/c5correto -q

exit