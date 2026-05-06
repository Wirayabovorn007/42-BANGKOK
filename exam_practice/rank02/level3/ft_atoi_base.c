

int	is_valid(char c, int base)
{
	char *lcbase = "0123456789abcdef";
	char *ucbase = "0123456789ABCDEF";
	int i = 0;

	while (i < base)
	{
		if (c == lcbase[i] || c == ucbase[i]) return 1;
		i++;
	}
	return 0;
}

int	ft_atoi_base(const char *str, int str_base)
{
	int res = 0, sign = 1, i = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' && str[i+1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}

	while (str[i] && is_valid(str[i], str_base))
	{
		res = res * str_base;

		if (str[i] >= '0' && str[i] <= '9')
			res += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'z')
			res += str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			res += str[i] - 'A' + 10;
		i++;
	}
	return (res *sign);
}

// #include <stdio.h>
// int	main(int ac, char **av)
// {
// 	(void) ac;
// 	(void) av;
// 	if (ac == 3)
// 	{
// 		printf("%d", ft_atoi_base(av[1], ft_atoi_base(av[2], 10)));
// 		return (0);
// 	}
// }