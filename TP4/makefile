comp=g++
cflags=-std=c++20 -Wall


bin = ./bin/
src = ./src/
incld = ./include/
bld = ./obj/

exe_name = tp4
target= ${bin}${exe_name}

${target}: ${bld}fila_pilhada.o ${bld}main.o
	${comp} -g ${cflags}  ${bld}fila_pilhada.o ${bld}main.o -o ${target} -g

${bld}fila_pilhada.o: ${incld}fila_pilhada.hpp ${src}fila_pilhada.cpp
	${comp} ${cflags} -I ${incld} -c ${src}fila_pilhada.cpp -o ${bld}/fila_pilhada.o -g

${bld}main.o:  ${incld}fila_pilhada.hpp ${src}main.cpp
	${comp} ${cflags} -I ${incld} -c ${src}main.cpp -o ${bld}/main.o -g

run: ${target}
	./${target}

test: ${target}
	./${target} interface

clear:
	rm ${target}

clear_all:
	rm -f ${bld}*o; make clear

clean:
	make clear_all