/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_into_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 03:11:50 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/16 03:39:52 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

int	get_index_bigger_than_num(t_stack *stack, int num)
{
	int	*elems;
	int	counter;
	int	max_index;

	elems = stack->elems;
	counter = 0;
	max_index = get_max_int_index(stack);
	while (counter < stack->length)
	{
		if (elems[counter] < elems[max_index] && elems[counter] > num)
			max_index = counter;
		counter++;
	}
	return (max_index);
}

void	correctly_arrange_for_push_a(t_stack *to, int num)
{
	push_on_top_of_a(to, get_index_bigger_than_num(to, num));	
}

void	push_back_into_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->length > 0)
	{
		correctly_arrange_for_push_a(stack_a, stack_b->elems[0]);
		pa(stack_a, stack_b);
	}
}
