#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	is_num(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
	return (1);
}

int	check_input(char *argv[], int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (!is_num(argv[i]))
			return (0);
		if (ft_atoi(argv[i]) <= 0 && i != 4)
			return (0);
		if (i == 4 && ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}