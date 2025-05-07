vpath %.c ./srcs/buildins
vpath %.c	./srcs/utils 
vpath %.c	./srcs/lexer 
vpath %.c	./srcs/parser
vpath %.c	./srcs/executor
vpath %.c	./srcs/setup
vpath %.c	./debug

BUILD_DR = ./build/
NAME =	minishell

LIBFT_DR = ./libft
LIBFT = -L$(LIBFT_DR) -lft
INCLUDES_DRS = -I./includes -I./libft/includes 
HEADERS = ./includes/utlis.h ./debug/debug.h ./includes/lexer.h ./includes/parser.h ./includes/container.h ./includes/types.h ./includes/executor.h ./includes/buildins.h

FLAGS = -Wall -Wextra -Werror -g
CC = cc
RM = rm -f

SRCS= main.c lexer.c \
			handel_exit.c \
			print_lexer.c 

OBJS = $(addprefix $(BUILD_DR),$(SRCS:%.c=%.o))
green = \033[32m
reset = \033[0m

all: $(NAME)
	@echo "$(green)SUCCESS!!!$(reset)"

$(BUILD_DR)%.o: %.c $(HEADERS) | $(BUILD_DR) 
	$(CC) $(FLAGS) $(INCLUDES_DRS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT_DR)
	$(CC) $(FLAGS) -lreadline -lhistory $(OBJS) $(INCLUDES_DRS) $(LIBFT) -o $(NAME)

$(BUILD_DR):
	mkdir -p $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DR) fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

vg:
	 valgrind --suppressions=../ignore_readline_leaks.supp --leak-check=full --show-leak-kinds=all ./minishell

.PHONY: all clean fclean re
