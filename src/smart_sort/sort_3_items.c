/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_items.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:34:19 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/15 16:49:53 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

void	sort_3_numbers(t_stack *stack)
{
	int	*elems;

	if (stack->length != 3)
		return ;
	elems = stack->elems;
	if (elems[0] > elems[1] && elems[1] < elems[2] && elems[0] < elems[2])
		sa(stack);
	else if (elems[0] > elems[1] && elems[1] < elems[2] && elems[0] > elems[2])
		ra(stack);
	else if (elems[0] > elems[1] && elems[1] > elems[2])
	{
		sa(stack);
		rra(stack);
	}
	else if (elems[0] < elems[1] && elems[1] > elems[2] && elems[0] < elems[2])
	{
		rra(stack);
		sa(stack);
	}
	else if (elems[0] < elems[1] && elems[1] > elems[2] && elems[0] > elems[2])
		rra(stack);
}
