# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carolinapapes <carolinapapes@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 07:27:27 by carolinapap       #+#    #+#              #
#    Updated: 2024/07/02 08:58:39 by carolinapap      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = CC
CFLAGS = -Wall -Wextra -Werror
DEFLAGS = -MMD -MP
DEBUGFLAGS = -g -fsanitize=address
INCLUDE = -I./include

PREQ = Makefile
NAME = philosophers

SRC_DIR = ./src
BUILD_DIR = ./build

SRC = main.c
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
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) has been created$(DEF_COLOR)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(PREQ) | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(DEFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GRAY)⏳Compiling $<$(DEF_COLOR)"

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)
	@echo "$(RED)🧹clean		${NAME}$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BUG)
	@echo "$(RED)🧹fclean		${NAME}$(DEF_COLOR)"

bugs: all | $(BUG)
	@echo 'Run "val.sh" to set VAL in your environment'
	@echo 'Execute $$VAL ./$(NAME) to run the program with valgrind'

$(BUG):
	@echo 'export VAL="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes"' > val.sh
	@chmod +x val.sh

-include $(DEP)

.PHONY: all clean fclean re

