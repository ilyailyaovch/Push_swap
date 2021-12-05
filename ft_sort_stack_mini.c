/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_mini.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:40:36 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 18:52:24 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static bool	sort_three_add(t_list *com, int min, int mid)
{
	if (com->a.head->next->value == min && com->a.tail->value == mid)
	{
		if (!(rotate_a(com)))
			return (com);
		return (true);
	}
	else if (com->a.head->value == min && com->a.tail->value == mid)
	{
		if (!(rev_rotate_a(com)))
			return (false);
		if (!(swap_a(com)))
			return (false);
		return (true);
	}
	else if (com->a.head->value == mid && com->a.head->next->value == min)
	{
		if (!(swap_a(com)))
			return (false);
		return (true);
	}
	else
		return (true);
}

static bool	sort_three(t_list *com)
{
	int	min;
	int	mid;

	mid = midpoint_alt(&com->a, com->arr);
	min = find_min(&com->a);
	if (com->a.head->value == mid && com->a.tail->value == min)
	{
		if (!(rev_rotate_a(com)))
			return (false);
		return (true);
	}
	else if (com->a.head->next->value == mid && com->a.tail->value == min)
	{
		if (!(swap_a(com)))
			return (false);
		if (!(rev_rotate_a(com)))
			return (false);
		return (true);
	}
	else
		return (sort_three_add(com, min, mid));
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
