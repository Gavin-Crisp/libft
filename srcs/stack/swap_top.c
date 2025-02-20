/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 08:34:41 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/16 13:42:25 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackswap_top(t_stack *stack)
{
	void	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->data->data;
	stack->data->data = stack->data->next->data;
	stack->data->next->data = tmp;
}
