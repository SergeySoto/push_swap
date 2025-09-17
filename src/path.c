/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:31:10 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/17 19:27:33 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	path_1(t_node **node)
{
	if ((*node)->cost_a > (*node)->target->cost_b)
		(*node)->total_cost = (*node)->cost_a;
	else
		(*node)->total_cost = (*node)->target->cost_b;
	(*node)->path = 1;
}

void	path_2(t_node **node)
{
	int	a;
	int	b;

	a = ft_abs((*node)->cost_a);
	b = ft_abs((*node)->target->cost_b);
	if (a > b)
		(*node)->total_cost = a;
	else
		(*node)->total_cost = b;
	(*node)->path = 2;
}

void	path_3(t_node **node)
{
	(*node)->total_cost = ft_abs((*node)->cost_a) + ft_abs((*node)->target->cost_b);
	(*node)->path = 3;
}

void	path_4(t_node **node)
{
	(*node)->total_cost = ft_abs((*node)->cost_a) + ft_abs((*node)->target->cost_b);
	(*node)->path = 4;
}
