/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:34:08 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 17:51:44 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	free_stack(t_list *com)
{
	t_node	*temp;

	if (com->a.head)
	{
		temp = com->a.head;
		while (temp)
		{
			com->a.head = com->a.head->next;
			free(temp);
			temp = com->a.head;
		}
	}
	if (com->b.head)
	{
		temp = com->b.head;
		while (temp)
		{
			com->b.head = com->b.head->next;
			free(temp);
			temp = com->b.head;
		}
	}
}

int	exit_free(t_list *com)
{
	t_com	*temp;

	if (com->arr)
		free(com->arr);
	free_stack(com);
	if (com->commands.head)
	{
		temp = com->commands.head;
		while (temp)
		{
			com->commands.head = com->commands.head->next;
			free(temp);
			temp = com->commands.head;
		}
	}
	return (-1);
}
