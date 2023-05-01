bin/exe: src/geraarvbin.c obj/geraarvbin.o
	g++ -w obj/geraarvbin.o -o bin/exe

obj/geraarvbin.o: src/geraarvbin.c
	g++ -w src/geraarvbin.c -c -o obj/geraarvbin.o 

run: bin/exe
	./bin/exe -o file.txt -n 10 -s 665

clean:
	rm bin/exe && rm obj/*.o