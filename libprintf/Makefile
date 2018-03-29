NAME = libftprintf.a

SRCS = ft_printf.c \
		ft_parsing.c \
		ft_itoa_base.c \
		ft_flags.c \
		ft_unicode.c \
		ft_string.c \
		ft_numbers.c \
		ft_uni_print.c \
		ft_hex.c \
		ft_octal.c \
		ft_unsign.c \
		ft_binary_print.c \
		ft_float.c \
		ft_data_time.c \

LIB = ft_isalnum.c \
		ft_isdigit.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_isalpha.c \
		ft_strdup.c \
		ft_atoi.c \
		ft_strlen.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_bzero.c \
		ft_memccpy.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_strlcat.c \
		ft_memalloc.c \
		ft_strnew.c \
		ft_memdel.c \
		ft_strclr.c \
		ft_strdel.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_itoa.c \
		ft_strsplit.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_print_hex.c \
		ft_sqrt.c \
		ft_bubble_sort_num.c \
		ft_binary_search.c \
		ft_max.c \
		get_next_line.c \

CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I libft/

LIBSRCS	= $(addprefix libft/, $(LIB))

OBJECTS = $(SRCS:.c=.o)
LIBOBJ = $(LIBSRCS:.c=.o)

.PHONY: all clean fclean re 

all: $(NAME)

$(OBJECTS): %.o: %.c
	gcc -c $(CFLAGS) $< -o $@

$(LIBOBJ): %.o: %.c
	gcc -c $(CFLAGS) $(IFLAGS) $< -o $@

$(NAME): $(LIBOBJ) $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(LIBOBJ)

clean:
	/bin/rm -f $(OBJECTS)
	make clean -C ./libft

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C ./libft

re: fclean all