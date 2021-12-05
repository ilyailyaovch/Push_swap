/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:43:41 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 18:00:35 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	rotate_a(t_list *all)
{
	if (!(add_command(all, ra)))
		return (!error(all));
	if (all->a.head && all->a.tail && all->a.head->next)
	{
		all->a.tail->next = all->a.head;
		all->a.head->prev = all->a.tail;
		all->a.head = all->a.head->next;
		all->a.tail = all->a.tail->next;
		all->a.head->prev = NULL;
		all->a.tail->next = NULL;
	}
	return (true);
}

bool	rotate_b(t_list *all)
{
	if (!(add_command(all, rb)))
		return (!error(all));
	if (all->b.head && all->b.tail && all->b.head->next)
	{
		all->b.tail->next = all->b.head;
		all->b.head->prev = all->b.tail;
		all->b.head = all->b.head->next;
		all->b.tail = all->b.tail->next;
		all->b.head->prev = NULL;
		all->b.tail->next = NULL;
	}
	return (true);
}

bool	rotate_ab(t_list *all)
{
	if (add_command(all, rr) == false)
		return (!error(all));
	if (all->a.head && all->a.tail && all->a.head->next)
	{
		all->a.tail->next = all->a.head;
		all->a.head->prev = all->a.tail;
		all->a.head = all->a.head->next;
		all->a.tail = all->a.tail->next;
		all->a.head->prev = NULL;
		all->a.tail->next = NULL;
	}
	if (all->b.head && all->b.tail && all->b.head->next)
	{
		all->b.tail->next = all->b.head;
		all->b.head->prev = all->b.tail;
		all->b.head = all->b.head->next;
		all->b.tail = all->b.tail->next;
		all->b.head->prev = NULL;
		all->b.tail->next = NULL;
	}
	return (true);
}
