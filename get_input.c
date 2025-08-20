
#include "push_swap.h"

// char	**get_input(int	argc, char **argv)
// {
// 	int		i;
// 	char	**num_array;
// 	char	*joined_args;
// 	char	*temp;

// 	joined_args = NULL;
// 	if (argc == 1)
// 		return (NULL);
// 	else if (argc >= 2)
// 		joined_args = ft_strdup(argv[1]);
// 	i = 2;
// 	while(i < argc)
// 	{
// 		temp = joined_args;
// 		joined_args = ft_strjoin(joined_args, " ");
// 		free(temp);
// 		temp = joined_args;
// 		joined_args = ft_strjoin(temp, argv[i]);
// 		free(temp);
// 		temp = joined_args;
// 		joined_args = ft_strjoin(temp, " ");
// 		free(temp);
// 		i++;
// 	}
// 	num_array = ft_split(joined_args, ' ');
// 	free(joined_args);
// 	return (num_array);
// }

char *new_join_args(int argc, char **argv, char *initial_str)
{
	int		i;
	char	*joined_args;
	char	*temp;

	joined_args = initial_str;
	i = 2;
	while(i < argc)
	{
		temp = joined_args;
		joined_args = ft_strjoin(temp, " ");
		free(temp);
		temp = joined_args;
		joined_args = ft_strjoin(temp, argv[i]);
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

	if (argc == 1)
		return (NULL);
	joined_args = ft_strdup(argv[1]);
	if (argc > 2)
		joined_args = new_join_args(argc, argv, joined_args);
	num_array = ft_split(joined_args, ' ');
	free(joined_args);
	return (num_array);
}
