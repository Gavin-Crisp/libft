/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reserve_exact.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:00:53 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/19 14:03:05 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vecreserve_exact(t_vector *vec, size_t num_elems)
{
	if (vec->length + num_elems <= vec->_capacity)
		return ;
	vec->_capacity = num_elems;
	vec->data = ft_realloc(vec->data, vec->_capacity * vec->_elem_size);
}
