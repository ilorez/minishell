
vpath %.c	./srcs/utils 
vpath %.c	./srcs/lexer 
vpath %.c	./srcs/parser
vpath %.c	./srcs/executor
vpath %.c	./srcs/setup
vpath %.c	./srcs/t_field
vpath %.c	./srcs/buildins

BUILD_DR = ./build/
NAME =	minishell

LIBFT_DR = ./libft
LIBFT = -L$(LIBFT_DR) -lft
INCLUDES_DRS = -I./includes -I./libft/includes 
HEADERS = ./includes/utils.h ./includes/t_field.h ./includes/lexer.h ./includes/parser.h ./includes/container.h ./includes/types.h ./includes/executor.h ./includes/buildins.h
FLAGS =  -Wall -Wextra -Werror -g
CC = cc
RM = rm -rf

# vpath %.c	./debug
#./debug/debug.h
# debug
# F_DEBUG = print_arr_str.c print_lexer.c print_ast.c lists.c components.c buildins_lists.c

# folders
F_UTILS = command_end.c free_methods.c get_word.c handel_exit.c wait_macros.c get_env.c get_paths.c set_env.c unset_env.c signals.c randtmpfile.c
F_SETUP = setup.c
F_LEXER = lexer.c
F_PARSER = grammar.c parser_1.c parser.c utils.c redir_utils.c heredoc.c
F_T_FIELD = field_append.c field_clean.c field_drop.c field_extract.c field_insert.c field_new.c field_set.c field_split_at.c 
F_EXECUTOR = executor.c exec_utils.c extract.c field_exec_expand.c field_exec_split.c wild_match.c exec_child.c redir.c
F_BUILDINS = cd.c echo.c env.c exit.c export.c pwd.c unset.c buildins.c

# used files
SRCS = main.c $(F_PARSER) $(F_LEXER) $(F_SETUP) $(F_UTILS) $(F_T_FIELD) $(F_BUILDINS) $(F_EXECUTOR) 
OBJS = $(addprefix $(BUILD_DR),$(SRCS:%.c=%.o))

# colors
green = \033[32m
reset = \033[0m

all: $(NAME)
	@echo "$(green)SUCCESS!!!$(reset)"

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
	$(RM) $(BUILD_DR)
	make -C $(LIBFT_DR) fclean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BUILD_DR)

re: fclean all

vg:
	 valgrind --suppressions=../ignore_readline_leaks.supp --track-fds=yes --leak-check=full --show-leak-kinds=all ./minishell
vgb:
	 valgrind --suppressions=../ignore_readline_leaks.supp --track-fds=yes --leak-check=full --show-leak-kinds=all bash
d:
	gdbgui ./$(NAME)

.PHONY: all clean fclean re
