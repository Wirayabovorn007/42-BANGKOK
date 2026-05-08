#include <stdlib.h>

int is_in_reject(char c, const char *reject)
{
	int i =-1;
	while (reject[++i])
		if (c == reject[i]) return 1;
	return 0;
}

size_t	ft_strcspn(const char *s1, const char *reject)
{
	size_t	size = 0;
	int i =0;
	while (s1[i])
	{
		if (is_in_reject(s1[i], reject))
			break ;
		i++;
		size++;
	}
	return size;
}

// #include <stdio.h>

// int main() {
//   char myStr[] = "Learn C++, Java and Python!";
//   int pos = ft_strcspn(myStr, "+.!?");
//   printf("%d", pos);
//   return 0;
// }