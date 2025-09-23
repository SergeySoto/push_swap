/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:37:19 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/23 16:30:59 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack **stack)
{
	if ((*stack)->len == 2)
	{
		if ((*stack)->node_lst->data > (*stack)->node_lst->next->data)
			sa(stack);
	}
}

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	if ((*stack)->len == 3)
	{
		a = (*stack)->node_lst->data;
		b = (*stack)->node_lst->next->data;
		c = (*stack)->node_lst->next->next->data;
		if (a < b && b < c)
			return ;
		if (a > b && a > c)
			ra(stack);
		else if (b > a && b > c)
			rra(stack);
		a = (*stack)->node_lst->data;
		b = (*stack)->node_lst->next->data;
		if (a > b)
			sa(stack);
	}
}

static int stack_size(t_stack **stack)
{
	t_node *aux;
	int i;
	i = 0;
	aux = (*stack)->node_lst;
	while(1)
	{
		i++;
		aux = aux->next;
		if((*stack)->node_lst == aux)
			break;
	}
	return(i);
}



void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*current;
	int		i;
	int		size;

	current = (*stack_a)->node_lst;
	size = stack_size(stack_a);
	i = size;
	//pb(stack_a, stack_b);
	//pb(stack_a, stack_b);
	while(i)
	{
		if((*stack_a)->node_lst->index < (size / 2) + (size % 2))
			pb(stack_a,stack_b);
		else
			ra(stack_a);
		//current = current->next;
		i--;
	}
	
	while(1)
	{
		if((*stack_a)->node_lst->index < size - 2)
			pb(stack_a,stack_b);
		else
			ra(stack_a);
		if(stack_size(stack_a) == 3)
			break;
	}
/* 	while ((*stack_a)->len > 3)
	{
		set_target_prev(stack_a, stack_b);
		set_cost_a(stack_a);
		set_cost_b_for_A(stack_a, stack_b);
		set_total_cost(stack_a, stack_b);
		move_cheapest_to_top(stack_a, stack_b);
		pb(stack_a, stack_b);
	} */
	sort_three(stack_a);
	//lstiter((*stack_a)->node_lst, print_node_A);
}

int node_size(t_node **stack)
{
	t_node *aux;
	int i;
	i = 0;
	aux = (*stack);
	while(1)
	{
		i++;
		aux = aux->next;
		if((*stack) == aux)
			break;
	}
	return(i);
}

static int calc_cost(t_node **stack,int pos)
{
	int ret;
	int size;
	size = node_size(stack);
	ret = 0;
	if(pos > node_size(stack) / 2)
		ret = (-1) * (size - pos);
	else
		ret = pos;
	return(ret);
}

static void set_cost(t_stack **stack_a,t_stack **stack_b)
{
	//t_stack *aux_a;
	//t_stack *aux_b;
	//int i = 0;
	t_node	*aux_a;
	t_node	*aux_b;

	//aux_a = (*stack_a);
	//aux_b = (*stack_b);
	aux_a = (*stack_a)->node_lst;
	aux_b = (*stack_b)->node_lst;
	while(1)
	{
		aux_b->cost_a = calc_cost(&aux_a,aux_b->target_pos);
		//printf("cost a %d\n",aux_b->node_lst->cost_a);
		aux_b->cost_b = calc_cost(&aux_b,aux_b->pos);
		//printf("cost b %d\n",aux_b->node_lst->cost_b);
		//printf("aux_b %d\n",aux_b->node_lst->index);
		//printf("stack b antes iterator %d\n",(*stack_b)->node_lst->index);
		aux_b = aux_b->next;
		//printf("aux_b post iterator %d\n",aux_b->node_lst->index);
		//printf("stack b post iterator %d\n",(*stack_b)->node_lst->index);
		if(aux_b == (*stack_b)->node_lst)
			break;
		//printf("vueltas de i %d\n",i);
		//i++;
	}
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*cheap;
	while ((*stack_b)->len > 0)
	{
		//set_pos((*stack_a)->node_lst);
		set_pos((*stack_a)->node_lst);
		set_pos((*stack_b)->node_lst);
		//set_pos((*stack_b)->node_lst);		
		set_target(stack_a, stack_b);
		set_cost(stack_a,stack_b);
		// set_cost_b(stack_b);
		// set_cost_a_for_B(stack_a, stack_b);
		set_total_cost(stack_b, stack_a);
		cheap = cheapest(stack_b);
		if (cheap)
		{
			//printf("--------------Stack A--------------\n");
			//lstiter((*stack_a)->node_lst, print_node_B);
			//printf("--------------Stack B--------------\n");
			//lstiter((*stack_b)->node_lst, print_node_B);
			cheapest_path(stack_b, stack_a, cheap);
			//set_path(stack_b, stack_a, cheap);
		}
		pa(stack_b, stack_a);
	}
}

void	put_small_top(t_stack **stack_a)
{
	// t_node	*current;
	// t_node	*smallest;
	// //set_pos((*stack_a)->node_lst);
	// current = (*stack_a)->node_lst;
	// smallest = find_smallest_node_B(stack_a);
	
 	// while (current->prev->next == (*stack_a)->node_lst)
	// {
	// 	if (smallest->pos > (*stack_a)->len / 2)
	// 		rra(stack_a);
	// 	else if (smallest->pos < (*stack_a)->len / 2)
	// 		ra(stack_a);
	// 	if (smallest == (*stack_a)->node_lst)
	// 		break ;
	// 	current = current->next;
	// } 


	t_node	*current;
	t_node	*smallest;
	//set_pos((*stack_a)->node_lst);
	current = (*stack_a)->node_lst;
	smallest = find_smallest_node_B(stack_a);
	
 	while (smallest->pos > 0)
	{
		if (smallest->pos >= (*stack_a)->len / 2)
			rra(stack_a);
		else if (smallest->pos < (*stack_a)->len / 2)
			ra(stack_a);
		if (smallest == (*stack_a)->node_lst)
			break ;
		current = current->next;
	} 



	
	// int	i;

	// i = 0;
	// if (smallest->pos <= (stack_size(stack_a) / 2))
	// {
	// 	while (i < smallest->pos)
	// 	{
	// 		ra(stack_a);
	// 		i++;
	// 	}
	// }
	// else
	// {
	// 	i = smallest->pos;
	// 	while (i < stack_size(stack_a))
	// 	{
	// 		rra(stack_a);
	// 		i++;
	// 	}
	// }
}

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	push_a(stack_a, stack_b);
	put_small_top(stack_a);
}
