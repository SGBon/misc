CC=gcc
CFLAGS=-c -Wall -Wextra -O3
LDFLAGS=-O3
SOURCES=fnvhash.c hashtable.c htutil.c hashtest.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=hashtest

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean run
run: all
	./$(EXECUTABLE)
clean:
	rm $(OBJECTS) $(EXECUTABLE)
