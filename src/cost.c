/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:07:35 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/11 19:08:19 by ssoto-su         ###   ########.fr       */
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
