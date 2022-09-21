CC = gcc -g
CFLAGS = -Wall -pedantic -ansi
OBJ = main.o LinkedList.o
EXEC = prog


$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c LinkedList.h
	$(CC) $(CFLAGS) -c main.c

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c

clean:
	rm -f $(EXEC) $(OBJ)