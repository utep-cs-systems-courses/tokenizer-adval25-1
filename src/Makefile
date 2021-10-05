main: main.o tokenizer.o history.o
	gcc -o main main.o tokenizer.o history.o

main.o: main.c tokenizer.c history.c
	gcc -c main.c tokenizer.c history.c

clean:
	rm -rf *.o *~ main

run: main
	./main
