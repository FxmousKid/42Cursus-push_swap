/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:36:56 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/05 19:59:55 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	parse_arg_count(char *str)
{
	char	*tmp;
	int		counter;

	tmp = str + 1;
	counter = 0;
	while (tmp && *tmp)
	{
		if (*tmp == '%' && *(tmp - 1) != '%')
			counter++;
		else if (*tmp == '%' && *(tmp - 1) == '%')
			counter++;
		tmp++;
	}
	return (counter);
}

char	parse_next_arg(char *str)
{
	while (str && *str)
	{
		if (*str == '%')
			return (*++str);
		str++;
	}
	return (0);
}

int	parse_closest_arg_idx(char *str)
{
	int		idx;

	idx = 0;
	while (str && str[idx])
	{
		if (str[idx] == '%')
			return (++idx);
		idx++;
	}
	return (idx);
}
