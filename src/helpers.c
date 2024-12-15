#include "../includes/headers.h"

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

unsigned long long	ft_atoi(const char *str)
{
	unsigned long long	result;
	int			sign;

	result = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		++str;
	}
	return (result * sign);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, (str + i), 1);
		i++;
	}
}

int ft_puterr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, (str + i), 1);
		i++;
	}
	return (1);
}

void ft_free(t_list *ptr)
{
	int	i;

	i = 0;
	while (i < 41)
	{
		free(ptr[i].nb);
		free(ptr[i].val);
		i++;
	}
	free(ptr);
}