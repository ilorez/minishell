vpath %.c srcs
vpath %.c	utils 

BUILD_DR = ./build/
NAME =	minishell

FLAGS = -Wall -Wextra -Werror -lreadline # -fsanitize=address -g #-g3 #
INCLUDES_DRS = -I./includes
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

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
