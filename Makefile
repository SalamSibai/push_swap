NAME	=	push_swap

BONUS_NAME = checker

FILES	=	main.c \
			parsing_utils/ft_get_charlist.c \
			parsing_utils/ft_join.c \
			parsing_utils/ft_split.c \
			parsing_utils/ps_libft.c \
			parsing_utils/sort_check.c \
			parsing_utils/argument_parsing.c \
			ft_stack/ft_destroy.c \
			ft_stack/ft_init_stack.c \
			ft_stack/ft_is_empty.c \
			ft_stack/ft_pop.c \
			ft_stack/ft_push.c \
			ft_stack/ft_stack_utils.c \
			push_swap.c \
			swap_push_operations.c rotate_operations.c  \
			ps_sort.c ps_mt.c ps_mt_utils.c ps_same_index.c ps_different_index.c\
			ps_different_index_utils.c weight_calculator.c \

BONUS_FILES	=	bonus/ps_checker.c \
				bonus/ps_checker_utils.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				parsing_utils/ft_get_charlist.c \
				parsing_utils/ft_join.c \
				parsing_utils/ft_split.c \
				parsing_utils/ps_libft.c \
				parsing_utils/sort_check.c \
				parsing_utils/argument_parsing.c \
				ft_stack/ft_destroy.c \
				ft_stack/ft_init_stack.c \
				ft_stack/ft_is_empty.c \
				ft_stack/ft_pop.c \
				ft_stack/ft_push.c \
				ft_stack/ft_stack_utils.c \
				push_swap.c \
				swap_push_operations.c rotate_operations.c  \
				ps_sort.c ps_mt.c ps_mt_utils.c ps_same_index.c ps_different_index.c\
				ps_different_index_utils.c weight_calculator.c \

OBJS	= $(FILES:.c=.o)

BONUS_OBJS =	$(BONUS_FILES:.c=.o)

CFLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):		$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

bonus:	$(BONUS_OBJS)
		$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re