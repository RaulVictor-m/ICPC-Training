test: test.cpp
	g++ -std=c++17 -O2 test.cpp -o test
	./test

main: main.cpp
	g++ -std=c++17 -O2 main.cpp -o main

testmain: main
	./main < .in

clean:
	rm -f ./main ./test
