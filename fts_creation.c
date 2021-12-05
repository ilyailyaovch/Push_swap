/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:42:29 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 18:15:53 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/* inits'&'shieet */

void	ft_create_workspace(t_list *all, int len)
{
	all->len = len;
	all->arr = NULL;
	all->a.size = 0;
	all->a.head = NULL;
	all->a.tail = NULL;
	all->b.size = 0;
	all->b.head = NULL;
	all->b.tail = NULL;
	all->commands.head = NULL;
}

void	ft_sort_utils(t_list *all)
{
	all->max = all->a.size;
	all->a.max = all->a.size;
	all->a.pmax = all->a.size - 1;
	all->a.ppmax = all->a.size - 2;
	all->a.min = 1;
	all->b.max = -1;
	all->b.min = -1;
}

t_node	*make_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	return (node);
}

bool	make_stack(t_list *all)
{
	int		c;
	t_node	*newnode;

	c = 0;
	while (c < all->len)
	{
		newnode = make_node(all->arr[c]);
		if (newnode == NULL)
			return (false);
		if (all->a.head == NULL)
		{
			all->a.head = newnode;
			all->a.tail = newnode;
		}
		else
		{
			all->a.tail->next = newnode;
			newnode->prev = all->a.tail;
			all->a.tail = newnode;
		}
		c++;
		(all->a.size)++;
	}
	return (true);
}
