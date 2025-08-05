/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:01:38 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/05 19:27:20 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number_valid(char *str)
{
	int	i;

	i = 0;
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

int	has_duplicates(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while(str[i])
	{
		j = i + 1;
		while(str[j])
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long	ft_atol(char *str)
{
	int		i;
	int		symbol;
	long	res;

	res = 0;
	symbol = 1;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
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

int	is_int_in_range(char *str)
{
	long num;

	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

//funcion que parsea todos los argumentos en un solo array de int
int	parse_arguments(char** str, int size)
{
	int	i;
	int	*numbers;
	i = 0;

	numbers = malloc((int*)sizeof(size));
	while(i < size)
	{
		numbers[i] = ft_atol(str[i]);
		i++;
	}
	return (numbers);
}