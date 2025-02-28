/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:25:43 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/25 12:15:13 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocator.h"

void	ft_free(void *ptr)
{
	t_chunk	*chunk;

	if (!ptr)
		return ;
	chunk = ptr - sizeof(t_chunk);
	if (chunk->is_free || !is_valid_chunk(chunk))
		return ;
	chunk->is_free = 1;
	if (chunk->prev->is_free)
	{
		chunk = chunk->prev;
		merge_with_next(chunk);
	}
	merge_with_next(chunk);
}
