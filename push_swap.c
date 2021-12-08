/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:41:58 by pleoma            #+#    #+#             */
/*   Updated: 2021/12/08 11:39:08 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	all;

	if (argc == 1)
		return (true);
	ft_create_workspace(&all, argc - 1);
	if (ft_check_char(argv, argc) == false)
		return (error(&all));
	if (ft_char_to_arr(argv, &all) == false)
		return (error(&all));
	if (ft_check_clones(all.arr, all.len) == false)
		return (error(&all));
	if (make_stack(&all) == false)
		return (error(&all));
	ft_quick_sort(all.arr, 0, all.len - 1);
	ft_numbering_stack(&all);
	if (sort_stack(&all) == false)
		return (exit_free(&all));
	if (all.commands.head)
		ft_simplyfy(all.commands.head, NULL);
	output(&all);
	return (!(exit_free(&all)));
}
