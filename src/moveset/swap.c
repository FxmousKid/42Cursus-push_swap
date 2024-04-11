/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:20:20 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/11 15:09:26 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common_funcs.h"

void	swap(t_stack *stack)
{
	int	tmp;
	int	*elems;

	if (stack->length < 2)
		return ;
	elems = stack->elems;
	tmp = elems[0];
	elems[0] = elems[1];
	elems[1] = tmp;
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
