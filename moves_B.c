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

void	sb(stack **stack_b)
{
	if (!*stack_b || (*stack_b)->node_lst->next == (*stack_b)->node_lst)
		return ;
	swap(stack_b);
	// write(1, "sb\n", 3);
}

void	pb(stack **stack_b, stack **stack_a)
{
	if (!*stack_b)
		return ;
	push(stack_b, stack_a);
	// write(1, "pb\n", 3);
}

void	rb(stack **stack_b)
{
	rotate(stack_b);
	// write(1, "rb\n", 3);
}

void	rrb(stack **stack_b)
{
	reverse_rotate(stack_b);
	// write(1, "rrb\n", 4);
}