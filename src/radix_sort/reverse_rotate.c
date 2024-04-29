/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:07:25 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/29 04:51:36 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_a(t_stacks *stacks)
{
	int	last;
	int	*elems;
	int	len;

	if (stacks->a_length < 2)
		return ;
	elems = stacks->a;
	len = stacks->a_length;
	last = elems[len - 1];
	while (len > 0)
	{
		elems[len] = elems[len - 1];
		len--;
	}
	elems[0] = last;
}

static void	reverse_rotate_b(t_stacks *stacks)
{
	int	last;
	int	*elems;
	int	len;

	if (stacks->b_length < 2)
		return ;
	elems = stacks->b;
	len = stacks->b_length;
	last = elems[len - 1];
	while (len > 0)
	{
		elems[len] = elems[len - 1];
		len--;
	}
	elems[0] = last;
}

void	rra(t_stacks *stacks)
{
	reverse_rotate_a(stacks);
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	reverse_rotate_b(stacks);
	ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks)
{
	reverse_rotate_a(stacks);
	reverse_rotate_b(stacks);
	ft_printf("rrr\n");
}
