#include "../includes/headers.h"

unsigned long long	getmult(unsigned long long nb, t_list *list)
{
	int	i;

	i = 40;
	while (i >= 0)
	{
		if (nb >= ft_atoi(list[i].nb))
			return (ft_atoi(list[i].nb));
		i--;
	}
	return (0);
}

void	ft_print(unsigned long long n, t_list *list, int *first)
{
	int			i;
	unsigned long long	mult;

	i = 0;
	mult = getmult(n, list);
	if (mult >= 100)
		ft_print(n / mult, list, first);
	if (*first == 0)
		write(1, " ", 1);
	*first = 0;
	while (ft_atoi(list[i].nb) != mult)
		i++;
	ft_putstr(list[i].val);
	if (mult != 0 && n % mult != 0)
		ft_print(n % mult, list, first);
}

int	valid_dict(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	return (1);
}

int checks(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2 || argc > 3)
		return (ft_puterr("Error\n"));
	if (argc == 3)
		j = 2;
	if (argc == 2)
		j = 1;
	if (argv[argc - j][0] == '-')
		return (ft_puterr("Error\n"));
	while (argv[argc - j][i] != '\0')
	{
		if (argv[argc - j][i] < '0' || argv[argc - j][i] > '9')
			return (ft_puterr("Error\n"));
		i++;
	}
	if (argc == 3 && valid_dict(argv[argc - 1]) == 0)
		return (ft_puterr("Dict Error\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_list				*list;
	int					first;
	unsigned long long	number;
	char				*dict;

	first = 1;
	dict = "numbers.dict";
	if (checks(argc, argv))
		return (1);
	number = ft_atoi(argv[argc - 1]);
	if (argc == 3)
	{
		dict = argv[argc - 1];
		number = ft_atoi(argv[argc - 2]);
	}
	list = logic(dict);
	ft_print(number, list, &first);
	write(1, "\n", 1);
	ft_free(list);
	return (0);
}