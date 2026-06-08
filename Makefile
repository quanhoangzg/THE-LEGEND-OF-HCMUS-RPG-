ifeq ($(OS),Windows_NT)
	TARGET = main.exe
	CLEAN = del /Q /F main.exe 2>NUL || rm -f main.exe
	RUN = .\$(TARGET)
else
	TARGET = main
	CLEAN = rm -f $(TARGET)
	RUN = ./$(TARGET)
endif

all: build run

build:
	g++ -std=c++17 app/main.cpp -o $(TARGET)

run:
	$(RUN)

clean:
	$(CLEAN)