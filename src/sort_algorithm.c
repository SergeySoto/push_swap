/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:37:19 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/15 17:11:13 by ssoto-su         ###   ########.fr       */
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
	int	i;
	int	mid;
	int	len;
	int	pushed;

	pushed = 0;
	i = 0;
	mid = ((*stack_a)->len / 2);
	len = (*stack_a)->len;
	while (pushed < mid && i < len)
	{
		if ((*stack_a)->node_lst->index < mid)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while ((*stack_a)->len > 3)
		pb(stack_a, stack_b);
}

// void	push_b(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_node	*current;

// 	current = (*stack_a)->node_lst;
// 	pb(stack_a,stack_b);
// 	pb(stack_a,stack_b);
// 	set_cost_b(stack_a);
// 	while ((*stack_a)->len > 3)
// 	{
		
// 	}
// }

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	// push_b(stack_a, stack_b);
	set_target_prev(stack_a, stack_b);
	set_target(stack_a, stack_b);
	set_cost_b(stack_b);
	set_cost_b(stack_a);
	set_cost_a(stack_a, stack_b);
	set_cost_a_for_A(stack_a, stack_b);
	// sort_numbers(stack_a, stack_b);
}
