/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:00:40 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/17 18:43:28 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	path_1_move(t_stack **stack_src, t_stack **stack_dst, t_node *cheapest)
{
	int		cost_a;
	int		cost_b;

	cost_a = cheapest->cost_a;
	cost_b = cheapest->cost_b;
	while (cost_a > 0 && cost_b > 0)
	{
		rr(stack_src,stack_dst);
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		ra(stack_src);
		cost_a--;
	}
	while (cost_b > 0)
	{
		rb(stack_dst);
		cost_b--;
	}
}

void	path_2_move(t_stack **stack_src, t_stack **stack_dst, t_node *cheapest)
{
	int		cost_a;
	int		cost_b;

	cost_a = cheapest->cost_a;
	cost_b = cheapest->cost_b;
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(stack_src,stack_dst);
		cost_a++;
		cost_b++;
	}
	while (cost_a < 0)
	{
		rra(stack_src);
		cost_a++;
	}
	while (cost_b < 0)
	{
		rrb(stack_dst);
		cost_b++;
	}
}

void	path_3_move(t_stack **stack_src, t_stack **stack_dst, t_node *cheapest)
{
	int		cost_a;
	int		cost_b;

	cost_a = cheapest->cost_a;
	cost_b = cheapest->cost_b;
	while (cost_a > 0)
	{
		ra(stack_src);
		cost_a--;
	}
	while (cost_b < 0)
	{
		rrb(stack_dst);
		cost_b++;
	}
}

void	path_4_move(t_stack **stack_src, t_stack **stack_dst, t_node *cheapest)
{
	int		cost_a;
	int		cost_b;

	cost_a = cheapest->cost_a;
	cost_b = cheapest->cost_b;
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
}

void	set_path(t_stack **stack_a, t_stack **stack_b, t_node *cheapest)
{
	if (cheapest->path == 1)
		path_1_move(stack_a, stack_b, cheapest);
	else if (cheapest->path == 2)
		path_2_move(stack_a, stack_b, cheapest);
	else if (cheapest->path == 3)
		path_3_move(stack_a, stack_b, cheapest);
	else
		path_4_move(stack_a, stack_b, cheapest);
}
