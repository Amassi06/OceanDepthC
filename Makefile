	CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/creatures.c
OBJ = $(SRC:.c=.o)
EXEC = oceandepths

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all
