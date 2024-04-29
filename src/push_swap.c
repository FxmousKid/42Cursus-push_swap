/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:24:29 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/29 05:26:01 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stacks *stacks)
{
	create_index(stacks);
	if (is_a_sorted(stacks))
		free_and_exit(stacks, NULL);
	if (stacks->a_length == 2)
		sa(stacks);
	else if (stacks->a_length == 3)
		sort_3(stacks);
	else if (stacks->a_length == 4 || stacks->a_length == 5)
		sort_4_5(stacks);
	else
		radix_sort(stacks);
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
	sort(stacks);
	exit_if_duplicate_in_a(stacks);
	return (free(stacks), 0);
}
