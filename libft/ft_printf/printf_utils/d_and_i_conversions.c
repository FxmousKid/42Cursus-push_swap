/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_and_i_conversions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:50:27 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/04 12:22:32 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

t_args	d_and_i_conversions(t_args s_args)
{
	int		num;

	num = va_arg(s_args.args, int);
	ft_putnbr(num);
	s_args.rendue += length_of_num(num, "0123456789");
	return (s_args);
}
