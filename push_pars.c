/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:01:38 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/13 17:44:04 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number_valid(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	if (len > 11)
		return (0);
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

long	ft_atol(char *str)
{
	int		i;
	int		symbol;
	long	res;
	if (!str)
		return (0);
	res = 0;
	symbol = 1;
	i = 0;
	while(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			symbol *= -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * symbol);
}

int	is_int_in_range(long num)
{
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	*parse_arguments(int count, char **array)
{
	int		i;
	int		*num_list;
	long	num_temp;

	i = 0;
	num_list = (int *)malloc(count * sizeof(int));
	if (!num_list)
		return (NULL);
	while(i < count)
	{
		if (!is_number_valid(*array[i]))
		{
			free(num_list);
			return (NULL);
		}
		num_temp = ft_atol(*array[i]);
		if (!is_int_in_range(num_temp))
		{
			free(num_list);
			return (NULL);
		}
		num_list[i] = (int)num_temp;
		i++;
	}
	return (num_list);
}

int	has_duplicates(int size, int *num_list)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while(j < size)
		{
			if (num_list[i] == num_list[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
