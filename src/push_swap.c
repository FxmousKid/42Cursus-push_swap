/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:48:22 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/15 16:08:33 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = make_stack_a(argc, argv);
	if (stack_a == NULL)
		return (ft_printf("Invalid arg count / invalid stack\n"), 1);
	stack_b = make_stack_b(stack_a->length);
	if (stack_b == NULL)
		return (free_stack(stack_a), 1);
	stupid_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
