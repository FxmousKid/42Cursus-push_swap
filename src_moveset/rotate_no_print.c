/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_no_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:39:06 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/13 03:11:11 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common_funcs.h"

void	ra_no_print(t_stack *stack_a)
{
	rotate(stack_a);
}

void	rb_no_print(t_stack *stack_b)
{
	rotate(stack_b);
}

void	rr_no_print(t_stack *stack_a, t_stack *stack_b)
{
	ra_no_print(stack_a);
	rb_no_print(stack_b);
}
