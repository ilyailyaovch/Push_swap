/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_mini.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:40:36 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 19:28:44 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static bool	sort_three_first_mid(t_list *all, int max)
{
	if (all->a.head->next->value == max)
	{
		if (rev_rotate_a(all) == false)
			return (false);
	}
	else
	{
		if (swap_a(all) == false)
			return (false);
	}
	return (true);
}

static bool	sort_three(t_list *all)
{
	int	min;
	int	max;
	int	mid;

	min_max(&all->a, &min, &max);
	find_mid(all->arr, min, max, &mid);
	if (all->a.head->value == max)
	{
		if (rotate_a(all) == false)
			return (false);
	}
	if (all->a.head->value == mid)
	{
		return (sort_three_first_mid(all, max));
	}
	if (all->a.head->next->value == max)
	{
		if (rev_rotate_a(all) == false)
			return (false);
		if (swap_a(all) == false)
			return (false);
	}
	return (true);
}

static bool	min_to_b(t_list *com, int min)
{
	if (com->a.tail->value == min)
	{
		if (!(rev_rotate_a(com)))
			return (false);
		if (!(push_b(com)))
			return (false);
	}
	else if (com->a.tail->prev->value == min)
	{
		if (!(rev_rotate_a(com)))
			return (false);
		if (!(rev_rotate_a(com)))
			return (false);
		if (!(push_b(com)))
			return (false);
	}
	else
	{
		while (com->a.head->value != min)
			if (!(rotate_a(com)))
				return (false);
		if (!(push_b(com)))
			return (false);
	}
	return (true);
}

bool	ft_mini_sort(t_list *com)
{
	if (com->a.size == 5)
	{
		if (!(min_to_b(com, find_min(&com->a))))
			return (false);
		if (!(min_to_b(com, find_min(&com->a))))
			return (false);
		if (!(sort_three(com)))
			return (false);
		if (!(push_a(com)))
			return (false);
		if (!(push_a(com)))
			return (false);
	}
	else if (com->a.size == 4)
	{
		if (!(min_to_b(com, find_min(&com->a))))
			return (false);
		if (!(sort_three(com)))
			return (false);
		if (!(push_a(com)))
			return (false);
	}
	else if (!(sort_three(com)))
		return (false);
	return (true);
}
