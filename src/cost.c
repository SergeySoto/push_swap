/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:07:35 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/19 19:53:55 by ssoto-su         ###   ########.fr       */
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
			node->cost_b = ft_abs(node->pos - (*stack_b)->len);
		node = node->next;
		i++;
	}
}

void	set_cost_a(t_stack **stack_a)
{
	int		size;
	int		i;
	t_node	*node;

	size = (*stack_a)->len / 2;
	node = (*stack_a)->node_lst;
	i = 0;
	while(i < (*stack_a)->len)
	{
		if (node->pos <= size)
			node->cost_a = node->pos;
		else if (node->pos > size)
			node->cost_a = ft_abs(node->pos - (*stack_a)->len);
		node = node->next;
		i++;
	}
}

void	set_cost_a_for_B(t_stack **stack_a, t_stack **stack_b)
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
			node->cost_a = ft_abs(target_pos - (*stack_a)->len);
		node = node->next;
		i++;
	}
}

void	set_cost_b_for_A(t_stack **stack_a, t_stack **stack_b)
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
			node->cost_b = target_pos;
		else
			node->cost_b = ft_abs(target_pos - (*stack_b)->len);
		node = node->next;
		i++;
	}
}

void	set_total_cost(t_stack **stack_src, t_stack **stack_dst)
{
	int		i;
	int		half_src;
	int		half_dst;
	t_node	*current;

	i = 0;
	current = (*stack_src)->node_lst;
	half_src = (*stack_src)->len / 2;
	half_dst = (*stack_dst)->len / 2;
	while (i < (*stack_src)->len)
	{
		if (current->pos <= half_src && current->target->pos <= half_dst)
			path_1(&current);
		else if (current->pos > half_src && current->target->pos > half_src)
			path_2(&current);
		else if (current->pos <= half_src && current->target->pos > half_dst)
			path_3(&current);
		else
			path_4(&current);
		current = current->next;
		i++;
	}
}
