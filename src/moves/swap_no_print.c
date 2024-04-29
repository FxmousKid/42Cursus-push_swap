/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_no_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:20:20 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/29 13:54:04 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_no_print(t_stacks *stacks)
{
	swap_a(stacks);
}

void	sb_no_print(t_stacks *stacks)
{
	swap_b(stacks);
}

void	ss_no_print(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}
