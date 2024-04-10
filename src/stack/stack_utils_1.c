/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 02:42:13 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/10 02:47:49 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common_funcs.h"

char	**parse_stack_input(int argc, char *argv[])
{
	char	**stack_elems;
	char	**tmp;
	int		counter1;
	int		counter2;

	(void) argc;
	stack_elems = ft_split(argv[1], ' ');
	if (stack_elems == NULL)
		return (NULL);
	tmp = stack_elems;
	counter1 = 0;
	counter2 = 0;
	while (tmp[counter1])
	{
		while (tmp[counter1][counter2])
		{
			if (!(ft_isdigit(tmp[counter1][counter2])))
				return (NULL);
			counter2++;
		}
		counter2 = 0;
		counter1++;
	}
	return (stack_elems);
}

void	free_stack_splited_input(char *stack[], int stack_len)
{
	int	counter;

	counter = 0;
	while (counter < stack_len)
	{
		free(stack[counter]);
		counter++;
	}
	free(stack);
}

int	*return_int_stack(int argc, char *argv[])
{
	char	**stack_input;
	int		*int_stack;
	int		*stack_ptr;
	int		counter;

	int_stack = (int *) ft_calloc(sizeof(int *), 500);
	if (int_stack == NULL)
		return (NULL);
	stack_ptr = int_stack;
	stack_input = parse_stack_input(argc, argv);
	if (stack_input == NULL)
	{
		free_stack_splited_input(stack_input, count_words(argv[1], ' '));
		return (NULL);
	}
	counter = -1;
	while (stack_input[++counter])
		stack_ptr[counter] = ft_atoi(stack_input[counter]);
	free_stack_splited_input(stack_input, count_words(argv[1], ' '));
	return (int_stack);
}

int	get_stack_len(int argc, char *argv[])
{
	int		stack_len;
	char	**stack_input;

	stack_input = parse_stack_input(argc, argv);
	if (stack_input == NULL)
		return (-1);
	stack_len = 0;
	while (stack_input[stack_len])
		stack_len++;
	free_stack_splited_input(stack_input, count_words(argv[1], ' '));
	return (stack_len);
}

void	free_stack(t_stack *stack)
{
	free(stack->elems);
	free(stack);
}
