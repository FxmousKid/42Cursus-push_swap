/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:33:21 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/16 03:38:30 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

void	smart_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->length <= 1)
		return ;
	if (stack_a->length == 2)
	{
		if (stack_a->elems[0] > stack_a->elems[1])
			sa(stack_a);
		return ;
	}
	if (stack_a->length == 3)
		return (sort_3_numbers(stack_a));
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	push_all_into_until_3_left(stack_a, stack_b);
	sort_3_numbers(stack_a);
	push_back_into_a(stack_a, stack_b);
	check_a_is_sorted(stack_a);
}
