/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 01:43:30 by fsitter           #+#    #+#             */
/*   Updated: 2025/12/05 15:59:32 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_push(t_stack *src, t_stack *dest)
{
	t_number	*node;

	if (!src || src->size == 0)
		return (0);
	node = src->top;
	src->top = node->next;
	if (src->top)
		src->top->previous = NULL;
	else
		src->bottom = NULL;
	src->size--;
	node->next = NULL;
	node->previous = NULL;
	if (!dest || dest->size == 0)
		dest->bottom = node;
	else
	{
		node->next = dest->top;
		dest->top->previous = node;
	}
	dest->top = node;
	dest->size++;
	return (1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (f_push(stack_a, stack_b))
		ft_putstr_fd("pb\n", 1);
	else
		return ;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (f_push(stack_b, stack_a))
		ft_putstr_fd("pa\n", 1);
	else
		return ;
}
