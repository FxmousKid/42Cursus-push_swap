/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_funcs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:27:33 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/13 00:41:38 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_FUNCS_H
# define COMMON_FUNCS_H

# include "../libft/include/libft.h"

// Stack type definition
typedef struct s_stack
{
	int	*elems;
	int	length;
}				t_stack;

typedef struct s_elem
{
	int	value;
	int	index;
}				t_elem;	

// Manipulating the Stack itself
int		verify_input(int argc, char *argv[]);
int		verify_dups_in_input(t_stack *stack);
int		*return_int_stack(int argc, char *argv[]);
int		get_stack_len(int argc, char *argv[]);
void	free_stack(t_stack *stack);
void	display_stack(t_stack *stack);

t_stack	*make_stack_a(int argc, char *argv[]);
t_stack	*make_stack_b(int len_stack_a);

// Moveset functions
void	push(t_stack *from, t_stack *to);
void	reverse_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	swap(t_stack *stack);

void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

void	rra_no_print(t_stack *stack_a);
void	rrb_no_print(t_stack *stack_b);
void	rrr_no_print(t_stack *stack_a, t_stack *stack_b);
void	ra_no_print(t_stack *stack_a);
void	rb_no_print(t_stack *stack_b);
void	rr_no_print(t_stack *stack_a, t_stack *stack_b);
void	pa_no_print(t_stack *stack_a, t_stack *stack_b);
void	pb_no_print(t_stack *stack_a, t_stack *stack_b);
void	sa_no_print(t_stack *stack_a);
void	sb_no_print(t_stack *stack_b);
void	ss_no_print(t_stack *stack_a, t_stack *stack_b);


// Helper functions
int		count_occ(char *str, char *charset);

// Sorting functions
int		get_min_depth(t_stack *stack);
void	push_min_top(t_stack *stack);
void	push_all_from_to(t_stack *from, t_stack *to);
void	make_b_sorted(t_stack *stack_a, t_stack *stack_b);
void	stupid_sort(t_stack *stack_a, t_stack *stack_b);

#endif
