all: lab7

lab7: getinput.o verify.o code.o
	g++ --std=c++11 getinput.o verify.o code.o -o lab7

test:
	afl-g++ --std=c++11 getinput.cpp verify.cpp code.cpp -o lab7-afl
	valgrind --leak-check=full ./lab7 < test-input
#	cppcheck --std=c++11 --enable=all code.cpp verify.cpp getinput.cpp
	AFL_SKIP_CPUFREQ=1 afl-fuzz -d -i in -o out -- ./lab7-afl
	sleep 10
	kill -9 %%

getinput.o: getinput.cpp
	g++ --std=c++11 -c getinput.cpp

verify.o: verify.cpp
	g++ --std=c++11 -c verify.cpp

code.o: code.cpp
	g++ --std=c++11 -c code.cpp

clean:
	rm *o lab7
