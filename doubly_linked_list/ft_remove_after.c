/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_after.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:16:16 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 12:23:39 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dllstremove_after(
	t_dllist **headptr,
	size_t index,
	void (*fr)(void *))
{
	t_dllist	*elem;

	if (!headptr)
		return ;
	elem = ft_dllstindex_after(*headptr, index);
	if (!elem)
		return ;
	ft_dllstremove_elem(&elem, fr);
}
