/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:50:20 by fsitter           #+#    #+#             */
/*   Updated: 2025/12/06 13:44:27 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// includes
# include "libft/libft.h"

// prototypes of structs
typedef struct s_number	t_number;
typedef struct s_stack	t_stack;

// struct to safe each individual nr
typedef struct s_number
{
	int					number;
	int					index;
	t_number			*previous;
	t_number			*next;
}						t_number;

// struct to store info about stack
typedef struct s_stack
{
	t_number			*top;
	t_number			*bottom;
	size_t				size;
}						t_stack;

// prototypes of functions

// input_helper.c
int						f_valid_integers_plus(char **av, int ac, int i);
int						f_find_duplicate(char **av, int ac, int i);
void					f_init_stack(t_stack *stack);
int						f_fill_nodes(t_stack *a, char **av, int ac, int i);
void					f_free_stack(t_stack *stack);

// swap_operations.c
int						f_swap(t_stack *stack);
void					sa(t_stack *stack_a);

// push_operations.c
int						f_push(t_stack *src, t_stack *dest);
void					pa(t_stack *stack_a, t_stack *stack_b);
void					pb(t_stack *stack_a, t_stack *stack_b);

// rotate_operations.c
int						f_rotate(t_stack *stack);
void					ra(t_stack *stack_a);

void					rr(t_stack *stack_a, t_stack *stack_b);

// reverse_rotate_operations.c
int						f_reverse_rotate(t_stack *stack);
void					rra(t_stack *stack_a);

// sort_index.c
void					ft_sort_int_tab(int *tab, int size);
int						*f_create_int_arr(int ac, char **av);
int						f_sort_index(t_stack *stack, char **av, int ac);
void					f_sort_in_stack(t_stack *stack, int *arr, int ac);
int						f_find_max_index(t_stack *stack);

// radix.c
int						f_max_runs(int max_index);
void					t_radix(t_stack *stack_a, t_stack *stack_b, int mr);
int						f_is_sorted(t_stack *stack_a);
void					f_pre_radix(t_stack *stack_a, t_stack *stack_b);

// quicksort.c
void					f_quicksort(t_stack *stack_a, t_stack *stack_b);
int						f_find_min_index(t_stack *stack);
int						f_ra_or_rra(t_stack *stack, int min_index);

// microsort.c
void					f_sort_three(t_stack *stack);
void					f_sort_five(t_stack *stack_a, t_stack *stack_b);
void					f_micro_sort(t_stack *stack_a, t_stack *stack_b);
#endif
