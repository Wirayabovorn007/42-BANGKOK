

#include <unistd.h>

int	ft_strlen(char *str)
{
	int i =-1;
	while (str[++i]);
	return i;
}

int main(int argc, char *argv[])
{
	if (!argv[1] || argc != 3)
	{
		write(1, "\n", 1);
		return 1;
	}

	int j=0, i=0;
	char *str = argv[1];
	char *str2 = argv[2];
	int len_str = ft_strlen(str);

	while (str2[j] && str[i])
	{
		if (str2[j] == str[i])
			i++;
		j++;
	}
	if (str[i] == '\0')
		write(1, "1", 1);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
