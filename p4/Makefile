CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = order.o user_input.o
EXEC = prog

$(EXEC) : $(OBJ)
    $(CC) $(OBJ) -o $(EXEC)

order.o : order.c order.h user_input.h
    $(CC) -c order.c $(CFLAGS)

user_input.o : user_input.c user_input.h
    $(CC) -c user_input.c $(CFLAGS)

clean :
    rm -f $(EXEC) $(OBJ)
 
