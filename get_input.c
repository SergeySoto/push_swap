
#include "push_swap.h"

char *new_join_args(int argc, char **argv)
{
	int		i;
	char	*joined_args;
	char	*temp;

	i = 2;
	while(i < argc)
	{
		temp = joined_args;
		joined_args = ft_strjoin(joined_args, " ");
		free(temp);
		temp = joined_args;
		joined_args = ft_strjoin(temp, argv[i]);
		free(temp);
		temp = joined_args;
		joined_args = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	return (joined_args);
}

char	**new_get_input(int	argc, char **argv)
{
	//int		i;
	char	**num_array;
	char	*joined_args;
	//char	*temp;

	joined_args = NULL;
	if (argc == 1)
		return (NULL);
	else if (argc == 2)
		joined_args = ft_strdup(argv[1]);
	joined_args = new_join_args(argc, argv);
	num_array = ft_split(joined_args, ' ');
	free(joined_args);
	return (num_array);
}

int	main(int argc, char **argv)
{
	int len;
	char **arr = new_get_input(argc, argv);
	if (!arr)
	{
		free_array(arr);
		return (0);
	}
	ft_putstr_fd("Este es el array:\n", 2);
	print_array(arr);
	int *list = parse_array(arr, &len);
	if (!list)
	{
		// free_array(arr);
		// free_int(list);
		return (0);
	}
	ft_putstr_fd("Esta es la lista de int:\n", 2);
	print_list(len, list);
	printf("la longitud: %d\n", len);
	if (!parse_list(list, &len))
	{
		free_array(arr);
		free_int(list);
		printf_error();
		return (0);
	}
	free_int(list);
	free_array(arr);
	//-----------------------------------------

	return (0);
}