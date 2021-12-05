/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:41:21 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 18:50:52 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/* checks if stack A is alltedy sorted  */

bool	check_sort(t_list *com)
{
	int		ct;
	t_node	*temp;

	temp = com->a.head;
	ct = -1;
	while (++ct < com->len)
	{
		if (temp->value != com->arr[ct])
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

static void	min_max(t_stack *n, int len, int *min, int *max)
{
	int		ct;
	t_node	*temp;

	ct = -1;
	temp = n->head;
	*min = temp->value;
	*max = temp->value;
	while (++ct < len)
	{
		if (temp->value < *min)
			*min = temp->value;
		if (temp->value > *max)
			*max = temp->value;
		temp = temp->next;
	}
}

int	midpoint_alt(t_stack *n, int *arr)
{
	int	min;
	int	max;
	int	len;
	int	i;
	int	j;

	len = n->size;
	min_max(n, len, &min, &max);
	i = 0;
	while (arr[i] != min)
		++i;
	j = i;
	while (arr[j] != max)
		++j;
	return (arr[(j - i) / 2 + i]);
}
