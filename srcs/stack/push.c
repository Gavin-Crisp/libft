/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 08:33:48 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/16 13:39:14 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackpush(t_stack *stack, int data)
{
	int	*tmp;

	tmp = malloc(sizeof(int));
	*tmp = data;
	ft_lstadd_front(&stack->data, ft_lstnew(tmp));
	stack->size += 1;
}
