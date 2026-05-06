

#include <stdlib.h>

int	count_word(char *str)
{
	int count = 0, in_word= 0;

	while (*str)
	{
		if (*str == ' ')
			in_word = 0;
		else
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		}
		str++;
	}
	return count;
}

char *word_dup(char *str, int len)
{
	char *dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return NULL;
	int i =0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}


int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	**ft_split(char *str)
{
	if (!str)
		return NULL;

	int wc = count_word(str);

	char** res = malloc((wc + 1) * sizeof(char *));
	if (!res)
		return (NULL);

	int len_tmp = 0;
	int i = 0;

	while (*str == ' ')
		str++;

	while (i < wc)
	{
		while (is_space(*str))
			str++;

		len_tmp = 0;
		while (str[len_tmp] && !is_space(str[len_tmp]))
			len_tmp++;
		res[i] = word_dup(str, len_tmp);
		if (!res[i]) return NULL;
		str += len_tmp;
		i++;
	}
	res[i] = NULL;
	return (res);
}

// #include <stdio.h>
// int	main()
// {
// 	char str[] = "Ba na na Wiraya";
// 	char **res = ft_split(str);
// 	int i =0;
// 	while (res[i])
// 	{
// 		printf("[%d]: %s\n", i,res[i]);
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// }