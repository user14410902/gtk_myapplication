CFLAGS=-O2 -g -Wall -Wextra -std=c11 -Wshadow $(shell pkg-config --libs --cflags gtk4)
LDFLAGS=$(shell pkg-config --libs gtk4)
BINARY=main
OBJECTS=my-application.o

default: $(BINARY)

$(BINARY): $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(BINARY)


