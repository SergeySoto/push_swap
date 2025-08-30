/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:02:27 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/29 19:44:50 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	// write(1, "puta!\n", 6);
	// printf_error();
	// ft_printf("is_number_valid: %d\n", is_number_valid(ft_strtrim("     123  	", " \n\t")));
	// ft_printf("is_number_valid: %d\n", is_number_valid(ft_strtrim("     1223f	", " \n\t")));
	// ft_printf("is_number_valid: %d\n", is_number_valid(ft_strtrim("			   -12123		", " \n\t")));
	// ft_printf("\n");
	// printf("ft_atol NUM_MIN: %ld\n", ft_atol("-2147483648"));
	// printf("ft_atol NUM_MAX: %ld\n", ft_atol("2147483647"));
	// printf("ft_atol NUM_MIN: %ld\n", ft_atol("-2147483649"));
	// printf("ft_atol NUM_MAX: %ld\n", ft_atol("2147483648"));
	// ft_printf("\n");
	// ft_printf("is_int_in_range: %d\n", is_int_in_range(ft_atol("-2147483648")));
	// ft_printf("is_int_in_range: %d\n", is_int_in_range(ft_atol("2147483647")));
	// ft_printf("is_int_in_range: %d\n", is_int_in_range(ft_atol("-2147483649")));
	// ft_printf("is_int_in_range: %d\n", is_int_in_range(ft_atol("2147483648")));
	//-----------------------------------------
	int	len1;
	int	len2;

	len2 = 0;
	char **arr = get_input(argc, argv);

	if (!arr)
	{
		free_array(arr);
		return (0);
	}
	//ft_putstr_fd("Este es el array:\n", 2);
	//print_array(arr);
	long *list = parse_array(arr, &len1);
	if (!list)
		return (0);
	//ft_putstr_fd("Esta es la lista de int:\n", 2);
	//print_list(len1, list);
	//printf("la longitud: %d\n", len1);
	if (!parse_list(list, &len1))
	{
		free_array(arr);
		free_long(list);
		printf_error();
		return (0);
	}
	t_node	*stack_a = create_node_list(&len1, list);
	t_node	*stack_b = NULL;
	list_to_circle(&stack_a);
	printf("--------------Stack A--------------\n");
	lstiter(stack_a, print_node);
	sa(&stack_a);
	pb(&stack_a, &stack_b, &len1, &len2);
	pb(&stack_a, &stack_b, &len1, &len2);
	printf("--------------Stack A--------------\n");
	lstiter(stack_a, print_node);
	printf("--------------Stack B--------------\n");
	lstiter(stack_b, print_node);
	ra(&stack_a);
	printf("--------------Stack A--------------\n");
	lstiter(stack_a, print_node);
	rra(&stack_a);
	printf("--------------Stack A--------------\n");
	lstiter(stack_a, print_node);
	// printf("len1: %d\n", len1);
	// printf("len2: %d\n", len2);
	free_node(stack_a, &len1);
	free_node(stack_b, &len2);
	free_long(list);
	free_array(arr);
	//-----------------------------------------

	return (0);
}
