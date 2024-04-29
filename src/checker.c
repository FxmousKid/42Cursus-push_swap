/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:58:33 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/29 13:54:59 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	apply_instruction(char *op, t_stacks *stacks)
{
	if (ft_strncmp(op, "rra", 3) == 0)
		rra_no_print(stacks);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		rrb_no_print(stacks);
	else if (ft_strncmp(op, "rrr", 3) == 0)
		rrr_no_print(stacks);
	else if (ft_strncmp(op, "sa", 2) == 0)
		sa_no_print(stacks);
	else if (ft_strncmp(op, "sb", 2) == 0)
		sb_no_print(stacks);
	else if (ft_strncmp(op, "ss", 2) == 0)
		ss_no_print(stacks);
	else if (ft_strncmp(op, "pa", 2) == 0)
		pa_no_print(stacks);
	else if (ft_strncmp(op, "pb", 2) == 0)
		pb_no_print(stacks);
	else if (ft_strncmp(op, "ra", 2) == 0)
		ra_no_print(stacks);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rb_no_print(stacks);
	else if (ft_strncmp(op, "rr", 2) == 0)
		rr_no_print(stacks);
	else
		ft_putstr_fd("Error\n", 2);
}

void	checker(t_stacks *stacks)
{
	char	*op;

	op = get_next_line(0);
	while (op != NULL)
	{
		apply_instruction(op, stacks);
		op = get_next_line(0);
	}
	free(op);
	if (is_a_sorted(stacks) && stacks->b_length == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	validate_arguments(argc, argv);
	stacks = (t_stacks *) malloc(sizeof (t_stacks));
	if (stacks == NULL)
		exit(1);
	initialize_stacks(argc, argv, stacks);
	join_args(argc, argv, stacks);
	parse_numbers(stacks);
	exit_if_duplicate_in_a(stacks);
	checker(stacks);
	free_stacks(stacks);
	return (0);
}
