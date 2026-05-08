
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	t_list *ptr = begin_list;
	int i = 0;
	while (ptr->next)
	{
		ptr = ptr->next;
		i++;
	}
	return i;
}