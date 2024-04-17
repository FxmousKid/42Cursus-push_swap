/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:14:08 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/15 20:05:02 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common_funcs.h"

int	cost_to_put_in_sorted(t_stack *to, int num)
{
	int	*elems;
	int	len;
	int	counter;

	elems = to->elems;
	len = to->length;
	counter = 0;
	while (counter < len)
	{
		if (elems[counter] < num)
			return (cost_to_move_on_top(to, counter));	
		counter++;
	}
	return (INT_MAX);
}
