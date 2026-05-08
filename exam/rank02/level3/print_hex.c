

#include <unistd.h>

int	ft_atoi(char *str)
{
	int i = 0;
	int sign = 1;
	int res = 0;

	while (str[i])
	{
		if (str[i] == '-')
		{
			sign = -sign;
		}
		else
		{
			res *= 10 + (str[i] - '0');
		}
		i++;
	}
	return (res * sign);
}

void	pussy(int n)
{
	char *digits = "0123456789abcdef";

	if (n >= 16)
		pussy(n / 16);
	n = digits[n % 16];
	write(1, &n, 1);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
        pussy(ft_atoi(av[1]));
    write(1, "\n", 1);
    return (0);
}