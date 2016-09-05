CC=gcc
HTINC=-I../hashtable/include
HTLIB=-lhashtable -L../hashtable/build -Wl,-rpath=../hashtable/build
CFLAGS=-c -Wall -Wextra -O3 $(HTINC)
LDFLAGS=-O3 $(HTLIB)
SOURCES=collatz.c helper.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=collatz

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(TEST) -o $@

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean run
run: all
	./$(EXECUTABLE)
clean:
	rm $(OBJECTS) $(EXECUTABLE)
