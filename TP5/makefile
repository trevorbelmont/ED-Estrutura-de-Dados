bin/exe: src/geraarvbin.c obj/geraarvbin.o
	g++ -w obj/geraarvbin.o -o bin/exe

obj/geraarvbin.o: src/geraarvbin.c
	g++ -w src/geraarvbin.c -c -o obj/geraarvbin.o 

run: bin/exe
	./bin/exe -o saida.txt -n 10 -s -899 && wait 4000

clean:
	rm bin/exe && rm obj/*.o && rm saida.txt