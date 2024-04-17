/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_elem_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:10:03 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/16 02:23:34 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

int	get_min_idx(int *array, int size)
{
	int	min_index;
	int	i;

	if (size == 0)
		return (INT_MAX);
	min_index = 0;
	i = 1;
	while (i < size)
	{
		if (array[i] < array[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}
