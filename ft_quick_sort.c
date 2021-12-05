/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:27:30 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/05 18:22:57 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_quick_sort(int *arr, int first, int last)
{
	int			lef_b;
	int			rig_b;
	int			pivot;

	if (first < last)
	{
		lef_b = first;
		rig_b = last;
		pivot = arr[(lef_b + rig_b) / 2];
		while (lef_b <= rig_b)
		{
			while (arr[lef_b] < pivot)
				lef_b++;
			while (arr[rig_b] > pivot)
				rig_b--;
			if (lef_b <= rig_b)
			{
				ft_swap(&arr[lef_b], &arr[rig_b]);
				lef_b++;
				rig_b--;
			}
		}
		ft_quick_sort(arr, first, rig_b);
		ft_quick_sort(arr, lef_b, last);
	}
}
