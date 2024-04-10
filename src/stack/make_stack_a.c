/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:13:36 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/10 02:47:12 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common_funcs.h"

t_stack	*make_stack_a(int argc, char *argv[])
{
	int		*stack_a_elems;
	t_stack	*stack_a;
	int		*int_stack;

	if (argc < 2 || argc > 2)
		return (NULL);
	int_stack = return_int_stack(argc, argv);
	if (int_stack == NULL)
		return (NULL);
	stack_a = (t_stack *) ft_calloc(sizeof(t_stack), 1);
	if (stack_a == NULL)
		return (free(int_stack), NULL);
	stack_a_elems = (int *) ft_calloc(sizeof(int *), 500);
	if (stack_a_elems == NULL)
		return (free(stack_a), free(int_stack), NULL);
	*stack_a = (t_stack){stack_a_elems, 0};
	ft_memcpy(stack_a->elems, int_stack, 500);
	stack_a->length = get_stack_len(argc, argv);
	if (stack_a->length == -1)
		return (free(stack_a), free(int_stack), NULL);
	free(int_stack);
	return (stack_a);
}
