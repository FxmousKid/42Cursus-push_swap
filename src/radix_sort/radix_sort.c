/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:34:05 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/25 16:09:53 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stacks *stacks)
{
	int	*elems;

	if (stacks->a_length != 3)
		return ;
	elems = stacks->a;
	if (elems[0] > elems[1] && elems[1] < elems[2] && elems[0] < elems[2])
		sa(stacks);
	else if (elems[0] > elems[1] && elems[1] < elems[2] && elems[0] > elems[2])
		ra(stacks);
	else if (elems[0] > elems[1] && elems[1] > elems[2])
	{
		sa(stacks);
		rra(stacks);
	}
	else if (elems[0] < elems[1] && elems[1] > elems[2] && elems[0] < elems[2])
	{
		rra(stacks);
		sa(stacks);
	}
	else if (elems[0] < elems[1] && elems[1] > elems[2] && elems[0] > elems[2])
		rra(stacks);
}

void	sort_4_5(t_stacks *stacks)
{
	while (stacks->b_length <= 1)
	{
		if (stacks->a[0] == 0 || stacks->a[0] == 1)
			pb(stacks);
		else
			ra(stacks);
	}
	if (stacks->b[0] == 0)
		sb(stacks);
	if (stacks->a[2] != 4)
	{
		if (stacks->a[0] == 4)
			ra(stacks);
		else
			rra(stacks);
	}
	if (stacks->a[0] > stacks->a[1])
		sa(stacks);
	pa(stacks);
	pa(stacks);
}

int	is_a_sorted(t_stacks *stacks)
{
	int	idx;
	int	*array;
	int	length;

	idx = 0;
	array = stacks->a;
	length = stacks->a_length;
	while (idx < length - 1)
	{
		if (array[idx] > array[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}

void	radix_sort_on_b(t_stacks *stacks, int b_length, int bit_size, int idx)
{
	while (b_length-- && idx <= bit_size && is_a_sorted(stacks) == 0)
	{
		if (((stacks->b[0] >> idx) & 1) == 0)
			rb(stacks);
		else
			pa(stacks);
	}
	if (is_a_sorted(stacks))
		while (stacks->b_length != 0)
			pa(stacks);
}

void	radix_sort(t_stacks *stacks)
{
	int	idx;
	int	bit_size;
	int	a_length;

	bit_size = 0;
	a_length = stacks->a_length;
	while (a_length > 1 && ++bit_size)
		a_length >>= 1;
	idx = -1;
	while (++idx <= bit_size)
	{
		a_length = stacks->a_length;
		while (a_length-- && is_a_sorted(stacks) == 0)
		{
			if (((stacks->a[0] >> idx) & 1) == 0)
				pb(stacks);
			else
				ra(stacks);
		}
		radix_sort_on_b(stacks, stacks->b_length, bit_size, idx + 1);
	}
	while (stacks->b_length != 0)
		pa(stacks);
}
