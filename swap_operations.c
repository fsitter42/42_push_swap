/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 00:26:46 by fsitter           #+#    #+#             */
/*   Updated: 2025/12/06 13:45:16 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_swap(t_stack *stack)
{
	t_number	*first;
	t_number	*second;
	t_number	*third;

	if (stack->size < 2 || !stack->top || !stack->top->next)
		return (0);
	first = stack->top;
	second = first->next;
	third = second->next;
	stack->top = second;
	second->next = first;
	first->next = third;
	if (third)
		third->previous = first;
	first->previous = second;
	second->previous = NULL;
	return (1);
}

void	sa(t_stack *stack_a)
{
	if (f_swap(stack_a))
		ft_putstr_fd("sa\n", 1);
	else
		return ;
}

// void	sb(t_stack *stack_b)
// {
// 	if (f_swap(stack_b))
// 		ft_putstr_fd("sb\n", 1);
// 	else
// 		return ;
// }

// void	ss(t_stack *stack_a, t_stack *stack_b)
// {
// 	if (f_swap(stack_a) && (f_swap(stack_b)))
// 		ft_putstr_fd("ss\n", 1);
// 	else
// 		return ;
// }