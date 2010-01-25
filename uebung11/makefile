CFLAGS = -Wall -Wextra -pedantic -std=c89 -ggdb3

SRC = main.c

OBJS = $(SRC:.c=.o)

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS) main
