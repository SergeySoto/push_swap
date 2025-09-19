/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:37:19 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/19 20:26:42 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack **stack)
{
	if ((*stack)->len == 2)
	{
		if ((*stack)->node_lst->data > (*stack)->node_lst->next->data)
			sa(stack);
	}
}

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	if ((*stack)->len == 3)
	{
		a = (*stack)->node_lst->data;
		b = (*stack)->node_lst->next->data;
		c = (*stack)->node_lst->next->next->data;
		if (a > b && a > c)
			ra(stack);
		else if (b > a && b > c)
			rra(stack);
		a = (*stack)->node_lst->data;
		b = (*stack)->node_lst->next->data;
		if (a > b)
			sa(stack);
	}
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*current;
	int		i;

	current = (*stack_a)->node_lst;
	i = 0;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while ((*stack_a)->len > 3)
	{
		set_target_prev(stack_a, stack_b);
		set_cost_a(stack_a);
		set_cost_b_for_A(stack_a, stack_b);
		set_total_cost(stack_a, stack_b);
		move_cheapest_to_top(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*cheap;
	while ((*stack_b)->len > 0)
	{
		set_target(stack_a, stack_b);
		set_cost_b(stack_b);
		set_cost_a_for_B(stack_a, stack_b);
		set_total_cost(stack_b, stack_a);
		cheap = cheapest(stack_b);
		if (cheap)
			set_path(stack_b, stack_a, cheap);
		pa(stack_b, stack_a);
	}
}

void	put_small_top(t_stack **stack_a)
{
	t_node	*current;
	t_node	*smallest;

	current = (*stack_a)->node_lst;
	smallest = find_smallest_node_B(stack_a);
	while (current->prev->next == (*stack_a)->node_lst)
	{
		if (smallest == (*stack_a)->node_lst)
			break ;
		current = current->next;
		ra(stack_a);
	}
}

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	push_a(stack_a, stack_b);
	put_small_top(stack_a);
}
