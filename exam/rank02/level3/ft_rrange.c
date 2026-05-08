
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

int *st_rrange(int start, int end)
{
	int	*arr;
	arr = ft_range(end, start);
	if (!arr)
		return (NULL);
	return arr;
}

// #include <stdio.h>
// int main()
// {
// 	int start = 0;
// 	int end = -3;
// 	int *arr = st_rrange(start, end);
// 	if (!arr) return 1;
// 	int size = 0;
// 	int i = 0;
// 	if (end - start < 0)
// 		size = ((end - start) * -1) + 1;
// 	else
// 		size = end - start + 1;
// 	printf("Arr: ");
// 	while (i < size)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	free(arr);
// }
