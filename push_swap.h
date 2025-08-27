/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:17:58 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/27 18:48:06 by ssoto-su         ###   ########.fr       */
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
void	list_to_circle(t_node **head);

#endif