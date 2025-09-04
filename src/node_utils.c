/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:20:40 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/04 18:21:01 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_last_node(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (1)
	{
		if (temp->next == stack)
			return (temp);
		temp = temp->next;
	}
}

void	set_pos(t_node *stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack;
	while(1)
	{
		temp->pos = i;
		temp = temp->next;
		if(temp == stack)
			break;
		i++;
	}
}
