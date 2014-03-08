CC = g++
CFLAGS = -pg -Wall -DTESTING
LIBRARIES = -lGL -lGLU -lglut -l3ds
OBJECTS = $(patsubst %.cpp, %.o, $(wildcard src/*/*.cpp))
BINARY = cardgametest

tested: all test

all: $(OBJECTS)
	$(CC) -o $(BINARY) $(CFLAGS) $(LIBRARIES) $(OBJECTS)

%.o: %.cpp
	$(CC) -c -o $@ $(CFLAGS) $<

test:
	./test.rb ./$(BINARY) test
	@echo done.

clean:
	rm -f ./$(BINARY)
	rm -f src/cards/*.o
	rm -f test/*
	rm -f *~

.PHONY: test
