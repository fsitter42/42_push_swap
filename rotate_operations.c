/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:29:33 by fsitter           #+#    #+#             */
/*   Updated: 2025/12/06 13:45:02 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_rotate(t_stack *stack)
{
	t_number	*old_top;
	t_number	*new_top;
	t_number	*old_bottom;

	if (stack->size < 2 || !stack->top || !stack->bottom)
		return (0);
	old_top = stack->top;
	new_top = old_top->next;
	old_bottom = stack->bottom;
	stack->top = new_top;
	if (new_top)
		new_top->previous = NULL;
	old_top->next = NULL;
	old_top->previous = old_bottom;
	old_bottom->next = old_top;
	stack->bottom = old_top;
	return (1);
}

void	ra(t_stack *stack_a)
{
	if (f_rotate(stack_a))
		ft_putstr_fd("ra\n", 1);
	else
		return ;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (f_rotate(stack_a) && (f_rotate(stack_b)))
		ft_putstr_fd("rr\n", 1);
	else
		return ;
}

// void	rb(t_stack *stack_b)
// {
// 	if (f_rotate(stack_b))
// 		ft_putstr_fd("rb\n", 1);
// 	else
// 		return ;
// }