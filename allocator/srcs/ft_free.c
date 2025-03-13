/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:25:43 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/11 11:56:53 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocator.h"

void	ft_free(void *ptr)
{
	t_chunk	*chunk;

	if (!ptr)
		return ;
	chunk = ptr - sizeof(t_chunk);
	if (chunk->is_free || !chunk_is_valid(chunk))
		return ;
	chunk->is_free = 1;
	if (chunk->prev->is_free)
	{
		chunk = chunk->prev;
		merge_with_next(chunk);
	}
	merge_with_next(chunk);
}
