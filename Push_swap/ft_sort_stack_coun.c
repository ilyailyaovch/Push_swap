/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_coun.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:39:48 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 19:06:40 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/* find place of target from the top*/

int	count_ra(t_node *target, t_stack *n)
{
	t_node	*node;
	int		ct;

	node = n->head;
	ct = 0;
	while (node != target)
	{
		++ct;
		node = node->next;
	}
	return (ct);
}

/* addition fun for count_rb(finds place of max in B stack*/

static int	count_rb_add(t_list *all)
{
	int		rb;
	t_node	*temp;

	rb = 0;
	temp = all->b.head;
	while (temp->place != all->b.max)
	{
		++rb;
		temp = temp->next;
	}
	return (rb);
}

/* finds number of rev b to place node in valid place*/

int	count_rb(t_list *all, t_node *node)
{
	int		ct;
	int		rb;
	int		max;
	t_node	*temp;

	temp = all->b.head;
	if (!temp)
		return (0);
	rb = -1;
	ct = 0;
	max = all->max;
	while (temp)
	{
		++ct;
		if (temp->place > node->place && temp->place <= max)
		{
			max = temp->place;
			rb = ct;
		}
		temp = temp->next;
	}
	if (rb == -1)
		return (count_rb_add(all));
	else
		return (rb % all->b.size);
}

/* determin best case after comparing actions*/

void	count_actions(t_act *act)
{
	int	a;
	int	b;
	int	c;

	a = ((act->ra < act->rra) * act->ra + (act->rra <= act->ra) * act->rra)
		+ ((act->rb < act->rrb) * act->rb + (act->rrb <= act->rb) * act->rrb);
	b = (act->ra > act->rb) * act->ra + (act->rb >= act->ra) * act->rb;
	c = (act->rra > act->rrb) * act->rra + (act->rrb >= act->rra) * act->rrb;
	act->acts = (a < c) * a + (c <= a) * c;
	act->acts = (act->acts < b) * act->acts + (b <= act->acts) * b;
	if (act->acts == b)
		act->case_a = true;
	else if (act->acts == c)
		act->case_b = true;
	else
		act->case_c = true;
}
