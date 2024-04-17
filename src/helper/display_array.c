/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:18:56 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/16 02:12:55 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

void	display_int_array(int *array, int size)
{
	int i;

	i = 0;
	ft_printf("Array: {");
	while (i < size - 1)
	{
		ft_printf("%d ,", array[i]);
		i++;
	}
	ft_printf("%d}\n", array[i]);
	ft_printf("\n");
}
