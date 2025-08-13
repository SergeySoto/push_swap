/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:17:58 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/12 20:59:21 by ssoto-su         ###   ########.fr       */
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

t_node	*ft_newnode(int data);
void	ft_add_node_back(t_node **node, t_node *new);
t_node	*ft_last_node(t_node *node);
int		has_duplicates(int size, int *num_list);
int		*parse_arguments(int size, char **str);
int		is_int_in_range(long num);
long	ft_atol(char *str);
int		is_number_valid(char *str);
void	printf_error();
char 	**get_input(int argc, char **argv);
int		word_count(const char *s, char c);

#endif