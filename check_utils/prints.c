/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:43:58 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/27 17:13:45 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_array(char **argv)
{
	int	i;

	i = 0;
	while(argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		printf("\n");
		i++;
	}
}

void	print_list(int len, long *list)
{
	int i;

	i = 0;
	while(i < len)
	{
		printf("%ld\n", list[i]);
		i++;
	}
}

void	print_node(t_node *node)
{
	printf("Node -> (I:%d , D:%d)\n", node->index, node->data);
}
