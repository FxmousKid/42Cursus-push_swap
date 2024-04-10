/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:56:35 by inazaria          #+#    #+#             */
/*   Updated: 2024/03/24 17:44:16 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <unistd.h>

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	char	*dup_s;

	len_s = ft_strlen(s);
	dup_s = (char *) malloc(sizeof(char) * (len_s + 1));
	if (dup_s == NULL)
		return (NULL);
	ft_strlcpy(dup_s, s, (ft_strlen(s) + 1));
	return (dup_s);
}
