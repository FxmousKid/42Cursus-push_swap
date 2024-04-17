/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_Total.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:01:47 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/16 01:27:25 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"
#include <limits.h>

int	cost_to_move_on_top(t_stack *stack, int index)
{
	int	len;

	len = stack->length;
	if (index <= len / 2)
		return (index);
	else if (index > len / 2)
		return (len - index);
	return (INT_MAX);
}

void	cost_to_move_in(t_stack *to, int *from, int *costs, int idx)
{
	if (to->length <= 1)
		return ;
	if (from[idx] > get_max_int_value(to) || from[idx] < get_min_int_value(to))
		costs[idx] += cost_to_move_on_top(to, get_max_int_index(to));
	else
		costs[idx] += cost_to_put_in_sorted(to, from[idx]);
}

int	*cost_total(t_stack *stack_a, t_stack *stack_b)
{
	int	*costs;
	int	counter;

	costs = (int *) ft_calloc(stack_a->length, sizeof(int));
	if (costs == NULL)
		return (NULL);
	counter = 0;
	while (counter < stack_a->length)
	{
		costs[counter] += cost_to_move_on_top(stack_a, counter);
		cost_to_move_in(stack_b, stack_a->elems, costs,  counter);
		(void) stack_b;
		counter++;
	}
	return (costs);
}
