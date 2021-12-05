/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:03:03 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 18:52:06 by pleoma           ###   ########.fr       */
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

bool	sort_stack(t_list *com)
{
	t_act	act;

	if (check_sort(com))
		return (true);
	if (com->a.size == 2)
		return (swap_a(com));
	if (com->a.size < 6)
		return (ft_mini_sort(com));
	ft_sort_utils(com);
	while (com->a.size > 3)
	{
		act = determine_best(com);
		if (act.case_a)
			case_a(com, &act);
		else if (act.case_b)
			case_b(com, &act);
		else
			case_c(com, &act);
		push_b(com);
	}
	sort_stack_add(com);
	return (true);
}
