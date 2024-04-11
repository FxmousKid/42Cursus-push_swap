/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:01:32 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/11 15:54:26 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common_funcs.h"

void	display_stack(t_stack *stack)
{
	int	len;
	int	*elems;

	len = stack->length;
	elems = stack->elems;
	while (len--)
		ft_printf("| %d |\n", *elems++);
	ft_printf("____\n");
}

void	free_stack(t_stack *stack)
{
	free(stack->elems);
	free(stack);
}

int	verify_input(char *input)
{
	while (input && *input)
	{
		if (!ft_isdigit(*input) && *input != ' ')
			return (0);
		input++;
	}
	return (1);
}
