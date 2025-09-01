/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:08:45 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/01 16:24:13 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of the stack a. Does nothing if there is only one or none. 
// sb (swap b) : Swap the first 2 elements at the top of the stack b. Does nothing if there is only one or none. 
// ss : sa and sb at the same time. 

void	swap(stack **stack)
{
	t_node	*first;
	t_node	*second;

	if ((*stack)->len < 2)
		return ;
	first = (*stack)->node_lst;
	second = first->next;
	first->prev->next = second;
	second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	(*stack)->node_lst = second;
}

// pa (push a): Takes the first element on top of b and puts it on a. Does nothing if b is empty. 
// pb (push b): Takes the first element on top of a and puts it on b. Does nothing if a is empty. 

void	if_dest(t_node *first, stack **dest)
{
	if ((*dest)->len == 0)
	{
		(*dest)->node_lst = first;
		first->next = first;
		first->prev = first;
	}
	else
	{
		first->next = (*dest)->node_lst;
		first->prev = (*dest)->node_lst->prev;
		(*dest)->node_lst->prev->next = first;
		(*dest)->node_lst->prev = first;
		(*dest)->node_lst = first;
	}
	(*dest)->len++;
}

void	push(stack **src, stack **dest)
{
	t_node	*first;

	if (!src || (*src)->len == 0)
		return ;
	first = (*src)->node_lst;
	if ((*src)->len == 1)
		(*src)->node_lst = NULL;
	else
	{
		(*src)->node_lst = first->next;
		first->prev->next = first->next;
		first->next->prev = first->prev;
	}
	(*src)->len--;
	if_dest(first, dest);
}

// ra (rotate a): Shifts all the elements of the stack a up by one position. The first element becomes the last. 
// rb (rotate b) : Shifts all the elements of the stack b one position upwards. The first element becomes the last one. 
// rr : ra and rb at the same time. 

void	rotate(stack **node)
{
	(*node)->node_lst = (*node)->node_lst->next;
}

// rra (reverse rotate a): Shifts all elements of the stack down one position. the stack a. The last element becomes the first. 
// rrb (reverse rotate b): Shifts all the elements of the stack b one position downwards. the stack b. The last element becomes the first. 
// rrr : rra and rrb at the same time.

void	reverse_rotate(stack **node)
{
	(*node)->node_lst = (*node)->node_lst->prev;
}