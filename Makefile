SRC_M = src/push_swap.c src/ft_inputs/ft_inputs.c src/ft_inputs/ft_clear_inputs.c \
		src/ft_stack/ft_stack.c src/ft_stack/ft_clear_stack.c src/ft_sort/ft_sort.c \
		src/ft_sort/ft_circo.c src/ft_sort/ft_order_three.c src/ft_sort/ft_indexer.c \
		src/ft_sort/ft_target.c src/ft_sort/ft_mvs.c src/ft_sort/ft_get.c src/ft_sort/ft_rotate_it.c \
		src/utils/ft_split.c src/utils/ft_atoi.c src/utils/ft_atol.c src/utils/ft_strlen.c \
		src/utils/ft_iserror.c src/operations/push.c src/operations/swap.c \
		src/operations/rotate.c src/operations/reverse_rotate.c

OBJ_M = $(SRC_M:.c=.o)

SRC_B = bonus/src/checker_bonus.c bonus/src/ft_inputs/ft_inputs_bonus.c \
		bonus/src/ft_inputs/ft_clear_inputs_bonus.c bonus/src/ft_stack/ft_stack_bonus.c \
		bonus/src/ft_stack/ft_clear_stack_bonus.c bonus/src/circo/ft_circo_bonus.c \
		bonus/src/circo/ft_get_bonus.c bonus/src/utils/ft_split_bonus.c \
		bonus/src/utils/ft_atoi_bonus.c bonus/src/utils/ft_atol_bonus.c \
		bonus/src/utils/ft_strcmp_bonus.c bonus/src/utils/ft_strlen_bonus.c \
		bonus/src/utils/ft_iserror_bonus.c bonus/src/operations/push_bonus.c \
		bonus/src/operations/swap_bonus.c bonus/src/operations/rotate_bonus.c \
		bonus/src/operations/reverse_rotate_bonus.c bonus/src/gnl/get_next_line_bonus.c \
		bonus/src/gnl/get_next_line_utils_bonus.c

OBJ_B = $(SRC_B:.c=.o)

NAME = push_swap

NAME_B = checker

CC = cc -Wall -Wextra -Werror

RM = rm -f

%_bonus.o: %_bonus.c bonus/include/checker_bonus.h bonus/include/get_next_line_bonus.h
	$(CC) -c $< -Ibonus/include -o $@

%.o: %.c include/push_swap.h
	$(CC) -c $< -Iinclude -o $@

all: $(NAME)

$(NAME): $(OBJ_M)
	$(CC) $(OBJ_M) -o $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(OBJ_B)
	$(CC) $(OBJ_B) -o $(NAME_B)

clean:
	$(RM) $(OBJ_M) $(OBJ_B)

fclean: clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all bonus