#include "../includes/headers.h"

long long	getmult(int nb, t_list *tab)
{
	int	i;

	i = 36;
	while (i >= 0)
	{
		if (nb >= ft_atoi(tab[i].nb))
			return (ft_atoi(tab[i].nb));
		i--;
	}
	return (0);
}

void	ft_print(int n, t_list *tab, int *first)
{
	int			i;
	long long	mult;

	i = 0;
	mult = getmult(n, tab);
	if (mult >= 100)
		ft_print(n / mult, tab, first);
	if (*first == 0)
		write(1, " ", 1);
	*first = 0;
	while (ft_atoi(tab[i].nb) != mult)
		i++;
	ft_putstr(tab[i].val);
	if (mult != 0 && n % mult != 0)
		ft_print(n % mult, tab, first);
}

int	valid_dict(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list		*tab;
	int			*first;
	int			addr_first;
	long long	number;
	char		*dict;

	addr_first = 1;
	first = &addr_first;
	if (argc == 3 && valid_dict(argv[argc - 2]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else if (argc == 3)
		dict = argv[argc - 2];
	else
		dict = "numbers.dict";
	tab = process(dict);
	number = process_number(argv[argc - 1]);
	ft_print(number, tab, first);
	write(1, "\n", 1);
	return (0);
}