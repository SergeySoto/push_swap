/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:17:58 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/29 19:45:47 by ssoto-su         ###   ########.fr       */
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

t_node	*ft_newnode(int data, int index);
void	add_node_back(t_node **lst, t_node *new);
t_node	*ft_last_node(t_node *node);
t_node	*create_node_list(int *len, long *list);
void	lstiter(t_node *lst, void (f)(t_node *));
void	list_to_circle(t_node **head);
void	swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	push(t_node **src, t_node **dest, int *len1, int *len2);
void	pa(t_node **stack_a, t_node **stack_b, int *len1, int *len2);
void	pb(t_node **stack_b, t_node **stack_a, int *len1, int *len2);
void	rotate(t_node **stack_a);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	reverse_rotate(t_node **node);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
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
void	free_node(t_node *node, int *len);
char	*join_args(int argc, char **argv, char *initial_str);
char	**get_input(int	argc, char **argv);
int		only_space(char *argv);
long	*parse_array(char **array, int *len);
int		parse_list(long	*num_list, int *len);
t_node	*find_last_node(t_node *stack);

#endif