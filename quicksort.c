/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:51:50 by fsitter           #+#    #+#             */
/*   Updated: 2025/12/06 13:41:53 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_quicksort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;

	while (stack_a->size > 0)
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
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
	return ;
}

int	f_find_min_index(t_stack *stack)
{
	t_number	*current;
	t_number	*min;

	current = stack->top;
	min = current;
	while (current)
	{
		if (current->number < min->number)
			min = current;
		current = current->next;
	}
	return (min->index);
}

int	f_ra_or_rra(t_stack *stack, int min_index)
{
	t_number	*current;
	size_t		i;

	i = 0;
	current = stack->top;
	while (current)
	{
		if (current->index == min_index)
			break ;
		current = current->next;
		i++;
	}
	if (i > stack->size / 2)
		return (0);
	return (1);
}
