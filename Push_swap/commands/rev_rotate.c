/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:43:31 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 18:02:11 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	rev_rotate_a(t_list *all)
{
	if (add_command(all, rra) == false)
		return (!error(all));
	if (all->a.head && all->a.tail && all->a.tail->prev)
	{
		all->a.tail->next = all->a.head;
		all->a.head->prev = all->a.tail;
		all->a.head = all->a.tail;
		all->a.tail = all->a.head->prev;
		all->a.tail->next = NULL;
		all->a.head->prev = NULL;
	}
	return (true);
}

bool	rev_rotate_b(t_list *all)
{
	if (add_command(all, rrb) == false)
		return (!error(all));
	if (all->b.head && all->b.tail && all->b.tail->prev)
	{
		all->b.tail->next = all->b.head;
		all->b.head->prev = all->b.tail;
		all->b.head = all->b.tail;
		all->b.tail = all->b.head->prev;
		all->b.tail->next = NULL;
		all->b.head->prev = NULL;
	}
	return (true);
}

bool	rev_rotate_ab(t_list *all)
{
	if (add_command(all, rrr) == false)
		return (!error(all));
	if (all->a.head && all->a.tail && all->a.tail->prev)
	{
		all->a.tail->next = all->a.head;
		all->a.head->prev = all->a.tail;
		all->a.head = all->a.tail;
		all->a.tail = all->a.head->prev;
		all->a.tail->next = NULL;
		all->a.head->prev = NULL;
	}
	if (all->b.head && all->b.tail && all->b.tail->prev)
	{
		all->b.tail->next = all->b.head;
		all->b.head->prev = all->b.tail;
		all->b.head = all->b.tail;
		all->b.tail = all->b.head->prev;
		all->b.tail->next = NULL;
		all->b.head->prev = NULL;
	}
	return (true);
}
