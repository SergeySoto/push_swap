/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:36:18 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/03 16:15:33 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(stack **stack_a, stack **stack_b)
{
	if ((*stack_a)->len < 2 || (*stack_b)->len < 2)
		return ;
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

void	rr(stack **stack_a, stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}

void	rrr(stack **stack_a, stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}