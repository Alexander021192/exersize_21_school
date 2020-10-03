/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:20:52 by ocalamar          #+#    #+#             */
/*   Updated: 2020/09/23 18:55:05 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_list_size(t_list *begin_list)
{
	int len_list;

	len_list = 0;
	while (begin_list)
	{
		printf("%s\n", begin_list->data);
		len_list++;
		begin_list = begin_list -> next;
	}
	return (len_list);
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
	int len_list;

	begin = ft_create_elem("friend");
	ft_list_push_front(&begin, "MY");
	ft_list_push_front(&begin, "HELLLO");
	

	len_list = ft_list_size(begin);
	printf("size of list %d\n", len_list);

}