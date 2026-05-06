

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*arr;

	int	size;

	if (end - start < 0)
		size = ((end - start) * -1) + 1;
	else
		size = end - start + 1;

	arr = malloc(sizeof(int) * size);
	if (!arr) return NULL;

	int i = 0;
	while (i < size)
	{
		if (start < end)
			arr[i] = start++;
		else
			arr[i] = start--;
		i++;
	}
	return arr;
}