/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:10:28 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/09/02 18:45:37 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*parse_input(int argc, char **argv, int *len)
{
	char	**arr;
	long	*list;

	arr = get_input(argc, argv);
	if (!arr)
		return (0);
	list = parse_array(arr, len);
	if (!list)
		return (0);
	if (!parse_list(list, len))
	{
		free_long(list);
		free_array(arr);
		printf_error();
		return (0);
	}
	free_array(arr);
	return (list);
}

