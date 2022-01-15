NAME = libftprintf.a

SRCS = ft_printf.c parsing.c print_char.c print_nbr.c print_string.c print.c utils.c

OBJS = ${SRCS:%.c=%.o}

FLAGS = -Wall -Wextra -Werror

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

all : $(NAME)

bonus : $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
