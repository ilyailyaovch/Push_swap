/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbering_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:29:54 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 17:34:30 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_numbering_stack(t_list *all)
{
	t_node	*node;
	int		i;

	node = all->a.head;
	while (node)
	{
		i = 0;
		while (node->value != all->arr[i])
			i++;
		node->place = i + 1;
		node = node->next;
	}
}
