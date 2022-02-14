NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

FILE = command1\
		command2\
		error\
		find\
		free\
		ft_split\
		logic_utils\
		logic\
		push_swap\
		sort\
		utils
							

INCS = ./includes

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILE))) 
OBJS_DIR = ./srcs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILE))) 

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
