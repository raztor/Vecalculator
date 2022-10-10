vecalculator: main.o
	g++ -o ./src/vecalculator main.o
main.o: src/main.cpp
	g++ -c ./src/main.cpp
clean:
	rm *.o vecalculator