/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:19:57 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/01 22:31:58 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s && s[counter])
		counter++;
	return (counter);
}
