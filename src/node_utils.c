/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:20:40 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/05 16:13:28 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_last_node(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (1)
	{
		if (temp->next == stack)
			return (temp);
		temp = temp->next;
	}
}

void	set_pos(t_node *stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack;
	while(1)
	{
		temp->pos = i;
		temp = temp->next;
		if(temp == stack)
			break;
		i++;
	}
}

void	set_index(t_stack **stack)
{
	t_node	*smallest;
	int		i;

	i = 0;
	while(i < (*stack)->len)
	{
		smallest = find_smallest_node(stack);
		if (smallest)
			smallest->index = i;
		i++;
	}
}
/*
void	set_target(t_stack **stack)
{
	int		i;
	t_node	*current;

	i = 0;
	current = (*stack)->node_lst;
	while(i < (*stack)->len)
	{
		if (current->target == -1)
		{
			if ()
		}
	}
}
*/
