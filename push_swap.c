/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:02:27 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/14 20:09:56 by ssoto-su         ###   ########.fr       */
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

// int	*parse_array(char **array)
// {
// 	int		i;
// 	int		*num_list;
// 	int		*len;

// 	*len = len_array(array);
// 	i = 0;
// 	num_list = (int *)malloc(*len * sizeof(int));
// 	if (!num_list)
// 		return (NULL);
// 	while(i < len)
// 	{
// 		if (!is_number_valid(*array[i]))
// 		{
// 			free_int(num_list);
// 			printf_error();
// 			return (NULL);
// 		}
// 		num_list[i] = ft_atol(*array[i]);
// 		i++;
// 	}
// 	return (num_list);
// }

// int	*parse_list(int	*num_list, int *len)
// {
// 	int	i;

// 	i = 0;
// 	while(i < len)
// 	{
// 		if(!is_int_in_range(num_list))
// 		{
			
// 		}
// 	}
// }

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
	
	char **arr = ft_split(&argv[1][0], ' ');
	int len = word_count(&argv[1][0], ' ');
	int *list = parse_arguments(len, arr); 
	int i = 0;
	while(i < len)
	{
		printf("%d\n", list[i]);
		i++;
	}
	i = 0;
	while(i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	free(list);

	return (0);
}
