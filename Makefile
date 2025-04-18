vpath %.c srcs
vpath %.c	utils 

BUILD_DR = ./build/
NAME =	minishell

LIBFT_DR = ./libft
INCLUDES_DRS = -I./includes -I./libft/includes 

FLAGS = -Wall -Wextra -Werror -lreadline # -fsanitize=address -g #-g3 #
CC = cc
RM = rm -f

SRCS= 

OBJS = $(addprefix $(BUILD_DR),$(SRCS:%.c=%.o))
green = \033[32m
reset = \033[0m

all: $(NAME)
	@echo "$(green)SUCCESS!!!$(reset)"

$(BUILD_DR)%.o: %.c ./includes/minishell.h | $(BUILD_DR) 
	$(CC) $(FLAGS) $(INCLUDES_DRS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(INCLUDES_DRS) -o $(NAME)

$(BUILD_DR):
	mkdir -p $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DR) fclean

fclean: clean
	$(RM) $(NAME)


re: fclean all

test: 
		make -C $(LIBFT_DR)
		$(CC)  ./test_read_cmd/read_command.c ./test_read_cmd/string.c -lreadline -lhistory $(LIBFT_DR)/libft.a  -o read_test


.PHONY: all clean fclean re
