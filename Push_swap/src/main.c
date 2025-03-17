/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:40:51 by cbouyer           #+#    #+#             */
/*   Updated: 2025/03/03 15:40:54 by cbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"

/*Main function, creates the stack
takes into account the utils and push_swap functions
obj: program that sorts a stack of int in ascending order
using two different stacks and different operations*/

/* main allowing me to print the results of arg to list
use of ft_bzero in order to initialize all values of the list a to 0
arg to list works and we should take into account what was done in main
check for int limit for argument parsing
 */
int	main(int argc, char *argv[])
{
	int	a[MAX_SIZE];
	int	b[MAX_SIZE];

	ft_bzero(a, MAX_SIZE);
	ft_bzero(b, MAX_SIZE);
	if (argc < 2)
		return (-1);
	arg_to_list(argc, argv, a);
}
