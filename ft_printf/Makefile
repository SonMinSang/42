NAME = libftprintf.a

SRCS_DIR = ./srcs/

SRCS_NAME = ft_printf.c parsing.c print_char.c print_nbr.c print_string.c print_pointer.c print.c utils.c

SRCS = $(addprefix $(SRCS_DIR),$(SRCS_NAME))

OBJS_DIR = ./objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_DIR),$(OBJS_NAME))

INCLUDE := -I./include

BONUS_DIR = ./bonus/

BONUS_NAME = ft_printf_bonus.c parsing_bonus.c print_char_bonus.c print_nbr_bonus.c print_string_bonus.c print_pointer_bonus.c print_bonus.c utils_bonus.c

BONUS = $(addprefix $(BONUS_DIR),$(BONUS_NAME))

OBJS_DIR = ./objs/

BONUS_OBJS_NAME = $(BONUS_NAME:.c=.o)

BONUS_OBJS = $(addprefix $(OBJS_DIR),$(BONUS_OBJS_NAME))

INCLUDE := -I./include

FLAGS = -Wall -Wextra -Werror

$(NAME):
	gcc $(FLAGS) -c $(SRCS) $(INCLUDE)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

bonus :
	gcc $(FLAGS) -c $(BONUS) $(INCLUDE)
	ar rc $(NAME) $(BONUS_OBJS)

clean:
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
