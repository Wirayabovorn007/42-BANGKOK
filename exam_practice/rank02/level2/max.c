int max(int *tab, unsigned int len)
{
	if (!tab || len <= 0) return 0;

	int i = 0;
	int max = tab[i];
	while (i < len - 1)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return max;
}