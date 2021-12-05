/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:43:46 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 18:04:35 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* swaps first and second element of stack A */

bool	swap_a(t_list *all)
{
	if (add_command(all, sa) == false)
		return (!error(all));
	if (!all->a.head || !all->a.head->next)
		return (true);
	ft_swap(&all->a.head->value, &all->a.head->next->value);
	ft_swap(&all->a.head->place, &all->a.head->next->place);
	return (true);
}

/* swaps first and second element of stack B */

bool	swap_b(t_list *all)
{
	if (add_command(all, sb) == false)
		return (!error(all));
	if (!all->b.head || !all->b.head->next)
		return (true);
	ft_swap(&all->b.head->value, &all->b.head->next->value);
	ft_swap(&all->b.head->place, &all->b.head->next->place);
	return (true);
}

/* swaps first and second element of stack A and B */

bool	swap_ab(t_list *all)
{
	if (add_command(all, ss) == false)
		return (!error(all));
	if (all->a.head && all->a.head->next)
	{
		ft_swap(&all->a.head->value, &all->a.head->next->value);
		ft_swap(&all->a.head->place, &all->a.head->next->place);
	}
	if (all->b.head && all->b.head->next)
	{
		ft_swap(&all->b.head->value, &all->b.head->next->value);
		ft_swap(&all->b.head->place, &all->b.head->next->place);
	}
	return (true);
}
