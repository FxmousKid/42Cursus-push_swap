/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:54:48 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/06 02:31:00 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	map_on_str(char *dest, char const *s, char (*f)(unsigned int, char))
{
	int	counter;

	counter = -1;
	while (s[++counter])
		dest[counter] = f(counter, s[counter]);
	dest[counter] = '\0';
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tab;

	tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (tab == NULL)
		return (NULL);
	map_on_str(tab, s, f);
	return (tab);
}
