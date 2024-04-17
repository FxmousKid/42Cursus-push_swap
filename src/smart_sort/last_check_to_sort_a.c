/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_check_to_sort_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 03:31:52 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/16 03:35:04 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

void	check_a_is_sorted(t_stack *stack_a)
{
	int	*elems;
	int	min_a;

	elems = stack_a->elems;
	min_a = get_min_int_value(stack_a);
	while (elems[0] != min_a)
		ra(stack_a);
}
