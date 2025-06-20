exec = nevz
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g -Wall -lm -ldl -fPIC -rdynamic

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)
	-rm src/*.o

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@
	
clean:
	-rm nevz
	-rm *.o
	-rm *.a
	-rm src/*.o

lint: 
	clang-tidy src/*.c src/include/*.h

# TODO We need to fix this up 