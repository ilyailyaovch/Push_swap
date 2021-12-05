/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_com.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:38:53 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 17:50:46 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	add_command(t_list *all, int command)
{
	t_com	*new;

	new = malloc(sizeof(t_com));
	if (new == NULL)
		return (false);
	new->next = NULL;
	new->command = command;
	if (all->commands.head == NULL)
	{
		all->commands.head = new;
		all->commands.tail = new;
	}
	else
	{
		all->commands.tail->next = new;
		all->commands.tail = new;
	}
	return (true);
}
