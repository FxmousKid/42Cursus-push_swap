/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:56:13 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/03 23:14:56 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

t_args	percent_conversion(t_args s_args)
{
	ft_putchar('%');
	s_args.rendue += 1;
	return (s_args);
}
