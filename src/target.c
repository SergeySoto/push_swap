/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:43:35 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/22 19:52:26 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_target_prev(t_stack **stack_b, t_node *node_a)
{
	int	i;
	t_node	*current;
	t_node	*prev_num;

	i = 0;
	current = (*stack_b)->node_lst;
	prev_num = NULL;
	while (i < (*stack_b)->len)
	{
		if (current->data < node_a->data)
		{
			if (!prev_num)
				prev_num = current;
			if (current->data > prev_num->data)
				prev_num = current;
		}
		current = current->next;
		i++;
	}
	if (!prev_num)
		prev_num = find_biggest_node(stack_b);
	return (prev_num);
}

void	set_target_prev(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	t_node	*target_node;
	t_node	*aux;

	aux = (*stack_a)->node_lst;
	i = 0;
	while (i < (*stack_a)->len)
	{
		target_node = find_target_prev(stack_b, aux);
		if (target_node)
			aux->target = target_node;
		else
			aux->target = (*stack_b)->node_lst;
		i++;
		aux = aux->next;
	}
}

t_node	*find_target(t_stack **stack_a, t_node *node_b)
{
	int		i;
	int		min_diff;
	t_node	*target;
	t_node	*current;
	int		diff;

	diff = 0;
	min_diff = INT_MAX;
	target = NULL;
	i = 0;
	current = (*stack_a)->node_lst;
	while (i < (*stack_a)->len)
	{
		diff = current->data - node_b->data;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			target = current;
		}
		i++;
		current = current->next;
	}
	if (!target)
	{
		target = find_smallest_node_B(stack_a);
	}
	return (target);
}
// static void	set_pos_aux(t_stack **stack)
// {
// 	int		i;
// 	t_node	*temp;

// 	i = 0;
// 	temp = (*stack)->node_lst;
// 	while (1)
// 	{
// 		temp->pos = i;
// 		temp = temp->next;
// 		if (temp == (*stack)->node_lst)
// 			break ;
// 		i++;
// 	}
// }

static int	find_smallest_pos(t_node **stack_a)
{
	t_node	*aux;
	t_node	*lowest;
	int		pos;

	aux = *stack_a;
	lowest = *stack_a;
	pos = 0;
	while (aux)
	{
		if (lowest->index > aux->index)
		{
			pos = aux->pos;
			lowest = aux;
		}
		aux = aux->next;
	}
	return (pos);
}
void	set_target(t_stack **stack_a, t_stack **stack_b)
{
	t_node *aux_a;
	t_node *aux_b;
	t_node *lolita;

	// set_pos_aux(stack_a);
	// set_pos_aux(stack_b);
	aux_a = (*stack_a)->node_lst;
	aux_b = (*stack_b)->node_lst;
	while(1)
	{
		lolita = NULL;
		while(1)
		{
			if(aux_a->index > aux_b->index && (lolita == NULL || lolita->index > aux_a->index))
				lolita = aux_a;
			aux_a = aux_a->next;
			if(aux_a == (*stack_a)->node_lst)
				break;
		}
		if(lolita)
			aux_b->target_pos = lolita->pos;
		else
			aux_b->target_pos = find_smallest_pos(&(*stack_a)->node_lst);
		aux_b = aux_b->next;
		if (aux_b == (*stack_b)->node_lst)
			break;
	}
/* 	int		i;
	t_node	*target_node;
	t_node	*aux;

	aux = (*stack_b)->node_lst;
	i = 0;
	while (i < (*stack_b)->len)
	{
		target_node = find_target(stack_a, aux);
		if (target_node)
			aux->target = target_node;
		else
			aux->target = (*stack_a)->node_lst;
		i++;
		aux = aux->next;
	} */

}
