/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 02:42:13 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/13 02:37:03 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common_funcs.h"

int	*return_int_stack(int argc, char *argv[])
{
	int		*int_stack;
	int		*stack_ptr;

	if (verify_input(argc, argv) == 0)
		return (NULL);
	int_stack = ft_calloc(sizeof(int *), argc--);
	if (int_stack == NULL)
		return (NULL);
	stack_ptr = int_stack;
	argv++;
	while (argc-- > 0)
		*stack_ptr++ = ft_atoi(*argv++);
	return (int_stack);
}

void	free_stack(t_stack *stack)
{
	free(stack->elems);
	free(stack);
}
