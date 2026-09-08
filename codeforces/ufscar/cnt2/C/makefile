test: test.cpp
	g++ -std=gnu++23 -O2 test.cpp -o test

main: main.cpp
	g++ -std=gnu++23 -O2 main.cpp -o main

testmain: main
	./main < .in

testtest: test
	./test < .in

mainHard: main.cpp
	g++ -O0 -g -std=gnu++23 -Wall -Wextra -D_GLIBCXX_DEBUG -fsanitize=address,undefined -fanalyzer main.cpp -o mainHard

testmainH: mainHard
	./mainHard < .in

testmainHV: mainHard
	valgrind ./mainHard < .in

clean:
	rm -f ./main ./test ./mainHard
