/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:36:18 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/29 19:44:05 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(stack **stack_a, stack **stack_b)
{
	if ((*stack_a)->node_lst->next == (*stack_a)->node_lst || (*stack_b)->node_lst->next == (*stack_b)->node_lst)
		return ;
	swap(stack_a);
	swap(stack_b);
	// write(1, "ss\n", 3);
}

void	rr(stack **stack_a, stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	// write(1, "rr\n", 3);
}

void	rrr(stack **stack_a, stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	// write(1, "rrr\n", 4);
}