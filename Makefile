EXEC=dummy-display-example
CC=g++
CFLAGS=-W -Wall -std=c++11 -ansi -pedantic -I./ -I./Adafruit-GFX-Library
LDFLAGS=-lgraph
SRC= $(wildcard *.cpp ./Adafruit-GFX-Library/Adafruit_GFX.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
