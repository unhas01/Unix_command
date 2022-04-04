TARGETS = test1 test2 t1 t2
SOURCES = t1.c add.c sub.c mul.c dvd.c
OBJECTS = t1.o add.o sub.o mul.o dvd.o

all : $(TARGETS)

test1 : test1.c
	gcc -o test1 test1.c

t1 : $(SOURCES)
	gcc -o t1 $(SOURCES)

test2 : test1.o
	gcc -o test2 test1.o

test1.o : test1.c
	gcc -c test1.c

t2 : $(OBJECTS)
	gcc -o t2 $(OBJECTS)

t1.o : t1.c
	gcc -c t1.c

add.o : add.c
	gcc -c add.c

sub.o : sub.c
	gcc -c sub.c

mul.o : mul.c
	gcc -c mul.c

dvd.o : dvd.c
	gcc -c dvd.c

clean:
	rm -f *.o $(TARGETS)

