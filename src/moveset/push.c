/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:50:13 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/14 20:44:15 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common_funcs.h"

int	pop_first_elem(t_stack *stack)
{
	int	first;
	int	counter;
	int	*elems;

	first = stack->elems[0];
	counter = 0;
	elems = stack->elems;
	while (counter < stack->length)
	{
		elems[counter] = elems[counter + 1];
		counter++;
	}
	stack->length--;
	return (first);
}

void	push(t_stack *from, t_stack *to)
{
	int	first_from;
	int	*elems_to;
	int	len_to;

	if (from->length < 1 || to->length > 499)
		return ;
	first_from = pop_first_elem(from);
	elems_to = to->elems;
	len_to = to->length;
	while (len_to > 0)
	{
		elems_to[len_to] = elems_to[len_to - 1];
		len_to--;
	}
	to->elems[0] = first_from;
	to->length++;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
