/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_full.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:40:27 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 17:40:30 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	actitons_det(t_list *com, t_node *node, t_act *act)
{
	act->ra = count_ra(node, &com->a);
	act->rra = (com->a.size - act->ra);
	act->rb = count_rb(com, node);
	if (!com->b.head)
		act->rrb = 0;
	else
		act->rrb = (com->b.size - act->rb);
	act->case_a = false;
	act->case_b = false;
	count_actions(act);
}

/* find list of best(actions efficient) moves to move node*/

t_act	determine_best(t_list *com)
{
	t_act	best;
	t_act	temp;
	t_node	*node;
	int		ct;

	node = com->a.head;
	while (node->place == com->a.max || node->place == com->a.pmax
		|| node->place == com->a.ppmax)
		node = node->next;
	actitons_det(com, node, &best);
	node = com->a.head;
	ct = 0;
	while (++ct < com->a.size)
	{
		node = node->next;
		actitons_det(com, node, &temp);
		if (temp.acts < best.acts && node->place != com->a.max && node->place
			!= com->a.pmax && node->place != com->a.ppmax)
			best = temp;
	}
	return (best);
}
