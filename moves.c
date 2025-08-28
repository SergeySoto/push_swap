/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:08:45 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/28 19:31:44 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of the stack a. Does nothing if there is only one or none. 
void	sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;

	first = *stack_a;
	second = first->next;

	first->prev->next = second;
	second->next->prev = first;

	first->next = second->next;
	second->prev = first->prev;

	second->next = first;
	first->prev = second;
	*stack_a = second;
}
// sb (swap b) : Swap the first 2 elements at the top of the stack b. Does nothing if there is only one or none. 

// ss : sa and sb at the same time. 

// pa (push a): Takes the first element on top of b and puts it on a. Does nothing if b is empty. 

// pb (push b): Takes the first element on top of a and puts it on b. Does nothing if a is empty. 

// ra (rotate a): Shifts all the elements of the stack a up by one position. The first element becomes the last. 

// rb (rotate b) : Shifts all the elements of the stack b one position upwards. The first element becomes the last one. 

// rr : ra and rb at the same time. 

// rra (reverse rotate a): Shifts all elements of the stack down one position. the stack a. The last element becomes the first. 

// rrb (reverse rotate b): Shifts all the elements of the stack b one position downwards. the stack b. The last element becomes the first. 

// rrr : rra and rrb at the same time.