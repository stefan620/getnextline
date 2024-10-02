NAME = get_next_line.a

SOURCES = get_next_line.c get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)


cc = cc

//CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)


.PHONY: all clean fclean re