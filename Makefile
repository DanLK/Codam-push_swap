NAME = push_swap
NAME_BONUS = checker
SOURCES = stack_utils.c \
		stack_utils_2.c \
		stack_operations.c \
		stack_operations_compound.c \
		input_checks.c \
		input_handles.c \
		memory_clears.c \
		debug.c \
		sorting_utils.c \
		sorting_utils_2.c \
		cost_analysis.c \
		cost_analysis_2.c \
		sorting.c
MAIN_SRC = 	push_swap.c
BONUS_SRCS = checker.c checker_utils.c
SRC_DIR = ./src
OBJ_DIR = ./obj
OBJFILES = $(SOURCES:%.c=$(OBJ_DIR)/%.o)
MAIN_OBJ = $(MAIN_SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS = $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

CFLAGS += -Wall -Wextra -Werror

LIBFT_NAME = ./libft/libft.a
LIBFT_PATH = ./libft

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJFILES) $(LIBFT_NAME) $(MAIN_OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJFILES) $(MAIN_OBJ) $(LIBFT_NAME)

$(NAME_BONUS): $(OBJFILES) $(OBJ_BONUS) $(LIBFT_NAME)
	$(CC) -o $(NAME_BONUS) $(OBJ_BONUS) $(OBJFILES) $(LIBFT_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	rm -f $(MAIN_OBJ)
	rm -f $(OBJFILES)
	rm -r -f $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus
