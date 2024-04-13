/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:32:51 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/13 00:40:49 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

void	rotate(t_stack *stack)
{
	int	first;
	int	*elems;
	int	counter;

	if (stack->length < 2)
		return ;
	elems = stack->elems;
	first = elems[0];
	counter = 0;
	while (counter < stack->length - 1)
	{
		elems[counter] = elems[counter + 1];
		counter++;
	}
	elems[stack->length - 1] = first;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
