/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 08:34:05 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/24 15:34:55 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackrotate_rev(t_stack *stack)
{
	t_list	*before;

	if (stack->size < 2)
		return ;
	before = ft_lstindex(stack->data, stack->size - 2);
	ft_lstadd_front(&stack->data, before->next);
	before->next = 0;
}
