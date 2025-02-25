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
	if (!is_valid_chunk(chunk) || chunk->is_free)
		return ;
	free_chunk(&chunk);
}
