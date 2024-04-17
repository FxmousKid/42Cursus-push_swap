/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_into_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 01:11:13 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/16 03:38:27 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

void	correctly_arrange_for_push_b(t_stack *to, int num)
{
	if (num > get_max_int_value(to) || num < get_min_int_value(to))
		push_on_top_of_b(to, get_max_int_index(to));
	else
		push_on_top_of_b(to, get_index_smaller_than_num(to, num));	
}

void	move_num_from_to(t_stack *from, t_stack *to, int index)
{
	push_on_top_of_a(from, index);
	correctly_arrange_for_push_b(to, from->elems[index]);
	pb(from, to);

}

void	push_all_into_until_3_left(t_stack *stack_a, t_stack *stack_b)
{
	int	*costs;
	int len_a;

	len_a = stack_a->length;
	while (len_a > 3)
	{
		costs = cost_total(stack_a, stack_b);
		move_num_from_to(stack_a, stack_b, get_min_idx(costs, stack_a->length));
		len_a = stack_a->length;
	}
	free(costs);
}
