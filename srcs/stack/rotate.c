/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 08:33:31 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/16 13:39:43 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackrotate(t_stack *stack)
{
	t_list	*elem;

	if (stack->size < 2)
		return ;
	elem = stack->data;
	stack->data = stack->data->next;
	elem->next = 0;
	ft_lstadd_back(&(stack->data), elem);
}
