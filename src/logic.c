#include "../includes/headers.h"

char	*get_number(char *text, int *start_i)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * 40);
	while (text[*start_i] != ':')
	{
		str[i] = text[*start_i];
		(*start_i)++;
		i++;
	}
	return (str);
}

char	*get_value(char *text, int *start_i)
{
	int		i;
	char	*str;

	i = 0;
	(*start_i) += 2;
	str = (char *)malloc(sizeof(char) * 100);
	while (text[*start_i] != '\n')
	{
		str[i] = text[*start_i];
		(*start_i)++;
		i++;
	}
	(*start_i)++;
	return (str);
}

long long	process_number(char *num)
{
	long long	number;

	number = ft_atoi(num);
	if (number < 0)
	{
		write(1, "minus ", 6);
		number *= -1;
	}
	return (number);
}

t_list	*process(char *file)
{
	int		i;
	int		fd;
	t_list	*tab;
	char	*text;
	int		start_i;

	fd = open(file, O_RDONLY);
	tab = malloc(sizeof(t_list) * 41);
	if (fd == -1 || !(tab))
		return (0);
	text = malloc(sizeof(char) * 5000);
	if (!(text))
		return (0);
	read(fd, text, 5000);
	i = 0;
	start_i = 0;
	while (i < 41)
	{
		tab[i].nb = get_number(text, &start_i);
		tab[i].val = get_value(text, &start_i);
		i++;
	}
	close(fd);
	return (tab);
}