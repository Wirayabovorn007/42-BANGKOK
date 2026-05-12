
#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
  int i = 0;
  if (!s) return NULL;
  
  while (s[i])
  {
	if (s[i] == (char)c) return (s + i);
	i++;
  }
  if ((char) c == '\0') return (s + i);
  return NULL;
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i = 0;
	if (!src && ! dest) return NULL;
  while(i < n)
    {
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
  return dest;
}

size_t ft_strlen(char *s)
{
  size_t res = 0;
  if (!s) return 0;
  while (s[res])
  {
    res++;
  }
  return res;
}

int str_append_mem(char **s1, char *s2, size_t size2)
{
  size_t size1 = ft_strlen(*s1);
  char *tmp = malloc(size2 + size1 + 1);
  if (!tmp)
	{
		free(*s1);
		*s1 = NULL;
		return 0;
	}
  if (*s1) ft_memcpy(tmp, *s1, size1);
  ft_memcpy(tmp + size1, s2, size2);
  tmp[size1 + size2] = '\0';
  free(*s1);
  *s1 = tmp;
  return 1; 
}

int str_append_str(char **s1, char *s2)
{
  return str_append_mem(s1, s2, ft_strlen(s2));
}


void *ft_memmove(void *dest, const void *src, size_t n)
{
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;

  if (!d && !s) return NULL;

  if (d < s) ft_memcpy(d, s, n);
  else
  {
	while (n > 0)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
  }
  return dest;
}

char *get_next_line(int fd)
{
	static char b[BUFFER_SIZE + 1] = "";
	char *ret = NULL;
	int read_ret;
	char *tmp;
	if (fd < 0 || BUFFER_SIZE <= 0) return NULL;
  while(1)
  {
	tmp = ft_strchr(b, '\n');
	if (tmp)
	{
		if (!str_append_mem(&ret, b, tmp - b + 1)) 
			return NULL;
		ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
		return ret;
	}
	if (b[0] != '\0')
	{
		if (!str_append_str(&ret, b))
			return NULL;
		b[0] = '\0';
	}
	read_ret = read(fd, b, BUFFER_SIZE);
	if (read_ret < 0)
	{
		free(ret);
		b[0] = '\0';
		return NULL;
	}
	if (read_ret == 0) return ret;
	b[read_ret] = '\0';
  }
}

