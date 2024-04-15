/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stupid_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:20:36 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/11 19:22:22 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common_funcs.h"

void	stupid_sort(t_stack *stack_a, t_stack *stack_b)
{
	make_b_sorted(stack_a, stack_b);
	push_all_from_to(stack_b, stack_a);
}
