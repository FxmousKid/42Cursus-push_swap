/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:14:53 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/10 02:43:45 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common_funcs.h"

t_stack	*make_stack_b(int len_stack_a)
{
	t_stack	*stack_b;
	int		*stack_elems;

	stack_b = (t_stack *) ft_calloc(sizeof(t_stack), 1);
	if (!stack_b)
		return (NULL);
	stack_elems = (int *) ft_calloc(sizeof(int *), 500);
	if (!stack_elems)
		return (free(stack_b), NULL);
	*stack_b = (t_stack){.elems = stack_elems, .length = len_stack_a};
	return (stack_b);
}
