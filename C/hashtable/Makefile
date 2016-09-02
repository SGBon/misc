CC=gcc
CFLAGS=-c -Wall -Wextra
LDFLAGS=
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
