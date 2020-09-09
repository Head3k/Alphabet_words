all:main

main:build/src/main.o build/src/computing.o
	gcc build/src/main.o build/src/computing.o -o bin/main
build/src/computing.o:src/computing.c
	gcc -c src/computing.c -o build/src/computing.o
build/src/main.o:src/main.c
	gcc -c src/main.c -o build/src/main.o	
	
test:build/test/test.o build/test/main.o build/src/computing.o 
	gcc -I thirdparty -Wall -Werror build/test/test.o build/test/main.o build/src/computing.o -o bin/test	
build/test/test.o:test/test.c
	gcc -I src -I thirdparty -Wall -Werror -c test/test.c -o build/test/test.o
build/test/main.o:test/main.c
	gcc -I thirdparty -c test/main.c -o build/test/main.o


testing:
	bin/./test
	
run:
	bin/./main


clean:
	rm -rf build/test/*.o
	rm -rf build/src/*.o 
	rm -rf bin/*
	
checkdir:
	mkdir -p bin build build/test build/src
