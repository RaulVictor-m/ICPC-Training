test:
	g++ -std=c++17 -O2 test.cpp -o test
	./test

main:
	g++ -std=c++17 -O2 main.cpp -o main

testmain: clean main
	./main < .in

clean:
	rm -f ./main ./test
