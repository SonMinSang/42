NAME = libftprintf.a

SRCS_DIR = ./srcs/

SRCS_NAME = ft_printf.c parsing.c print_char.c print_nbr.c print_string.c print_pointer.c print.c utils.c

SRCS = $(addprefix $(SRCS_DIR),$(SRCS_NAME))

OBJS = $(SRCS_NAME:.c=.o)

INCLUDE := -I./include

BONUS_DIR = ./bonus/

BONUS_NAME = ft_printf_bonus.c parsing_bonus.c print_char_bonus.c print_nbr_bonus.c print_string_bonus.c print_pointer_bonus.c print_bonus.c utils_bonus.c

BONUS_SRCS = $(addprefix $(BONUS_DIR),$(BONUS_NAME))

BONUS_OBJS = $(BONUS_NAME:.c=.o)

INCLUDE := -I./include

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS) $(INCLUDE)
	ar rc $(NAME) $(OBJS)

bonus :
	gcc $(FLAGS) -c $(BONUS_SRCS) $(INCLUDE)
	ar rc $(NAME) $(BONUS_OBJS)

clean:
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME)


re: fclean all
