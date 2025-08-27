/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:08:45 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/27 19:53:37 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of the stack a. Does nothing if there is only one or none. 
void	sa(t_node *stack_a, int	*len)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	first = find_node(0, stack_a);
	second = find_node(1, stack_a); 
	last = find_node(*len - 1, stack_a);
	first->next = last;
	first->prev = second;
	second->next = first;
	second->prev = last;
	last->next = second;
	last->prev = first;
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