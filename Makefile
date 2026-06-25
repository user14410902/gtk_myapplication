CFLAGS=-O2 -g -Wall -Wextra -std=c11 -Wshadow $(shell pkg-config --libs --cflags gtk4)
LDFLAGS=$(shell pkg-config --libs gtk4)
BINARY=main
OBJECTS=resources.o my-window.o my-application.o my-preference-dialog.o

default: $(BINARY)

$(BINARY): $(OBJECTS)

resources.c:
	glib-compile-resources my.gresource.xml --target resources.c --generate-source

clean:
	rm -f $(OBJECTS) $(BINARY) resources.c


