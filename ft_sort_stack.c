/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:03:03 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 19:06:52 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	sort_stack_add(t_list *all)
{
	int	rb;

	rb = find_max(&all->b);
	while (all->b.head->place != all->b.max)
	{
		if (rb < (all->b.size - rb))
			rotate_b(all);
		else
			rev_rotate_b(all);
	}
	ft_mini_sort(all);
	while (all->b.head)
		push_a(all);
}

bool	sort_stack(t_list *all)
{
	t_act	act;

	if (check_sort(all))
		return (true);
	if (all->a.size == 2)
		return (swap_a(all));
	if (all->a.size < 6)
		return (ft_mini_sort(all));
	ft_sort_utils(all);
	while (all->a.size > 3)
	{
		act = determine_best(all);
		if (act.case_a)
			case_a(all, &act);
		else if (act.case_b)
			case_b(all, &act);
		else
			case_c(all, &act);
		push_b(all);
	}
	sort_stack_add(all);
	return (true);
}
