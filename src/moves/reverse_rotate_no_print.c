/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_no_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:07:25 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/29 13:51:48 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_no_print(t_stacks *stacks)
{
	reverse_rotate_a(stacks);
}

void	rrb_no_print(t_stacks *stacks)
{
	reverse_rotate_b(stacks);
}

void	rrr_no_print(t_stacks *stacks)
{
	reverse_rotate_a(stacks);
	reverse_rotate_b(stacks);
}
