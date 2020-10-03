/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:47:12 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/24 11:00:25 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		printf("%s\n", begin->data);
		begin = begin -> next;
	}
}

int main(int argc, char **argv)
{
	t_list *begin;
	t_list *at;
	if(argc < 2)
	{
		puts("wrong number arguments");
		return(-1);
	}
	begin = ft_list_push_strs(argc - 1, argv + 1);
	off_list(begin);
	printf("%s its start\n", begin->data);

	at = ft_list_at(begin, 2);
	printf("%s its 02(third) elem\n", at->data);
}