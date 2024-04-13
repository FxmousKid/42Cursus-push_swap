/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_no_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:31:46 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/13 02:26:00 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

void	pa_no_print(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
}

void	pb_no_print(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
}
