/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:06:16 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/13 19:20:41 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

int	get_min_depth(t_stack *stack)
{
	int		*elems;
	int		counter;
	t_elem	min;

	elems = stack->elems;
	min = (t_elem){.index = 0, .value = elems[0]};
	counter = 1;
	while (counter < stack->length)
	{
		if (elems[counter] < min.value)
			min = (t_elem){.index = counter, .value = elems[counter]};
		counter++;
	}
	return (min.index);
}

void	push_min_top(t_stack *stack)
{
	int	min_depth;

	min_depth = get_min_depth(stack);
	if (min_depth < stack->length / 2)
	{
		while (min_depth > 0)
		{
			ra(stack);
			min_depth--;
		}
	}
	else
	{
		while (min_depth < stack->length)
		{
			rra(stack);
			min_depth++;
		}
	}
}

void	make_b_sorted(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->length > 0)
	{
		push_min_top(stack_a);
		pb(stack_a, stack_b);
	}
}

void	push_all_from_to(t_stack *from, t_stack *to)
{
	while (from->length > 0)
		pa(to, from);
}
