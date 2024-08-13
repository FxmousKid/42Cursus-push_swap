/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:33:55 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/24 22:16:15 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_if_duplicate_in_a(t_stacks *stacks)
{
	int	idx1;
	int	idx2;

	idx1 = 0;
	while (idx1 < stacks->a_length)
	{
		idx2 = idx1 + 1;
		while (idx2 < stacks->a_length)
		{
			if (stacks->a[idx1] == stacks->a[idx2])
				free_and_exit(stacks, "Error\n");
			idx2++;
		}
		idx1++;
	}
}

void	parse_numbers(t_stacks *stacks)
{
	char	**concatenated_args;
	int		idx;
	int		idx_stack;

	idx = 0;
	idx_stack = 0;
	concatenated_args = ft_split(stacks->join_args, ' ');
	while (concatenated_args[idx] != NULL && concatenated_args[idx][0] != '\0')
	{
		stacks->a[idx_stack] = ft_atol(concatenated_args[idx], stacks);
		idx++;
		idx_stack++;
		free(concatenated_args[idx - 1]);
	}
	free(concatenated_args);
}

void	initialize_stacks(int argc, char **argv, t_stacks *stacks)
{
	int	counter;

	counter = 0;
	stacks->a_length = 0;
	stacks->b_length = 0;
	while (--argc)
	{
		if (count_words(argv[counter + 1], ' '))
			stacks->a_length += count_words(argv[counter + 1], ' ');
		else
			stacks->a_length++;
		counter++;
	}
	stacks->a = (int *) ft_calloc(stacks->a_length, sizeof (int));
	if (stacks->a == NULL)
		free_and_exit(stacks, "Error\n");
	stacks->b = (int *) ft_calloc(stacks->a_length, sizeof(int));
	if (stacks->b == NULL)
		free_and_exit(stacks, "Error\n");
}

void	create_index(t_stacks *stacks)
{
	int		idx1;
	int		idx2;
	int		true_idx;
	int		*new_a;

	new_a = (int *) ft_calloc(stacks->a_length, sizeof (int));
	if (new_a == NULL)
		free_and_exit(stacks, "Error\n");
	idx1 = 0;
	while (idx1 < stacks->a_length)
	{
		true_idx = 0;
		idx2 = -1;
		while (++idx2 < stacks->a_length)
		{
			if (stacks->a[idx1] > stacks->a[idx2])
				true_idx++;
		}
		new_a[idx1] = true_idx;
		idx1++;
	}
	idx1 = stacks->a_length;
	while (idx1--)
		stacks->a[idx1] = new_a[idx1];
	free(new_a);
}

int	ft_atol(const char *num, t_stacks *stacks)
{
	int			idx;
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	idx = 0;
	while (num[idx] == ' ' || (num[idx] >= '\t' && num[idx] <= '\r'))
		idx++;
	if ((num[idx] == '+' || num[idx] == '-'))
	{
		if (num[idx] == '-')
			sign = -1;
		idx++;
	}
	while (num[idx])
	{
		if (res > INT_MAX || (res * sign) < INT_MIN)
			free_and_exit(stacks, "Error\n");
		if (num[idx] < '0' && num[idx] > '9')
			free_and_exit(stacks, "Error\n");
		res = res * 10 + (num[idx] - '0');
		idx++;
	}
	return ((int)(res * sign));
}
