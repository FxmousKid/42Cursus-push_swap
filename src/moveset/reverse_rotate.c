/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:07:25 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/11 15:10:30 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common_funcs.h"

void	reverse_rotate(t_stack *stack)
{
	int	last;
	int	*elems;
	int	len;

	if (stack->length < 2)
		return ;
	elems = stack->elems;
	len = stack->length;
	last = elems[len - 1];
	while (len > 0)
	{
		elems[len] = elems[len - 1];
		len--;
	}
	elems[0] = last;
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
