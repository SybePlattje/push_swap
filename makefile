NAME = push_swap
BONUS_NAME = checker

SRC_DIR = ./mandatory/src
INC_SRC_DIR = ./mandatory/include
BONUS_DIR = ./bonus/src
INC_BONUS_DIR = ./bonus/include

SOURCES_MAND = $(SRC_DIR)/actions.c \
			$(SRC_DIR)/error_free.c \
			$(SRC_DIR)/list_utils.c \
			$(SRC_DIR)/main.c \
			$(SRC_DIR)/sorting.c \
			$(SRC_DIR)/stack_init.c \
			$(SRC_DIR)/tiny_sort.c \
			$(SRC_DIR)/normalize.c \

SOURCES_BONUS = $(BONUS_DIR)/bonus_actions.c \
			$(BONUS_DIR)/bonus_error_free.c \
			$(BONUS_DIR)/bonus_list_utils.c \
			$(BONUS_DIR)/bonus_stack_init.c \
			$(BONUS_DIR)/check_on_input.c \
			$(BONUS_DIR)/checker.c \

OBJS_MAND = $(SOURCES_MAND:.c=.o)
OBJS_BONUS = $(SOURCES_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS_MAND) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_MAND) $(LIBFT) -o $(NAME)

bonus: $(OBJS_BONUS)
	@make -C ./libft
	@make -C ./libft gnl
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -L ./libft -l:libft.a -o $(BONUS_NAME)

clean:
	@rm -f $(OBJS_MAND) $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re