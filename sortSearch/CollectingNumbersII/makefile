test: test.cpp
	g++ -std=c++17 -O2 test.cpp -o test

main: main.cpp
	g++ -std=c++17 -O2 main.cpp -o main

testmain: main
	timeout 2s ./main < .in

testtest: test
	timeout 2s ./test < .in

clean:
	rm -f ./main ./test
