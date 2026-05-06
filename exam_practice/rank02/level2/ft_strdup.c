#include <stdlib.h>

int len(const char *str)
{
	int i = -1;
	while (str[++i]);
	return i;
}

char *strdup(const char *src)
{
	if (!src)
		return NULL;
	int i = 0;
	int size = len(src);
	char *str = malloc(sizeof(char) * (size + 1));
	if (!str)	return NULL;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>

// int main()
// {
// 	const char	*a;
// 	a = "Hello World";
// 	char *b = strdup(a);
// 	printf("%s\n", b);
// }