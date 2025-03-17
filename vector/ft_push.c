/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:31:09 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/17 12:04:33 by gcrisp           ###   ########.fr       */
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

int	ft_vecpush(t_vector *vec, void *elem)
{
	if (vec->_capacity == vec->length)
		expand_vec(vec);
	ft_memcpy(ft_vecindex(vec, vec->length), elem, vec->_elem_size);
	vec->length++;
	return (1);
}
