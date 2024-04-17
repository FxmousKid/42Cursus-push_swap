/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_into_b_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 03:10:31 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/16 03:34:40 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

int	get_index_smaller_than_num(t_stack *stack, int num)
{
	int	*elems;
	int	counter;
	int	min_index;

	elems = stack->elems;
	counter = 0;
	min_index = get_min_depth(stack);
	while (counter < stack->length)
	{
		if (elems[counter] > elems[min_index] && elems[counter] < num)
			min_index = counter;
		counter++;
	}
	return (min_index);
}

void	push_on_top_of_b(t_stack *on, int index)
{
	if (index <= on->length / 2)
	{
		while (index-- > 0)
			rb(on);
	}
	else
	{
		while (index++ < on->length)
			rrb(on);
	}
}


void	push_on_top_of_a(t_stack *on, int index)
{
	if (index <= on->length / 2)
	{
		while (index-- > 0)
			ra(on);
	}
	else
	{
		while (index++ < on->length )
			rra(on);
	}
}
