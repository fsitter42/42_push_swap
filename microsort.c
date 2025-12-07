/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:44:58 by fsitter           #+#    #+#             */
/*   Updated: 2025/12/06 13:23:23 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_sort_three(t_stack *stack)
{
	int	max_index;

	if (stack->size > 3)
		return ;
	max_index = f_find_max_index(stack);
	if (stack->top->index == max_index)
		ra(stack);
	else if (stack->top->next->index == max_index)
		rra(stack);
	if (stack->top->index > stack->top->next->index)
		sa(stack);
}

void	f_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;

	if (stack_a->size > 25)
		return ;
	while (stack_a->size > 3)
	{
		min_index = f_find_min_index(stack_a);
		if (f_ra_or_rra(stack_a, min_index) == 1)
		{
			while (stack_a->top->index != min_index)
				ra(stack_a);
			pb(stack_a, stack_b);
		}
		else
		{
			while (stack_a->top->index != min_index)
				rra(stack_a);
			pb(stack_a, stack_b);
		}
	}
	f_sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

void	f_micro_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		if (!f_is_sorted(stack_a))
			ra(stack_a);
	}
	else if (stack_a->size == 3)
		f_sort_three(stack_a);
	else if (stack_a->size > 3 && stack_a->size < 25)
		f_sort_five(stack_a, stack_b);
}
