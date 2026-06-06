all: build run

build:
	g++ -std=c++17 app/main.cpp -o main.exe

run:
	./main.exe

clean:
	rm -f main.exe