/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:52:41 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/01 12:11:57 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdio.h>

char	*ft_strrch(const char *s, int c)
{
	int	rev_idx;

	rev_idx = ft_strlen(s) - 1;
	if (ft_strlen(s) == 0)
	{
		if (c == 0)
			return ((char *) s);
		return (NULL);
	}
	if (c == 0)
		return ((char *) s + ft_strlen(s));
	while (rev_idx != 0)
	{
		if (s[rev_idx] == (char) c)
			return ((char *) s + rev_idx);
		rev_idx--;
	}
	return (NULL);
}
