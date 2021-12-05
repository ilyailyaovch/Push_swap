/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:34:39 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 15:34:39 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef enum e_inst
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}t_inst;

typedef struct s_node
{
	int				value;
	int				place;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

typedef struct s_act
{
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		acts;
	bool	case_a;
	bool	case_b;
	bool	case_c;
}t_act;

typedef struct s_com
{
	char			command;
	struct s_com	*next;
}t_com;

typedef struct s_command
{
	t_com			*head;
	t_com			*tail;
}t_command;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	short			size;
	int				max;
	int				pmax;
	int				ppmax;
	int				min;
}t_stack;

typedef struct s_list
{
	t_stack			a;
	t_stack			b;
	t_command		commands;
	int				len;
	int				max;
	int				*arr;
}t_list;

/*		commands */
bool	add_command(t_list *com, int command);
bool	push_a(t_list *com);
bool	push_b(t_list *com);
bool	swap_a(t_list *com);
bool	swap_b(t_list *com);
bool	swap_ab(t_list *com);
bool	rotate_a(t_list *com);
bool	rotate_b(t_list *com);
bool	rotate_ab(t_list *com);
bool	rev_rotate_a(t_list *com);
bool	rev_rotate_b(t_list *com);
bool	rev_rotate_ab(t_list *com);

/*		fts_arg_check.c */
bool	ft_check_integer(char *s);
bool	ft_check_char(char **argv, int argc);
bool	ft_char_to_arr(char **argv, t_list *com);
bool	ft_check_clones(int *arr, int len);

/*		fts_creation.c */
void	ft_create_workspace(t_list *com, int len);
void	ft_sort_utils(t_list *com);
t_node	*make_node(int val);
bool	make_stack(t_list *com);

/*		fts_outputs.c */
void	print_output(int n);
void	output(t_list *com);
int		error(t_list *com);
void	ft_simplyfy(t_com *node, t_com *temp);

/*		ft_free_memory.c */
int		exit_free(t_list *com);

/*		sort_stack.c */
bool	sort_stack(t_list *com);

/*		ft_sort_stack_mini.c */
bool	ft_mini_sort(t_list *com);

/*		ft_sort_stack_utils.c */
bool	check_sort(t_list *com);
void	find_mid(int *arr, int min, int max, int *mid);
int		find_max(t_stack *n);
int		find_min(t_stack *n);
void	min_max(t_stack *stack, int *min, int *max);

/*		ft_sort_stack_full.c */
void	actitons_det(t_list *com, t_node *node, t_act *act);
t_act	determine_best(t_list *com);

/*		ft_sort_stack_cases.c */
void	case_a(t_list *com, t_act *act);
void	case_b(t_list *com, t_act *act);
void	case_c(t_list *com, t_act *act);

/*		ft_sort_stack_coun.c */
int		count_ra(t_node *target, t_stack *n);
int		count_rb(t_list *com, t_node *node);
void	count_actions(t_act *act);

/* 		fts_utils.c.c */
long	ft_atoi(const char *str);
void	ft_swap(int *a, int *b);

/*	ft_numbering_stack.c */
void	ft_numbering_stack(t_list *all);

/*	ft_quick_sort.c */
void	ft_quick_sort(int *arr, int first, int last);

#endif