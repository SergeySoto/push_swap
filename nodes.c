/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:37:26 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/25 19:42:51 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_newnode(int data, int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->index = (int)index;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_node	*ft_last_node(t_node *node, int *len)
{
	int	i;

	i = 0;
	if (!node)
		return (NULL);
	// printf("longitud: %d", len);
	while (i < *len)
	{
		// printf("iterador: %d", i);
		node = node->next;
		i++;
	}
	return (node);
}

// void	ft_add_node_back(t_node *node1, int *len, t_node *new)
// {
// 	t_node	*temp;

// 	if (!new)
// 		return ;
// 	// if (node1 == NULL)
// 	// {
// 	// 	node1 = new;
// 	// 	return ;
// 	// }
// 	temp = node1;
// 	temp = ft_last_node(temp, len);
// 	temp->next = new;
// 	temp->prev = node1;
// 	node1->prev = new;
// 	new->prev = node1;
// 	new->next = node1;
// 	//crear otra funcion que agrege mas nodos a partir del tercer nodo!
// }

// t_node	*list_to_node(int *len, long *list)
// {
// 	int	i;
// 	t_node	*node_list;

// 	i = 1;
// 	node_list = ft_newnode(*list, i);
// 	while(i < *len)
// 	{
// 		list++;
// 		ft_add_node_back(node_list, len, ft_newnode(*list, i));
// 		i++;
// 	}
// 	return (node_list);
// }

t_node	*two_nodes(int *len, long *num_list)
{
	t_node	*first_node;
	t_node	*second_node;

	first_node = ft_newnode(*num_list, *len);
	len++;
	num_list++;
	second_node = ft_newnode(*num_list, *len);
	first_node->next = second_node;
	first_node->prev = second_node;
	second_node->next = first_node;
	second_node->prev = first_node;

	return (first_node);
}

t_node	*add_node_back(t_node *first_node, int *len, long *num_list)
{
	t_node	*node;
	t_node	*last_node;
	int		i;

	i = 0;
	while(i < *len)
	{
		last_node = ft_last_node(first_node, len);
		printf("last_node es: %d\n", last_node->data);
		node = ft_newnode(*num_list, *len);
		first_node->prev = node;
		last_node->next = node;
		node->prev = last_node;
		node->next = first_node;
		i++;
	}
	return (first_node);
}

// t_node	*nueva_funcion(int	*len, long *num_list)
// {
// 	t_node	*first_node;
// 	t_node	*last_node;
// 	int		i;

// 	i = 0;
// 	first_node = ft_newnode(*num_list, *len);
// 	while()
// }