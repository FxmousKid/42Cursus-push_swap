/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_no_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:41:07 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/13 18:50:46 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

void	sa_no_print(t_stack *stack_a)
{
	swap(stack_a);
}

void	sb_no_print(t_stack *stack_b)
{
	swap(stack_b);
}

void	ss_no_print(t_stack *stack_a, t_stack *stack_b)
{
	sa_no_print(stack_a);
	sb_no_print(stack_b);
}
