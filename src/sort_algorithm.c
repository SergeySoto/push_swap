/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:37:19 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/18 16:47:51 by ssoto-su         ###   ########.fr       */
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

// void	push_b(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	i;
// 	int	mid;
// 	int	len;
// 	int	pushed;

// 	pushed = 0;
// 	i = 0;
// 	mid = ((*stack_a)->len / 2);
// 	len = (*stack_a)->len;
// 	while (pushed < mid && i < len)
// 	{
// 		if ((*stack_a)->node_lst->index < mid)
// 		{
// 			pb(stack_a, stack_b);
// 			pushed++;
// 		}
// 		else
// 			ra(stack_a);
// 		i++;
// 	}
// 	while ((*stack_a)->len > 3)
// 		pb(stack_a, stack_b);
// }

void	move_cheapest_to_top(t_stack **stack_src, t_stack **stack_dst)
{
	int		cost_a;
	int		cost_b;
	t_node	*cheap;

	cheap = cheapest(stack_src);
	cost_a = cheap->cost_a;
	cost_b = cheap->cost_b;
	while (cost_a > 0 && cost_b > 0)
	{
		rr(stack_src, stack_dst);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(stack_src, stack_dst);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0)
	{
		ra(stack_src);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(stack_src);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(stack_dst);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(stack_dst);
		cost_b++;
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
		sort_three(stack_a);
		rb(stack_b);
	}
	// while ((*stack_b)->len != 0)
	// 	pa(stack_b, stack_a);
}

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);

	// set_target_prev(stack_a, stack_b);
	// set_cost_a(stack_a);
	// set_cost_b_for_A(stack_a, stack_b);
	// set_total_cost(stack_a, stack_b);
	// set_total_cost(stack_b, stack_a);
	// t_node	*cheap = cheapest(stack_a);
	// print_node(cheap);
	// printf("path: %d\n", cheap->path);
	// if (cheap)
	// 	pb(stack_a, stack_b);
	// set_cost_a_for_A(stack_a, stack_b);
	// sort_numbers(stack_a, stack_b);
}
