#include "../libft/libft.h"
#include "../push_swap.h"

void	print_array(int	argc, char **argv)
{
	char **arr = get_input(argc, argv);
	int	i = 0;

	i = 0;
	while(arr[i])
	{
		ft_putstr_fd(arr[i], 1);
		i++;
	}
	i = 0;
	while(arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
