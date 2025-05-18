
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
HEADERS = ./debug/debug.h ./includes/utils.h ./includes/t_field.h  ./includes/lexer.h ./includes/parser.h ./includes/container.h ./includes/types.h ./includes/executor.h ./includes/buildins.h
FLAGS =  -Wall -Wextra -Werror -g
CC = cc
RM = rm -f

# debug
F_DEBUG = ast_examples.c print_arr_str.c print_lexer.c print_ast.c

# folders
F_UTILS = command_end.c free_methods.c get_word.c handel_exit.c heredoc.c wait_macros.c
F_LEXER = lexer.c
F_PARSER = grammar.c parser_1.c parser.c utils.c
F_T_FIELD = field_append.c field_clean.c field_drop.c field_extract.c field_insert.c field_new.c field_set.c field_split_at.c 
F_EXECUTOR = executor.c exec_utils.c extract.c field_exec_expand.c field_exec_split.c wild_match.c
F_BUILDINS = cd.c echo.c env.c exit.c export.c pwd.c unset.c

# used files
SRCS = main_ast.c $(F_PARSER) $(F_LEXER) $(F_DEBUG) $(F_UTILS) $(F_T_FIELD) $(F_EXECUTOR)
OBJS = $(addprefix $(BUILD_DR),$(SRCS:%.c=%.o))

# colors
green = \033[32m
reset = \033[0m

all: $(NAME)
	@clear;
	@echo "$(green)SUCCESS!!!$(reset)"
	@./$(NAME)

debug: $(NAME)
	clear
	make re
	gdbgui ./minishell

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
d:
	gdbtui ./$(NAME)

.PHONY: all clean fclean re
