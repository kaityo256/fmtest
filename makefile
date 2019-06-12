TARGET=gs
SRC=$(TARGET).c $(TARGET).h
CC=g++

all: a.out

$(SRC): $(TARGET).fmr $(TARGET).yaml
	formura $(TARGET).fmr

a.out: $(SRC) 
	$(CC) $(CPPFLAGS) main.cpp $(TARGET).c

clean:
	rm -f gs.c gs.h gs.o run
	rm -f a.out

