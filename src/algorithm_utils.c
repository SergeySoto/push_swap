/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:21:06 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/18 17:29:50 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	first_sort(t_stack **stack_src, t_stack **stack_dst, t_node *cheap)
{
	int		cost_a;
	int		cost_b;

	cost_a = cheap->cost_a;
	cost_b = cheap->cost_b;
	while (cost_a > 0 && cost_b > 0)
	{
		rr(stack_src, stack_dst);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(stack_src, stack_dst);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0)
	{
		ra(stack_src);
		cost_a--;
	}
}

void	second_sort(t_stack **stack_src, t_stack **stack_dst, t_node *cheap)
{
	int		cost_a;
	int		cost_b;

	cost_a = cheap->cost_a;
	cost_b = cheap->cost_b;
	while (cost_a < 0)
	{
		rra(stack_src);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(stack_dst);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(stack_dst);
		cost_b++;
	}
}
