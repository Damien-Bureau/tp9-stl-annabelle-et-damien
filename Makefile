main.exe : main.o
	g++ -o main.exe *.o

main.o : main.cpp
	g++ -c main.cpp csv.cpp

clean:
	rm -f main.exe *.o