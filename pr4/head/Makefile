TARGETS = test1 test2 t1 t2
SOURCES = t1.c add.c sub.c mul.c dvd.c mod.c
OBJECTS = t1.o add.o sub.o mul.o dvd.o mod.o
HEADS = add.h sub.h mul.h dvd.h mod.h

all : $(TARGETS)

test1 : test1.c
	gcc -o test1 test1.c

t1 : $(SOURCES) $(HEADS)
	gcc -o t1 $(SOURCES)

test2 : test1.o
	gcc -o test2 test1.o

test1.o : test1.c
	gcc -c test1.c

t2 : $(OBJECTS)
	gcc -o t2 $(OBJECTS)

t1.o : t1.c $(HEADS)
	gcc -c t1.c

add.o : add.c add.h
	gcc -c add.c

sub.o : sub.c sub.h
	gcc -c sub.c

mul.o : mul.c mul.h
	gcc -c mul.c

dvd.o : dvd.c dvd.h
	gcc -c dvd.c

mod.o : mod.c mod.h
	gcc -c mod.c

clean:
	rm -f *.o $(TARGETS)

