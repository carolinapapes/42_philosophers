# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: capapes <capapes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 07:27:27 by carolinapap       #+#    #+#              #
#    Updated: 2024/07/22 21:14:43 by capapes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUGFLAGS = -fsanitize=thread
CFLAGS = -Wall -Wextra -Werror
DEFLAGS = -MMD -MP 
INCLUDE = -I./include

PREQ = Makefile
NAME = philo

SRC_DIR = ./src
BUILD_DIR = ./build

SRC = 	main.c \
		action.c\
		fn_aux.c \
		parser.c \
		parser_is_int.c \
		philo_init.c \
		philo_forks.c \
		philo_exit.c \
		philo_rutine.c \
		philo_sysfn.c \
		philo_utils.c \
		philos_init.c \
		program_init.c \
		program_run.c \
		program_status.c \
		program_utils.c \
		program_end.c \

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
