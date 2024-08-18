/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_no_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:50:13 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/18 02:55:34 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pop_first_elem_a(t_stacks *stacks)
{
	long	first;
	long	counter;
	long	*elems;

	first = stacks->a[0];
	counter = 0;
	elems = stacks->a;
	while (counter < stacks->a_length)
	{
		elems[counter] = elems[counter + 1];
		counter++;
	}
	stacks->a_length--;
	return (first);
}

static int	pop_first_elem_b(t_stacks *stacks)
{
	long	first;
	long	counter;
	long	*elems;

	first = stacks->b[0];
	counter = 0;
	elems = stacks->b;
	while (counter < stacks->b_length)
	{
		elems[counter] = elems[counter + 1];
		counter++;
	}
	stacks->b_length--;
	return (first);
}

void	pa_no_print(t_stacks *stacks)
{
	long	first_from;
	long	*elems_to;
	int		len_to;

	if (stacks->b_length < 1)
		return ;
	first_from = pop_first_elem_b(stacks);
	elems_to = stacks->a;
	len_to = stacks->a_length;
	while (len_to > 0)
	{
		elems_to[len_to] = elems_to[len_to - 1];
		len_to--;
	}
	stacks->a[0] = first_from;
	stacks->a_length++;
}

void	pb_no_print(t_stacks *stacks)
{
	long	first_from;
	long	*elems_to;
	int		len_to;

	if (stacks->a_length < 1)
		return ;
	first_from = pop_first_elem_a(stacks);
	elems_to = stacks->b;
	len_to = stacks->b_length;
	while (len_to > 0)
	{
		elems_to[len_to] = elems_to[len_to - 1];
		len_to--;
	}
	stacks->b[0] = first_from;
	stacks->b_length++;
}
