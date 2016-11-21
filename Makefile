all: lab7

lab7: getinput.o verify.o code.o
	g++ --std=c++11 getinput.o verify.o code.o -o lab7

test:
#	afl-g++ --std=c++11 getinput.cpp verify.cpp code.cpp -o lab7-afl
	valgrind --leak-check=full --show-leak-kinds=all ./lab7 < test-input
#	cppcheck --std=c++11 --enable=all code.cpp verify.cpp getinput.cpp
#	AFL_SKIP_CPUFREQ=1 afl-fuzz -d -i in -o out -- ./lab7-afl
	zzuf -s 0:1000 -c -C 0 -q -T 3 ./lab7 < test-input

getinput.o: getinput.cpp
	g++ --std=c++11 -c getinput.cpp

verify.o: verify.cpp
	g++ --std=c++11 -c verify.cpp

code.o: code.cpp
	g++ --std=c++11 -c code.cpp

clean:
	rm *o lab7
