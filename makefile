main: main.o NerfGun.o
	g++ -std=c++17 main.cpp NerfGun.cpp -o main
clean:
	rm -f *.o
