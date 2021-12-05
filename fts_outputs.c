/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_outputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:33:30 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 18:20:10 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_output(int n)
{
	if (n == sa)
		write(1, "sa\n", 3);
	else if (n == sb)
		write(1, "sb\n", 3);
	else if (n == ss)
		write(1, "ss\n", 3);
	else if (n == pa)
		write(1, "pa\n", 3);
	else if (n == pb)
		write(1, "pb\n", 3);
	else if (n == ra)
		write(1, "ra\n", 3);
	else if (n == rb)
		write(1, "rb\n", 3);
	else if (n == rr)
		write(1, "rr\n", 3);
	else if (n == rra)
		write(1, "rra\n", 4);
	else if (n == rrb)
		write(1, "rrb\n", 4);
	else
		write(1, "rrr\n", 4);
}

void	output(t_list *all)
{
	t_com	*cmd;

	cmd = all->commands.head;
	while (cmd)
	{
		print_output(cmd->command);
		cmd = cmd->next;
	}
}

int	error(t_list *all)
{
	write(2, "Error\n", 6);
	exit_free(all);
	exit(-1);
}

void	ft_simplyfy(t_com *node, t_com *temp)
{
	while (node->next)
	{
		if (node->command == sa && node->next->command == sb)
		{
			temp = node->next;
			node->command = ss;
			node->next = temp->next;
			free(temp);
		}
		else if (node->command == ra && node->next->command == rb)
		{
			temp = node->next;
			node->command = rr;
			node->next = temp->next;
			free(temp);
		}
		else if (node->command == rra && node->next->command == rrb)
		{
			temp = node->next;
			node->command = rrr;
			node->next = temp->next;
			free(temp);
		}
		node = node->next;
	}
}
