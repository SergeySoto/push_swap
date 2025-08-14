/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:09:27 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/08/14 17:09:32 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_array(char **array)
{
	int	len;
	len = 0;
	if (!array)
		return (0);
	while(array[len] != NULL)
		len++;
	return (len);
}