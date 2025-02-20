/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 08:25:29 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/16 13:39:01 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stackpop(t_stack *stack)
{
	int		val;

	val = *(int *)stack->data->data;
	ft_lstremove(&(stack->data), 0, free);
	stack->size -= 1;
	return (val);
}
