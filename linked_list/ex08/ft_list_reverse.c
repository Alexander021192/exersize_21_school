#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	while (nbr > 0)
	{
		begin_list = begin_list -> next;
		nbr--;
	}
	return (begin_list);
}

int	ft_list_size(t_list *begin_list)
{
	int len_list;

	len_list = 0;
	while (begin_list)
	{
		len_list++;
		begin_list = begin_list -> next;
	}
	return (len_list);
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list *tmp;
	t_list *tmp_next;
	t_list *begin;
	int size;

	begin = *begin_list;
	size = ft_list_size(begin);
	printf("\n ==> %d len of list <==\n\n", size);
	tmp_next = begin->next;
	begin->next = 0;
	
	while (size > 1)
	{
		tmp = begin;
		begin = tmp_next;
		tmp_next = begin->next;
		begin->next = tmp;
		size--;
	}
	*begin_list = begin;
}

t_list	*ft_create_elem(void *data)
{
	t_list	*begin;

	begin = (t_list*)malloc(sizeof(t_list));
	if (begin)
	{
		begin->data = data;
		begin->next = 0;
	}
	return (begin);	 
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_begin;

	new_begin = ft_create_elem(data);
	if (new_begin)
	{
		new_begin->next = *begin_list;
		*begin_list = new_begin;
	}
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int 	i;
	t_list 	*last;

	last = NULL;
	i = 0;
	if (size > 0)
	{
		last = ft_create_elem(strs[i]);
		i++;
		while (i < size)
		{
			ft_list_push_front(&last, strs[i]);
			i++;
		}
	}
	return (last);
}

void off_list(struct s_list *begin)
{
	while (begin)
	{
		printf(" %s", begin->data);
		begin = begin -> next;
	}
}

int main(int argc, char **argv)
{
	t_list *begin;
	if(argc < 2)
	{
		puts("wrong number arguments");
		return(-1);
	}
	begin = ft_list_push_strs(argc - 1, argv + 1);
	off_list(begin);
	printf("\n ==> %s its start of list <==\n\n", begin->data);

	ft_list_reverse(&begin);
	off_list(begin);
}