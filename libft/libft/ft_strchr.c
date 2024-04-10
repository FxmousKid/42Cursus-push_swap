/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:57:20 by inazaria          #+#    #+#             */
/*   Updated: 2024/03/24 12:46:26 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	return (NULL);
}
