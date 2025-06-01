/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:54:46 by cbouyer           #+#    #+#             */
/*   Updated: 2025/06/01 20:09:40 by candrabouye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/include/libft.h"
# include "../printf/include/ft_printf.h"

//Defines the list structure
typedef struct s_listswap
{
	int					data;
	int					index;
	struct s_listswap	*next;
	struct s_listswap	*previous;
}	t_list_swap;

//defines the doubly linked structure
typedef struct s_doublelink
{
	struct s_listswap	*head;
	struct s_listswap	*tails;
}	t_doublelink;

int			check_dup_arg(int argc, char *argv[]);
void		ft_freelist(t_doublelink *list);
int			count_stack(t_doublelink *a);
int			check_arg(int argc, char *argv[]);
int			is_valid_num(char *str);
void		assign_index(t_doublelink *list);
int			find_next_index_pos(t_doublelink *stack, int limit);
void		rotate_to_top(t_doublelink *stack, int pos);
void		push_back_to_a(t_doublelink *a, t_doublelink *b);
int			handle_split(char **split, int *num, int *k);

t_list_swap	*ini_node(int value);
void		ft_ini_list(t_doublelink *list);
int			ft_isempty(t_doublelink *list);
void		ft_insert_end(t_doublelink *list, int value);
void		ft_arg_to_list(int argc, char *argv[], t_doublelink *list);
int			find_min_index(t_doublelink *stack);
int			find_max_index(t_doublelink *b);
void		push_min_b(t_doublelink *a, t_doublelink *b);
void		push_max_b(t_doublelink *a, t_doublelink *b);
int			get_position(t_doublelink *list, int index);
void		ft_free_split(char **split);

void		pa(t_doublelink *a, t_doublelink *b);
void		pb(t_doublelink *b, t_doublelink *a);

void		rra(t_doublelink *a);
void		rrb(t_doublelink *b);
void		rrr(t_doublelink *a, t_doublelink *b);

void		ra(t_doublelink *a);
void		rb(t_doublelink *b);
void		rr(t_doublelink *a, t_doublelink *b);

void		sa(t_doublelink *a);
void		sb(t_doublelink *b);
void		ss(t_doublelink *a, t_doublelink *b);

void		ft_freelist(t_doublelink *list);
int			count_stack(t_doublelink *a);
void		tiny_sort_3(t_doublelink *a);
void		tiny_sort_2(t_doublelink *a);
void		tiny_sort_5(t_doublelink *a, t_doublelink *b);
void		tiny_sort_4(t_doublelink *a, t_doublelink *b);
void		merge_sort(t_doublelink *a, t_doublelink *b);

#endif