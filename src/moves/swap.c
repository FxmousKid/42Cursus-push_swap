/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:20:20 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/18 02:59:09 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	long	tmp;
	long	*elems;

	if (stacks->a_length < 2)
		return ;
	elems = stacks->a;
	tmp = elems[0];
	elems[0] = elems[1];
	elems[1] = tmp;
}

void	swap_b(t_stacks *stacks)
{
	long	tmp;
	long	*elems;

	if (stacks->b_length < 2)
		return ;
	elems = stacks->b;
	tmp = elems[0];
	elems[0] = elems[1];
	elems[1] = tmp;
}

void	sa(t_stacks *stacks)
{
	swap_a(stacks);
	ft_printf("sa\n");
}

void	sb(t_stacks *stacks)
{
	swap_b(stacks);
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
	ft_printf("ss\n");
}
