/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:58:26 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/21 16:58:26 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *join_args(int argc, char **argv, char *initial_str)
{
	int		i;
	char	*joined_args;
	char	*temp;

	joined_args = initial_str;
	i = 2;
	while(i < argc)
	{
		temp = joined_args;
		joined_args = ft_strjoin(temp, " ");
		free(temp);
		temp = joined_args;
		joined_args = ft_strjoin(temp, argv[i]);
		free(temp);
		i++;
	}
	return (joined_args);
}

char	**get_input(int	argc, char **argv)
{
	//int		i;
	char	**num_array;
	char	*joined_args;
	//char	*temp;

	if (argc == 1)
		return (NULL);
	//crar un funcion que busque un caracter, de no encontrarlo. ERROR!
	joined_args = ft_strdup(argv[1]);
	if (argc > 2)
		joined_args = join_args(argc, argv, joined_args);
	num_array = ft_split(joined_args, ' ');
	free(joined_args);
	return (num_array);
}
