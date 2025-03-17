/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:54:46 by cbouyer           #+#    #+#             */
/*   Updated: 2025/03/03 15:54:52 by cbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_SIZE 1000
# include <unistd.h>
# include <stdarg.h>
# include "../libft/include/libft.h"
# include "../printf/include/ft_printf.h"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*previous;
}t_list;

typedef struct s_stack
{
	struct t_node	*top;
}t_stack;

int		error_handling(int argc, char *argv[]);
void	arg_to_list(int argc, char *argv[], int *content);

t_list	*ini_node(int value);
#endif