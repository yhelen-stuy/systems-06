all:
	gcc -o list list.c

run: all
	./list

clean:
	rm list
