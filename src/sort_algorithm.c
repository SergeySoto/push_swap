/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:37:19 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/05 11:58:36 by ssoto-su         ###   ########.fr       */
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

t_node	*find_smallest_node(t_stack **stack)
{
	t_node	*smallest;
	t_node	*current;
	int		i;

	smallest = NULL;
	current = (*stack)->node_lst;
	i = 0;
	while(i < (*stack)->len)
	{
		if (current->index == -1)
		{
			smallest = current;
			break;
		}
		current = current->next;
		i++;
	}
	while (i < (*stack)->len)
	{
		if (current->data < smallest->data && current->index == -1)
			smallest = current;
		current = current->next;
		i++;
	}
	return (smallest);
}

// // Find the target node in stack A for one node in stack B
// t_node *find_target_node(t_node *stack_a, int b_value)
// {
//     t_node *target = NULL;
//     int min_diff = INT_MAX;

//     while (stack_a)
//     {
//         int diff = stack_a->value - b_value;
//         if (diff > 0 && diff < min_diff)
//         {
//             min_diff = diff;
//             target = stack_a;
//         }
//         stack_a = stack_a->next;
//     }

//     // If no bigger value was found, return the smallest in A
//     if (!target)
//         target = find_smallest_node(stack_a);

//     return target;
// }

// // Assign target nodes for all nodes in stack B
// void assign_target_nodes(t_node *stack_a, t_node *stack_b)
// {
//     t_node *current_b = stack_b;
//     while (current_b)
//     {
//         current_b->target_node = find_target_node(stack_a, current_b->value);
//         current_b = current_b->next;
//     }
// }

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->len > 3)
		pb(stack_a, stack_b);
	sort_numbers(stack_a, stack_b);
}
