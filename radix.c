/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:10:42 by fsitter           #+#    #+#             */
/*   Updated: 2025/12/07 22:55:29 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_max_runs(int max_index)
{
	int	i;

	i = 0;
	while (max_index >> i != 0)
		i++;
	return (i);
}

void	t_radix(t_stack *stack_a, t_stack *stack_b, int mr)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	size = stack_a->size;
	while (mr > i)
	{
		j = 0;
		while (j++ < size)
		{
			if (!(stack_a->top->index & (1 << i)))
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		if (f_is_sorted(stack_a))
			return ;
		i++;
	}
}

void	f_pre_radix(t_stack *stack_a, t_stack *stack_b)
{
	int	max_runs;

	max_runs = f_max_runs(f_find_max_index(stack_a));
	t_radix(stack_a, stack_b, max_runs);
}

int	f_is_sorted(t_stack *stack_a)
{
	t_number	*current;

	current = stack_a->top;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}
