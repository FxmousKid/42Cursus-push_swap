/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:32:51 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/10 15:07:35 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common_funcs.h"

void	rotate(t_stack *stack)
{
	int	first;
	int	*elems;
	int	counter;

	elems = stack->elems;
	first = elems[0];
	counter = 0;
	while (counter < stack->length - 1)
	{
		elems[counter] = elems[counter + 1];
		counter++;
	}
	elems[counter] = first;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
