/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_B.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:34:00 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/29 19:43:22 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node	**stack_b)
{
	if (!*stack_b || (*stack_b)->next == *stack_b)
		return ;
	swap(stack_b);
	// write(1, "sb\n", 3);
}

void	pb(t_node **stack_b, t_node **stack_a, int *len1, int *len2)
{
	if (!*stack_b)
		return ;
	push(stack_b, stack_a, len1, len2);
	// write(1, "pb\n", 3);
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	// write(1, "rb\n", 3);
}

void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	// write(1, "rrb\n", 4);
}