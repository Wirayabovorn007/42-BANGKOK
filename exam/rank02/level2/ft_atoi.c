


int	ft_atoi(const char *str)
{
	int n = 0;

	int i =0;
	int sign = 1;

	while (str[i] == ' ') i++;
	while (str[i])
	{
		if (str[i] == '-')
		{
			sign = -sign;
			i++;
			continue ;
		}
		if (str[i] >= '0' && str[i] <= '9') n = n * 10 + (str[i] - '0'); 
		i++;
	}
	return n*sign;
}

// #include <stdio.h>

// int main()
// {
// 	printf("%d\n", ft_atoi("-    - - - -42"));
// }