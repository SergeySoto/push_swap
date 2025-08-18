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
}

void	print_list(int len, int *list)
{
	int i = 0;
	while(i < len)
	{
		printf("%d\n", list[i]);
		i++;
	}
}