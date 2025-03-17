/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:04:06 by cbouyer           #+#    #+#             */
/*   Updated: 2025/03/09 19:04:08 by cbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"

/*functin allowing me to push a value into the DLL*/
void	push(t_stack *stack, int value)
{
	t_list *new_node;

	new_node = ini_node(value);
	if (!new_node)
		return (NULL);
	if (stack -> top)
	{
		new_node -> next = stack -> top;
		stack -> top -> previous = new_node;
	}
	stack -> top = new_node;
}