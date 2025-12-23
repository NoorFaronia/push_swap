#include "push_swap.h"

void	error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

long	ft_atol(char *str)
{
	long	num;
	int	s;

	num = 0;
	s = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	if (!*str)
		error();
	while (*str)
	{
		if (*str < '0' || *str > '9')
			error();
		num = num * 10 + (*str - '0');
		str++;
		if ((num * s) > INT_MAX || (num * s) < INT_MIN)
			error();
	}
	return (num * s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
