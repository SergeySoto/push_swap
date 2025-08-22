/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:15:17 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/22 18:35:30 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_array(char **str)
{
	int	i;
	if (!str)
		return ;
	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_str(char *str)
{
	if (str)
		free(str);
}

void	free_long(long *str)
{
	if (str)
		free(str);
}

void	free_node(t_node *node, int *len)
{
	int	i;

	i = 0;
	while(i < *len)
	{
		free(node);
		node = node->next;
		i++;
	}
}