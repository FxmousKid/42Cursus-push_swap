/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_no_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:34:45 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/15 15:23:30 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common_funcs.h"

void	rra_no_print(t_stack *stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb_no_print(t_stack *stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr_no_print(t_stack *stack_a, t_stack *stack_b)
{
	rra_no_print(stack_a);
	rrb_no_print(stack_b);
}
