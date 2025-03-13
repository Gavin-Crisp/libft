/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reserve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:31:21 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 10:31:22 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	next_highest_p2(size_t n)
{
	size_t	power;

	power = 1;
	while (power <= n)
		power *= 2;
	return (power);
}

void	ft_vecreserve(t_vector *vec, size_t num_elements)
{
	if (vec->length + num_elements <= vec->_capacity)
		return ;
	vec->_capacity = next_highest_p2(vec->_capacity + num_elements);
	vec->data = ft_realloc(vec->data, vec->_capacity * vec->_elem_size);
}
