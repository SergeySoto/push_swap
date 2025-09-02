/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:02:27 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/02 16:55:19 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	len;
	char **arr = get_input(argc, argv);

	if (!arr)
	{
		free_array(arr);
		return (0);
	}
	long *list = parse_array(arr, &len);
	if (!list)
		return (0);
	if (!parse_list(list, &len))
	{
		free_array(arr);
		free_long(list);
		printf_error();
		return (0);
	}
	stack	*stack_a = create_node_list(&len, list);
	stack	*stack_b = malloc(sizeof(stack));
	stack_b->node_lst = NULL;
	stack_b->len = 0;
	list_to_circle(&stack_a);
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
	printf("--------------Stack A--------------\n");
	lstiter(stack_a->node_lst, print_node);
	sort_two(&stack_a);
	sort_three(&stack_a);
	printf("--------------Stack A--------------\n");
	lstiter(stack_a->node_lst, print_node);
	free_stack(stack_a);
	free_stack(stack_b);
	free_long(list);
	free_array(arr);

	return (0);
}
