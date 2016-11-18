all: lab7

lab7: getinput.o verify.o code.o
	g++ getinput.o verify.o code.o -o lab7

test:
	rm lab7-afl
	afl-g++ getinput.cpp verify.cpp code.cpp -o lab7-afl
	valgrind --leak-check=full -v ./lab7 < test-input
	cppcheck --std=c++11 --enable=all code.cpp verify.cpp getinput.cpp
	AFL_SKIP_CPUFREQ=1 afl-fuzz -i in -o out -- ./lab7-afl

getinput.o: getinput.cpp
	g++ -c getinput.cpp

verify.o: verify.cpp
	g++ -c verify.cpp

code.o: code.cpp
	g++ -c code.cpp

clean:
	rm *o lab7
