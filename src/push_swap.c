/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:02:27 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/11 16:27:49 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_cost_b(t_stack **stack_b)
{
	int		size;
	int		i;
	t_node	*node;

	size = (*stack_b)->len / 2;
	node = (*stack_b)->node_lst;
	i = 0;
	while(i < (*stack_b)->len)
	{
		if (node->pos <= size)
			node->cost_b = node->pos;
		else if (node->pos > size)
			node->cost_b = node->pos - (*stack_b)->len;
		node = node->next;
		i++;
	}
}

// void	set_cost_a(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		half_size;
// 	int		i;
// 	t_node	*node;
// 	int		target_pos;

// 	half_size = (*stack_a)->len / 2;
// 	node = (*stack_b)->node_lst;
// 	i = 0;
// 	while(i < (*stack_b)->len)
// 	{
// 		target_pos = node->target;
// 		if (target_pos <= half_size)
// 			node->cost_a = target_pos;
// 		else
// 			node->cost_a = target_pos - (*stack_a)->len;
// 		node = node->next;
// 		i++;
// 	}
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node	*nodo;

	nodo = NULL;
	create_stack(argc, argv, &stack_a, &stack_b);
	sort_numbers(&stack_a, &stack_b);
	printf("--------------Stack A--------------\n");
	lstiter(stack_a->node_lst, print_node);
	set_cost_b(&stack_b);
	printf("--------------Stack B--------------\n");
	lstiter(stack_b->node_lst, print_node);
	nodo = find_biggest_node(&stack_a);
	printf("--------------Nodo mas grande--------------\n");
	print_node(nodo);
	printf("%d\n", stack_b->node_lst->target->data);
	printf("%d\n", stack_b->node_lst->target->next->data);
	free_stack(stack_a);
	free_stack(stack_b);
}
