/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_arg_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:20:21 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/08 11:24:38 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

bool	ft_check_integer(char *s)
{
	int	coun;
	int	len;

	len = 0;
	coun = 0;
	if (s[coun] == '-')
		coun++;
	if (s[coun] == '\0')
		return (false);
	while (s[coun])
	{
		if (s[coun] < '0' || s[coun] > '9')
			return (false);
		coun++;
		len++;
	}
	if (len > 10)
		return (false);
	return (true);
}

bool	ft_check_char(char **argv, int argc)
{
	int	c;

	c = 0;
	while (++c < argc)
	{
		if (!(ft_check_integer(argv[c])))
			return (false);
	}
	return (true);
}

bool	ft_char_to_arr(char **argv, t_list *all)
{
	int		c;
	long	num;

	c = -1;
	all->arr = malloc(sizeof(int) * all->len);
	if (all->arr == NULL)
		return (false);
	while (++c < all->len)
	{
		num = ft_atoi(argv[c + 1]);
		if (num > INT_MAX || num < INT_MIN)
			return (false);
		all->arr[c] = num;
	}
	return (true);
}

bool	ft_check_clones(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
