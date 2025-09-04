/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:20:40 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/04 19:50:27 by ssoto-su         ###   ########.fr       */
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

void	set_index(t_stack **stack)
{
	t_node	*list_node;
	t_node	*smallest;
	int		i;

	i = 1;
	smallest = find_smallest_node(stack);
	printf("smallest %d\n",smallest->data);
	smallest->index = 0;
	list_node = (*stack)->node_lst;
	while(1)
	{
		
		//list_node = list_node->next;
		smallest = find_smallest_node(stack);
		smallest->index = i;
		// if (smallest = find_smallest_node((*stack)))
		// {
		// 	smallest = list_node;
		// 	smallest->index = i;
		// }
		//printf("%d\n", smallest->index);
		// list_node = list_node->next;
		(*stack)->node_lst = (*stack)->node_lst->next;
		if (list_node == (*stack)->node_lst)
		{
			printf("llega 2\n");
			break ;
		}
		i++;
	}
}
