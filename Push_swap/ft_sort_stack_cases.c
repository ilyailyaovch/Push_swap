/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_cases.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:39:25 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 17:39:40 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	case_a(t_list *com, t_act *act)
{
	int	ct;
	int	min;

	ct = -1;
	min = (act->ra < act->rb) * act->ra + (act->rb <= act->ra) * act->rb;
	while (++ct < min)
		rotate_ab(com);
	if (act->ra > act->rb)
		while (ct++ < act->ra)
			rotate_a(com);
	else
		while (ct++ < act->rb)
			rotate_b(com);
}

void	case_b(t_list *com, t_act *act)
{
	int	ct;
	int	min;

	ct = -1;
	min = (act->rra < act->rrb) * act->rra + (act->rrb <= act->rra) * act->rrb;
	while (++ct < min)
		rev_rotate_ab(com);
	if (act->rra > act->rrb)
		while (ct++ < act->rra)
			rev_rotate_a(com);
	else
		while (ct++ < act->rrb)
			rev_rotate_b(com);
}

void	case_c(t_list *com, t_act *act)
{
	int	ct;

	ct = -1;
	if (act->ra < act->rra)
		while (++ct < act->ra)
			rotate_a(com);
	else
		while (++ct < act->rra)
			rev_rotate_a(com);
	ct = -1;
	if (act->rb < act->rrb)
		while (++ct < act->rb)
			rotate_b(com);
	else
		while (++ct < act->rrb)
			rev_rotate_b(com);
}
