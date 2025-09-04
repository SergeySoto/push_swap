/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:02:27 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/04 18:17:43 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	create_stack(argc, argv, &stack_a, &stack_b);
	printf("--------------Stack A--------------\n");
	lstiter(stack_a->node_lst, print_node);
	sort_numbers(&stack_a, &stack_b);
	printf("--------------Stack A--------------\n");
	lstiter(stack_a->node_lst, print_node);
	// t_node *temp = find_smallest_node(stack_a);
	// printf("smallest node: %d\n", temp->data);
	printf("--------------Stack B--------------\n");
	lstiter(stack_b->node_lst, print_node);
	free_stack(stack_a);
	free_stack(stack_b);


	// create_stack(argc, argv, &stack_a, &stack_b);
	// printf("--------------Stack A--------------\n");
	// lstiter(stack_a->node_lst, print_node);
	// // sort_numbers(&stack_a, &stack_b);
	// sa(&stack_a);
	// printf("--------------Stack A--------------\n");
	// lstiter(stack_a->node_lst, print_node);
	// // t_node *temp = find_smallest_node(stack_a);
	// // printf("smallest node: %d\n", temp->data);
	// // printf("--------------Stack B--------------\n");
	// // lstiter(stack_b->node_lst, print_node);
	// free_stack(stack_a);
	// free_stack(stack_b);
	// return (0);
}

	// stack_a = create_node_list(&len, list);
	// stack_b = malloc(sizeof(stack));
	// stack_b->node_lst = NULL;
	// stack_b->len = 0;
	// list_to_circle(&stack_a);
	// sa(&stack_a);
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// pb(&stack_b, &stack_a);
	// ra(&stack_a);
	// rra(&stack_a);
	// sb(&stack_b);
	// pa(&stack_a, &stack_b);
	// rr(&stack_a, &stack_b);
	// rrr(&stack_a, &stack_b);
	// rb(&stack_b);
	// rrb(&stack_b);
	// ss(&stack_a, &stack_b);
	// printf("--------------Stack A--------------\n");
	// lstiter(stack_a->node_lst, print_node);
	// printf("--------------Stack B--------------\n");
	// lstiter(stack_b->node_lst, print_node);
	// printf("len1: %d\n", stack_a->len);
	// printf("len2: %d\n", stack_b->len);
