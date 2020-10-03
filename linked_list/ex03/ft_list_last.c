/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 19:08:05 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/23 21:26:18 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list 	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
	{
		printf("%s\n", begin_list->data);
		begin_list = begin_list -> next;
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

int main()
{
	t_list *begin;
	t_list *last;
	
	begin = ft_create_elem("friend");
	ft_list_push_front(&begin, "MY");
	ft_list_push_front(&begin, "HELLLO");
	

	last = ft_list_last(begin);
	printf("begin data %s\n", begin->data);
	printf("last data %s\n", last->data);

}