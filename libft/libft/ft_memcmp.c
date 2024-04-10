/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:01:31 by inazaria          #+#    #+#             */
/*   Updated: 2024/03/24 22:45:38 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	counter;
	char	*s1_ptr;
	char	*s2_ptr;

	counter = 0;
	s1_ptr = (char *) s1;
	s2_ptr = (char *) s2;
	while (s1_ptr[counter] == s2_ptr[counter] && counter < n)
		counter++;
	if (counter == n)
		return (0);
	return (s1_ptr[counter] - s2_ptr[counter]);
}
