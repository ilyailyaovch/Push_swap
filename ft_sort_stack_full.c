/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_full.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:40:27 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 19:07:18 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	actitons_det(t_list *all, t_node *node, t_act *act)
{
	act->ra = count_ra(node, &all->a);
	act->rra = (all->a.size - act->ra);
	act->rb = count_rb(all, node);
	if (!all->b.head)
		act->rrb = 0;
	else
		act->rrb = (all->b.size - act->rb);
	act->case_a = false;
	act->case_b = false;
	act->case_c = false;
	count_actions(act);
}

/* find list of best(actions efficient) moves to move node*/

t_act	determine_best(t_list *all)
{
	t_act	best;
	t_act	temp;
	t_node	*node;
	int		ct;

	node = all->a.head;
	while (node->place == all->a.max || node->place == all->a.pmax
		|| node->place == all->a.ppmax)
		node = node->next;
	actitons_det(all, node, &best);
	node = all->a.head;
	ct = 0;
	while (++ct < all->a.size)
	{
		node = node->next;
		actitons_det(all, node, &temp);
		if (temp.acts < best.acts && node->place != all->a.max && node->place
			!= all->a.pmax && node->place != all->a.ppmax)
			best = temp;
	}
	return (best);
}
