
#include <stdlib.h>

int	len(int n)
{
	int l = 0;

	while (n)
	{
		n /= 10;
		l++;
	}
	return l;
}

void	rev_arr(char *s)
{
	int i =0;

	while (s[i])
		i++;

	int j = 0;

	while (j < i / 2)
	{
		char temp = s[j];
		s[j] = s[i - j - 1];
		s[i - j - 1] = temp;
		j++;
	}
}

char	*ft_itoa(int nbr)
{
	char *res;
	int len_nbr = len(nbr);

	res = malloc(sizeof(char) * (len_nbr + 1));
	if (!res)
		return NULL;
	int i =0;
	while (nbr)
	{
		res[i] = (nbr % 10) + '0';
		nbr /= 10;
		i++;
	}
	rev_arr(res);
	return (res);
}

// #include <stdio.h>
// int main(int argc, char *argv[])
// {
// 	char *num = ft_itoa(12001);
// 	if (!num) return 1;
// 	printf("%s\n", num);
// 	free(num);
// }