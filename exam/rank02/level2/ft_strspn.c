

#include <stdlib.h>

int is_in_accpt(char c, const char *accept)
{
	int i =-1;
	while (accept[++i])
		if (c == accept[i]) return 1;
	return 0;
}

size_t	ft_strspn(const char *s1, const char *accept)
{
	size_t i;

	i = -1;
	while (is_in_accpt(s1[++i], accept));
	return i;
}

// #include <stdio.h>

// int main() {
// 	char myStr[] = "4096 bytes should be enough";
// 	int pos = ft_strspn(myStr, "0123456789");
// 	printf("%d", pos);
// 	return 0;
// }
