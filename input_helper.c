/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:03:48 by fsitter           #+#    #+#             */
/*   Updated: 2025/12/07 23:08:23 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_valid_integers_plus(char **av, int ac, int i)
{
	char	*itoa_of_atoi;
	int		old_i;

	old_i = i;
	while (i < ac)
	{
		itoa_of_atoi = ft_itoa(ft_atoi(av[i]));
		if (!ft_strncmp(av[i], "-0", ft_strlen(av[i])))
			i++;
		else if (!ft_strncmp(av[i], itoa_of_atoi, ft_strlen(av[i])))
			i++;
		else if (!ft_strncmp(av[i], "+", ft_strlen(av[i])))
			return (free(itoa_of_atoi), 0);
		else if ((ft_strchr("+", av[i][0])) && !(ft_strncmp(av[i] + 1,
					itoa_of_atoi, (ft_strlen(av[i]) - 1))))
			i++;
		else
			return (free(itoa_of_atoi), 0);
		free(itoa_of_atoi);
	}
	if (f_find_duplicate(av, ac, old_i))
		return (0);
	return (1);
}

int	f_find_duplicate(char **av, int ac, int i)
{
	int	j;

	while (i < ac)
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	f_init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

int	f_fill_nodes(t_stack *a, char **av, int ac, int i)
{
	t_number	*new_node;

	while (ac > i)
	{
		new_node = malloc(sizeof(t_number));
		if (!new_node)
			return (0);
		new_node->number = ft_atoi(av[ac - 1]);
		new_node->index = a->size;
		new_node->previous = NULL;
		new_node->next = a->top;
		if (a->top != NULL)
			a->top->previous = new_node;
		a->top = new_node;
		if (a->size == 0)
			a->bottom = new_node;
		a->size++;
		ac--;
	}
	return (1);
}

void	f_free_stack(t_stack *stack)
{
	t_number	*current;
	t_number	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	f_init_stack(stack);
}
