/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:02:27 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/11 19:00:58 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printf_error(void)
{
	write(2, "Error\n", 6);
	return ;
}

int	main(int	argc, char **argv)
{
	int		i;
	char	**num_array;
	char	*array_temp;
	//int		*list_num;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		num_array = ft_split(argv[1], ' ');
	else
	{
		i = 0;
		array_temp = argv[1];
		while(i < argc - 1)
		{
			array_temp = ft_strjoin(array_temp, " ");
			array_temp = ft_strjoin(array_temp, argv[i + 1]);
			i++;
		}
	}
	//push_swap();
	return (0);
}

// int	main(int	argc, char **argv)
// {
// 	int	i;
// 	char	**num_array;
// 	int		*list_num;
// 	if (argc == 1)
// 		write(1, "\n", 1);
// 	else if (argc == 2)
// 		num_array = ft_split(argv + 1, ' ');
// 	if (!is_number_valid(num_array))
// 	{
// 		ft_printf_error();
// 		return (0);
// 	}
// 	i = 1;
// 	while(i < argc - 1)
// 	{
// 		list_num = parse_arguments(argc, argv[i]);
// 		i++;
// 	}
// 	push_swap();
// 	return (0);
// }
