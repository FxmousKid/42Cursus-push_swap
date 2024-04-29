/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:59 by huaydin           #+#    #+#             */
/*   Updated: 2024/04/29 05:22:54 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_length;
	int		b_length;
	char	*join_args;
}			t_stacks;

//  Moveset
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

//  Utils
void	display_stack(t_stacks *stacks);
int		ft_atol(const char *n, t_stacks *s);
void	free_stacks(t_stacks *stacks);

//  Error Handling
void	free_and_exit(t_stacks *stacks, char *message);
void	exit_if_duplicate_in_a(t_stacks *stacks);

//  Parsing
void	validate_arguments(int argc, char **argv);
void	verify_argv_entry(char *argv[], int i, int j);
void	join_args(int argc, char **argv, t_stacks *stacks);
void	initialize_stacks(int argc, char **argv, t_stacks *s);
void	parse_numbers(t_stacks *s);
void	create_index(t_stacks *s);

// Sorting
void	sort_3(t_stacks *s);
void	sort_4_5(t_stacks *s);
void	radix_sort(t_stacks *s);
int		is_a_sorted(t_stacks *stacks);

#endif
