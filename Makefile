MSRC = push_swap.c ft_stack.c ft_inputs.c ft_split.c ft_clear.c s_sort.c s_circo.c ft_atoi.c ft_strlen.c s_get_it.c s_sinfo1.c s_sinfo2.c	\
		op_swap.c  op_push.c s_rotate_it.c op_reverse_rotate.c op_rotate.c

BSRC = checker_bonus.c ch_ft_stack_bonus.c ch_ft_inputs_bonus.c ch_ft_split_bonus.c ch_ft_clear_bonus.c ch_circo_bonus.c ch_utils_bonus.c	\
		ch_op_swap_bonus.c ch_op_push_bonus.c ch_op_rotate_bonus.c ch_op_reverse_rotate_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c

MOBJ =	$(MSRC:.c=.o)

BOBJ =	$(BSRC:.c=.o)

NAME =	push_swap

BNAME =	checker

CC =	cc -Wall -Wextra -Werror

RM =	rm -f

%.o: %.c push_swap.h
	$(CC) -c $< -o $@

%_bonus.o: %_bonus.c checker_bonus.h get_next_line_bonus.h
	$(CC) -c $< -o $@

$(NAME): $(MOBJ)
	$(CC) $(MOBJ) -o $(NAME)

$(BNAME): $(BOBJ)
	$(CC) $(BOBJ) -o $(BNAME)

all: $(NAME)

bonus: $(BNAME)

clean:
	$(RM) $(MOBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean all bonus
