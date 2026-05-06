#include <stdlib.h>
int len(const char *str)
{
	int i = -1;
	while (str[++i]);
	return i;
}

char *ft_strrev(char *str)
{
	if (!str)
		return (NULL);
	int size = len(str);
	int i =0;
	while (i <= size / 2)
	{
		char temp = str[i];
		str[i] = str[size - 1];
		str[size - 1] = temp;
		i++;
		size--;
	}
	return (str);
}


// #include <stdio.h>

// int main()
// {
// 	char str[] = "Wiraya";
// 	printf("%s\n", ft_strrev(str));
// }