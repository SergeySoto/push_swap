/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:17:58 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/02 16:53:41 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <limits.h>
# include <unistd.h>

typedef struct t_node
{
	int				data;
	int				index;
	int				cost;
	struct t_node	*prev;
	struct t_node	*next;
}					t_node;

typedef struct stack
{
	struct t_node	*node_lst;
	int				len;
}					stack;

t_node	*ft_newnode(int data, int index);
void	add_node_back(t_node **lst, t_node *new);
t_node	*ft_last_node(t_node *node);
stack	*create_node_list(int *len, long *list);
void	lstiter(t_node *lst, void (f)(t_node *));
void	list_to_circle(stack **head);
void	swap(stack **stack);
void	sa(stack **stack_a);
void	sb(stack **stack_b);
void	ss(stack **stack_a, stack **stack_b);
void	if_dest(t_node *first, stack **dest);
void	push(stack **src, stack **dest);
void	pa(stack **stack_a, stack **stack_b);
void	pb(stack **stack_b, stack **stack_a);
void	rotate(stack **stack_a);
void	ra(stack **stack_a);
void	rb(stack **stack_b);
void	reverse_rotate(stack **node);
void	rra(stack **stack_a);
void	rrb(stack **stack_b);
void	rr(stack **stack_a, stack **stack_b);
void	rrr(stack **stack_a, stack **stack_b);
void	sort_two(stack **stack);
void	sort_three(stack **stack);
int		has_duplicates(int *size, long *num_list);
int		is_int_in_range(long num);
long	ft_atol(char *str);
int		is_number_valid(char *str);
char	**get_input(int argc, char **argv);
int		len_array(char **array);
void	printf_error(void);
void	print_array(char **argv);
void	print_list(int len, long *list);
void	print_node(t_node *node);
void	free_array(char **str);
void	free_str(char *str);
void	free_long(long *str);
void	free_stack(stack *node);
char	*join_args(int argc, char **argv, char *initial_str);
char	**get_input(int	argc, char **argv);
int		only_space(char *argv);
long	*parse_array(char **array, int *len);
int		parse_list(long	*num_list, int *len);
t_node	*find_last_node(t_node *stack);

#endif