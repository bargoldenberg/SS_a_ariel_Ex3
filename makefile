all:  stringProg
stringProg: main.o StringProglib.a StringProg.h
	gcc -Wall -g -o stringProg main.o StringProglib.a
StringProglib:StringProglib.a
StringProglib.a: StringProg.o 
	ar -rcs StringProglib.a StringProg.o
StringProg.o: StringProg.c StringProg.h
	gcc -Wall -g -c StringProg.c 
main.o: main.c StringProg.h
	gcc -Wall -g -c main.c 

.PHONY: clean#.PHONY means that clean is not a file.
clean:
	rm -f *.o *.a  stringProg 