/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_funcs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:27:33 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/11 15:50:19 by inazaria         ###   ########.fr       */
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

// Manipulating the Stack itself
int		verify_input(char *input);
void	free_stack_splited_input(char *stack[], int stack_len);
int		*return_int_stack(int argc, char *argv[]);
char	**parse_stack_input(int argc, char *argv[]);
int		get_stack_len(int argc, char *argv[]);
void	free_stack(t_stack *stack);
void	display_stack(t_stack *stack);

t_stack	*make_stack_a(int argc, char *argv[]);
t_stack	*make_stack_b(int len_stack_a);

// Moveset functions
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

// Helper functions
int		count_occ(char *str, char *charset);

#endif
