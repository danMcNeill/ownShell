all: myshell

myshell:
	gcc myshell.c -o myshell -m32 -std=c89 -g

clean:
	rm -f *.o myshell
