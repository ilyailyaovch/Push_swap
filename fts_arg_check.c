/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_arg_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:20:21 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 18:17:36 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

bool	ft_check_integer(char *line) //
{
	int	c;

	c = 0;
	if (*line == '-')
		++line;
	if (*line == '\0')
		return (false);
	while (*line)
	{
		if (*line < '0' || *line > '9')
			return (false);
		++line;
		++c;
	}
	if (c > 10)
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

bool	ft_char_to_arr(char **argv, t_list *com)
{
	int		c;
	long	num;

	c = -1;
	com->arr = malloc(sizeof(int) * com->len);
	if (com->arr == NULL)
		return (false);
	while (++c < com->len)
	{
		num = ft_atoi(argv[c + 1]);
		if (num > INT_MAX || num < INT_MIN)
			return (false);
		com->arr[c] = num;
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
