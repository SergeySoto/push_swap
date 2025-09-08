/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:02:27 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/08 18:35:53 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_cost_a(t_stack **stack_a)
{
	int		size;
	int		i;
	t_node	*node;

	size = (*stack_a)->len / 2;
	node = (*stack_a)->node_lst;
	i = 1;
	while(i < (*stack_a)->len)
	{
		if (node->pos <= size)
			node->cost_b = node->pos;
		else if (node->pos > size)
			node->cost_b = node->pos - size;
		node = node->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	create_stack(argc, argv, &stack_a, &stack_b);
	sort_numbers(&stack_a, &stack_b);
	printf("--------------Stack A--------------\n");
	lstiter(stack_a->node_lst, print_node);
	set_cost(&stack_b);
	printf("--------------Stack B--------------\n");
	lstiter(stack_b->node_lst, print_node);
	free_stack(stack_a);
	free_stack(stack_b);
}
