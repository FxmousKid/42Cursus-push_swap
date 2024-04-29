/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_no_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:32:51 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/29 13:53:35 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_no_print(t_stacks *stacks)
{
	rotate_a(stacks);
}

void	rb_no_print(t_stacks *stacks)
{
	rotate_b(stacks);
}

void	rr_no_print(t_stacks *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
}
