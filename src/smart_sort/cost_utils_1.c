/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:49:59 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/15 19:17:28 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

int	get_max_int_value(t_stack *stack)
{
	int	*elems;
	int	max;
	int	len;

	len = stack->length;
	elems = stack->elems;
	max = elems[0];
	while (len-- > 0)
	{
		if (elems[len] > max)
			max = elems[len];
	}
	return (max);
}

int	get_max_int_index(t_stack *stack)
{
	int	*elems;
	int	max;
	int	counter;

	elems = stack->elems;
	max = get_max_int_value(stack);
	counter = 0;
	while (counter < stack->length)
	{
		if (elems[counter] == max)
			return (counter);
		counter++;
	}
	return (counter);
}

int	get_min_int_value(t_stack *stack)
{
	int	*elems;
	int	min;
	int	len;

	len = stack->length;
	elems = stack->elems;
	min = elems[0];
	while (len-- > 0)
	{
		if (elems[len] < min)
			min = elems[len];
	}
	return (min);
}

int	get_int_int_index(t_stack *stack)
{
	int	*elems;
	int	min;
	int	counter;

	elems = stack->elems;
	min = get_max_int_value(stack);
	counter = 0;
	while (counter < stack->length)
	{
		if (elems[counter] == min)
			return (counter);
		counter++;
	}
	return (counter);
}
