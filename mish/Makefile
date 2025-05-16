vpath %.c ./srcs/buildins
vpath %.c	./srcs/utils 
vpath %.c	./srcs/lexer 
vpath %.c	./srcs/parser
vpath %.c	./srcs/executor
vpath %.c	./srcs/setup
vpath %.c	./srcs/t_field
vpath %.c	./debug

BUILD_DR = ./build/
NAME =	minishell

LIBFT_DR = ./libft
LIBFT = -L$(LIBFT_DR) -lft
INCLUDES_DRS = -I./includes -I./libft/includes 
HEADERS = ./debug/debug.h ./includes/utlis.h ./includes/t_field.h  ./includes/lexer.h ./includes/parser.h ./includes/container.h ./includes/types.h ./includes/executor.h ./includes/buildins.h

FLAGS =  -Wall -Wextra -Werror -g
CC = cc
RM = rm -f

# SRCS= main.c lexer.c \
# 			handel_exit.c ft_heredoc.c\
# 			print_lexer.c 

SRCS = ast_examples.c extract.c field_exec_expand.c field_exec_split.c wild_match.c ft_get_word.c  handel_exit.c exec_utils.c executor.c wait_macros.c \
			 field_append.c field_clean.c field_drop.c field_extract.c field_insert.c field_new.c field_set.c field_split_at.c
#SRCS = wild_match.c # handel_exit.c exec_utils.c executor.c wait_macros.c 

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
