/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:01:32 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/13 19:18:32 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

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

int	verify_number(char *input)
{
	int	minus_flag;

	minus_flag = 0;
	while (input && *input)
	{
		if (!ft_isdigit(*input) && *input != ' ' && *input != '-')
			return (0);
		if (*input == '-' && minus_flag == 0)
			minus_flag = 1;
		else if (*input == '-' && minus_flag == 1)
			return (0);
		input++;
	}
	return (1);
}

int	verify_input(int argc, char *argv[])
{
	int	counter;

	counter = 1;
	while (counter < argc)
	{
		if (verify_number(argv[counter]) == 0)
			return (0);
		counter++;
	}
	return (1);
}

int	verify_dups_in_input(t_stack *stack)
{
	int	*elems;
	int	counter1;
	int	counter2;

	elems = stack->elems;
	counter1 = 0;
	while (counter1 < stack->length)
	{
		counter2 = counter1 + 1;
		while (counter2 < stack->length)
		{
			if (elems[counter1] == elems[counter2])
				return (0);
			counter2++;
		}
		counter1++;
	}
	return (1);
}

int	is_stack_empty(t_stack *stack)
{
	return (stack->length == 0);
}
