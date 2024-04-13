/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:58:33 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/13 17:25:28 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

void	apply_instruction(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(op, "rra", 3) == 0)
		rra_no_print(stack_a);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		rrb_no_print(stack_b);
	else if (ft_strncmp(op, "rrr", 3) == 0)
		rrr_no_print(stack_a, stack_b);
	else if (ft_strncmp(op, "sa", 2) == 0)
		sa_no_print(stack_a);
	else if (ft_strncmp(op, "sb", 2) == 0)
		sb_no_print(stack_b);
	else if (ft_strncmp(op, "ss", 2) == 0)
		ss_no_print(stack_a, stack_b);
	else if (ft_strncmp(op, "pa", 2) == 0)
		pa_no_print(stack_a, stack_b);
	else if (ft_strncmp(op, "pb", 2) == 0)
		pb_no_print(stack_a, stack_b);
	else if (ft_strncmp(op, "ra", 2) == 0)
		ra_no_print(stack_a);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rb_no_print(stack_b);
	else if (ft_strncmp(op, "rr", 2) == 0)
		rr_no_print(stack_a, stack_b);
	else
		ft_putstr_fd("Error\n", 2);
}

int	is_sorted(t_stack *stack)
{
	int	*elems;
	int	counter;

	if (stack->length <= 1)
		return (1);
	elems = stack->elems;
	counter = 1;
	while (counter < stack->length)
	{
		if (elems[counter - 1] > elems[counter])
			return (0);
		counter++;
	}
	return (1);
}

void	checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*op;

	op = get_next_line(0);
	while (op != NULL)
	{
		apply_instruction(op, stack_a, stack_b);
		op = get_next_line(0);
	}
	free(op);
	if (is_sorted(stack_a) && stack_b->length == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = make_stack_a(argc, argv);
	if (stack_a == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack_b = make_stack_b(stack_a->length);
	if (stack_b == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (free_stack(stack_a), 1);
	}
	checker(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
