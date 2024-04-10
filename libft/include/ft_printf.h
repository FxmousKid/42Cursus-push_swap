/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:41:52 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/09 20:52:38 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h> 
# include <stdint.h>
# include <stdio.h>
# include <stdarg.h>

// Typedefs
typedef struct s_args
{
	int		rendue;
	va_list	args;
}				t_args;	
typedef t_args	(*t_conversionFuncPtr)(t_args);

// Helper functions
size_t				ft_strlen(const char *s);
void				ft_putstr(char *str);
void				ft_putchar(char c);
void				ft_putnbr(long n);
int					length_of_num(long num, char *base);
int					length_of__ulong_num(unsigned long long num, char *base);

// Parsing functions
char				parse_next_arg(char *str);

// Conversion functions
t_args				d_and_i_conversions(t_args s_args);
t_args				upper_x_conversion(t_args s_args);
t_args				lower_x_conversion(t_args s_args);
t_args				p_conversion(t_args s_args);
t_args				percent_conversion(t_args s_args);
t_args				c_conversion(t_args s_args);
t_args				u_conversion(t_args s_args);
t_args				s_conversion(t_args s_args);

t_conversionFuncPtr	*make_conversion_table(void);

// Main function
int					ft_printf(const char *format, ...)
					__attribute__ ((format (printf, 1, 2)));

#endif
