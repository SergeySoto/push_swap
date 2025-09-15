/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:07:35 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/15 17:45:17 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_cost_b(t_stack **stack_b)
{
	int		size;
	int		i;
	t_node	*node;

	size = (*stack_b)->len / 2;
	node = (*stack_b)->node_lst;
	i = 0;
	while(i < (*stack_b)->len)
	{
		if (node->pos <= size)
			node->cost_b = node->pos;
		else if (node->pos > size)
			node->cost_b = node->pos - (*stack_b)->len;
		node = node->next;
		i++;
	}
}

void	set_cost_a(t_stack **stack_a, t_stack **stack_b)
{
	int		half_size;
	int		i;
	t_node	*node;
	int		target_pos;

	half_size = (*stack_a)->len / 2;
	node = (*stack_b)->node_lst;
	i = 0;
	while (i < (*stack_b)->len)
	{
		target_pos = node->target->pos;
		if (target_pos <= half_size)
			node->cost_a = target_pos;
		else
			node->cost_a = target_pos - (*stack_a)->len;
		node = node->next;
		i++;
	}
}

void	set_cost_a_for_A(t_stack **stack_a, t_stack **stack_b)
{
	int		half_size;
	int		i;
	t_node	*node;
	int		target_pos;

	half_size = (*stack_b)->len / 2;
	node = (*stack_a)->node_lst;
	i = 0;
	while (i < (*stack_a)->len)
	{
		target_pos = node->target->pos;
		if (target_pos <= half_size)
			node->cost_a = target_pos;
		else
			node->cost_a = target_pos - (*stack_b)->len;
		node = node->next;
		i++;
	}
}

void	cheapest(t_stack **stack)
{
	int		i;
	t_node	*current;
	t_node	*cheapest;

	i = 0;
	current = (*stack)->node_lst;
	cheapest = current;
	while(i < (*stack)->len)
	{
		current->total_cost = current->cost_a + current->cost_b;
		if (current->total_cost < 0)
			current->total_cost = current->total_cost * -1;
		current = current->next;
		i++;
	}
}
