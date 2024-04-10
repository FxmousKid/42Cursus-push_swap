/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:17:54 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/04 12:50:58 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

t_conversionFuncPtr	*make_conversion_table(void)
{
	static t_conversionFuncPtr	conversion_table[127] = {0};

	conversion_table['c'] = c_conversion;
	conversion_table['s'] = s_conversion;
	conversion_table['p'] = p_conversion;
	conversion_table['d'] = d_and_i_conversions;
	conversion_table['i'] = d_and_i_conversions;
	conversion_table['u'] = u_conversion;
	conversion_table['x'] = lower_x_conversion;
	conversion_table['X'] = upper_x_conversion;
	conversion_table['%'] = percent_conversion;
	return (conversion_table);
}
