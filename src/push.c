/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:04:06 by cbouyer           #+#    #+#             */
/*   Updated: 2025/06/01 19:59:32 by candrabouye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"

static void	push(t_doublelink *dest, t_doublelink *src)
{
	t_list_swap	*node;

	if (!src || !src -> head)
		return ;
	node = src -> head;
	src -> head = node -> next;
	if (src -> head)
		src -> head -> previous = NULL;
	else
		src -> tails = NULL;
	node -> next = dest -> head;
	node -> previous = NULL;
	if (dest -> head)
		dest -> head -> previous = node;
	else
		dest -> tails = node;
	dest -> head = node;
}

void	pa(t_doublelink *a, t_doublelink *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_doublelink *a, t_doublelink *b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
