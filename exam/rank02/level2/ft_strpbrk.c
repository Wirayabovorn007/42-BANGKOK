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

int is_in_accpt(char c, const char *accept)
{
	int i =-1;
	while (accept[++i])
		if (c == accept[i]) return 1;
	return 0;
}

char	*ft_strpbrk(const char *s1, const char *s2)
{
	char *str = strdup(s1);
	while (*str)
	{
		if (is_in_accpt(*str, s2)) return str;
		str++;
	}
	return NULL;
}

// #include <stdio.h>

// int main() {
//   char myStr[] = "I think 4096 bytes should be enough";
//   char *pos = ft_strpbrk(myStr, "0123456789");
//   if (pos != NULL) {
//     printf("%s", pos);
//   }
//   return 0;
// }