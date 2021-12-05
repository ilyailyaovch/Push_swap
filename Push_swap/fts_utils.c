/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:30:12 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 17:43:07 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

long	ft_atoi(const char *str)
{
	int		ct;
	int		val;
	long	ret;

	val = 1;
	ct = 0;
	ret = 0;
	if (str[ct] == '-')
	{
		ct++;
		val = -1;
	}
	else if (str[ct] == '+')
		ct++;
	while (str[ct] > 47 && str[ct] < 58)
	{
		ret = ret * 10 + str[ct] - '0';
		ct++;
	}
	return (ret * val);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
