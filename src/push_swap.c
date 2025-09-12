/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:02:27 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/12 18:07:32 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	create_stack(argc, argv, &stack_a, &stack_b);
	// printf("--------------Stack A--------------\n");
	// lstiter(stack_a->node_lst, print_node);
	// set_cost_b(&stack_a);
	sort_numbers(&stack_a, &stack_b);
	// printf("--------------Stack A--------------\n");
	// lstiter(stack_a->node_lst, print_node);
	printf("--------------Stack B--------------\n");
	lstiter(stack_b->node_lst, print_node);
	// t_node	*nodo = find_target_prev(&stack_b, (*stack_a).node_lst);
	// print_node(nodo);
	// printf("%d\n", stack_b->node_lst->target->data);
	// printf("%d\n", stack_b->node_lst->next->target->data);
	free_stack(stack_a);
	free_stack(stack_b);
}
