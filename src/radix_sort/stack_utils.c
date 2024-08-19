/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:22:35 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/19 13:15:18 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(t_stacks *stacks, char *message)
{
	if (message != NULL)
		ft_putstr_fd(message, 2);
	if (stacks != NULL)
	{
		if (stacks->a != NULL)
			free(stacks->a);
		if (stacks->b != NULL)
			free(stacks->b);
		if (stacks->join_args != NULL)
			free(stacks->join_args);
	}
	free(stacks);
	exit(1);
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks != NULL)
	{
		if (stacks->a != NULL)
			free(stacks->a);
		if (stacks->b != NULL)
			free(stacks->b);
		if (stacks->join_args != NULL)
			free(stacks->join_args);
	}
}

void	verify_argv_entry(char *argv[], int i, int j)
{
	while (argv[i][j] != '\0')
	{
		if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
		&& (argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' '))
		|| (argv[i][j] == '-' && argv[i][j + 1] == '\0')
		|| (argv[i][j] == '+' && argv[i][j + 1] == '\0')
		|| (argv[i][j] == '-' && argv[i][j + 1] == ' ')
		|| (argv[i][j] == '+' && argv[i][j + 1] == ' ')
		|| ((!ft_isdigit(argv[i][j])) && (argv[i][j] != ' ') 
		&& (argv[i][j] != '-')))
			free_and_exit(NULL, "Error\n");
		j++;
	}
}

void	validate_arguments(int argc, char **argv)
{
	int	idx1;
	int	idx2;

	idx1 = 1;
	if (argc < 2)
		free_and_exit(NULL, "");
	while (idx1 < argc && argv[idx1] != NULL)
	{
		if (!argv[idx1][0] || (argv[idx1][0] && argv[idx1][0] == ' '))
			free_and_exit(NULL, "Error\n");
		idx2 = 0;
		verify_argv_entry(argv, idx1, idx2);
		idx1++;
	}
}

void	join_args(int argc, char **argv, t_stacks *stacks)
{
	char	*tmp;
	char	*tmp2;
	int		counter;

	counter = 0;
	tmp2 = ft_strdup("");
	while (counter++ < argc && argv[counter] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[counter]);
		if (tmp != NULL)
			free(tmp2);
		if (counter != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	stacks->join_args = ft_strdup(tmp);
	if (stacks->join_args == NULL)
		free_and_exit(stacks, "Error\n");
	if (tmp != NULL)
		free(tmp);
}
