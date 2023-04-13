comp=g++
cflags=-std=c++20 -Wall

bin = ./bin/
src = ./src/
incld = ./include/
bld = ./obj/

exe_name = ff
target= ${bin}${exe_name}

${target}: ${bld}fibfat.o ${bld}main.o
	${comp} -pg ${cflags}  ${bld}fibfat.o ${bld}main.o -o ${target}

${bld}fibfat.o: ${incld}fibfat.hpp ${src}fibfat.cpp
	${comp} ${cflags} -I ${incld} -c ${src}fibfat.cpp -o ${bld}fibfat.o

${bld}main.o: ${incld}fibfat.hpp ${src}main.cpp
	${comp} ${cflags} -I ${incld} -c ${src}main.cpp -o ${bld}/main.o

run: ${target}
	${target} rFat 5
	${target} iFat 5
	${target} rFib 5
	${target} iFib 5

clear:
	rm ${target}; rm gmon.out

clear_all:
	rm -f ${bld}*o; make clear

clean:
	make clear_all