/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:02:27 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/06 16:34:10 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int	argc, char **argv)
{
	if (argc == 1)
		write(1, "\n", 1);
	else
		if (argc >= 2)
		{
			if(is_number_valid())
				if(is_int_in_range())
					if(!has_duplicates())
			push_swap();
		}
	return (0);
}