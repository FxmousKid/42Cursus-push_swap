/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:01:08 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/03 23:16:15 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

t_args	s_conversion(t_args s_args)
{
	char	*result;

	result = va_arg(s_args.args, char *);
	if (result == NULL)
	{
		ft_putstr("(null)");
		s_args.rendue += 6;
		return (s_args);
	}
	ft_putstr(result);
	s_args.rendue += ft_strlen(result);
	return (s_args);
}
