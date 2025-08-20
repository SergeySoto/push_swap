/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:01:38 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/18 18:02:55 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while(str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_int_in_range(long num)
{
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	*parse_array(char **array, int *len)
{
	int		i;
	int		*num_list;

	if (!array || !len)
		return (NULL);
	*len = len_array(array);
	i = 0;
	num_list = (int *)malloc(*len * sizeof(int));
	if (!num_list)
		return (NULL);
	while(i < len[0])
	{
		if (!is_number_valid(array[i]))
		{
			free_int(num_list);
			free_array(array);
			printf_error();
			return (NULL);
		}
		num_list[i] = ft_atol(array[i]);
		i++;
	}
	return (num_list);
}

int	parse_list(int	*num_list, int *len)
{
	int	i;

	i = 0;
	while(i < *len)
	{
		if(!is_int_in_range(num_list[i]))
			return (0);
		i++;
	}
	if(has_duplicates(len, num_list))
		return (0);
	return (1);
}

// int	*parse_arguments(int count, char **array)
// {
// 	int		i;
// 	int		*num_list;
// 	long	num_temp;

// 	i = 0;
// 	num_list = (int *)malloc(count * sizeof(int));
// 	if (!num_list)
// 		return (NULL);
// 	while(i < count)
// 	{
// 		if (!is_number_valid(array[i]))
// 		{
// 			printf_error();
// 			free_int(num_list);
// 		}
// 		num_temp = ft_atol(array[i]);
// 		if (!is_int_in_range(num_temp))
// 		{
// 			free(num_list);
// 			printf_error();
// 		}
// 		num_list[i] = (int)num_temp;
// 		i++;
// 	}
// 	return (num_list);
// }

int	has_duplicates(int *size, int *num_list)
{
	int	i;
	int	j;

	i = 0;
	while (i < *size)
	{
		j = i + 1;
		while(j < *size)
		{
			if (num_list[i] == num_list[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
