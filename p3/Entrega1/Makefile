#Using the example given by the professor Paulo Pedreiras in TP Class

P=app
OBJECTS= app.o MyFIFO.o
CFLAGS = -g -Wall -O3
LDLIBS=
CC=gcc

all: $(P)

# Generate application
$(P): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(P) $(OBJECTS)

# Generate object files
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o $(P)
