/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:58:33 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/19 14:56:00 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	apply_instruction(char *op, t_stacks *stacks)
{
	if (ft_strncmp(op, "rra\n", 4) == 0 && ft_strlen(op) == 4)
		rra_no_print(stacks);
	else if (ft_strncmp(op, "rrb\n", 4) == 0 && ft_strlen(op) == 4)
		rrb_no_print(stacks);
	else if (ft_strncmp(op, "rrr\n", 4) == 0 && ft_strlen(op) == 4)
		rrr_no_print(stacks);
	else if (ft_strncmp(op, "sa\n", 3) == 0 && ft_strlen(op) == 3)
		sa_no_print(stacks);
	else if (ft_strncmp(op, "sb\n", 3) == 0 && ft_strlen(op) == 3)
		sb_no_print(stacks);
	else if (ft_strncmp(op, "ss\n", 3) == 0 && ft_strlen(op) == 3)
		ss_no_print(stacks);
	else if (ft_strncmp(op, "pa\n", 3) == 0 && ft_strlen(op) == 3)
		pa_no_print(stacks);
	else if (ft_strncmp(op, "pb\n", 3) == 0 && ft_strlen(op) == 3)
		pb_no_print(stacks);
	else if (ft_strncmp(op, "ra\n", 3) == 0 && ft_strlen(op) == 3)
		ra_no_print(stacks);
	else if (ft_strncmp(op, "rb\n", 3) == 0 && ft_strlen(op) == 3)
		rb_no_print(stacks);
	else if (ft_strncmp(op, "rr\n", 3) == 0 && ft_strlen(op) == 3)
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
	stacks = (t_stacks *) ft_calloc(sizeof(t_stacks), 1);
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
