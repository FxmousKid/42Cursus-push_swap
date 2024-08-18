/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:32:51 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/18 02:58:39 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stacks)
{
	long	first;
	long	*elems;
	int		counter;

	if (stacks->a_length < 2)
		return ;
	elems = stacks->a;
	first = elems[0];
	counter = 0;
	while (counter < stacks->a_length - 1)
	{
		elems[counter] = elems[counter + 1];
		counter++;
	}
	elems[stacks->a_length - 1] = first;
}

void	rotate_b(t_stacks *stacks)
{
	long	first;
	long	*elems;
	int		counter;

	if (stacks->b_length < 2)
		return ;
	elems = stacks->b;
	first = elems[0];
	counter = 0;
	while (counter < stacks->b_length - 1)
	{
		elems[counter] = elems[counter + 1];
		counter++;
	}
	elems[stacks->b_length - 1] = first;
}

void	ra(t_stacks *stacks)
{
	rotate_a(stacks);
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	rotate_b(stacks);
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
	ft_printf("rr\n");
}
