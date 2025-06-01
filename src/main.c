/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:40:51 by cbouyer           #+#    #+#             */
/*   Updated: 2025/06/01 19:53:54 by candrabouye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"
#include <unistd.h>

static void	which_sort(t_doublelink *a, t_doublelink *b, int size)
{
	if (size == 2)
		tiny_sort_2(a);
	else if (size == 3)
		tiny_sort_3(a);
	else if (size == 4)
		tiny_sort_4(a, b);
	else if (size == 5)
		tiny_sort_5(a, b);
	else
		merge_sort(a, b);
}

int	main(int argc, char *argv[])
{
	t_doublelink	a;
	t_doublelink	b;
	int				size;

	ft_ini_list(&a);
	ft_ini_list(&b);
	if (check_arg(argc, argv) == -1 || check_dup_arg(argc, argv) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_arg_to_list(argc, argv, &a);
	size = count_stack(&a);
	if (size == 1)
	{
		ft_freelist(&a);
		ft_freelist(&b);
		return (write(1, "Only one number \n", 18));
	}
	else
		which_sort(&a, &b, size);
	ft_freelist(&a);
	ft_freelist(&b);
	return (0);
}
