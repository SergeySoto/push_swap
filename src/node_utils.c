/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:20:40 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/16 19:37:51 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_pos(t_node *stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack;
	while (1)
	{
		temp->pos = i;
		temp = temp->next;
		if (temp == stack)
			break ;
		i++;
	}
}

void	set_index(t_stack **stack)
{
	t_node	*smallest;
	int		i;

	i = 0;
	while (i < (*stack)->len)
	{
		smallest = find_smallest_node(stack);
		if (smallest)
			smallest->index = i;
		i++;
	}
}

t_node	*cheapest(t_stack **stack)
{
	t_node	*cheapest;
	t_node	*current;
	int		i;

	current = (*stack)->node_lst;
	cheapest = current;
	i = 0;
	while (i < (*stack)->len)
	{
		if (current->total_cost < cheapest->total_cost)
			cheapest = current;
		current = current->next;
		i++;
	}
	return (cheapest);
}
