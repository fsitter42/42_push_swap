/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:10:25 by fsitter           #+#    #+#             */
/*   Updated: 2025/12/10 23:27:48 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac < 2)
		return (0);
	if (!f_valid_integers_plus(av, ac, 1))
		return (ft_putstr_fd("ERROR\n", 2), 0);
	f_init_stack(&stack_a);
	f_init_stack(&stack_b);
	if (!f_fill_nodes(&stack_a, av, ac, 1))
		return (ft_putstr_fd("ERROR:\nMalloc!\n", 2), 0);
	f_sort_index(&stack_a, av, ac);
	if (f_is_sorted(&stack_a))
		return (f_free_stack(&stack_a), f_free_stack(&stack_b), 0);
	if (stack_a.size <= 69)
		f_micro_sort(&stack_a, &stack_b);
	else
		f_pre_radix(&stack_a, &stack_b);
	if (!(f_is_sorted(&stack_a)))
		return (f_free_stack(&stack_a), f_free_stack(&stack_b), -1);
	f_free_stack(&stack_a);
	f_free_stack(&stack_b);
}
