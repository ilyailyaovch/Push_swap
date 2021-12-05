# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 15:26:48 by pleoma            #+#    #+#              #
#    Updated: 2021/11/15 12:16:50 by pleoma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror

HEADER = includes/push_swap.h
OBJ = $(patsubst %.c, %.o, $(SRC))
SRC =	push_swap.c\
		fts_creation.c\
		fts_arg_check.c\
		fts_outputs.c\
		fts_utils.c\
		ft_numbering_stack.c\
		ft_quick_sort.c\
		ft_free_memory.c\
		ft_sort_stack.c\
		ft_sort_stack_mini.c\
		ft_sort_stack_full.c\
		ft_sort_stack_coun.c\
		ft_sort_stack_cases.c\
		ft_sort_stack_utils.c\
		commands/add_com.c\
		commands/push.c\
		commands/rev_rotate.c\
		commands/rotate.c\
		commands/swap.c
		
.c.o:
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "Compiling $@"

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) -o $@
	@echo "Compiling $@"

clean:
	@rm -f $(OBJ)
	@echo "Removing obj"

fclean: clean
	@rm -f $(NAME)
	@echo "Removing prog"

re: fclean all

.PHONY: all clean fclean re