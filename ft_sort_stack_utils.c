/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:41:21 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 19:18:40 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

bool	check_sort(t_list *all)
{
	int		ct;
	t_node	*temp;

	temp = all->a.head;
	ct = -1;
	while (++ct < all->len)
	{
		if (temp->value != all->arr[ct])
			return (false);
		temp = temp->next;
	}
	return (true);
}

int	find_min(t_stack *n)
{
	t_node	*temp;
	int		ret;

	temp = n->head;
	ret = temp->value;
	while (temp)
	{
		if (temp->value < ret)
			ret = temp->value;
		temp = temp->next;
	}
	return (ret);
}

int	find_max(t_stack *n)
{
	int		ct;
	t_node	*temp;

	ct = 0;
	temp = n->head;
	while (temp->place != n->max)
	{
		++ct;
		temp = temp->next;
	}
	return (ct);
}

void	min_max(t_stack *stack, int *min, int *max)
{
	t_node	*node;

	node = stack->head;
	*min = node->value;
	*max = node->value;
	while (node)
	{
		if (node->value < *min)
			*min = node->value;
		if (node->value > *max)
			*max = node->value;
		node = node->next;
	}
}

void	find_mid(int *arr, int min, int max, int *mid)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != min)
		i++;
	j = i;
	while (arr[j] != max)
		j++;
	*mid = arr[(j - i) / 2 + i];
}
