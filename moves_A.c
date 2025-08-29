/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_A.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:32:07 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/29 19:43:04 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node	**stack_a)
{
	if (!*stack_a || (*stack_a)->next == *stack_a)
		return ;
	swap(stack_a);
	// write(1, "sa\n", 3);
}

void	pa(t_node **stack_a, t_node **stack_b, int *len1, int *len2)
{
	if (!*stack_a)
		return ;
	push(stack_a, stack_b, len1, len2);
	// write(1, "pa\n", 3);
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	// write(1, "ra\n", 3);
}

void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	// write(1, "rra\n", 4);
}