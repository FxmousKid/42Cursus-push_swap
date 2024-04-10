/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:21:00 by inazaria          #+#    #+#             */
/*   Updated: 2024/03/25 22:24:22 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*debut;
	t_list	*tmp;

	if (lst == NULL)
		return ;
	debut = *lst;
	while (debut->next != NULL)
	{
		tmp = debut->next;
		del(debut->content);
		free(debut);
		debut = tmp;
	}
	del(debut->content);
	free(debut);
	*lst = NULL;
}
