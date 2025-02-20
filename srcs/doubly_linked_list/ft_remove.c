/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:16:16 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:39:35 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dllstremove(t_dllist	**headptr, size_t index, void (*fr)(void *))
{
	t_dllist	*elem;

	elem = ft_dllstindex(*headptr, index);
	if (!elem)
		return ;
	if (!index)
		*headptr = elem->next;
	else
		elem->prev->next = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
	fr(elem->data);
	free(elem);
}
