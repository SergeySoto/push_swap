#include "../libft/libft.h"
#include "../push_swap.h"

void	print_array(char **argv)
{
	int	i;

	i = 0;
	while(argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		printf("\n");
		i++;
	}
	i = 0;
	while(argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	print_list(int *len, int *list)
{
	int i = 0;
	while(i < *len)
	{
		printf("%d\n", list[i]);
		i++;
	}
}