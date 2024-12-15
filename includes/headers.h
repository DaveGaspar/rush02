#ifndef HEADERS_H
# define HEADERS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	char	*nb;
	char	*val;
}		t_list;

unsigned long long		ft_atoi(const char *str);
void					ft_putstr(char *str);
int 					ft_puterr(char *str);
void					ft_free(t_list *ptr);
char					*get_number(char *text, int *start_i);
char					*get_value(char *text, int *start_i);
int						ft_strcmp(char *s1, char *s2);
t_list					*logic(char *file);

#endif