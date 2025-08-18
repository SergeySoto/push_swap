/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:02:27 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/18 19:50:57 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	word_count(char const *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	flag = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		if (s[i] == c)
		{
			flag = 0;
		}
		i++;
	}
	return (count);
}

char	**get_input(int	argc, char **argv)
{
	int		i;
	char	**num_array;
	char	*array_temp;
	char	*point_temp;
	if (argc == 1)
		return (NULL);
	else if (argc == 2)
		array_temp = argv[1];
	i = 2;
	while(i < argc)
	{
		point_temp = array_temp;
		array_temp = ft_strjoin(array_temp, argv[i]);
		free(point_temp);
		point_temp = array_temp;
		array_temp = ft_strjoin(array_temp, " ");
		free(point_temp);
		i++;
	}
	num_array = ft_split(array_temp, ' ');
	//free(array_temp);
	return (num_array);
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

int	main(int argc, char **argv)
{
	(void)argc;
	// (void)*argv;

	// write(1, "puta!\n", 6);
	// printf_error();
	// ft_printf("is_number_valid: %d\n", is_number_valid(ft_strtrim("     123  	", " \n\t")));
	// ft_printf("is_number_valid: %d\n", is_number_valid(ft_strtrim("     1223f	", " \n\t")));
	// ft_printf("is_number_valid: %d\n", is_number_valid(ft_strtrim("			   -12123		", " \n\t")));
	// ft_printf("\n");
	// printf("ft_atol NUM_MIN: %ld\n", ft_atol("-2147483648"));
	// printf("ft_atol NUM_MAX: %ld\n", ft_atol("2147483647"));
	// printf("ft_atol NUM_MIN: %ld\n", ft_atol("-2147483649"));
	// printf("ft_atol NUM_MAX: %ld\n", ft_atol("2147483648"));
	// ft_printf("\n");
	// ft_printf("is_int_in_range: %d\n", is_int_in_range(ft_atol("-2147483648")));
	// ft_printf("is_int_in_range: %d\n", is_int_in_range(ft_atol("2147483647")));
	// ft_printf("is_int_in_range: %d\n", is_int_in_range(ft_atol("-2147483649")));
	// ft_printf("is_int_in_range: %d\n", is_int_in_range(ft_atol("2147483648")));
	//-----------------------------------------
	int len;
	char **arr = get_input(argc, argv);
	if (!arr)
	{
		free_array(arr);
		return (0);
	}
	print_array(arr);
	int *list = parse_array(arr, &len);
	if (!list)
	{
		free_array(arr);
		free_int(list);
		return (0);
	}
	print_list(len, list);
	printf("la longitud: %d\n", len);
	if (!parse_list(list, &len))
	{
		free_array(arr);
		free_int(list);
		return (0);
	}
	free_int(list);
	free_array(arr);
	//-----------------------------------------

	return (0);
}
