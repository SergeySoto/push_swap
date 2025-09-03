/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:20:40 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/03 18:45:38 by ssoto-su         ###   ########.fr       */
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
