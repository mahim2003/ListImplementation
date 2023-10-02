
all: main

main: main.c list.c
	gcc -o main main.c list.c

clean:
	rm -f main


