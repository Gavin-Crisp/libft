/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:30:42 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/17 11:54:20 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	expand_vec(t_vector *vec)
{
	if (vec->_capacity == 0)
		vec->_capacity = 4;
	else
		vec->_capacity *= 2;
	vec->data = ft_realloc(vec->data, vec->_capacity * vec->_elem_size);
}

int	ft_vecinsert(t_vector *vec, void *elem, size_t index)
{
	void	*mem_loc;

	if (index > vec->length)
		return (0);
	if (vec->_capacity == vec->length)
		expand_vec(vec);
	mem_loc = ft_vecindex(vec, index);
	ft_memmove(mem_loc + vec->_elem_size, mem_loc,
		(vec->length - index) * vec->_elem_size);
	ft_memcpy(mem_loc, elem, vec->_elem_size);
	vec->length++;
	return (1);
}
