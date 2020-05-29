all: bin/circles_execut bin/test
	./bin/test

bin/test: build/circle_proc.o build/read_file.o build/main_test.o build/geometry_tests.o
	gcc -Wall -Werror build/main_test.o build/circle_proc.o build/read_file.o build/geometry_tests.o -o bin/test -lm


build/main_test.o: test/main.c
	gcc -Wall -Werror -I thirdparty -I src -c test/main.c -o build/main_test.o 

build/geometry_tests.o: test/geometry_tests.c
	gcc -Wall -Werror -I thirdparty -I src -c test/geometry_tests.c -o build/geometry_tests.o

bin/circles_execut: build/main.o build/circle_proc.o build/read_file.o
	gcc -Wall -Werror build/main.o build/circle_proc.o build/read_file.o -o bin/circles_execut -lm

build/circle_proc.o: src/circle_proc.c
	gcc -Wall -Werror -c src/circle_proc.c -o build/circle_proc.o

build/read_file.o: src/read_file.c
	gcc -Wall -Werror -c src/read_file.c -o build/read_file.o 

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o 

.PHONY: clean

clean:
	rm -rf build/*.o bin/circles_execut bin/test


