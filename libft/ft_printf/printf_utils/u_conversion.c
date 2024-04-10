/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:02:37 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/04 02:13:02 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

t_args	u_conversion(t_args s_args)
{
	unsigned int	n;
	int				len;

	n = va_arg(s_args.args, unsigned int);
	ft_putnbr(n);
	len = length_of_num(n, "0123456789");
	s_args.rendue += len;
	return (s_args);
}
