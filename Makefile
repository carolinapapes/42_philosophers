# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: capapes <capapes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 07:27:27 by carolinapap       #+#    #+#              #
#    Updated: 2024/07/11 18:09:47 by capapes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g  -O3  
DEFLAGS = -MMD -MP 
DEBUGFLAGS = -fsanitize=thread
INCLUDE = -I./include

PREQ = Makefile
NAME = philosophers

SRC_DIR = ./src
BUILD_DIR = ./build

SRC = 	main.c \
		mutex_write.c\
		debug.c \
		fn_aux.c \
		parser.c \
		program__end.c \
		philo__init.c \
		philo__rutine.c \
		philos__init.c \
		philo__eat.c \
		philos__utils.c \
		program__init.c \
		program__run.c \
		program__utils.c \
		mx__meals.c \

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)
DEP = $(OBJ:%.o=%.d)
BUG = val.sh


# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) has been created$(DEF_COLOR)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(PREQ) | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(DEFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GRAY)⏳Compiling $<$(DEF_COLOR)"

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)
	echo "$(RED)🧹clean		${NAME}$(DEF_COLOR)"

fclean: clean
	rm -f $(NAME)
	rm -f $(BUG)
	echo "$(RED)🧹fclean		${NAME}$(DEF_COLOR)"

bugs: all | $(BUG)
	echo 'Run "val.sh" to set VAL in your environment'
	echo 'Execute $$VAL ./$(NAME) to run the program with valgrind'

$(BUG):
	echo 'export VAL="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes"' > val.sh
	chmod +x val.sh

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re

.SILENT:
