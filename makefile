all:main


main:build/src/main.o
	gcc build/src/main.o -o bin/main
build/src/main.o:src/main.c
	gcc -c src/main.c -o build/src/main.o


run:
	bin/./main


clean:
	rm -rf build/src/*.o build/test/*.o bin/main
