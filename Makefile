NAME = lem-in

SRCS = main.c \
		reader.c \
		builder.c \
		builder_2.c \
		queue.c \
		other_queues.c \
		ants.c \
		check_errors.c \
		tools_1.c \
		bonus_lem_in.c

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libprintf/libftprintf.a

OBJECTS = $(SRCS:.c=.o)

.PHONY: all comp ncomp start clean fclean re 

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ./libprintf
	gcc $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT)

comp:
	gcc $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT)

ncomp:
	gcc -o $(NAME) $(SRCS) $(LIBFT)

start:
	@./$(NAME)

clean:
	/bin/rm -f $(OBJECTS)
	make clean -C ./libprintf

fclean: clean
	/bin/rm -f $(NAME) $(LIBFT) 
	make fclean -C ./libprintf

re: fclean all

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<