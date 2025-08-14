/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:37:26 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/05 18:02:47 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_newnode(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

t_node	*ft_last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	ft_add_node_back(t_node **node, t_node *new)
{
	t_node	*temp;

	if (!node || !new)
		return ;
	if (*node == NULL)
	{
		*node = new;
		return ;
	}
	temp = *node;
	temp = ft_last_node(temp);
	temp->next = new;
}

