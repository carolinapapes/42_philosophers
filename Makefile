CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O3 -I./include
SRC_DIR = ./src
SRC = main.c \
ft_isdigit.c \
ft_isempty.c \
ft_issign.c \
ft_strlen.c \
ft_strncmp.c \
parser.c

BUILD_DIR = ./build

OBJ_SRC = $(SRC:%.c=$(BUILD_DIR)/%.o)
DPS = $(OBJ_SRC:%.o=%.d)

PREQ = Makefile
NAME = philosophers
DEFLAGS := -MMD -MP

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m

all: $(NAME)

$(NAME): $(OBJ_SRC)
	@$(CC) $(CFLAGS) $(OBJ_SRC) -o $(NAME)
	@echo "$(GREEN)📚completed		$(NAME)$(DEF_COLOR)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(PREQ) | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(DEFLAGS) -c $< -o $@
	@echo "$(GRAY)⏳compiling		$<$(DEF_COLOR)"
	
$(BUILD_DIR):
	@mkdir -p $@

val: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS)

clean:
	@rm -rf $(BUILD_DIR)
	@echo "$(RED)🧹clean		${NAME}$(DEF_COLOR)"

fclean:
	@rm -f $(NAME)
	@rm -rf $(BUILD_DIR)
	@echo "$(RED)🧹fclean		${NAME}$(DEF_COLOR)"

re: fclean all

-include $(DPS)

.PHONY: re fclean clean all