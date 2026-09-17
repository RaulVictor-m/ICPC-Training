test: test.cpp
	g++ -std=gnu++17 -O0 -Wno-c++23-extensions -fno-exceptions -fno-rtti -fno-stack-protector -pipe test.cpp -o test

main: main.cpp
	g++ -std=gnu++17 -O0 -Wno-c++23-extensions -fno-exceptions -fno-rtti -fno-stack-protector -pipe main.cpp -o main

debug: main.cpp
	g++ -std=gnu++23 -g -Wall -Wextra -D_GLIBCXX_DEBUG main.cpp -o main

testmain: main
	./main < .in

testtest: test
	./test < .in

clean:
	rm -f ./main ./test
