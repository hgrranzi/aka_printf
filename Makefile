NAME = libakaprintf.a

COMPILE = gcc -Wall -Wextra -Werror -c

MAKELIB = ar rcs $(NAME)

SRCS = aka_printf.c print_arg.c check_specifier.c print_signed.c \
		print_unsigned.c print_chars.c aka_printf_utils.c utils.c

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): aka_printf.h $(OBJS)
	$(MAKELIB) $(OBJS)

%.o: %.c ft_printf.h
	$(COMPILE) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
