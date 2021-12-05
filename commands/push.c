/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:43:20 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 18:01:17 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_new_min_max(t_stack *stc)
{
	if (stc->max == -1)
	{
		stc->max = stc->head->place;
		stc->min = stc->head->place;
	}
	if (stc->head->place > stc->max)
		stc->max = stc->head->place;
	else if (stc->head->place < stc->min)
		stc->min = stc->head->place;
}

bool	push_a(t_list *all)
{
	t_node	*temp;

	if (add_command(all, pa) == false)
		return (!error(all));
	if (!all->b.head)
		return (true);
	temp = all->b.head;
	all->b.head = all->b.head->next;
	if (all->b.head)
		all->b.head->prev = NULL;
	if (!all->b.head)
		all->b.tail = all->b.head;
	if (all->b.head && !all->b.head->next)
		all->b.tail = all->b.head;
	temp->next = all->a.head;
	all->a.head = temp;
	(all->a.size)++;
	(all->b.size)--;
	if (!all->a.tail)
		all->a.tail = all->a.head;
	if (all->a.head->next)
		all->a.head->next->prev = temp;
	set_new_min_max(&all->a);
	return (true);
}

bool	push_b(t_list *all)
{
	t_node	*temp;

	if (add_command(all, pb) == false)
		return (!error(all));
	if (!all->a.head)
		return (true);
	temp = all->a.head;
	all->a.head = all->a.head->next;
	if (all->a.head)
		all->a.head->prev = NULL;
	if (!all->a.head)
		all->a.tail = all->a.head;
	if (all->a.head && !all->a.head->next)
		all->a.tail = all->a.head;
	temp->next = all->b.head;
	all->b.head = temp;
	(all->b.size)++;
	(all->a.size)--;
	if (!all->b.tail)
		all->b.tail = all->b.head;
	if (all->b.head->next)
		all->b.head->next->prev = temp;
	set_new_min_max(&all->b);
	return (true);
}
