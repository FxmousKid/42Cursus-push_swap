/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:59 by huaydin           #+#    #+#             */
/*   Updated: 2024/08/18 03:36:11 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stacks
{
	long	*a;
	long	*b;
	int		a_length;
	int		b_length;
	char	*join_args;
}			t_stacks;

// Moveset utils

void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	reverse_rotate_a(t_stacks *stacks);
void	reverse_rotate_b(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	swap_a(t_stacks *stacks);

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

// Moveset no print for checker
void	pa_no_print(t_stacks *stacks);
void	pb_no_print(t_stacks *stacks);
void	rra_no_print(t_stacks *stacks);
void	rrb_no_print(t_stacks *stacks);
void	rrr_no_print(t_stacks *stacks);
void	ra_no_print(t_stacks *stacks);
void	rb_no_print(t_stacks *stacks);
void	rr_no_print(t_stacks *stacks);
void	sa_no_print(t_stacks *stacks);
void	sb_no_print(t_stacks *stacks);
void	ss_no_print(t_stacks *stacks);

//  Utils
void	display_stack(t_stacks *stacks);
long	ft_atol(const char *n, t_stacks *s);
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
