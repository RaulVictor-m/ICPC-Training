test: test.cpp
	g++ -std=c++17 -O2 test.cpp -o test

main: main.cpp
	g++ -std=c++17 -O2 main.cpp -o main

testmain: main
	./main < .in

testmainC: main
	./main < .in > out1
	python main.py < .in > out2
	diff out1 out2

testtest: test
	./test < .in

mainHard: main.cpp
	g++ -O0 -g -std=c++17 -Wall -Wextra -D_GLIBCXX_DEBUG -fsanitize=address,undefined -fanalyzer main.cpp -o mainHard

testmainH: mainHard
	./mainHard < .in

testmainHV: mainHard
	valgrind ./mainHard < .in

clean:
	rm -f ./main ./test ./mainHard
